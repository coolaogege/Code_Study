// 引用
// 作用 ： 给变量名起别名
// 语法 ： 数据类型 &别名  = 原名   ---- 数据类型 要一样！

// 引用使用的注意事项
//      -- 引用必须初始化   
//          -- int a = 10;
//            -- int &b; // error!
//      -- 引用在初始化后，不可以改
//          -- int &b = a;
//            -- int &b = c; // error!
//              -- b = c; // 这样可以，这是赋值的操作！


// 引用做函数的传递
// 作用： 函数传参时，可以利用引用的技术 --- 让形参修饰实参
// 优点： 可以简化指针修改实参！

// ---- 通过引用参数产生的效果同地址传递是一样的。而且引用的语法更为简单。


// 引用做函数的返回值
// 作用： 引用是可以作为函数的返回值存在的

// 注意： 不要返回局部变量引用
// 用法： 函数调用作为左值


// 引用的本质
// 引用的本质  在c++内部实现 是一个指针常量   -- 指针指向不可以修改   内容可以修改
// int &ref = a;  ----->   int* const ref = a; (等价的)
// ref = 20;   ------>  *ref = 20; 


// 常量引用
// 作用：常量引用 主要用来 修饰形参 ，防止误操作
// 在 函数形参列表 中，可以加==const修饰形参==，防止形参改变实参

#include <iostream>

using namespace std;

//1. 值传递
void mySwap01(int a, int b) 
{
	int temp = a;
	a = b;
	b = temp;
}

//2. 地址传递
void mySwap02(int* a, int* b) 
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//3. 引用传递
void mySwap03(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}


//返回局部变量引用  -- 注意  int&  ----> 因为接收使用的   int &ref  
int& test01() 
{
	int a = 10; //局部变量  -  存放在栈区 使用之后就释放
	return a;
}

int& test02() 
{
	static int a = 10; //静态变量  -  存放在全局区 
	return a;
}


//引用使用的场景，通常用来修饰形参
void showValue(const int& v) 
{
	//v = 1000;  // 就会报错！ --- 因为加了 const  不能够修改
	cout << v << endl;
}

int main()
{
    // 创建变量
    int a = 10;

    // 创建引用
    int &b = a;

    cout << b << endl;
    
    b = 20;  // 给别名改值 原值也会变化！

    cout << b << endl;
    cout << a << endl;

    // 创建变量
    int c = 10;
    int d = 20;

    // 引用修改
    mySwap03(c,d);

    cout << c << endl;
    cout << d << endl;   

    // 引用作为函数返回值
    int &ref = test01();
    // cout << ref << endl;   -- 直接俄报错了！！

    int &ref2 = test02();
    cout << ref2 << endl;  // 输出10


    // 作为左值！
    test02() = 1000;  //  test02 -- 对a的引用   让其为1000 ---  即为对a直接进行操作  
    cout << ref2 << endl;  // 输出1000      ---  因为 ref2 对a 的引用  ---- 对a的更改相当于对ref2的更改！


    // 加入const 编译器将代码进行修改 ---- int temp = 10; const int &ref3 = temp;
    const int &ref3 = 10;       // 引用必须是一个合法的内存空间  --  临时的空间
    
    cout << ref3 << endl;  
    // ref3 = 20;   // --- 报错 ----> 加入const 只读  不可以修改


    // 函数中利用常量引用防止误操作修改实参
    int e  = 30;
    showValue(e);


    system("pause");
    return 0;
}

