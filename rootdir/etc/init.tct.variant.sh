#!/system/bin/sh

setprop ro.cm.variant `/system/xbin/strings /dev/block/bootdevice/by-name/traceability | /system/xbin/grep '6039' | /system/xbin/cut -c4-8`
