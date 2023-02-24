#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Aruzhan Zhanatkyzy, Diana Umbetova, Nazira Shaimerdenova");
MODULE_DESCRIPTION("A simple example of a kernel module for calculating parameters.");

static int num1 = 0;
static int num2 = 0;
static char *op = "add";

module_param(num1, int, S_IRUSR | S_IWUSR);
module_param(num2, int, S_IRUSR | S_IWUSR);
module_param(op, charp, S_IRUSR | S_IWUSR);

static int __init calc_init(void)
{
    int result;

    if (strcmp(op, "add") == 0) {
        result = num1 + num2;
    } else if (strcmp(op, "sub") == 0) {
        result = num1 - num2;
    } else if (strcmp(op, "mul") == 0) {
        result = num1 * num2;
    } else if (strcmp(op, "div") == 0) {
        result = num1 / num2;
    } else {
        printk(KERN_ALERT "Invalid operation type\n");
        return -EINVAL;
    }

    printk(KERN_ALERT "Result of %d %s %d is %d\n", num1, op, num2, result);

    return 0;
}

static void __exit calc_exit(void)
{
    printk(KERN_ALERT "Calculation module unloaded\n");
}

module_init(calc_init);
module_exit(calc_exit);
