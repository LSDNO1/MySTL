# c++内存配置操作和释放操作

```C++
class Foo{};
Foo* pf=new Foo;
delete  pf;
```

## new阶段：

(1)调用::operator new配置内存

(2)调用Foo：：Foo()构造对象内容

## delete阶段：

(1)Foo：：~Foo()将对象析构

(2)调用::operator delete释放内存



## ::operator delete和delete有啥区别

对于 C++ 中的内存管理，`::operator delete` 和 `delete` 都可以用于释放动态分配的内存，但它们之间有一些区别。

`delete` 是一个 C++ 关键字，用于释放由 `new` 运算符分配的内存。它会调用对象的析构函数并释放内存。如果使用了自定义分配器，则会使用分配器的 `deallocate` 函数释放内存。

**`::operator delete` 是一个全局函数**，用于释放由 `::operator new` 分配的内存。**它不会调用对象的析构函数，只是简单地释放内存**。如果使用了自定义分配器，则会使用分配器的 `deallocate` 函数释放内存。

因此，如果您使用了自定义分配器并且希望在释放内存时调用分配器的 `deallocate` 函数，则应该使用 `delete` 运算符。如果您只是想简单地释放内存而不调用析构函数或分配器，则可以使用 `::operator delete` 函数。