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
    std::cout<<"��һ��Ԫ��ֵ"<<s[0]<<std::endl;
    std::cout<<"����ʱ��"<<clock()-time_start<<std::endl;
    std::cout<<"����"<<s.capacity()<<std::endl;
    std::cout<<"ʹ�ô�С"<<s.size()<<std::endl;

    //time_start=clock();//�ٴμ�¼ʱ��

    std::string target="8213";
    auto tmp=std::find(s.begin(),s.end(),target);//�᷵��һ��ָ��
    std::cout<<*tmp<<std::endl;
    std::cout<<clock()-time_start<<std::endl;

}
