//#include<iostream>
//using namespace std;
//
//
//class father
//{
//public:
//	father(string name = " ", int age = 0) : m_name(name), m_age(age) {}
//	virtual void call()
//	{
//		cout << "father的虚函数call调用！" << endl;
//	}
//	virtual ~father() = default;
//
//	string m_name;
//	int m_age;
//	static int count;
//};
//int  father::count = 10;
//
//class son final : public father
//{
//public:
//	son(string name = " ", int age = 0, int weight = 0) 
//		: father(name, age), m_weight(weight) 
//	{
//
//	}
//
//	void call()
//	{
//		cout << "son的虚函数call调用！" << endl;
//	}
//	int m_weight;
//};
//
//
//void test00(void)
//{
//	father *f = new son;
//	f->call();   //son
//	delete f;
//	son s;
//	father &rf = s;
//	rf.call();   //son
//
//
//	son s1("红尘", 28, 44);
//	cout << "姓名： " << s1.m_name << "  年龄：" << s1.m_age << "  体重：" << s1.m_weight << endl;
//
//	cout << "father::count : " << father::count << endl;
//	cout << "son::count : " << son::count << endl;
//	cout << "s1.count : " << s1.count << endl;
//
//}
//
//
//int main()
//{
//	test00();
//
//
//
//	system("pause");
//	return 0;
//}