//
// Created by WLSD on 2023/6/21.
//
#include "stadfix.h"

void DequeTest()
{
    const int MaxSize=1e6;
    std::deque<std::string>Deque;
    char buf[10];

    //����Ŀ��
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

    std::cout<<"��ֹʱ��: "<<clock()-Time_start<<std::endl;
    std::cout<<"��Ԫ��: "<<*Deque.begin()<<std::endl;
    std::cout<<"��Ԫ��: "<<Deque.front()<<std::endl;
    std::cout<<"βԪ��: "<<Deque.back()<<std::endl;
    std::cout<<"���������"<<Deque.max_size()<<std::endl;
    std::cout<<"˫����г���: "<<Deque.size()<<std::endl;

    std::cout<<"��¼����ǰʱ��"<<std::endl;
    Time_start=clock();
    auto ptr=std::find(Deque.begin(),Deque.end(),tmp);
    std::cout<<"���Һ�ʱ��: "<<clock()-Time_start<<std::endl;

    std::cout<<"��¼�������ǰʱ��"<<std::endl;
    Time_start=clock();
    std::sort(Deque.begin(),Deque.end());
    auto ptr1=std::find(Deque.begin(),Deque.end(),tmp);
    std::cout<<"���Һ�ʱ��: "<<clock()-Time_start<<std::endl;
}