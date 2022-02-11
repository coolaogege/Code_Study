
/* #### 4.5.3 递增运算符重载


作用： 通过重载递增运算符，实现自己的整型数据 */

// 目的：  MyInteger myint ;

// 类似于  int a = 0 ;   cout << a++ << endl ;    cout << ++a << endl ;
// 实现  自己创建对象的自增  cout << myint++ << endl ;    cout << ++myint << endl ;
// 前置递增  后置递增


// > 总结： 前置递增返回引用，后置递增返回值

#include <iostream>

using namespace std;


class MyInteger {

    // 友元
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
    // 构造函数
	MyInteger() {
		m_Num = 0;
	}

    // MyInteger&  为了 是 一直对 这一个 对象进行 操作 
    // 具体可看视频的讲解！！

	//前置++   --- 直接返回对象 自增的结果
	MyInteger& operator++() {
		//先++
		m_Num++;
		//再返回
		return *this;
	}

	//后置++
    // operator++(int)  int 代表的是一个占位参数！ 用于区分 前置 和 后置递增  区分函数重载用
    // MyInteger operator++(int)  没加&  temp是局部变量 ！！
	MyInteger operator++(int) {
		//先记录当时结果 --->  再自增 ---> 返回记录的结果
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		return temp;
	}

private:
	int m_Num;
};

// MyInteger myint 这里 没有添加 引用  是因为
// 直接返回值的话 相当于 适用拷贝构造函数返回了一个新对象 ， 而 使用引用返回 相当于 返回这个对象本身
// 这里的话 
ostream& operator<<(ostream& cout, MyInteger myint) {
	cout << myint.m_Num;
	return cout;
}


//前置++ 先++ 再返回
void test01() {
	MyInteger myInt;
	cout << ++myInt << endl;
	cout << myInt << endl;
}

//后置++ 先返回 再++
void test02() {

	MyInteger myInt;
	cout << myInt++ << endl;
	cout << myInt << endl;
}

int main() {

    int a = 0;
    cout << ++(++a) << endl;    // 不报错!
	cout << a << endl;

	// test01();

    // 对于后置 不能使用 链式操作  int a 也不能进行链式操作！ 否则报错
    // int a = 0;
    // cout << (a++)++ << endl;    // x++ 需要作用到一个变量上，不能作用到一个表达式上，所以（a++）++不行  显示  非法错误！
	// cout << a << endl;

    test02();


	system("pause");

	return 0;
}