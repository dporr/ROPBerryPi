FROM ubuntu:24.04

RUN  apt-get update &&  apt-get install -y --no-install-recommends && \
 apt install -y git bc bison flex libssl-dev make \
libc6-dev libncurses5-dev \
crossbuild-essential-arm64 \
crossbuild-essential-armhf \
crossbuild-essential-armel

 CMD ["/bin/bash"]






