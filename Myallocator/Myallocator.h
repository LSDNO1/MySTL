//
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
        delete ptr;
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
