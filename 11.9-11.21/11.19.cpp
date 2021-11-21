#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<set>
#include<vector>


void test00(void)
{
	map<string,	size_t> word_count;  //��map
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
	                        "the", "but", "and", "or", "an", "a"};

	string word;
	while (cin >> word)
	{
		if (exclude.find(word) == exclude.end())  //���word������set�����򷵻ؿ��õ���������������set��������end������
		{
			++word_count[word];  //��ȡ������word�ļ�����
		}

		if ( cin.get() == '\n' )
			break;
	}

	for (const auto &w : word_count)
		cout << w.first << "  ����  " << w.second << ( (w.second > 1) ? "  times" : "  time" ) << endl;

}

//��ϰ11.12
void test01(void)
{
	vector<pair<string, int> > vec;	
	string word;
	int num = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> word;
		cin >> num;
		vec.push_back(make_pair(word, num));
		word = " ";
		num = 0;
	}
   
	for (auto &v : vec)
		cout << "first = " << v.first << "  second = " << v.second << endl;

}



void test02(void)
{
	map<int, string> p;
	p.insert(make_pair(1, "��"));
	p.insert(make_pair(2, "��"));
	p.insert(make_pair(3, "��"));
	p.insert(make_pair(4, "ݼ"));
	p.insert(make_pair(5, "��"));

	map<int, string>::iterator it = p.begin();

	//it->first = 10;  //�ؼ��ʲ����޸�
	it->second = "����"; //�����޸ĵڶ�����

	auto ws = p.insert(make_pair(1, "��"));
	cout << "ws.first = " << (ws.first)->second << endl;  //���صĵ�һ��ֵ�ǵ�����ָ��mapԪ�أ�mapԪ������pair����Ӧ��ʹ�� -> �鿴
	cout << "ws.second = " << ws.second << endl;  //second��һ������ֵ��first��һ��������

	auto pa = p.begin();
	cout << "key = " << (*pa).first << "  value = " << (*pa).second << endl;  //��map�����������õõ�����pair����



}

void test03(void)
{
	multimap<int, string> mp;

	mp.insert(make_pair(1, "��"));
	mp.insert(make_pair(1, "��"));
	mp.insert(make_pair(6, "��"));
	mp.insert(make_pair(6, "��"));
	mp.insert(make_pair(6, "��"));
	mp.insert(make_pair(6, "�o"));
	mp.insert(make_pair(6, "��"));
	 
	auto it = mp.equal_range(6);  //equal_range����һ��������pair��Ҳ����˵��������ָ��mp�ĵ�����
	                              //һ��ָ���һ����keyֵƥ���ֵ���ڶ���ָ�����һ��ƥ��Ԫ�ص�֮���λ��
	for (; it.first != it.second; ++(it.first))
	{
		cout << (it.first)->second << endl;
	}

}
int main()
{
	//test00();
	//test01();
	//test02();
	test03();

	return 0;
}