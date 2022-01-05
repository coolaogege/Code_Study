/* #### 4.2.5 深拷贝与浅拷贝



深浅拷贝是面试经典问题，也是常见的一个坑



浅拷贝：简单的赋值拷贝操作



深拷贝：在堆区重新申请空间，进行拷贝操作 */



#include <iostream>

using namespace std;


class Person {
public:
	//无参（默认）构造函数
	Person() {
		cout << "No-argument constructor" << endl;
	}
	//有参构造函数
	Person(int age ,int height) {
		
		cout << "Parameterized constructor" << endl;

		m_age = age;
		m_height = new int(height); // new 创建空间 返回的是地址 需要指针进行接收
		
	}
	//拷贝构造函数  
	Person(const Person& p) {
		cout << "Copy constructor" << endl;
		//如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
		m_age = p.m_age;
		m_height = new int(*p.m_height);
		
	}

	//析构函数
	~Person() {
		cout << "Destructor" << endl;
        // 将堆区开辟的数据 做释放操作
		if (m_height != NULL)
		{
			delete m_height;
            m_height = NULL;
		}
	}
public:
	int m_age;
	int* m_height;
};

void test01()
{
	Person p1(18, 180);

	Person p2(p1);

	cout << "Age of p1: " << p1.m_age << " height: " << *p1.m_height << endl;

	cout << "Age of p2: " << p2.m_age << " height: " << *p2.m_height << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}


// 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
