# Script Echo // Version Windows

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
Param(
    [string] $vpnt   = $(throw "You must specify the text to print with colors."),
    [string] $fcolor = $(throw "You must specify the foreground color (default for no changes)."),
    [string] $bcolor = $(throw "You must specify the background color (default for no changes).")
)

$colors = @{black = 0; red = 1; green = 2; yellow = 3; blue = 4; magenta = 5; cyan = 6; white = 7; default = 8}
$Ret    = $false

foreach($c in $colors.keys)
{
    if($fcolor -ceq $c)
    {
        $Ret = $true;
    }
}

if($Ret -ceq $false)
{
    Write-Host "Foreground color is invalid."
    exit 1
}

$Ret = $false

foreach($c in $colors.keys)
{
    if($bcolor -ceq $c)
    {
        $Ret = $true;
    }
}

if($Ret -ceq $false)
{
    Write-Host "Background color is invalid."
    exit 2
}

if($fcolor -cne "default")
{
    tput setaf $colors[$fcolor]
}

if($bcolor -cne "default")
{
    tput setab $colors[$bcolor]
}

Write-Output $vpnt
tput sgr0

exit 0

