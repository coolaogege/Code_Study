#include <iostream>

#include <string> //使用string时调用 新版本不需要了

using namespace std;

// 定义一个常量  - 常量不可修改
#define pi 3.14

int main(){
    // const 修饰的变量 也是常量 不可进行修改
    const int day = 7; 

    // 变量创建 -- 注意 数字表示越界
    // 短整型 short 2字节
    // 整型 int 4字节
    // 长整型 long 4字节
    // 长长整型 long long 8字节   
    int a = 10;


    // 关键字 不可做为变量
    // int int = 10;


    // 标识符 字母、下划线，数字 开头不能为数字 区分大小写


    // sizeof的使用
    short num1 = 10;
    // cout <<"short占用空间为： "<< sizeof(num1) << endl; 


    // 单精度 float 占空间4字节  双精度 double 占空间 8字节
    float f1 = 3.1415926f; // float后加f ，告诉编译器
    // cout <<"f1 = "<< f1 << endl;
    double d1 = 3.1415926;
    // cout <<"d1 = "<< d1 << endl;
    // 在C++中输出一个小数 ，默认产生6位有效数字
    float f2 = 3e2; // 3*10^2 -- 300  3e-2 --3*0.1^2 -- 0.03
    cout <<"f2 = "<< f2 << endl;


    //字符型 -显示单个字符 -只占用一个字节的内存
    //将对应的ACSII编码放入到存储单元！
    // 创建方式  占内存大小sizeof(char)  常见错误  对应ASCii码
    // 'a' not "abc"
    char ch = 'a';
    cout << ch << endl;
    cout << (int)ch << endl; //打印出对应的编码 int强转型
    
    
    //转义字符  \换行符   \\反斜杠  \t水平制表符
    cout << "hello,ya\n";
    cout << "\\\n";
    //cout << "\\\";---显示错误
    cout << "aaa\thello\n";  // aaa\t  aaa五个空格hello
    //输出对齐！！  整齐输出数据


    //字符串 表示一个字符串  要用双引号""
    char str1[] = "hello,ya";   //C风格的
    cout << str1 << endl;  //自动换行了
    string str2 = "hello,ya";
    cout << str2 << endl;


    //布尔型 true -1   falue -0  占用一个字节大小
    bool flag = true;
    cout << flag << endl;


    //数据的输入 cin 从键盘上获取数据  
    //获取整型 浮点型 字符型 字符串型 布尔型
    // cout << "Please input a value:" << a << endl;
    // cin >> a ;
    // cout << a << endl;

    // string str = "hello";
    // cout << str << "\n" << "Please input new string:" << endl;
    // cin >> str;
    // cout << str << endl;


    //运算符 算术  赋值  比较 逻辑

    //算术  / 除取整   % 除取余  
    //除数有0 则出错 
    //两小数可以相除
    double dou1 = 0.5;
    double dou2 = 0.25;
    cout << dou1/dou2 << endl;

    //取余 %   
    //取余同样除数不能为0
    //两个小数不能做取模运算！！

    // ++ --运算符
    // ++a 先让变量加1再运算   a++ 先运算再递增
    int a1 = 10;
    //int b1 = ++a + 20 ;  //输出31
    int b1 = 20 + a1++  ;   //输出30  a1变为11
    cout << b1 << endl;
    cout << a1 << endl;

    //赋值运算 =  -=  +=  *=  /=  %=
    //  a-=10  means: a = a-10   

    //比较运算符  返回一个真值或假值 ==  !=  <  >  <=  >=

    //逻辑运算符  !  &&  ||      ---- 除了0以外 都是真  a = 10   !a---0 

    
    // cout <<"a = "<< pi << endl;
    // cout << day << endl;

    //cout << "你好！" << endl;
    system("pause");
    return 0;
    
}