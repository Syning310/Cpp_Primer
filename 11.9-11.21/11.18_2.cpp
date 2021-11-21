#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<numeric>

void test00(void)
{
	//istream_iterator

	istream_iterator<int> enter_int(cin);  //从cin读取int
	istream_iterator<int> eof;       //尾后迭代器


	vector<int> vec(enter_int, eof);    //这个构造函数从cin中读取数据，直至遇到文件尾或者遇到一个不是int的数据为止
										//从流中读取的数据被用来构造vec

	//vector<int> vec;
	//while (enter_int != eof)
	//	vec.push_back(*enter_int++);

	for (auto &s : vec)
		cout << s << "  ";
	cout << endl;
}

void test01(void)
{
	istream_iterator<int> in(cin);  //从cin读取int
	istream_iterator<int> eof;      //尾后迭代器

	cout << accumulate(in, eof, 0) << endl;  //accumulate会计算出从标准输入读取值的和，碰到非int值才停下来

}


void test02(void)
{
	vector<int> vec = {1, 5, 6, 0, 6, 0, 3, 3, 2, 5, 0};

	ostream_iterator<int> out_it(cout, " ");
	for (auto &s : vec)
		*out_it++ = s;    //写成 out_it = s;  也是一样    
	//*out_it++  只是便于理解，增加可读性；其实解引用，前置++，后置++，对于out_it而言不会执行任何操作
    //都是返回本身
	cout << endl;

	//此程序将vec中每个元素写道cout，每个元素后加一个空格，每次向out_it赋值时，写操作就会被提交

	copy(vec.begin(), vec.end(), out_it);
	cout << endl;


}


int main()
{
	//test00();
	//test01();
	test02();


	return 0;
}