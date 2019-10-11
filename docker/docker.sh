#!/bin/bash
#这是docker下载的执行命令脚本



#判断命令是否执行成功的function函数
function check()
{
	$1
        if [ $? -eq 0 ];then
		echo "succeed"
	else
		echo "failed"
		exit 2
	fi
}

echo "/***********************系统控制启动docker*******************/"
#系统控制启动docker
check 'systemctl start docker'

echo "/*************************使能docker************************/"
#使能docker
check 'systemctl enable docker'

echo "/***********************查看docker版本***********************/"
#查看docker版本
check 'docker version'

echo "/**********************查看docker详细消息*********************/"
#查看docker详细信息
check 'docker info'

echo "/**************************下载镜像***************************/"
#下载镜像
check 'wget http://download.openvz.org/template/precreated/ubuntu-16.04-x86_64.tar.gz'

echo "/*********************Docker导入ubuntun***********************/"
#Docker导入ubuntu
check 'docker import ubuntu-16.04-x86_64.tar.gz ubutu:16.04'

echo "/***********************查看docker镜像*************************/"
#查看docker镜像
check 'docker images'

