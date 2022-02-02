
// 4.4.2 类做友元

#include <iostream>

using namespace std;


class Building;
class goodGay
{
public:

	goodGay();
	void visit();

private:
	Building *building;
};


class Building
{
	//告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
	friend class goodGay;

public:
	Building();

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

// 类外写成员函数
Building::Building()
{
	this->m_SittingRoom = "m_SittingRoom";
	this->m_BedRoom = "m_BedRoom";
}

goodGay::goodGay()
{
    // 创建对象！
	building = new Building;
}

void goodGay::visit()
{
	cout << "good gay is visting SittingRoom: " << building->m_SittingRoom << endl;
	cout << "good gay is visting BedRoom: " << building->m_BedRoom << endl;
}

void test01()
{
	goodGay gg;
	gg.visit();

}

int main(){

	test01();

	system("pause");
	return 0;
}