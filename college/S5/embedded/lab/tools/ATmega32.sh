#!/bin/sh

set -e
clear
echo "select option number"
echo ""
echo "compile AVR C program. [1]"
echo "install AVR-GCC pkgs.  [2]"
echo "install SimulIDE + config. [3]"
echo ""
echo "quit [q]"

# variables

MCU="atmega32" # architecture
OPTIMIZER="s" # optimization level [Os, O1, O2, O3]


echo "provide option: \c"
read -r option
echo "$option"

case "$option" in
    "1")
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
        if dpkg -s gcc-avr ? /dev/null 2>&1; then
            echo "avr-gcc packages and dependencies are already installed"
        else
        echo "installing avr-gcc packages and dependencies.."
        sudo apt-get install gcc build-essential
        sudo apt-get install gcc-avr binutils-avr avr-libc gdb-avr
        fi

    ;;
    "3")
        echo "installing SimulIDE from source"
        wget -O simuilde.tar.gz https://launchpad.net/simulide/1.1.0/1.1.0-sr0/+download/SimulIDE_1.1.0-SR0_Lin64.tar.gz
        tar -xvf simuilde.tar.gz
        echo "setting some configurations"
        # this fix is for my system which runs in wayland and may not be needed for college systems
        export QT_QPA_PLATFORM="xcb"
        echo "successfully installed SimulIDE"
        rm simulide.tar.gz

    ;;
    "q")
        echo "quitting...."
        exit 1
    ;;

    *)
    ;;
esac
