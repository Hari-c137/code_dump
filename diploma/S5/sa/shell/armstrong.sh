#!/usr/bin/env bash

read -p "enter a number: " -r n
a=0
t=$n

while [ "$n" != 0 ]; do
  r=$(( n % 10))
  a=$(( a + r * r * r))
  n=$(( n / 10))
done
if [[ $a == $t ]]; then
  echo "armstrong"
else
  echo "not armstrong"
fi
