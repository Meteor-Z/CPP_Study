# C++面向对象高级编程

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
```

但是