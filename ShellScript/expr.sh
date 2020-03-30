#!/bin/bash

x=23
echo `expr $x + 1`
val=`expr $x + 1`
echo $val
# 乘号(*)前边必须加反斜杠(\)才能实现乘法运算；