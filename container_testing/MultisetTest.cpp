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

    std::cout<<"��ֹʱ��: "<<clock()-Time_start<<std::endl;
    std::cout<<"���������"<<Mulset.max_size()<<std::endl;
    std::cout<<"�����ظ�: "<<Mulset.size()<<std::endl;

    std::cout<<"��¼����ǰʱ��"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(Mulset.begin(),Mulset.end(),tmp);
    std::cout<<"���Һ�ʱ��: "<<clock()-Time_start<<std::endl;

}