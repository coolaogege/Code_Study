/* #### 4.2.3 拷贝构造函数调用时机



C++中拷贝构造函数调用时机通常有三种情况

* 使用一个已经创建完毕的对象来初始化一个新对象
* 值传递的方式给函数参数传值
* 以值方式返回局部对象 */


#include <iostream>

using namespace std;

class Person {
public:
	Person() {
		cout << "No-argument constructor" << endl;
		mAge = 0;
	}
	Person(int age) {
		cout << "Parameterized constructor" << endl;
		mAge = age;
	}
	Person(const Person& p) {
		cout << "Copy constructor" << endl;
		mAge = p.mAge;
	}
	//析构函数在释放内存之前调用
	~Person() {
		cout << "Destructor" << endl;
	}
public:
	int mAge;
};

//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test01() {

	Person man(100); //p对象已经创建完毕
	Person newman(man); //调用拷贝构造函数
	Person newman2 = man; //拷贝构造
    cout << newman.mAge << "   " << newman2.mAge << endl;

	//Person newman3;
	//newman3 = man; //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数参数传值
//相当于Person p1 = p;
void doWork(Person p1) {}
void test02() {
	Person p; //无参构造函数
	doWork(p);
}

//3. 以值方式返回局部对象  -- Person doWork2() --- 注意是这种形式
Person doWork2(){
	Person p1;
    cout << p1.mAge << endl ; 
	cout << (int *)&p1 << endl; 
	return p1;
}

void test03(){
	Person p = doWork2();
	cout << (int *)&p << endl;
    cout << p.mAge << endl ; 

}



int main(){

    test01();
    test02();
    test03();

	system("pause");

	return 0;

}