#!/usr/bin/env bash

read -p "enter the day of the week: " -r c

case "$c" in
1) echo "monday" ;;
2) echo "tuesday" ;;
3) echo "wednesday" ;;
4) echo "thursday" ;;
5) echo "friday" ;;
6) echo "saturday" ;;
7) echo "sunday" ;;
*) echo "u r dumbw" ;;
esac
