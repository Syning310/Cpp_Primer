//#include<iostream>
//using namespace std;
//
//
//
//template<unsigned N, unsigned M>
//int compare(const char(&p1)[N], const char(&p2)[M])
//{
//	return strcmp(p1, p2);
//}
//
//template<typename T>
//int compare(const T& lhs, const T& rhs)
//{
//	if(lhs < rhs) return -1;
//	if(rhs < lhs) return 1;
//	return 0;
//}
//
//template<typename T1, typename T2>
//class person
//{
//public:
//	person(T1 name, T2 age) : m_name(name), m_age(age) { } 
//	int func();
//	void delp();
//
//	T1 m_name;
//	T2 m_age;
//};
//
//
//void test01(void)
//{
//	person<string, int> p1("宁", 2500);
//	cout << p1.m_name << "  " << p1.m_age << endl;
//	person<string, int> p2(p1);
//
//	int ret = compare<>(p1.m_age, p2.m_age);
//	cout << ret << endl;
//
//	//p1.delp();  //这个成员函数，因为连续delete同一块堆区内存两次
//	              //如果没有调用的话，则这个函数不会实例化，程序不会出现错误
//	              //说明了，类模板的成员函数，函数模板，只有在调用的时候，才会实例化
//
//}
//
//void test00(void)
//{
//    int ret = compare("h1", "mom");
//	cout << ret << endl;  // -1
//
//	ret = compare<>(10, 1);
//	cout << ret << endl;
//
//}
//
//int main()
//{
//	//test00();
//	test01();
//
//	system("pause");
//	return 0;
//}
//
//template<typename T1, typename T2>
//int func()
//{
//	return 1;
//}
//
//template<typename T1, typename T2>
//int person<T1, T2>::func()
//{
//	return 0;
//}
//
//template<typename T1, typename T2>
//void person<T1, T2>::delp()
//{
//	int *p = new int(10);
//	auto *q = p;
//	delete p;
//	delete q;
//
//}