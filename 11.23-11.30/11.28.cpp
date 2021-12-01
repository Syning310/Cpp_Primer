//#include<iostream>
//using namespace std;
//
//
//class Base
//{
//public:
//	virtual int func()  //Base的虚函数
//	{
//		cout << "Base的虚函数func调用！" << endl;
//		return 0;
//	}
//};
//class D1 : public Base
//{
//public:
//	int func(int)  //形参列表不同，这是隐藏基类的func没有重写虚函数
//	{
//		cout << "D1的func有参调用！" << endl;
//		return 0;
//	}
//	virtual void f2()  //D1的虚函数
//	{
//		cout << "D1的虚函数f2调用！" << endl;
//	}
//};
//class D2 : public D1
//{
//public:
//	int func(int)  //隐藏D1的func函数
//	{
//		cout << "D2的func有参调用！" << endl;
//		return 0;
//	}
//	int func()    //重写了从D1继承来的func虚函数，D1的是从Base继承来的
//	{
//		cout << "D2的虚函数func调用！" << endl;
//		return 0;
//	}
//	void f2()    //重写了D1的虚函数
//	{
//		cout << "D2的虚函数f2调用！" << endl;
//	}
//
//};
//
//void test00(void)
//{
//	Base bobj; 
//	D1 d1obj;
//	D2 d2obj;
//
//	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
//
//	bp1->func();   //虚调用：Base的虚函数func调用
//	bp2->func();   //虚调用：Base的虚函数func调用
//	bp3->func();   //虚调用：D2的虚函数func调用
//
//	D1 *d1p = &d1obj;
//	D2 *d2p = &d2obj;
//
//	//bp2->f2();  //错误指针类型是Base，Base没有f2
//	d1p->f2();    //虚调用：D1的虚函数f2调用
//	d2p->f2();    //虚调用：D2的虚函数f2调用
//
//}
//
//class base
//{
//public:
//	base(int age, string name) : m_age(age), m_name(name){ }
//	virtual ~base()
//	{
//		cout << "base的析构函数调用" << endl;
//	}
//
//	int m_age;
//	string m_name;
//private:
//	string m_cat;
//};
//class Derived : public base
//{
//public:
//	Derived(int age, string name) : base(age, name){}
//	~Derived() 
//	{
//		cout << "Derived的析构函数调用" << endl;
//	}
//	
//	using base::base;
//};
//
//void test01(void)
//{
//	base *bp = new Derived(20, "烟");
//	delete bp;  //基类必须写虚析构函数，如此才能先释放派生类的动态空间
//
//
//	cout << sizeof(base) << endl;
//	cout << sizeof(Derived) << endl;
//
//}
//
//int main()
//{
//	//test00();
//	test01();
//
//
//	system("pause");
//	return 0;
//}