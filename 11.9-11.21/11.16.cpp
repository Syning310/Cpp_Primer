#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>

//��Ԫν�ʣ���lambda���ʽ
//lambda���ʽ [ ] �����б�ʹ�ñ��ʽ���ڵĺ����ж���ľֲ�������ͨ��Ϊ��

class Person
{
public:
	Person(string name, int age);
	string m_name;
	int m_age;
};
void printV(const vector<Person> &vec);
bool isLess(const Person& val1, const Person& val2);
void test01(void)
{
	Person p1 = { "��", 2500 };
	Person p2 = { "��", 2200 };
	Person p3 = { "��", 240000 };
	Person p4 = { "��", 20 };
	Person p5 = { "�o", 2000 };

	vector<Person> vec = { p1, p2, p3, p4, p5 };

	printV(vec);

	sort(vec.begin(), vec.end(), isLess);

	cout << "-----------------------------------" << endl;
	printV(vec);

}
//bool isShort(const string& s1, const string& s2)
//{
//	return s1.size() < s2.size();
//}
void test02(void)
{
	vector<string> word = { "the boy", "quick", "red bag", "white fox", "jumps", "game over", "the", "slow", "red", "turle" };
	
	//���������򣬳�����ͬ�ĵ���ά���ֵ���
	stable_sort(word.begin(), word.end(), 
		[ ](const string &s1, const string &s2)
		  { return s1.size() < s2.size(); } );  

	auto sz = 5;

	auto wc = find_if(word.begin(), word.end(), 
		[ sz ](const string &val)
			{ return val.size() >= sz; } );


    for_each(wc, word.end(), 
		[ ](const string &s)
		{ cout << s << endl; } );

}
int main()
{
	//test01();
	test02();
	return 0;
}


Person::Person(string name, int age)
{
	this->m_name = name;
	this->m_age = age;
}

void printV(const vector<Person>& vec)
{
	for (vector<Person>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		cout << "������ " << it->m_name << "   ���䣺 " << it->m_age << endl;
	}
}

bool isLess(const Person& val1, const Person& val2)
{
	return val1.m_age < val2.m_age;
}

