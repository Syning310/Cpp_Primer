#include<iostream>
using namespace std;
#include<vector>
#include<functional>
#include<algorithm>
using namespace placeholders;

//����������


bool check_size(const string &s, string::size_type sz)  //��һ����Ҫ�ж�Ԫν��
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
	//bind������������һ��Ϊ������ַ���ڶ�����ռλ��,_1��ʾһ��������_2��ʾ����������������ǲ���
	//check_perpor��һ���ɵ��ö��󣬽���һ��string���͵Ĳ��������ô�string��ֵ6������check_size
	                                              
	bool b1 = check_perpor(s0);  //check_perpor�����check_size(s0, 5);
	cout << b1 << endl;
}

void test01(void)
{
	vector<string> word = { "the boy", "quick", "red bag", "white fox", "jumps", "game over", "the", "slow", "red", "turle" };

	sort(word.begin(), word.end(),   //����
		[ ](const string &s1, const string &s2)
		{ return s1.size() < s2.size(); } );

	auto it = find_if(word.begin(), word.end(), bind(check_size, _1, 6));  //ʹ�ú�����������������ַ����������������

	for_each(it, word.end(), 
		[ ](string &s)
		{ cout << s << endl; } );

}

void test02(void)
{
	vector<string> word = { "the boy", "quick", "red bag", "white fox", "jumps", "game over", "the", "slow", "red", "turle" };
	sort(word.begin(), word.end(), bind(&isShort, _2, _1));  //bind���Ų���˳��


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
	//bind���԰�һ���ɵ��õĶ���͵��������������Ĳ���
	cout << func() << endl;  //2

	//���ֻȷ����һ���봫��Ĳ�������һ�����ڵ��õ�ʱ���룬����Ҫ�õ�ռλ����
	//ռλ�������þ��ǿ��Լ��ٵ��ò�����������Ҳ���Խ����ò�����λ�û���
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
