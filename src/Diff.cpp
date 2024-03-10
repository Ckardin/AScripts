/// English version
/*
Copyright (C) 2024 BOUCARD NICOLLE Jody

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
Copyright (C) 2024 BOUCARD NICOLLE Jody

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

/// @file Diff.cpp
/// @brief Source de AScripts/Diff
/// @author F&nµx
/// @version 1.0
/// @date 10/03/2024

#include "AScripts.h"

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        std::cout << "You must specifiy exactly 2 directories for comparing themselves." <<std::endl;
        return -1;
    }

    if(!std::filesystem::exists(argv[1]) || !std::filesystem::is_directory(argv[1]))
    {
        std::cout << "Path1 doesn't exist or isn't a directory." <<std::endl;
        return -2;
    }

    if(!std::filesystem::exists(argv[2]) || !std::filesystem::is_directory(argv[2]))
    {
        std::cout << "Path2 doesn't exist or isn't a directory." <<std::endl;
        return -3;
    }

    if(Fenyx::CompareDir(argv[1], argv[2])) std::cout << "Same directory" <<std::endl;
    else                             std::cout << "Not same directory" <<std::endl;

    return 0;
}