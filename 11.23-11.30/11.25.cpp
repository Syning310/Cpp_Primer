//#include<iostream>
//using namespace std;
//#include<functional>
//#include<map>
//
//int add(int lhs, int rhs)
//{
//	return lhs + rhs;
//}
//struct mul
//{
//public:
//	int operator()(int lhs, int rhs)
//	{
//		return lhs * rhs;
//	}
//};
//
////练习14.44
//void test01(void)
//{
//	auto sub = [](int lhs, int rhs){ return lhs - rhs;};
//
//	map<string, function<int(int, int)> > calc = {
//		make_pair("+", add),
//		make_pair("-", sub),
//		make_pair("*", mul()),
//		make_pair("/", [](int lhs, int rhs){ return lhs / rhs;})
//	};
//
//	string act;
//	cout << "请选择要执行的操作 + - * / ： " ;
//	cin >> act;
//	int i = 0, j = 0;
//	if (act != "+" && act != "-" && act != "/" && act != "*")
//	{
//		cout << "输入的操作有误" << endl;
//		return ;
//	}
//
//	cout << "请输入两个数字： " ;
//	cin >> i;
//	cin >> j;
//
//	cout << calc[act](i, j) << endl;
//
//
//}
//
//
//
//class Person
//{
//public:
//	Person(string name = " ", int age = 0) : m_name(name), m_age(age)
//	{
//
//	}
//
//	string m_name;
//	int m_age;
//};
//
//class PrintPerson
//{
//public:
//	PrintPerson(ostream& o = cout, char c = ' ') : os(o), sep(c)
//	{
//
//	}
//	void operator()(const Person &p)
//	{
//		os << "姓名： " << p.m_name << sep << "年龄： " << p.m_age << sep;
//	}
//
//private:
//	ostream &os;
//	char sep;
//};
//
//void test00(void)
//{
//	Person p1("宁", 2000);
//	PrintPerson pson;
//	pson(p1);
//	PrintPerson perr(cerr, ' ');
//	perr(p1);
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