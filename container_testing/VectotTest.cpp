//
// Created by WLSD on 2023/6/21.
//
#include "stadfix.h"
void VectorTest()
{
    const int MaxSize=1e5;
    std::vector<std::string> s;
    char buf[10]={};

    clock_t time_start=clock();
    for(int i=0;i<MaxSize;i++)
    {
        try
        {
            snprintf(buf,10,"%d",rand());
            s.push_back(buf);
        }
        catch (std::exception& p)
        {
            std::cout<<i<<' '<<p.what()<<std::endl;
            abort();
        }
    }
    std::cout<<"第一个元素值"<<s[0]<<std::endl;
    std::cout<<"插入时间"<<clock()-time_start<<std::endl;
    std::cout<<"容量"<<s.capacity()<<std::endl;
    std::cout<<"使用大小"<<s.size()<<std::endl;

    //time_start=clock();//再次记录时间

    std::string target="8213";
    auto tmp=std::find(s.begin(),s.end(),target);//会返回一个指针
    std::cout<<*tmp<<std::endl;
    std::cout<<clock()-time_start<<std::endl;

}
