//
// Created by WLSD on 2023/6/20.
//
#include "stafix.h"

template<class T>
class Funtional
{
public:
    bool operator()(T a,T b )
    {
        return a>b;
    }
};

int main()
{
    int a[]={1,4,5,8,2,0,10};
    //                   默认分配器
    std::vector<int,std::allocator<int>>res(a,a+6);

    for(auto& num:res)
    {
        std::cout<<num<<' ';
    }
    std::cout<<std::endl;
    //通过迭代器来进行对容器内存的遍历
    std::vector<int>::iterator it_begin=res.begin();
    std::vector<int>::iterator it_end=res.end();
    //默认升序
    std::sort(it_begin,it_end);
    for(auto& num:res)
    {
        std::cout<<num<<' ';
    }
    std::cout<<std::endl;
    //实现降序,通过仿函数实现
    std::sort(it_begin,it_end,Funtional<int>());
    for(auto& num:res)
    {
        std::cout<<num<<' ';
    }
    std::cout<<std::endl;
    return 0;
}

