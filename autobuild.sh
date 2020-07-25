#########################################################################
# File Name: autobuild.sh
# Author: lv qiang
# mail: 1149622825@qq.com lq13892023709@163.com
# Created Time: 2020年07月25日 星期日 18时43分50秒
#########################################################################
#!/bin/bash

set -x

rm -rf `pwd`/build/*
cd `pwd`/build &&
	cmake .. &&
	make
