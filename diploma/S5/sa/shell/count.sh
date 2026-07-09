#!/usr/bin/env bash

read -p "enter filename: " -r file

if [[ ! -f $file ]]; then 
  echo "file not found"
  exit 1
fi

w=$(wc -w <"$file")
l=$(wc -l <"$file")
c=$(wc -c <"$file")

echo "words: $w"
echo "lines: $l"
echo "count: $c"
