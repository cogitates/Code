#!/bin/bash

array_name=(1 2 3 4 5 6)
echo ${array_name[2]}
echo ${array_name[@]}
echo "数组的元素为: ${array_name[*]}"

echo "数组元素个数为: ${#array_name[*]}"
echo "数组元素个数为: ${#array_name[@]}"
# 注释
:<<EOF
GOOD
GOOD
EOF