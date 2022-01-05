/* #### 4.3.1 成员变量和成员函数分开存储



在C++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上  */


#include <iostream>

using namespace std;


class test {

};

class Person {
public:
	Person() {
		mA = 0;
	}
	//非静态成员变量占对象空间
	int mA;
    //int mC;

	//静态成员变量不占对象空间
	static int mB; 
	//函数也不占对象空间，所有函数共享一个函数实例
	void func() {
		cout << "mA:" << this->mA << endl;
	}
	//静态成员函数也不占对象空间
	static void sfunc() {
	}
};

void test01() {
    test p;
    // C++编译器会给每个空对象分配一个字节空间 为了区分空对象占内存的位置
    // 每个空对象也应该有个独一无二的内存空间
    cout << "size of p:" << sizeof(p) << endl;
}

int main() {

    test01();

	cout << sizeof(Person) << endl;  // 非静态成员变量占对象空间  --> 对象内存空间为 mA 所占空间大小 4 --> 加上mC  变为 8

	system("pause");

	return 0;
}