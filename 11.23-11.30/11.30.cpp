#include<iostream>
using namespace std;


//用来终止递归并打印最后一个元素的函数
//此函数必须在可变参数版本的print定义之前
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}
//包中除了最后一个元素之外，其他元素都会调用这个版本的print
template<typename T, typename... A>
ostream& print(ostream& os, const T& t, const A&... rest)
{
	os << t << ",";              //打印第一个实参
	return print(os, rest...);   //递归调用，打印其他实参
}



void test01(void)
{
	print(cout, "i", "s", 42, 1, 2, 3, 4, 5, 6, 7, 8, 9, '\n');
	


}

template<typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}
void test00(void)
{
	int (*pf1)(const int&, const int&) = compare;

	int (*pf2)(const string&, const string&) = compare;


	


}

int main()
{
	//test00();
	test01();
	system("pause");
	return 0;
}