//
// Created by WLSD on 2023/6/20.
//
#include "stadfix.h"

void Array_test()
{
    const int MaxSize=1e5;
    std::array<long long,MaxSize> num;

    clock_t time_start=clock();

    for(int i=0;i<MaxSize;i++)
    {
        num[i]=rand()%10;
    }
    //计算录入50万随机数所耗费的时间
    std::cout<<clock()-time_start<<std::endl;
    std::cout<<num.begin()<<std::endl;//也是数组首地址
    std::cout<<num.end()<<std::endl;//数组尾地址下一个位置，相当于前面的MaxSize
    std::cout<<num.data()<<std::endl;//数组首地址

    std::cout<<*num.end()<<std::endl;//指向开区间，即随机数
    std::cout<<*num.begin()<<std::endl;//首元素
    std::cout<<num[MaxSize-1]<<std::endl;//尾元素
}