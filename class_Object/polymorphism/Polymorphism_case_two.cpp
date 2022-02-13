

/* #### 4.7.4 多态案例二-制作饮品

**案例描述：**

制作饮品的大致流程为：煮水 -  冲泡 - 倒入杯中 - 加入辅料



利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶 */


#include <iostream>

using namespace std;


//抽象制作饮品
class AbstractDrinking {
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;

	//规定流程
	void MakeDrink() {
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee : public AbstractDrinking {
public:
	//烧水
	virtual void Boil() {
		cout << "Coffee--1!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "Coffee--2!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "Coffee--3!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "Coffee--4!" << endl;
	}
};

//制作茶水
class Tea : public AbstractDrinking {
public:
	//烧水
	virtual void Boil() {
		cout << "Tea--1!" << endl;
	}
	//冲泡
	virtual void Brew() {
		cout << "Tea--2!" << endl;
	}
	//倒入杯中
	virtual void PourInCup() {
		cout << "Tea--3!" << endl;
	}
	//加入辅料
	virtual void PutSomething() {
		cout << "Tea--4!" << endl;
	}
};

//业务函数
// 形参的声明！
void DoWork(AbstractDrinking* drink) {
	drink->MakeDrink();
	delete drink;
}

void test01() {
	DoWork(new Coffee);
	cout << "--------------" << endl;
	DoWork(new Tea);
}


int main() {

	test01();

	system("pause");

	return 0;
}