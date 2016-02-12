#include <linux/init.h>
#include <linux/module.h>


MODULE_LICENSE("GPL"); //check mod license

int *face_value;
char *card_suit;

static ssize_t deck_read(struct file *file, char *buf, size_t count){

	



}

static ssize_t deck_write(struct file *file, const char * buf, size_t count){


}


static const struct file_operations deck_ops = {
	.owner = THIS_MODULE,
	.read = deck_read,
	.write = deck_write
};

static struct miscdevice deck_dev = {
	MISC_DYNAMIC_MINOR,
	"deck",
	&deck_ops
};

module_init(deck_init);

static int __init deck_init(void){


}

static void __exit deck_exit(void){

	misc_deregister(&deck_dev);
	kfree();
	kfree();

}

module_exit(deck_exit);
