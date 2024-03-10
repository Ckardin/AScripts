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