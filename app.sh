#!/bin/bash
#sleep 3&&(cd /home/sia/YuLin_lab/src/DucoCobotAPI_py&&python3 demo.py)

# if [ "$?" = 0 ]; then

cd /opt/rocos/app/bin

sudo ./rocosAppMain -urdf models/talon/robot_white.urdf -nosim

# fi
