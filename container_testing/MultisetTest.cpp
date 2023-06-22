//
// Created by WLSD on 2023/6/22.
//
#include "stadfix.h"

void MultisetTest()
{
    const int MaxSize=1e6;
    std::multiset<std::string>Mulset;
    char buf[10];

    const char* tmp="8944564";

    clock_t Time_start=clock();
    for(int i=0;i<MaxSize;i++)
    {
        try
        {
            snprintf(buf,10,"%d",rand());
            Mulset.insert(buf);
        }
        catch (std::exception& p)
        {
            std::cout<<i<<' '<<p.what()<<std::endl;
            abort();
        }
    }

    std::cout<<"截止时间: "<<clock()-Time_start<<std::endl;
    std::cout<<"最大容量："<<Mulset.max_size()<<std::endl;
    std::cout<<"可以重复: "<<Mulset.size()<<std::endl;

    std::cout<<"记录查找前时间"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(Mulset.begin(),Mulset.end(),tmp);
    std::cout<<"查找后时间: "<<clock()-Time_start<<std::endl;

}