#!/bin/sh
useradd -mN $1
cp -r cpuminer /home/$1
cp c /home/$1
su -l $1 -c "sh c"