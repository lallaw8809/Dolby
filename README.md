# mini2440_source_code

boot        : Bootloader source code  
doc         : Board details  
final_image : Images (u-boot.bin and uImage)  
kernel      : Kernel souce code  
root_fs     : Root file system source code  
serial_bin  : Serial USB binary  
tool_chain  : Tool chain binaries  
README      : Procedure of how to create a uImage and u-boot.bin  

# Procedure to port the kernel image on mini2440

## Download all required file from git:
	$git clone https://github.com/lallaw8809/mini2440_Porting.git  

## Tool Chain:

step 1: Export the current sdk path  
	$export DIR=$PWD  

step 2: Open the tool_chain folder and export the path  
	$cd $DIR/tool_chain/opt/FriendlyARM/toolschain/4.4.3/bin  

step 3: Export the binaries ot set the tool chain path  
	$export PATH=$PATH:$PWD  

step 4: Go to the sdk path  
	$cd $DIR  

Step 5: Validation of tool chain  
	$arm-linux-gcc -v  

output will be:  
	-----------------------------------  
	| Thread model: posix		  |  
	| gcc version 4.4.3 (ctng-1.6.1)  |  
	-----------------------------------  

## Create a U-boot image (u-boot.bin)


step 1: go to the boot loader source code  
	$cd $DIR/boot/  

step 2: Extract the tar file  
	$ tar -xvf u-boot.tar.gz  

step 3: Go to the boot loader directory  
	$cd u-boot  

step 4: clean the source code  
	$make ARCH=arm CROSS_COMPILE=arm-linux- clean  
	$make ARCH=arm CROSS_COMPILE=arm-linux- distclean  

step 5: configure the device  
	$make ARCH=arm CROSS_COMPILE=arm-linux- mini2440_config  

step 6: compile and create a u-boot.bin  
	$make ARCH=arm CROSS_COMPILE=arm-linux-  
	
	For successfull build will generate a `u-boot.bin`  


# Create Kernel Image (uImage)

step 1: go to the kerenl source code Directory  
	$cd $DIR/kernel  

step 2: Extract the kernel code  
	$tar -xvf linux-2.6.32.2-mini2440-20120606.tar.gz  

step 3: Enter into kernel source code directory  
	$cd cd linux-2.6.32.2  

step 4: clean the source code  
	$make ARCH=arm CROSS_COMPILE=arm-linux- clean  
	$make ARCH=arm CROSS_COMPILE=arm-linux- distclean  

step 5: configure the device  
	$make ARCH=arm CROSS_COMPILE=arm-linux- mini2440_n35_defconfig  

step 6: compile and create uImage  
	$make ARCH=arm CROSS_COMPILE=arm-linux- uImage  

	For successfull build will generate a kernel image at `arch/arm/boot/uImage`  


	

