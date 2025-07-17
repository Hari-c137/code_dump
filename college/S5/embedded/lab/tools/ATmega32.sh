#!/bin/sh

# Author: Harry P.
#   Date: 7-17-25
# Header: Atmega32
# Descri: Setup and compile utility for AVR_C ATmega mcus

set -e # dont remove this, all my error_catching hope is hanging on this little shit!!!
clear
echo "select option number"
echo ""
echo "compile AVR C program. [1]"
echo "install AVR-GCC pkgs.  [2]"
echo "install SimulIDE + config. [3]"
echo ""
echo "quit [q]"

# variables

MCU="atmega32" # architecture // only tested on atmega32, for other MCUs i dont know and i dont care!
OPTIMIZER="s"  # optimization level [Os, O1, O2, O3] // in order for binary performance

echo "provide option: \c"
read -r option

case "$option" in
"1")
    # also creating elf files because i fucking can!!
    echo "enter your filename(no extension): \c"
    read -r FNAME
    echo "generating object code..."
    avr-gcc -mmcu="$MCU" -Wall -O"$OPTIMIZER" -o "$FNAME".elf "$FNAME".c
    echo "successfully created object code"
    echo "creating hex file from object code..."
    avr-objcopy -j .text -j .data -O ihex "$FNAME".elf "$FNAME".hex
    echo "hex file created successfully.. load this hex file as firmware in SimulIDE"

    ;;
"2")
    # my system is void_linux therefore i haven't tested this case on debian based(ubuntu) so... use at your own risk
    if dpkg -s gcc-avr ? /dev/null 2>&1; then # i call this part "my skill issue :("
        echo "avr-gcc packages and dependencies are already installed"
    else
        echo "installing avr-gcc packages and dependencies.."
        sudo apt-get install gcc build-essential
        sudo apt-get install gcc-avr binutils-avr avr-libc gdb-avr
    fi

    ;;
"3")
    echo "installing SimulIDE from source"
    # todo: fix latency/404 when api_call to webserver_bucket or just selfhost it in my server
    wget -O simuilde.tar.gz https://launchpad.net/simulide/1.1.0/1.1.0-sr0/+download/SimulIDE_1.1.0-SR0_Lin64.tar.gz
    echo "extracting files.."
    sleep 3
    tar -xvf simuilde.tar.gz
    echo "setting some configurations"
    # this fix is for my system which runs in wayland and may not be needed for college systems, nevertheless it doesn't hurt anyone
    export QT_QPA_PLATFORM="xcb"
    echo "successfully installed SimulIDE"
    echo "cleaning up bloat"
    sleep 2
    rm simulide.tar.gz #  whoosh... its gone..

    ;;
"q")
    echo "quitting...."
    exit 1
    ;;

*) ;;
esac
