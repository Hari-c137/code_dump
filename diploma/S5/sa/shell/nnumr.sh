#!/usr/bin/env bash

read -p "enter a number: " -r n
for(( i = n; i >= 0; i-- )); do echo "$i"; done
