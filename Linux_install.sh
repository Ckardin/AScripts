#!/bin/bash

if [ $(printenv | grep ASHES_DIR | grep -c .) -eq 0 ]; then
    export ASHES_DIR="/Ashes"
    sudo mkdir /Ashes
    sudo mkdir /Ashes/bin/
    sudo cp ./Linux/* /Ashes/bin
    sudo chmod +x /Ashes/bin/Diff
    sudo chmod +x /Ashes/bin/Echo
    sudo chmod +x /Ashes/bin/Lines
    sudo chmod +x /Ashes/bin/MakeInfo
    sudo chmod +x /Ashes/bin/Spaces

    echo "export ASHES_DIR='/Ashes'" >> ~/.bashrc
else
    sudo mkdir $ASHES_DIR/bin
    sudo cp ./Linux/* $ASHES_DIR/bin/
    sudo chmod +x $ASHES_DIR/bin/Diff
    sudo chmod +x $ASHES_DIR/bin/Echo
    sudo chmod +x $ASHES_DIR/bin/Lines
    sudo chmod +x $ASHES_DIR/bin/MakeInfo
    sudo chmod +x $ASHES_DIR/bin/Spaces
fi
