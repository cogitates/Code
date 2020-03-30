#!/bin/bash

num1=100
num2=100

# test is alias of []
if test $[num1] -eq $[num2]
then
    echo '两个数相等！'
else
    echo '两个数不相等！'
fi