//
//  main.cpp
//  testcode
//
//  Created by mac on 2019/7/8.
//  Copyright © 2019年 yinzhibang. All rights reserved.
//

#include <iostream>
#include<cstdio>
#include<cmath>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<string>
#include<utility>
#include<sstream>
#include<cstring>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include <vector>

using namespace std;

class Solutionpermute {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,res,0);
        return res;
    }
    void swap(int &a,int &b)
    {
        int temp;
        temp=a;
        a=b;
        b=temp;
    }
    //n代表数组的总数，k代表当前已经递归到第k个数
    void backtrack(vector<int> &nums,vector<vector<int>> &res,int i){
        if(i==nums.size())
            res.push_back(nums);
        for(int j=i;j<nums.size();j++){
            printf("in----i-num[%d]= %d | j-num[%d]= %d \n",i,nums[i],j,nums[j]);
            swap(nums[i],nums[j]);
            backtrack(nums,res,i+1);
            printf("out---i-num[%d]= %d | j-num[%d]= %d \n",i,nums[i],j,nums[j]);
            swap(nums[i],nums[j]);
        }
    }
};

/*
 sizeof 和 strlen 的区别：
 
（1）sizeof是运算符，而strlen是函数；
（2）sizeof的用法是sizeof(参数)，这个参数可以是数组，指针，类型，对象，甚至是函数，其值在编译的时候就计算好了，而strlen的参数必须是字符型指针（char*）,其值必须在函数运行的时候才能计算出来；
（3） sizeof的功能是获得保证能容纳实现的建立的最大对象的字节的大小，而strlen的功能是返回字符串的长度，切记这里的字符串的长度是包括结束符的；
（4）当数组作为参数传递给函数的时候，传的是指针，而不是数组，传递数组的首地址
*/


/*
内联函数和宏定义区别：
1)内联函数在编译时展开，而宏在预编译时展开
2)在编译的时候，内联函数直接被嵌入到目标代码中去，而宏只是一个简单的文本替换。
3)内联函数可以进行诸如类型安全检查、语句是否正确等编译功能，宏不具有这样的功能。
4)宏不是函数，而inline是函数
*/

//override关键字(C++ 11)


//https://www.cnblogs.com/hushpa/p/5707475.html
//虚函数表

//问题
/*
malloc / free
 
*  malloc/free只是动态分配内存空间/释放空间。而new/delete除了分配空间还会调用构造函数和析构函数进行初始化与清理（清理成员）。
 
*  它们都是动态管理内存的入口。
*  malloc/free是C/C++标准库的函数，new/delete是C++操作符。
*  malloc/free需要手动计算类型大小且返回值w为void*，new/delete可自动计算类型的大小，返回对应类型的指针。
*  malloc/free管理内存失败会返回0，new/delete等的方式管理内存失败会抛出异常

 */


//问题
//动态绑定 和 静态绑定 的定义
/*
 静态类型：对象在声明期间已经确定
 动态类型：指指针或者引用目前所指的对象类型，运行期间决定
 静态绑定：绑定的是静态类型，发送在编译期间
 动态绑定：绑定的是动态类型，发生在运行期间，动态绑定只有指针或者引用虚函数的时候才会发生
 
 非虚函数静态绑定，虚函数动态绑定
 
 */

//析构函数一定要是虚函数
//析构函数声明为一定要为虚函数？在继承或者多态的时候
/*
 
不一定，在继承和多态的情况下使用虚函数
 
 A 是父类，B是子类
 A *a = new B();

 delete a;
 
 如果A的析构函数没有调用加 virtual , 怎只会析构A，
 
 1.加 virtual
 2. delete ((B *)a);
 
*/




//c++ operator
//https://blog.csdn.net/sunxu2016/article/details/77074683
/*
 问题 拷贝构造函数 和 赋值函数的区别
 1. 拷贝构造函数是构造函数，属于操作符范畴，赋值函数是类成员函数；
 2. A（const A &a） |  A & (const A &a) ,返回参数不同，便于连续赋值
 3. 应用场景不同，首次创建 都使用拷贝构造函数 A b(a) ; A c(a)
    二次赋值属于赋值函数 A d;  A e;  d = 3;
 4. 自己创建拷贝构造函数，是防止悬挂指针出现；https://www.cnblogs.com/balingybj/p/4731690.html
 */
//拷贝构造函数


//https://blog.csdn.net/gaozhefeng/article/details/17248753
//对象里面包含有指针，如果不做深度copy ,进行两次析构，产生悬挂指针

/*
如果没定义复制构造函数（别的不管），编译器会自动生成默认复制构造函数
如果定义了其他构造函数（包括复制构造函数），编译器绝不会生成默认构造函数
即使自己写了析构函数，编译器也会自动生成默认析构函数
*/
#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String(const char *str);
    String(const String &other);
    String & operator=(const String &other);
    ~String(void);
private:
    char *m_data;
};

String::String(const char *str)
{
    cout << "自定义构造函数" << endl;
    if (str == NULL)
    {
        m_data = new char[1];
        *m_data = '\0';
    }
    else
    {
        int length = strlen(str);
        m_data = new char[length + 1];
        strcpy(m_data, str);
    }
}

String::String(const String &other)
{
    cout << "自定义拷贝构造函数" << endl;
    int length = strlen(other.m_data);
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

String & String::operator=(const String &other)
{
    cout << "自定义赋值函数" << endl;
    
    if (this == &other)    //  在赋值函数中一定要记得比较
    {
        return *this;
    }
    else
    {
        delete [] m_data;
        int length = strlen(other.m_data);
        m_data = new char[length + 1];
        strcpy(m_data, other.m_data);
        return *this;
    }
}

String::~String(void)
{
    cout << "自定义析构函数" << endl;
    delete [] m_data;
}
int func8()
{
    cout << "a(\"abc\")" << endl;
    String a("abc"); //构造函数
    
    cout << "b(\"cde\")" << endl;
    String b("cde");//构造函数
    
    cout << " d = a" << endl;
    String d = a;//自定义的拷贝构造函数
    
    cout << "c(b)" << endl;
    String c(b);// 自定义拷贝构造函数
    
    cout << "c = a" << endl;
    c = a;//赋值函数
    //拷贝构造函数是对象被创建时调用，赋值函数只能被已经存在了的对象调用
    
    cout << endl;
    return 0;
}
//类直接赋值的时候使用的拷贝构造函数

//深拷贝就是把另一个对象在内存里的数据全部复制到当前对象里
//而浅拷贝就只是让当前对象有一个对另一个对象的引用而已

//sizeof strlen


/*
 指针数组  数组指针
 指针数组： 是数组，存的元素都是指针；
 数组指针： 指向数组的指针；
 */


void func9()
{
    //指针数组。
    int *am[5]; // 5 个指针元素
    typedef int* pInt;
    pInt cm[5];
    
    //数组指针
    int (*bm)[5]; //指向数组b 的指针

    int c[4]={1,2,3,4};
    int *a[4]; //指针数组
    int (*b)[4]; //数组指针
    b=&c;
    //将数组c中元素赋给数组a
    for(int i=0;i<4;i++)
    {
        a[i]=&c[i];
    }
    //输出看下结果
    cout<<*a[1]<<endl; //输出2就对
    cout<<(*b)[2]<<endl; //输出3就对
    
    int m[4]={1,2,3,4};
    int *p = &m[0];
    return ;
}

/*
 注意：定义了数组指针，该指针指向这个数组的首地址，必须给指针指定一个地址，容易犯的错得就是，不给b地址，直接用(*b)[i]=c[i]给数组b中元素赋值，这时数组指针不知道指向哪里，调试时可能没错，但运行时肯定出现问题，使用指针时要注意这个问题。但为什么a就不用给他地址呢，a的元素是指针，实际上for循环内已经给数组a中元素指定地址了。但若在for循环内写*a[i]=c[i]，这同样会出问题。总之一句话，定义了指针一定要知道指针指向哪里，不然要悲剧。
 
 类似的还有指针函数和函数指针，遇到了再说吧。
 
 char *array[2] = { "beij","sha" };声明一个有两个元素的指针数组，其中一个元素指向char数组“beig”，另一个指向数组“sha”
 

 */

 
/*
  常量指针
 1.拥有常量的所有属性，可以指向多个地址
 2.常量指针指向的对象不能通过这个指针修改这个数值，需要通过之前的声明来修改；
 3.常量指针可以被赋值为变量地址，但限制了通过指针修改变量的值；
 */

void func10(){
    int i = 10;
    int i2 = 11;
    const int *p = &i;
    printf("%d\n", *p);//10
    i = 9; //OK,仍然可以通过原来的声明修改值，
    //Error,*p是const int的，不可修改，即常量指针不可修改其指向地址
    //*p = 11;  //error: assignment of read-only location ‘*p’
    p = &i2;//OK,指针还可以指向别处，因为指针只是个变量，可以随意指向；
    printf("%d\n", *p);//11
    
    
    //常量指针：
    int a = 30;
    const int b = 9;
    int const *pc;//另外一种表达方式
    const int *pb = &a; //常量指针
    pb =&b;//b 是常量，指向是合法的
    // *pb = 20;//这个是错误的
    //字符串拷贝的时候
    int strcmp(const char *str1, const char *str2);
    
    return ;
}

//指针常量：顾名思义它就是一个常量，但是是指针修饰的
//1.是一个常量
//2.指针常量，指针本身是一个常量，指向的地址不可以变化，但是指向的地址所对应的内容可以变化的；
void func7(){
    //int *const pb ；//指针常量
    int pm ;
    int *const pa = &pm; //指针常量 声明了一个常量pa 他指向了 pm 的地址
    //那么分为一下两种操作
    *pa=9;//操作成功
 //   p=&b;//操作错误
   // 因此，有这么段程序：
    char *ta = "abcde1234";
    char *tb = "bcde";
  //  char *const tc = &ta;
   // 下面的操作是可以的。
    ta[0] = 'x'; // 我们并没有限制a为常量指针（指向常量的指针）
   // 或者
  //  *tc[0] = 'x'; // 与上面的操作一致
    
    int i = 10;
    int *const p = &i;
    printf("%d\n", *p);//10
    //Error,因为p是const 指针，因此不能改变p指向的内容
    //p++;//error: increment of read-only variable ‘p’
    (*p)++;    //OK,指针是常量，指向的地址不可以变化,但是指向的地址所对应的内容可以变化
    printf("%d\n", *p);//11
    i = 9;//OK,仍然可以通过原来的声明修改值
}

//指向常量的常指针
/*
 指向常量的指针常量就是一个常量，且它指向的对象也是一个常量；
 
 1.一个指针常量，指向的是一个指针对象；
 2.指向的指针对象是一个常量，即指向对象不能变换；
 
 */
// const int* const p;
void func11(void)
{
    int i = 10;
    const int *const p = &i;
    printf("%d\n", *p);//10
    //p++;//error: increment of read-only variable ‘p’
    //(*p)++;//increment of read-only location ‘*p’
    i++;//OK,仍然可以通过原来的声明修改值
    printf("%d\n", *p);//11
    return;
}


/*
 函数指针回调，
 */
typedef void (*callback)(char *x);

void funcb(char *s){
    printf("callback %s \n",s);
}
void call_callback(callback cb,char *s){
    cb(s);
}
// 普通调用函数方法

//callback = &funcb();
void func5(){
    void (*fptr)();
    void func_aa();
   // fptr = &func_aa();
    
    typedef void(*MeanFun)();
    
//    void f1(){};
//    void f2(){};
//    void f3(){};
//    MeanFun fun[]={f1,f2,f3};
//    fun[0]();
//    (*fun[0])();
}

/*
 函数指针和指针函数
 指针函数本身是一个函数，返回一个指针，返回的指针类型和函数类型相同
 */
void func4()
{
//    int *p = nullptr;
//    int *funcbb();
//    p = (int *)funcbb();
}

/*
 a 是值传递
 b 是引用传递
 */

/*
void change1(int n){
    //cout<<"值传递--函数操作地址"<<&n<<endl;         //显示的是拷贝的地址而不是源地址
    n++;
}

9 //引用传递
10 void change2(int & n){
    11     cout<<"引用传递--函数操作地址"<<&n<<endl;
    12     n++;
    13 }
14  //指针传递
15 void change3(int *n){
    16      cout<<"指针传递--函数操作地址 "<<n<<endl;
    17     *n=*n+1;
    18  }
*/

//引用规则：
//n1 值传递  n2 引用传递 n3 指针传递
//1） 引用被创建时候必须被初始化,指针可以任何时候初始化
//2) 不能有null引用，引用必须关联想过的变量
//3) 一旦被引用的就不能改变初始化关系了

//值传递实质

/*
 行参对实参数的一次拷贝，函数内修改的是行参的值，不会对外部的实参，造成影响，传递是单向的
*/

//指针传递实质
/*
 指针传递 其实是值传递 ，传递了一个地址，这正的实参在栈上开辟了空间保存了起来，不能修改其实参的数值
 *／
 
 引用传递实质
 
 ／*
 1. 函数内部传递修改调用者
 2. 对比指针传递 是可以将 行参 “传递” 给 “实参”的
 3. 需要多个返回值的时候
 */

void func_test(int n1,int &n2,int *n3){
    
    cout<<"值传递--函数操作地址"<<&n1<<endl;         //显示的是拷贝的地址而不是源地址
    n1++;
    
    cout<<"引用传递--函数操作地址"<<&n2<<endl;
    n2++;
    
    cout<<"指针传递--函数操作地址 "<<n3<<endl;
    *n3=*n3+1;
}

typedef int* int_ptr;

void func(int *fa,int *&fb,int **fc,int &fd){
    int b = 1;//指针
    fa = &b;
    //*fa =b;
    
    //指针引用
    int *b_tmp = (int *)malloc(4);
    *b_tmp = 2;
    //a = b_tmp;
    fb = b_tmp;
    
    //指针的指针
    int c = 3;
    int *p_n = *fc;
    //**n = c;
    *fc = &c;
    
    //引用
    fd = 4;
    
    printf("func = *a = %d fa=%d *m= %d  **n=%d  w= %d \n",*fa,fa,*fb,**fc,fd);
    return;
}

//指针和引用的自增(++)运算意义不一样
//指针是地址加sizeof(指针类型)
//引用是引用对象的数值加1
//指针是间接访问，引用是直接访问
void func3(){
    //引用的写法
    int val = 10;
    int val2 = 11;
    
    int *b_test = &val;
    b_test = &val2;
    
    char *c_test = (char *)&val;
    
    printf("addr_b_test = %d  c_test %d\n",b_test,c_test);
    b_test++;
    c_test++;
    printf("addr_add_b_test = %d c_test=%d ",b_test,c_test);
    
    printf("p_test_point = %d  val= %d  val2= %d \n",*b_test,val,val2);
    
    int &p_test = val;
    p_test = val2;
    
    printf("p_test_yinyong = %d  val= %d  val2= %d \n",p_test,val,val2);
    p_test++;
    printf("p_test_2yinyong = %d  val= %d  val2= %d \n",p_test,val,val2);
}


class A
{
public:
    virtual void fun1()
    {
        cout << "A::fun1()" << endl;
    }
    virtual void fun2()
    {
        cout << "A::fun2()" << endl;
    }
};

class B : public A
{
public:
    void fun1()
    {
        cout << "B::fun1()" << endl;
    }
    void fun2()
    {
        cout << "B::fun2()" << endl;
    }
};

class C {
public:
    virtual void fun1(){
        cout << "C::fun1()" << endl;
    }
};

class D : public C {
public:
    void fun1(){
        cout << "C::fun1()" << endl;
    }
};

/*
 C++迟后联编和虚函数表
 */
class Base
{
public:
    long b;
    virtual void Show(int x)
    {
        cout << "In Base class, int x = " << x << endl;
    }
};

class Base1
{
public:
    long m;
    virtual void Show(int x)
    {
        cout << "In Base class, int x = " << x << endl;
    }
};

class Derived : public Base ,public Base1
{
public:
    long c;
    virtual void Show(float x)
    {
        cout << "In Derived, float x = " << x << endl;
    }
    virtual void Show(int x)
    {
        cout << "In Derived , int x = " << x << endl;
    }
};

void test (Base &b)
{
    int i = 1;
    b.Show(i);
    
    float f = 2.0;
    b.Show(f);
}
void test_2 (Derived &c){
    int i = 4;
    c.Show((int)i);
    
    float f = 6.0;
    c.Show(f);
}

// 智能指针
//auto_ptr

class Test
{
public:
    Test(string s)
    {
        str = s;
        cout<<"Test creat\n";
    }
    ~Test()
    {
        cout<<"Test delete:"<<str<<endl;
    }
    string& getStr()
    {
        return str;
    }
    void setStr(string s)
    {
        str = s;
    }
    void print()
    {
        cout<<str<<endl;
    }
public:
    int test_int;
private:
    string str;
};

struct LinkNode
{
    int value;
    LinkNode* next;
};

LinkNode* Reverse(LinkNode* header);

LinkNode* Reverse(LinkNode* header)
{
    if (header == NULL || header->next == NULL)
    {
        return header;
    }
    
    LinkNode* pre = header;
    LinkNode* cur = header->next;
    pre->next = NULL;
    while(cur != NULL)
    {
        auto next = cur-> next;
        cur->next = pre;//2->1
        pre = cur;
        cur = next;
    }
    return pre;
}

LinkNode* reverseList(LinkNode* head) {
    if(!head){
        return nullptr;
    }
    LinkNode* first = head;//始终指向原链表的首位元素
    LinkNode* target = head->next;//始终指向即将要放到当前链表首元素之前的目标元素
    
    //
    while(target != nullptr){
        first->next = target->next; // 3 链接 到 1 上
        LinkNode* temp = target->next; //保留
        target->next = head;//   1 链接到 2
        head = target; // 2 放到 链表头
        target = temp; // 移动目标转移到下一个节点
    }
    return head;
}

void printLink(LinkNode* header)
{
    while(header != NULL)
    {
        cout<< header->value;
        header = header->next;
        if (header != NULL)
        {
            cout<< "->";
        }
    }
    cout<<endl;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n"<< "sizeof(C)" << sizeof(C) << "D: "<<sizeof(D)<<endl;
    
 
    //
   // In Derived, float x = 4 为什么不是调用的基类的函数实现
   // In Derived, float x = 6
    
//    vector<int> vtest;
//
//    vtest.push_back(1);
//    vtest.push_back(2);
//    vtest.push_back(3);
//
//    Solutionpermute *per =   new Solutionpermute;
//    per->permute(vtest);
    
    int a[]= {1,2,3,4,5};
    int *p = &a[0];
    p++;
    //int c =
    printf("fffval= %d \n",*(p++));
    
    int arr[] ={1,2,3,4,5,6,7,8};
    
    int *ptr =(int *)(&arr+1);  //2  5 加& 为 行 + 1
    //*(arr +1) //为列加一
    
    //ptr + 1 //指针地址移动4byte ;
    
    cout<<*(arr+1)<<" kkkkkk= "<<*(ptr-1)<<endl;
    
    int *m_ptr = nullptr;
    m_ptr = ptr+1;
    cout << "ptr " << ptr << "m_ptr "<< m_ptr << endl;
    cout<< " ffff = "<<*(arr+1)<<" kkkk= "<<*(ptr+1)<<endl;
    
    int *mptr =(int *)(arr+1);
    
    int *tmp = &arr[0];
    
    cout<< "&arr= "<< &arr << " (&arr+1) " << (&arr+1) << " "<<*(ptr)<< "*mptr= " << *mptr<<endl;
    
    
    tmp++;
    int tmp_a = *tmp +1;
    int tmp_b = *(tmp+1);
    printf(" tmp = %d  tmp_a=%d  tmp_b= %d  ",tmp[0],tmp_a,tmp_b);
    
   
    
    int *ptrr =(int *)(arr+1);   //2  1
    
    cout<<*(arr+1)<<" "<<*(ptr-1)<<endl;
    
    int b[2][3] = {{1,2,3},{4,5,6}};
    int (*pb)[3];
    pb = b;
    pb++;
    cout<<"**pb= " << **pb << endl;  //4
    
//    ————————————————
//    版权声明：本文为CSDN博主「wsqyouth」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
//    原文链接：https://blog.csdn.net/u013457167/article/details/82814413
    
    
    call_callback(funcb,"Hello World!\n");
    
    
//    int arr[] ={1,2,3,4,5,6};
//
//    int *ptr =(int *)(&arr+1);
//    int *ptrr =(int *)(arr+2);

    int *ptr_v = &arr[0];
    int *ptr_m = ptr_v + 3;
    
    printf("*ptr %d   *ptrr= %d  *ptr_m =%d \n",*ptr,*ptrr,*ptr_m);
    
    cout<<*(arr+1)<<" "<<*(ptr-1)<<endl;
    
    char *cp ;
    int *ip;
    
    printf("cp %d  ip= %d \n",sizeof(cp),sizeof(ip));
    
   // int *tmp = nullptr;
    int aa = 13;
    int *tmp_aa = (int *)malloc(4);
    *tmp_aa = aa;
  
    int *tmp_bb = (int *)malloc(4);
    int bb = 23;
    *tmp_bb = bb;
    
    int *tmp_cc = (int *)malloc(4);
    int cc = 33;
    *tmp_cc = cc;
    
    int tmp_dd = 43;
    printf("111tmp_aa = %d  *tmp_aa = %d tmp_bb=%d  *tmp_bb=%d tmp_cc=%d *tmp_cc=%d tmp_dd=%d \n",tmp_aa,*tmp_aa,tmp_bb,*tmp_bb,tmp_cc,*tmp_cc,tmp_dd);
    func(tmp_aa,tmp_bb,&tmp_cc,tmp_dd);
    printf("222tmp_aa = %d  *tmp_aa = %d tmp_bb=%d  *tmp_bb=%d tmp_cc=%d *tmp_cc=%d tmp_dd=%d \n",tmp_aa,*tmp_aa,tmp_bb,*tmp_bb,tmp_cc,*tmp_cc,tmp_dd);
    
    int n1 = 10;
    func_test(n1,n1,&n1);
    
    func3();

    func11();
    
    /*
     虚函数表大小和调用流程验证
     */
    
    Base bc;
    Derived sc;
    
    test(bc);
    test(sc);
    test_2(sc);
    std::cout << " size " << sizeof(Base) <<" Derived "<< sizeof(Derived)<< "sizeofint= "<< sizeof(int)<<endl;
    
    
    printf("auto_ptr**************************************\n");
    
    auto_ptr<Test> ptest(new Test("123"));
    ptest->setStr("hello ");
    ptest->print();
    ptest.get()->print();
    ptest->getStr() += "world !";
    (*ptest).print();
    ptest.reset(new Test("123"));
    ptest->print();
    
    auto_ptr<Test> ptest1(new Test("123"));
    auto_ptr<Test> ptest2(new Test("456"));
    ptest2 = ptest1;
    ptest2->print();
    ptest->test_int;
    ptest->setStr("aa");
    if(ptest.get() == NULL)cout<<"ptest = NULL\n";

    
    printf("auto_ptr**************************************\n");
    
    
    printf("unique_ptr**************************************\n");
    
    
    printf("unique_ptr**************************************\n");
    
    
    printf("reverse_ptr**************************************\n");
    LinkNode* header = NULL, *cur = NULL;
    for(int i = 1; i <= 5; ++i)
    {
        LinkNode* node = new LinkNode;
        node->value = i;
        node->next = NULL;
        
        if (header == NULL)
        {
            header = node;
            cur = header;
        }
        else
        {
            cur->next = node;
            cur = node;
        }
    }
    
    printLink(header);
    
    //反转单向链表
    auto newHeader = Reverse(header);
    
    printLink(reverseList(header));
    
     printLink(header);
   printf("reverse_ptr**************************************\n");
    
    
    shared_ptr<string> pint1 = make_shared<string>("safe uage!");
    
    int *ptr_a;
    
    std::shared_ptr<int> sp(new int(10));
    std::weak_ptr<int> wp(sp);
   // wp = sp;
    printf("%d\n", wp.use_count()); // 1
    wp.reset();
    printf("%d %d \n", sizeof(wp),sizeof(sp));
    
     printf("reverse_ptr************************************** %d %d\n",sizeof(ptr_a),sizeof(pint1));
    
}



/*
 多态性：由继承产生的不同的类，其对象对同一个消息产生的不同的响应。
 
 */




/*
 class struct 区别
 
 1. class 默认继承 属性 private , struct 默认属性 public
 2. class 可以继承／struct 不能
 3. class 可以有静态函数／ struct 不能
 
 */


/*
  构造函数会重载，一般不会重载，不然产生歧义
 */
class Box{
    public :
    Box(int h=10,int w=10,int m=10);
    Box(int,int);
};

//Box box(13,23);

/*
 c++ const  用法：
 const 定义变量
 
 */

/*
 
 /*
 封装 public / private / protect
 
 继承

  函数重载
  同一个类中，函数名相同，参数不同， virtual 关键字可有可无
 
  函数覆盖
  子类和父类中，函数名相同，参数也相同，父类必须包含 virtual 关键字
 
  函数重定义（隐藏）
  1）子类和父类中，函数名相同，参数不同，无论是否有 virtual 关键字，基础类都被隐藏了。
  2）子类和父亲中，函数名相同，参数不同，父类中没有virtual 关键字，基础类被隐藏。
  “2）的隐藏也是覆盖的一种”
 
 
  隐藏1 相对于覆盖是参数不同，覆盖参数相同
  覆盖2 相对于覆盖是 基类 没有 virtual 关键字
 */

/*
 static 作用：
 c 文件里面：
 1.全局静态变量
   作用范围为整个文件内部，内存开辟在静态存储区
 2.局部静态变量
   作用范围为函数内部，首次进入初始化，后续就会持续使用当前数值，如果没有初始化，会默认初始化为0
 3.函数默认是extern ，加了static 默认使用的区域为本文件内部
 
 c++
 
 1. 定义在类里面的静态变量，初始化的时候使用 作用域运算符 ,在 c 文件中将其初始化
 2. 定义在类里面的静态函数，访问静态变量使用的，都属于某个类，而不属于某个对象，增加了类的访问权限的全局函数
 3. （静态函数可以继承和覆盖，但是不能是虚函数）
 */


/*
  const 作用：
 
 1. 常量
    const int a = 5;
    c 中是全局变量
 
 2. 指针和常量
    常量指针
    const char *p; / char const *p
    可以指向
 
    指针常量
   char *const p;
 
 3.const修饰函数传入参数
 
    func(const A *p)
    func(const A &p)

 4.修饰函数返回值
    需要返回一个常量或者常指针
 
 5.const修饰成员函数
   const 修饰的成员函数不能修改相对应的成员变量
   任何不会修改数据成员的函数都因该声明为const类型
   void fun() const;
 
 6.
 
*/


/*
 const 和 define 区别；
 
 const作用：定义常量、修饰函数参数、修饰函数返回值三个作用。
 
 被Const修饰的东西都受到强制保护，可以预防意外的变动，能提高程序的健壮性。
 
 1） const 常量有数据类型，而宏常量没有数据类型。
    const 编译器可以对前者进行类型安全检查。
    define 而对后者只进行字符替换，没有类型安全检查，并且在字符替换可能会产生意料不到的错误。
 
 2） 有些集成化的调试工具可以对const 常量进行调试，但是不能对宏常量进行调试
*/

/*
 数组和指针区别：
 
 1）数组在栈上开辟内存，指针在堆上开辟内存
 2）数组的内存获取方式可以是sizeof , 指针无法有效获取指向地址里面内容的所占用的内存大小
 
 */


/*
 sizeof和strlen的区别
 （1）sizeof是运算符，而strlen是函数；
 （2）sizeof的用法是sizeof(参数)，这个参数可以是数组，指针，类型，对象，甚至是函数，其值在编译的时候就计算好了，而strlen的参数必须是字符型指针（char*）,其值必须在函数运行的时候才能计算出来；
 （3） sizeof的功能是获得保证能容纳实现的建立的最大对象的字节的大小，而strlen的功能是返回字符串的长度，切记这里的字符串的长度是包括结束符的；
 （4）当数组作为参数传递给函数的时候，传的是指针，而不是数组，传递数组的首地址；
 */


/*
 c++ 11 的特性
 
 1.类型推导
 auto type
 auto i = 1; //int
 auto c = "adc";// char *
 

 template <nametype T,nametype C>
 void add(T a,C b){
    return a+b;
 }
 auto add(1,2);
 auto add(3.0,4.0);
 
 
 2.遍历
 
 std::vector<string> v = {"a","b"}
 for(auto &m:v){
 
 }
 
 3.nullptr
 
 void f(int i)
 void f(char *s)
 NULL / 0 都为0 ，传入 nullptr 为 第二个函数
 
 4.构造函数互相调用
 
 5.final 关键字
   a.  禁止函数被重写
   b.  禁止被继承
 
 class A {
 public:
    virtual void f1() final {}
 };
 
 class B : public A {
    virtual void f1() {}
 };
 
 6.override
 
 class Base ｛
 virtual void f();
 }；
 
 class Derived : public Base {
 void f() override; // 表示派生类重写基类虚函数f
 void F() override;//错误：函数F没有重写基类任何虚函数
 }；
 
 */

/*
 //vector
  */

    int data[4];
    int length =sizeof(data)/sizeof(data[0]);
    
    int a[3] = {0,1,2};

    std::vector<int> fp_vec;
    vector<int>ivec1;

    std::vector<int>test_vec;//建立一个vector
  //  test_vec.push_back(1);

    //fp_vec->push_back(0);

    vector<int> i_vec = {a,a+3};
    int v_size = sizeof(a)/sizeof(a[0]);

//    int m = 0;
//    i_vec.push_back(m[i]);


/*
 1、不要使用std::auto_ptr
 
 2、当你需要一个独占资源所有权（访问权+生命控制权）的指针，且不允许任何外界访问，请使用std::unique_ptr
 
 3、当你需要一个共享资源所有权（访问权+生命控制权）的指针，请使用std::shared_ptr
 
 当你需要一个能访问资源，但不控制其生命周期的指针，请使用std::weak_ptr
 
 
 
 推荐用法：
 一个shared_ptr和n个weak_ptr搭配使用 而不是n个shared_ptr
 因为一般模型中，最好总是被一个指针控制生命周期，然后可以被n个指针控制访问。
 */

 
 
 
 
 
 
 
 


















