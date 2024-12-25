#!/bin/bash


if [ ! "`whoami`" = "root" ] 
then
	echo 
    	echo "Please run script as root or using sudo."
    	exit 1
fi


read -p 'Enter a User Name: ' NAME
read -p 'Enter a group to be added to you: ' GROUP

if id "$NAME" > /dev/null 2>&1; then
    echo "User '$NAME' exists. Here is the information:"
    id "$NAME"
    echo "Home Directory: $(getent passwd "$NAME" | cut -d: -f6)"
    echo "Shell: $(getent passwd "$NAME" | cut -d: -f7)"
else
    echo "The user '$NAME' does not exist."
    sudo useradd $NAME
fi


if getent group "$GROUP" > /dev/null 2>&1; then
    echo "Group '$GROUP' exists. Here is the information:"
    getent group "$GROUP"
    echo "The group '$GROUP' exists."
else
    echo "The group '$GROUP' does not exist."
    sudo groupadd $GROUP
fi


