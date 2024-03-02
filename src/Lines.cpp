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

/// @file Lines.cpp
/// @brief Source de AScripts/Lines
/// @author F&nµx
/// @version 1.0
/// @date 02/03/2024

#include "AScripts.h"

int main(int argc, char *argv[])
{
    uint8_t nline = 0;

    if(argc != 2)
    {
        std::cout << "You must specifiy the number of lines." <<std::endl;
        return -1;
    }

    if(!Fenyx::IsNumStr(argv[1]))
    {
        std::cout << "You must specifiy a valid integer as first argument." <<std::endl;
        return -2;
    }

    std::istringstream isstr(argv[1]);
    isstr >> nline;

    for(uint16_t i = 0; i < nline; i = i + 1)
    {
        std::cout << "" <<std::endl;
    }

    return 0;
}
