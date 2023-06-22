//
// Created by WLSD on 2023/6/21.
//
#include "stadfix.h"

void DequeTest()
{
    const int MaxSize=1e6;
    std::deque<std::string>Deque;
    char buf[10];

    //查找目标
    const char* tmp="8944564";

    clock_t Time_start=clock();
    for(int i=0;i<MaxSize;i++)
    {
        try
        {
            snprintf(buf,10,"%d",rand());
            Deque.push_back(buf);
        }
        catch (std::exception& p)
        {
            std::cout<<i<<' '<<p.what()<<std::endl;
            abort();
        }
    }

    std::cout<<"截止时间: "<<clock()-Time_start<<std::endl;
    std::cout<<"首元素: "<<*Deque.begin()<<std::endl;
    std::cout<<"首元素: "<<Deque.front()<<std::endl;
    std::cout<<"尾元素: "<<Deque.back()<<std::endl;
    std::cout<<"最大容量："<<Deque.max_size()<<std::endl;
    std::cout<<"双向队列长度: "<<Deque.size()<<std::endl;

    std::cout<<"记录查找前时间"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(Deque.begin(),Deque.end(),tmp);
    std::cout<<"查找后时间: "<<clock()-Time_start<<std::endl;

    std::cout<<"记录排序查找前时间"<<std::endl;
    Time_start=clock();
    std::sort(Deque.begin(),Deque.end());
    auto ptr1=std::find(Deque.begin(),Deque.end(),tmp);
    std::cout<<"查找后时间: "<<clock()-Time_start<<std::endl;
}