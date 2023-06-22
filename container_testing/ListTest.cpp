//
// Created by WLSD on 2023/6/21.
//
#include "stadfix.h"

void ListTest()
{
    const int MaxSize=1e6;
    std::list<std::string> List;
    char buf[10];

    //查找目标
    const char* tmp="2345";

    clock_t Time_start=clock();
    for(int i=0;i<MaxSize;i++)
    {
        try
        {
            snprintf(buf,10,"%d",rand());
            List.push_back(buf);
        }
        catch (std::exception& p)
        {
            std::cout<<i<<' '<<p.what()<<std::endl;
            abort();
        }
    }

    std::cout<<"截止时间: "<<clock()-Time_start<<std::endl;
    std::cout<<"首元素: "<<*List.begin()<<std::endl;
    std::cout<<"首元素: "<<List.front()<<std::endl;
    std::cout<<"尾元素: "<<List.back()<<std::endl;
    std::cout<<"最大容量："<<List.max_size()<<std::endl;
    std::cout<<"链表长度: "<<List.size()<<std::endl;

    std::cout<<"记录查找前时间"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(List.begin(),List.end(),tmp);
    std::cout<<"查找后时间: "<<clock()-Time_start<<std::endl;

    std::cout<<"记录排序查找前时间"<<std::endl;
    Time_start=clock();
    List.sort();//链表本身的排序函数
    auto ptr1=std::find(List.begin(),List.end(),tmp);
    std::cout<<"查找后时间: "<<clock()-Time_start<<std::endl;
}