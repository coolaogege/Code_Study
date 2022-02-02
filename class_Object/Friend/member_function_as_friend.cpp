
// 4.4.3 成员函数做友元

#include <iostream>

using namespace std;


class Building;
class goodGay
{
public:

	goodGay();
	void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
	void visit2(); 

private:
	Building *building;
};


class Building
{
	//告诉编译器  goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容
	friend void goodGay::visit();

public:
	Building();

public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;//卧室
};

Building::Building()
{
	this->m_SittingRoom = "m_SittingRoom";
	this->m_BedRoom = "m_BedRoom";
}

goodGay::goodGay()
{
	building = new Building;
}

void goodGay::visit()
{
	cout << "good gay is visting SittingRoom: " << building->m_SittingRoom << endl;
	cout << "good gay is visting BedRoom: " << building->m_BedRoom << endl;
}

void goodGay::visit2()
{
	cout << "good gay is visting SittingRoom: " << building->m_SittingRoom << endl;
    // 这句话会报错！  原因是 指定成员函数作为友类   指定的成员函数 可以访问 ， 其他的不可以！
	// cout << "good gay is visting BedRoom: " << building->m_BedRoom << endl;
}

void test01()
{
	goodGay  gg;
	gg.visit2();

}

int main(){
    
	test01();

	system("pause");
	return 0;
}