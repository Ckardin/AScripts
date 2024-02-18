# Script MakeInfo // Version Windows

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

# [CmdletBinding()]
Param (
    [string] $type = $(throw "You must specify the type of info."),
    [string] $vpnt = $(throw "You must specify the name of info.")
)

$shellcmd = ""
$colorcmd = ""

if($type -ceq "making")
{
    $shellcmd = "Making "
    $colorcmd = "red"
}
elseif($type -ceq "clean")
{
    $shellcmd = "Cleaning "
    $colorcmd = "red"
}
elseif($type -ceq "install")
{
    $shellcmd = "Installing "
    $colorcmd = "red"
}
elseif($type -ceq "module")
{
    $shellcmd = "... Compile Module " + $(Spaces.ps1 9) + " "
    $colorcmd = "green"
}
elseif($type -ceq "static")
{
    $shellcmd = "==> Creating static lib " + $(Spaces.ps1 4) + " "
    $colorcmd = "blue"
}
elseif($type -ceq "dynamic")
{
    $shellcmd = "==> Creating dynamic lib " + $(Spaces.ps1 3) + " "
    $colorcmd = "cyan"
}
elseif($type -ceq "program_s")
{
    $shellcmd = "==> Linking static " + $(Spaces.ps1 9) + " "
    $colorcmd = "magenta"
}
elseif($type -ceq "program_d")
{
    $shellcmd = "==> Linking dynamic " + $(Spaces.ps1 8) + " "
    $colorcmd = "magenta"
}
elseif($type -ceq "doc")
{
    $shellcmd = "... Compiling doc: "
    $colorcmd = "yellow"
}
else
{
    Echo.ps1 "Invalid [type] parameter." red default
    exit 1
}

$shellcmd = $shellcmd + $vpnt

Echo.ps1 $shellcmd $colorcmd default
exit 0

