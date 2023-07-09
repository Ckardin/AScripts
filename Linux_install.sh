#!/bin/bash

# Install Script // Version Linux

<<"COMMENTS"
COMMENTS

# English version
# Copyright (C) 2023 BOUCARD NICOLLE Jody

# This file is part of AScripts.

# AScripts is free software: you can redistribute it and/or modify it under the terms of the GNU General 
# Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
# option) any later version.

# AScripts is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.

# You should have received a copy of the GNU General Public License along with AScripts. If not, see 
# <https://www.gnu.org/licenses/>.


# Version française
# Copyright (C) 2023 BOUCARD NICOLLE Jody

# Ce fichier fait partie de AScripts.

# AScripts est un logiciel libre ; vous pouvez le redistribuer ou le modifier suivant les termes de la GNU General 
# Public License telle que publiée par la Free Software Foundation, soit la version 3 de la licence, soit (à votre 
# gré) toute version ultérieure.

# AScripts est distribué dans l'espoir qu'il sera utile, mais SANS AUCUNE GARANTIE; sans même la 
# garantie tacite de QUALITÉ MARCHANDE ou d'ADÉQUATION À UN BUT PARTICULIER. Consultez la GNU 
# General Public License pour plus de détails.

# Vous devez avoir reçu une copie de la GNU General Public License en même temps que AScripts. Si ce n'est pas le cas, consultez 
# <http://www.gnu.org/licenses>.

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
