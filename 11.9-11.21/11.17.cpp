#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>
using namespace placeholders;

//函数适配器


bool check_size(const string &s, string::size_type sz)  //第一步，要有二元谓词
{
	return s.size() >= sz;
}
bool isShort(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
ostream& printStr(ostream &os, const string &s, char c)
{
	os << s << c << endl;
	return os;
}

void test00(void)
{
	
	string s0 = "hello";
	auto check_perpor = bind(check_size, _1, 6);
	//bind是适配器，第一个为函数地址，第二个是占位符,_1表示一个参数，_2表示两个参数，后面的是参数
	//check_perpor是一个可调用对象，接收一个string类型的参数；并用此string和值6来调用check_size
	                                              
	bool b1 = check_perpor(s0);  //check_perpor会调用check_size(s0, 5);
	cout << b1 << endl;
}

void test01(void)
{
	vector<string> word = { "the boy", "quick", "red bag", "white fox", "jumps", "game over", "the", "slow", "red", "turle" };

	sort(word.begin(), word.end(),   //排序
		[ ](const string &s1, const string &s2)
		{ return s1.size() < s2.size(); } );

	auto it = find_if(word.begin(), word.end(), bind(check_size, _1, 6));  //使用函数适配器：函数地址，参数个数，参数

	for_each(it, word.end(), 
		[ ](string &s)
		{ cout << s << endl; } );

}

void test02(void)
{
	vector<string> word = { "the boy", "quick", "red bag", "white fox", "jumps", "game over", "the", "slow", "red", "turle" };
	sort(word.begin(), word.end(), bind(&isShort, _2, _1));  //bind重排参数顺序


	for_each(word.begin(), word.end(), bind(&printStr, ref(cout), _1, ' '));
}

int main()
{
	test00();
	test01();
	test02();

	return 0;
}


int myDivide(int x, int y)
{
	return x / y;
}
int main()
{
	auto func = bind(&myDivide, 10, 5);
	//bind可以绑定一个可调用的对象和调用这个对象所需的参数
	cout << func() << endl;  //2

	//如果只确定了一个想传入的参数，另一个想在调用的时候传入，就需要用到占位符；
	//占位符的作用就是可以减少调用参数的数量，也可以将调用参数的位置互换
	auto fn_h = bind(&myDivide, _1, 2);
	cout << fn_h(10) << endl;


	auto fn_wc = bind(&myDivide, _2, _1);
	cout << fn_wc(60, 6) << endl;    // 6 / 60 = 0.1

	return 0;
}


void g(int a, int b, int c, int d, int e)
{
	cout << "a = " << a << "  b = " << b << "  c = " << c << "  d = " << d << "  e = " << e << endl;
}         //a = 1    b = 2    c = 5    d = 4    e = 3
int main()
{
	auto f0 = bind(g, 1, 2, _2, 4, _1);
	f0(3, 5);

	return 0;
}
