
/* #### 5.1.2读文件

读文件与写文件步骤相似，但是读取方式相对于比较多


读文件步骤如下：

1. 包含头文件   

     \#include <fstream\>

2. 创建流对象  

   ifstream ifs;

3. 打开文件并判断文件是否打开成功

   ifs.open("文件路径",打开方式);

4. 读数据

   四种方式读取  -- 尽量选择前四种！

5. 关闭文件

   ifs.close(); */



/* 总结：

- 读文件可以利用 ifstream  ，或者fstream类
- 利用is_open函数可以判断文件是否打开成功
- close 关闭文件 */



#include <fstream>

#include <iostream>  // cout
using namespace std; 


void test01()
{
	ifstream ifs;  // 创建流对象 
	ifs.open("test.txt", ios::in);

    // 判断是否 读取文件成功
	if (!ifs.is_open())
	{
		cout << "file open failed !" << endl;
        // 如果读取失败 直接return 退出此函数 
		return;
	}

	//第一种方式
	// char buf[1024] = { 0 };
	// while (ifs >> buf)  // 读到头了，返回假的标志！
	// {
	// 	cout << buf << endl;
	// }

	//第二种
	// char buf[1024] = { 0 };
	// while (ifs.getline(buf,sizeof(buf)))  // getline 一行行获取
	// {
	// 	cout << buf << endl;
	// }

	//第三种
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}

    //第四种
	// char c;
	// while ((c = ifs.get()) != EOF)  // 一个个字符读，直到读到文件尾
	// {
	// 	cout << c;
	// }

	ifs.close();


}

int main() {

	test01();

	system("pause");

	return 0;
}