#!/bin/bash
rm lib/libget_command.so
mkdir build
cd build
rm -rf *
cmake ..
make
make
echo "*************make is OK!*************"
echo "*******请分别输入命令和版本号********"
./docker
