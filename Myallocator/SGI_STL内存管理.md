# STL的内存管理

## 一个标准的配置器

一个配置器最重要的问题是如何分配和回收内存，下面是一个经典的配置器

```C++
// Created by WLSD on 2023/6/23.
//

#ifndef MYALLOCATOR_MYALLOCATOR_H
#define MYALLOCATOR_MYALLOCATOR_H
#include "stadfix.h"

namespace jj
{
    template<class T>
    inline T*_allocate(size_t n,T*ptr)
    {
        std::set_new_handler(0);
        T*tmp=(T*)(::operator new(size_t(n*sizeof (T))));
        if(tmp== nullptr)
        {
            std::cout<<"out of memory"<<std::endl;
            exit(-1);
        }
        return tmp;
    }
    //销毁空间
    template<class T>
    inline void _deallocate(T*ptr)
    {
        ::operator delete(ptr);
    }
    //构造对象，使得已经开辟的内存空间指向对象
    template<class T1,class T2>
    inline void _construct(T1*ptr,const T2& value)
    {
        new(ptr)(T1)(value);
    }
    //销毁对象
    template<class T>
    inline void _destroy(T*ptr)
    {
        ptr->~T();
    }

    template<class T>
    class allocator
    {
    public:
        typedef T               value_type;
        typedef T*              pointer;
        typedef const T*        const_pointer;
        typedef T&              reference;
        typedef const T&        const_reference;
        typedef size_t          size_type;
        typedef ptrdiff_t       difference_type;

        //绑定allocator，使得不用显示调用
        template<typename U>
        struct rbind
        {
            typedef allocator<U> other;
        };

        pointer allocate(size_type n,const void* hint=0)
        {
            return _allocate((difference_type)n,(pointer)0);
        }

        void deallocate(pointer ptr,size_type n)
        {
            _deallocate(ptr);
        }

        void construct(pointer ptr,const T& value)
        {
            _construct(ptr,value);
        }

        void destroy(pointer ptr)
        {
            _destroy(ptr);
        }

        //返回某个对象的地址
        pointer address(reference x)
        {
            return (T*)&x;
        }

        //返回某个const对象地址
        const_pointer address(const_reference x)
        {
            return (const T*)&x;
        }

        //返回对象可配置容量的最大值
        size_type max_type() const
        {
            return (size_t)(UINT_MAX/sizeof (T));
        }

    };
}


#endif //MYALLOCATOR_MYALLOCATOR_H
```

要自己写个配置器完全可以以这个类为模板。 而需要做的工作便是写下自己的 allocate和deallocate即可。

其实SGI的allocator 就是这样直接调用operator new 和::operator delete实现的，不过这样做的话效率就很差。

**因为不使用内存管理，会反复申请与销毁空间，从而需要额外开销。**