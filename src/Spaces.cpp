/// English version
/*
Copyright (C) 2025 BOUCARD NICOLLE Jody

This file is part of AScripts.

AScripts is a free library: you can redistribute it and/or modify it under the terms of the GNU General 
Public License as published by the Free Software Foundation, either version 3 of the License, or (at your 
option) any later version.

ASCripts is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the 
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
General Public License for more details.

You should have received a copy of the GNU General Public License along with AScripts. If not, see 
<https://www.gnu.org/licenses/>.
*/

/// Version française
/*
Copyright (C) 2025 BOUCARD NICOLLE Jody

Ce fichier fait partie de AScripts.

AScripts est une bibliothèque libre ; vous pouvez la redistribuer ou la modifier suivant les termes de la GNU General 
Public License telle que publiée par la Free Software Foundation, soit la version 3 de la licence soit (à votre 
gré) toute version ultérieure.

AScripts est distribuée dans l'espoir qu'elle sera utile, mais SANS AUCUNE GARANTIE; sans même la 
garantie tacite de QUALITÉ MARCHANDE ou d'ADÉQUATION À UN BUT PARTICULIER. Consultez la GNU 
General Public License pour plus de détails.

Vous devez avoir reçu une copie de la GNU General Public License en même temps que AScripts. Si ce n'est pas le cas, consultez 
<http://www.gnu.org/licenses>.
*/

/*
---------------------------------------------
|    ____                                   |
|   /\  _`\                                 |
|   \ \ \L\_\ __    ___   __  __   __  _    |
|    \ \  _\/'__`\/' _ `\/\ \/\ \ /\ \/'\   |
|     \ \ \/\  __//\ \/\ \ \ \_\ \\/>  </   |
|      \ \_\ \____\ \_\ \_\/`____ \/\_/\_\  |
|       \/_/\/____/\/_/\/_/`/___/> \//\/_/  |
|                             /\___/        |
|                             \/__/         |
|                                           |
---------------------------------------------
*/

/// @file Spaces.cpp
/// @brief Source de AScripts/Spaces
/// @author F&nµx
/// @version 1.0
/// @date 02/03/2024

#include "AScripts.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << "You must specifiy the number of spaces." <<std::endl;
        return -1;
    }

    if(!Fenyx::IsNumStr(argv[1]))
    {
        std::cout << "You must specifiy a valid integer as first argument." <<std::endl;
        return -2;
    }

    if(!Fenyx::VerifTermExist())
    {
        std::cout << "You don't have terminal." <<std::endl;
        return -4;
    }

    std::string s_cmd = "tput cuf " + std::string(argv[1]);
    system(s_cmd.c_str());

    return 0;
}
