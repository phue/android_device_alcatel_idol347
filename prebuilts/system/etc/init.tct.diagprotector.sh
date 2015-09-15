#!/system/bin/sh

#external/sepolicy/domain.te:177
#neverallow { domain -kernel -init -recovery -ueventd -watchdogd -healthd -vold -uncrypt } self:capability mknod;

buildtype=$(getprop ro.build.type)
if [ $buildtype == user ]; then
    if echo $(getprop sys.usb.state) | grep diag; then
        if [ ! -e /dev/diag ]; then
            major_name=$(grep " dia" /proc/devices)
            #mknod /dev/diag c ${major_name:0:3}, 0
            #chown system:qcom_diag /dev/diag
            #chmod 0660 /dev/diag
            /system/bin/log -t diagprotector -p w "Diag Protector OFF, must reboot."
        fi
    else
        if [ -e /dev/diag ]; then
            rm /dev/diag
        fi
    fi
fi
