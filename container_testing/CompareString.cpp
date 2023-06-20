//
// Created by WLSD on 2023/6/20.
//
#include "stadfix.h"
int CompareString(const void*a,const void*b)
{
    if(*(std::string*)a>*(std::string*)b)
        return 1;
    else if(*(std::string*)a<*(std::string*)b)
        return -1;
    else
        return 0;
}