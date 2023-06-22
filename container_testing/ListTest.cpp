//
// Created by WLSD on 2023/6/21.
//
#include "stadfix.h"

void ListTest()
{
    const int MaxSize=1e6;
    std::list<std::string> List;
    char buf[10];

    //����Ŀ��
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

    std::cout<<"��ֹʱ��: "<<clock()-Time_start<<std::endl;
    std::cout<<"��Ԫ��: "<<*List.begin()<<std::endl;
    std::cout<<"��Ԫ��: "<<List.front()<<std::endl;
    std::cout<<"βԪ��: "<<List.back()<<std::endl;
    std::cout<<"���������"<<List.max_size()<<std::endl;
    std::cout<<"������: "<<List.size()<<std::endl;

    std::cout<<"��¼����ǰʱ��"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(List.begin(),List.end(),tmp);
    std::cout<<"���Һ�ʱ��: "<<clock()-Time_start<<std::endl;

    std::cout<<"��¼�������ǰʱ��"<<std::endl;
    Time_start=clock();
    List.sort();//�������������
    auto ptr1=std::find(List.begin(),List.end(),tmp);
    std::cout<<"���Һ�ʱ��: "<<clock()-Time_start<<std::endl;
}