#!/usr/bin/env bash

read -p "enter a number" -r n
temp=$n
a=0

while [ $n != 0 ]; do
  d=$(( n % 10))
  a=$(( a + d ))
  n=$(( n / 10))
done
echo " $a"
