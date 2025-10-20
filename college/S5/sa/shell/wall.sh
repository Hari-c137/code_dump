#!/bin/sh

WALLPAPER_DIR="$HOME/Pictures/Wallpapers" 
INTERVAL=1200  # 20 minutes in seconds

if ! command -v gsettings >/dev/null 2>&1; then
    echo "Err: not on GNOME DE"
    exit 1
fi

get_wallpapers() {
    find "$WALLPAPER_DIR" -type f \( -iname "*.jpg" -o -iname "*.png" -o -iname "*.jpeg" \) | sort
}

show_menu() {
    echo "Available Wallpapers:"
    i=1
    for wp in $wallpapers; do
        name=$(basename "$wp")
        echo "  [$i] $name"
        i=$((i + 1))
    done
    echo "  [r] Random wallpaper mode (change every 20 minutes)"
    echo "  [q] Quit"
}

set_wallpaper() {
    gsettings set org.gnome.desktop.background picture-uri "file://$1"
    gsettings set org.gnome.desktop.background picture-uri-dark "file://$1" 2>/dev/null
    echo "Wallpaper set to: $(basename "$1")"
}

random_mode() {
    echo "Random wallpaper mode started. Changing every $(($INTERVAL / 60)) minutes..."
    while true; do
        wp=$(echo "$wallpapers" | shuf -n 1)
        set_wallpaper "$wp"
        sleep "$INTERVAL"
    done
}

wallpapers=$(get_wallpapers)
count=$(echo "$wallpapers" | wc -l)

if [ "$count" -eq 0 ]; then
    echo "No wallpapers found in $WALLPAPER_DIR"
    exit 1
fi

show_menu

echo
printf "Enter number or option: "
read choice

if [ "$choice" = "q" ]; then
    echo "Exiting."
    exit 0
elif [ "$choice" = "r" ]; then
    random_mode
elif [ "$choice" -ge 1 ] 2>/dev/null && [ "$choice" -le "$count" ]; then
    selected=$(echo "$wallpapers" | sed -n "${choice}p")
    set_wallpaper "$selected"
else
    echo "Invalid choice."
    exit 1
fi
