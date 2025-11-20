#!/usr/bin/env bash

read -p "enter a number: " -r n
a=0
b=1
for (( i = 0; i < n; i++ )); do
  echo "$a "
  b=$((a + b))
  a=$((b - a))
done
