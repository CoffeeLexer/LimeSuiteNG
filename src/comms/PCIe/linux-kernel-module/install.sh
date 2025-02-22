#!/bin/bash
# This script load specified kernel module from system directory

MODULE_NAME=$1
if [ -z $MODULE_NAME ]
then
    echo "Kernel module name not specified"
    exit 1
fi

if [ `id -u` != 0 ] ; then
    echo -e "\033[33mWarning, script must be run with root permissions\033[0m"
    exit 1
fi

LOG_FILE=/var/tmp/$MODULE_NAME.log

if ! lsmod | grep -Eq "^$MODULE_NAME" ; then
    depmod
    modprobe -v $MODULE_NAME >> $LOG_FILE

    # Configure /etc/modules to load it automatically
    if ! grep -xq "$MODULE_NAME" /etc/modules ; then
        echo "$MODULE_NAME" >> /etc/modules
    fi

    if lsmod | grep -Eq "^$MODULE_NAME"; then
        echo "SUCCESS: $MODULE_NAME module loaded" >> $LOG_FILE
    else
        echo "FAILURE: $MODULE_NAME install failed" >> $LOG_FILE
        exit 1
    fi
else
    echo "$MODULE_NAME module was loaded successfully" >> $LOG_FILE
fi

exit 0
