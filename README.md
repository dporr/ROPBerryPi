# RopBerry v1
![Person with hoodie reading computer screen wiht the raspberry logo](images/ropberry_1.png)

This is an adaptation of the challenges at [https://ropemporium.com](https://ropemporium.com/) to work on modern ARM processors, namely my raspberry pi.

This was tested on **RaspeberryPi 4B** 
* CPU Model:BCM2711 
* Core: CCortext-A72 
* ISA: ARMv8.0-A. 

# Compiling the targets for raspberry

In this example we compile a static binary for ARMv5 EABI, the same EABI as the original ropemporium. Our docker container includes toolchains for armel (Old ARM processors without hardwar floating point support), armhf (Rpi2-3) and aarch64 (RPI4 and RPI5). 
```sh
#Compile the docker file in this project
docker build -f compile2rasp.dockerfile -t arm:latest .

#run the container, get a shell and compile target binaries
docker run -it --rm --volume=$PWD:/ropberry arm:latest /bin/bash        

#inside the docker container
root@6030bb8c4e7c:/# ls
root@6030bb8c4e7c:/# cd ropberry/
root@6030bb8c4e7c:/robperry# arm-linux-gnueabi-gcc main.c -static -o target.elf
root@6030bb8c4e7c:/robperry# file target.elf 
target.elf: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), statically linked, BuildID[sha1]=cac2923c0081cfd5fff779084ab62018f549c344, for GNU/Linux 3.2.0, not stripped

#For RPI4 you do
root@6030bb8c4e7c:/robperry# aarch64-linux-gnu-gcc main.c -static -o target.elf

root@6030bb8c4e7c:/robperry# file target.elf 
target.elf: ELF 64-bit LSB executable, ARM aarch64, version 1 (GNU/Linux), statically linked, BuildID[sha1]=56b77a56e57cbe8fc5190853e26e5dd0fb74d89c, for GNU/Linux 3.7.0, not stripped

```

# Running older arm binaries
```sh
$ docker run -it --rm --name my-running-script -v "$PWD":/target -w /target balenalib/armv5e-python:latest ./main.armv5-sf-static
```