//
// Created by WLSD on 2023/6/22.
//
#include "stadfix.h"

void Multimap()
{
    const int MaxSize=1e5;
    std::multimap<int,std::string>Mumap;
    char buf[10];

    const char* tmp="8944564";
    const int tmp1=123456;

    clock_t Time_start=clock();
    for(int i=0;i<MaxSize;i++)
    {
        try
        {
            snprintf(buf,10,"%d",rand());
            Mumap.insert(std::pair<int,std::string>(i,buf));
        }
        catch (std::exception& p)
        {
            std::cout<<i<<' '<<p.what()<<std::endl;
            abort();
        }
    }

    std::cout<<"����ǰ: "<<(*Mumap.begin()).second<<std::endl;
    Mumap.insert(std::pair<int,std::string>(0,"79"));
    std::cout<<"���º�: "<<(*Mumap.begin()).second<<std::endl;

    std::cout<<"��ֹʱ��: "<<clock()-Time_start<<std::endl;
    std::cout<<"���������"<<Mumap.max_size()<<std::endl;
    std::cout<<"�����ظ�: "<<Mumap.size()<<std::endl;

    std::cout<<"��¼����ǰʱ��"<<std::endl;
    Time_start=clock();
    auto p=Mumap.find(tmp1);
    std::cout<<"���Һ�ʱ��: "<<clock()-Time_start<<std::endl;

}