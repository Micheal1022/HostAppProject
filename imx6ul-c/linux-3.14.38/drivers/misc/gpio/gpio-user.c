#include <linux/init.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/ioctl.h>
#include <linux/uaccess.h>
#include <linux/platform_device.h>
#include <linux/fs.h>

#define GPIO_U_IOCTL_BASE 'x'
#define GPIOC_OPS	_IOWR(GPIO_U_IOCTL_BASE,0,int)

#define MAX_GPIO_NR 32

struct gpio_user_data{
	const char *label;
	bool input;
	unsigned gpio;
	unsigned dft;
};
static struct gpio_misc{
	struct miscdevice misc;
	struct gpio_user_data *data;
	int gpio_count;
} *gpio_misc;



static int gpio_user_open(struct inode *inodp, struct file *filp)
{
	if(!gpio_misc)
				return -ENODEV;
		return 0;
}

static int gpio_user_release(struct inode *inodp, struct file *filp)
{
	if(!gpio_misc)
				return -ENODEV;
		return 0;
}

static long gpio_user_ioctl(struct file *filp, unsigned int cmd,unsigned long arg)
{
		int no, offset;
		unsigned long val;
		unsigned long __user *p = (void __user *)arg;
		struct gpio_user_data *data;
		unsigned long get_value;
		if(!gpio_misc)
				return -ENODEV;
		data = gpio_misc->data;

		if(_IOC_TYPE(cmd) != GPIO_U_IOCTL_BASE)
				return -EINVAL;
		switch(_IOC_NR(cmd)){
				case 0:
						if(get_user(val,p))
						return -EFAULT;
						
						if(data[val].input){
							val = gpio_get_value(data[val].gpio);
							put_user(val,p);
						} else {
							gpio_set_value(data[val].gpio,val >> 31);
						}

						break;

				default:
						return -ENOTTY;
		}
		return 0;
}

static const struct file_operations gpio_user_fops = {
	.owner = THIS_MODULE,
	.open = gpio_user_open,
	.release = gpio_user_release,
	.unlocked_ioctl = gpio_user_ioctl,
};

static void gpio_user_init_default(void)
{
		int i,ret;
		struct gpio_user_data *data;
		data = gpio_misc->data;

		for(i = 0;i < gpio_misc->gpio_count;i++){
				if(!gpio_is_valid(data[i].gpio)){
						continue;
				}
				ret = gpio_request(data[i].gpio,data[i].label);
				if(ret < 0){
						continue;
				}
				if(data[i].input)
				{
						gpio_direction_input(data[i].gpio);
				}
				else
				{
					gpio_direction_output(data[i].gpio,data[i].dft);
				}
		}
}
static void gpio_user_free_default(void)
{
		int i;
		struct gpio_user_data *data;

		data = gpio_misc->data;

		for(i = 0;i < gpio_misc->gpio_count;i++){
				if(!gpio_is_valid(data[i].gpio)){
						continue;
				}
				gpio_free(data[i].gpio);
		}
}
static int gpio_user_probe(struct platform_device *pdev)
{
	int index;
	struct device_node *node = pdev->dev.of_node, *child;
	gpio_misc = devm_kzalloc(&pdev->dev,sizeof(*gpio_misc),GFP_KERNEL);
	if(!gpio_misc){
		return -ENOMEM;
	}

	gpio_misc->gpio_count = of_get_available_child_count(node);
	if(!gpio_misc->gpio_count){
		return -ENODEV;
	}
	if(gpio_misc->gpio_count > MAX_GPIO_NR){
		gpio_misc->gpio_count = MAX_GPIO_NR;
	}

	gpio_misc->data = devm_kzalloc(&pdev->dev,sizeof(struct gpio_user_data) * gpio_misc->gpio_count,GFP_KERNEL);
	if(!gpio_misc->data){
		return -ENOMEM;
	}

	index = 0;
	for_each_available_child_of_node(node,child){
			const char *input;
			struct gpio_user_data *data = &gpio_misc->data[index++];		
			data->label = of_get_property(child,"label",NULL) ? : child->name;
			input = of_get_property(child,"default-direction",NULL) ? : "in";
			if(strcmp(input,"in") == 0)
				data->input = true;
			data->gpio = of_get_gpio_flags(child,0,&data->dft);
	}
	gpio_user_init_default();
	gpio_misc->misc.name = "gpio";
	gpio_misc->misc.minor = MISC_DYNAMIC_MINOR;
	gpio_misc->misc.fops = &gpio_user_fops;
	return misc_register(&gpio_misc->misc);
}
static int gpio_user_remove(struct platform_device *pdev)
{
	gpio_user_free_default();
	misc_deregister(&gpio_misc->misc);
	return 0;
}

static const struct of_device_id of_gpio_user_id_table[] = {
	{ .compatible = "gpio-user",},
	{},
};

MODULE_DEVICE_TABLE(of,of_gpio_user_id_table);

static struct platform_driver gpio_user_driver = {
	.probe = gpio_user_probe,
	.remove = gpio_user_remove,
	.driver = {
		.owner = THIS_MODULE,
		.name = "gpio-user",
		.of_match_table = of_gpio_user_id_table,
	},
};
module_platform_driver(gpio_user_driver);
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:gpio-user");
