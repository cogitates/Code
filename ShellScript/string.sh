#!/bin/bash
a="good"

echo `expr ${#a} + 1`   # length
echo ${a:1:3}

echo `expr index "$a" ad`

string="runoob is a great site"
echo `expr index "$string" io`  # è¾“å‡º 4