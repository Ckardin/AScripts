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
    uint8_t nspace = 0;

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

    std::istringstream isstr(argv[1]);
    isstr >> nspace;

    if(nspace > 64)
    {
        std::cout << "The number of spaces is too big (max 64)." <<std::endl;
        return -3;
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
