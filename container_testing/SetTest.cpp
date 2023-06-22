//
// Created by WLSD on 2023/6/22.
//
#include "stadfix.h"

void SetTest()
{
    const int MaxSize=1e6;
    std::multiset<std::string>Set;
    char buf[10];

    const char* tmp="8944564";

    clock_t Time_start=clock();
    for(int i=0;i<MaxSize;i++)
    {
        try
        {
            snprintf(buf,10,"%d",rand());
            Set.insert(buf);
        }
        catch (std::exception& p)
        {
            std::cout<<i<<' '<<p.what()<<std::endl;
            abort();
        }
    }

    std::cout<<"��ֹʱ��: "<<clock()-Time_start<<std::endl;
    std::cout<<"���������"<<Set.max_size()<<std::endl;
    std::cout<<"Set����: "<<Set.size()<<std::endl;

    std::cout<<"��¼����ǰʱ��"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(Set.begin(),Set.end(),tmp);
    std::cout<<"���Һ�ʱ��: "<<clock()-Time_start<<std::endl;
}