//
// Created by WLSD on 2023/6/21.
//
#include "stadfix.h"

void Forward_ListTest()
{
    const int MaxSize=1e6;
    std::forward_list<std::string>forward_List;
    char buf[10];

    //查找目标
    const char* tmp="8944564";

    clock_t Time_start=clock();
    for(int i=0;i<MaxSize;i++)
    {
        try
        {
            snprintf(buf,10,"%d",rand());
            forward_List.push_front(buf);
        }
        catch (std::exception& p)
        {
            std::cout<<i<<' '<<p.what()<<std::endl;
            abort();
        }
    }

    std::cout<<"截止时间: "<<clock()-Time_start<<std::endl;
    std::cout<<"首元素: "<<*forward_List.begin()<<std::endl;
    std::cout<<"首元素: "<<forward_List.front()<<std::endl;
    //std::cout<<"尾元素: "<<forward_List.back()<<std::endl;
    std::cout<<"最大容量："<<forward_List.max_size()<<std::endl;
    //std::cout<<"链表长度: "<<forward_List.size()<<std::endl;

    std::cout<<"记录查找前时间"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(forward_List.begin(),forward_List.end(),tmp);
    std::cout<<"查找后时间: "<<clock()-Time_start<<std::endl;

    std::cout<<"记录排序查找前时间"<<std::endl;
    Time_start=clock();
    forward_List.sort();//链表本身的排序函数
    auto ptr1=std::find(forward_List.begin(),forward_List.end(),tmp);
    std::cout<<"查找后时间: "<<clock()-Time_start<<std::endl;
}