

/* #### 5.2.2 读文件

二进制方式读文件主要利用流对象调用成员函数read

函数原型：`istream& read(char *buffer,int len);`

参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数 */


#include <fstream>

#include <iostream>  // cout
using namespace std;

class Person
{
public:
	char m_Name[64];
	int m_Age;
};

void test01()
{
    // 读取文件
	ifstream ifs("person.txt", ios::in | ios::binary);

	if (!ifs.is_open())
	{
		cout << "file open failed !" << endl;
	}

	Person p;

    // 函数原型：`istream& read(char *buffer,int len);`
    // 参数解释：字符指针buffer指向内存中一段存储空间。len是读写的字节数
	ifs.read((char *)&p, sizeof(p));

	cout << "Name: " << p.m_Name << "   " << "Age: " << p.m_Age << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}
