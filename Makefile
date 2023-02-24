obj-m += numb.o

EXTRA_CFLAGS=-DNUM1=$(num1) -DNUM2=$(num2) -DOP=$(op)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

run:
	sudo insmod numb.ko num1=$(num1) num2=$(num2) op=$(op)
	sudo rmmod numb.ko

