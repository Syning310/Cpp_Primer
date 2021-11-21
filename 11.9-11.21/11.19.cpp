#include<iostream>
using namespace std;
#include<string>
#include<map>
#include<set>
#include<vector>


void test00(void)
{
	map<string,	size_t> word_count;  //空map
	set<string> exclude = {"The", "But", "And", "Or", "An", "A",
	                        "the", "but", "and", "or", "an", "a"};

	string word;
	while (cin >> word)
	{
		if (exclude.find(word) == exclude.end())  //如果word存在于set容器则返回可用迭代器，不存在于set容器返回end迭代器
		{
			++word_count[word];  //获取并递增word的计数器
		}

		if ( cin.get() == '\n' )
			break;
	}

	for (const auto &w : word_count)
		cout << w.first << "  出现  " << w.second << ( (w.second > 1) ? "  times" : "  time" ) << endl;

}

//练习11.12
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
	p.insert(make_pair(1, "宁"));
	p.insert(make_pair(2, "月"));
	p.insert(make_pair(3, "尘"));
	p.insert(make_pair(4, "菁"));
	p.insert(make_pair(5, "乐"));

	map<int, string>::iterator it = p.begin();

	//it->first = 10;  //关键词不可修改
	it->second = "亦宁"; //可以修改第二个词

	auto ws = p.insert(make_pair(1, "宁"));
	cout << "ws.first = " << (ws.first)->second << endl;  //返回的第一个值是迭代器指向map元素，map元素又是pair所以应该使用 -> 查看
	cout << "ws.second = " << ws.second << endl;  //second是一个布尔值，first是一个迭代器

	auto pa = p.begin();
	cout << "key = " << (*pa).first << "  value = " << (*pa).second << endl;  //对map迭代器解引用得到的是pair类型



}

void test03(void)
{
	multimap<int, string> mp;

	mp.insert(make_pair(1, "亦"));
	mp.insert(make_pair(1, "宁"));
	mp.insert(make_pair(6, "宁"));
	mp.insert(make_pair(6, "月"));
	mp.insert(make_pair(6, "尘"));
	mp.insert(make_pair(6, "乷"));
	mp.insert(make_pair(6, "瑶"));
	 
	auto it = mp.equal_range(6);  //equal_range返回一个迭代器pair，也就是说返回两个指向mp的迭代器
	                              //一个指向第一个与key值匹配的值，第二个指向最后一个匹配元素的之后的位置
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