#include "stadfix.h"
#include "Myallocator.h"

int main()
{
    int a[]={1,2,3,4,5};

    std::vector<int,jj::allocator<int>>res(a,a+5);

    for(int i=0;i<5;i++)
    {
        std::cout<<res[i]<<' ';
    }

    std::cout<<std::endl;

    return 0;
}
