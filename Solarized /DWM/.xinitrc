#!/bin/sh

. ~/.rate.sh &

# Programs
nitrogen --restore &
picom -b
dunst &
slstatus &
gammastep -l -9.8:-37.7 -t 6500:4000 &
# gsr-ui & 
xset dpms 300 600 900 &
gentoo-pipewire-launcher &

# Environment
export GDK_BACKEND=x11
export QT_QPA_PLATFORM=xcb
export SDL_VIDEODRIVER=x11
export CLUTTER_BACKEND=x11
# export LIBVA_DRIVER_NAME=i965
# export MESA_LOADER_DRIVER_OVERRIDE=i915
unset  WAYLAND_DISPLAY

# DWM 
exec dbus-launch --exit-with-session dwm
