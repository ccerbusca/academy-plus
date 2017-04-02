#!/bin/bash
if [[ $EUID -ne 0 ]]; then
	echo "This script must be run as root" 1>&2
	exit 1
fi
OLDPORT=$(grep -r Port /etc/ssh/sshd_config)
NEWPORT="Port 64269"
sed -i "s@$OLDPORT@$NEWPORT@" /etc/ssh/sshd_config
/etc/init.d/ssh restart
