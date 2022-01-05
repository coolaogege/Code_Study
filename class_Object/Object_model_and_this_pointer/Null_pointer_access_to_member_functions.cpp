/* #### 4.3.3 空指针访问成员函数


C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针


如果用到this指针，需要加以判断保证代码的健壮性 */


#include <iostream>

using namespace std;


//空指针访问成员函数
class Person {
public:

	void ShowClassName() {
		cout << "I am Person class" << endl;
	}

	void ShowPerson() {
		if (this == NULL) {
			return;
		}
		cout << mAge << endl; // 定义空指针 p --> 空指针不含属性  --> 访问错误！   因此前面用 this 判断
	}

public:
	int mAge;
};

void test01()
{
	Person * p = NULL;  // 定义一个空指针
	p->ShowClassName(); //空指针，可以调用成员函数
	p->ShowPerson();  //但是如果成员函数中用到了this指针，就不可以了
}

int main() {

	test01();

	system("pause");

	return 0;
}