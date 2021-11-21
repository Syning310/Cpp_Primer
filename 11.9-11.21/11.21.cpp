#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"11.21_StrBlob.h"


void test00(void)
{
	//右值是返回  指向一个值为42的int类型的shared_ptr
	shared_ptr<int> pi1 = make_shared<int>(42);

	//ps2 指向一个值为10个为 p 字符的string
	shared_ptr<string> ps2 = make_shared<string>(10, 'p');

	//指向一个值初始化的int，值为0
	shared_ptr<int> pi3 = make_shared<int>();

}

void test01(void)
{
	vector<string> b1;
	{
		vector<string> b2 = {"a", "an", "the"};
		b1 = b2;
		b2[0] = "alway";
		for (auto &v : b2)
			cout << v << endl;
	}
	for (auto &v : b1)
		cout << v << endl;
}





void test02(void)
{
	StrBlob s1 = {"any", "break", "count", "double"};

	cout << "s1中有多少个元素？" << s1.size() << endl;
	cout << "s1.empty() = " << s1.empty() << endl;

	s1.push_back("int");
	cout << "尾插的元素为: " << s1.back() << endl;

	s1.pop_back();
	cout << "尾删之后back为：" << s1.back() << endl;
	cout << "头元素为:" << s1.front() << endl;

	cout << "----------------------------------" << endl;

	StrBlob s2;
	cout << "s2.empty() = " << s2.empty() << endl;
	cout << "s2中有多少个元素？" << s2.size() << endl;

	
}


int main()
{
	//test00();
	//test01();
	test02();



	return 0;
}