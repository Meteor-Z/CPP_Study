# 堆,栈,RAII

堆：分配内存之后需要手动释放，否则，将要造成内存泄漏

- `new`和`delete`操作的是`free store`
- `malloc`和`free`操作的是heap

`new`的底层就是`malloc`

动态获取内存都是在堆中进行的
`auto ptr = new std::vector<int>()`


# 智能指针

## unique_ptr

独享它所指向的指针，也就是说，同时只有一个unique_ptr指向一个对象，不能多个`unique_ptr`指向一个对象，
如果说`unique_ptr`被销毁，那么它所指向的对象也会被销毁

不能进行拷贝复制

## shared_ptr

共享他们呢所指向的指针，多个`shared_ptr`可以同时指向一个相同的对象，在计算机内部采用技术机制来实现
如果有对象关联的话，那么引用计数就会+1，如果智能指针减少，那么就会-1,当变成0,贼会将这个对象进行释放

## 删除器
在构造函数中第二个删除器就行了

1. 可以进行拷贝复制


## 两者区别
`unique_ptr` 占用资源比较小，所以大多数还是用`unique_ptr`吧




# ## 文件操作

文件流都在`<fstream>`里面


## 复合

构造函数由内到外,析构函数由外道内,`c++`会默认进行执行这些代码,我们只要完成其中的函数
如果自己不写的话，那么就要调用默认的构造函数和析构函数

## 委托

指针，不同步，外边的函数有了，但是里面的函数有可能没有
什么是委托?
但是
## 继承

构造函数:先先构造自己的父类，然后再构造自己的
析构函数:先执行父类的析构函数，然后再析构自己

### 虚函数

`non-virtual`:不希望子类重新定义他
`virtual`:希望子类能够重新定义他
`pure virtual`:希望子类一定要重新定义他


```c++
#include <iostream>

class CDocument
{
private:
public:
    void on_file_open()
    {
        std::cout << "你好" << std::endl;
        std::cout << "check file status.." << std::endl;
        std::cout << "open file" << std::endl;
        Serialize();
        std::cout << "close file" << std::endl;
        std::cout << "update all views" << std::endl;

    }
    virtual void Serialize() = 0; // =0 就是纯虚函数 需要子类亲自实现进行实现
};
class CMyDoc : public CDocument
{
private:
public:
    virtual void Serialize()
    {
        std::cout << "CMyDoc::Serialize()" << std::endl;
    }
};
int main()
{
    CMyDoc myDoc;
    myDoc.on_file_open();
}

```

定义虚函数是允许用基类的指针来调用子类的函数
纯虚函数是为了实现一个接口，起到一个规范的作用，规范是：子类必须继承这个函数

## 转换函数

```c++
class Fraction
{
private:
    int a, b; // a 是分子, b 是分母
public:
    Fraction(int a, int b = 1) : a(a), b(b)
    {}

    // 当做成 double 类型的时候，就会被调用起来
    operator double() const
    {
        return 1.0 * a / b;
    }
};

### explicit

如果加上的话，就是当正确的调用构造函数的时候才会出现，不会隐式的出现这个函数，
所以只要是隐式转换，就会寄了，

`注意`: 这个函数只在构造函数的时候会出现，十分明确当正确的时候才会出现这个函数

```c++
class Fraction
{
private:
    int a;
public:
    Fraction(int a = 1) : a(a)
    {}

    Fraction operator+(const Fraction& other)
    {
        return a + other.a;
    }
};


```

## 迭代器

## 仿函数

不懂

## namespace

如果使用`using namespace std`,那么就会发生冲突，所以说还是用namespace 包起来，然后再使用吧

## 成员模板

在模板里面的模板，在模板里面发生过变化

## 函数特化

面对



