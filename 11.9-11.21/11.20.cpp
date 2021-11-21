#include<iostream>
using namespace std;
#include<unordered_map>


//测试unordered_map
void test00(void)
{
	unordered_map<string, size_t> word_count;  //无序容器

	string word;
	while (cin >> word)
	{
		++word_count[word];
	
	}
	for (const auto &w : word_count)
		cout << "单词： " << w.first << " 出现了 " << w.second << " 次" << endl;

}

void test01(void)
{
	unordered_map<size_t, string> mp;

	mp.insert(pair<size_t, string>(1, "宁"));
	mp.insert(pair<size_t, string>(2, "月"));
	mp.insert(pair<size_t, string>(3, "尘"));
	mp.insert(pair<size_t, string>(4, "希"));
	mp.insert(pair<size_t, string>(5, "心"));
	mp.insert(pair<size_t, string>(6, "青"));
	
	cout << "正在使用的桶的数目  " << mp.bucket_count() << endl;
	cout << "能容纳的最多桶的数量  " << mp.max_bucket_count() << endl;
	cout << "第1个桶中有多少元素  " << mp.bucket_size(1) << endl;    //对于不允许重复的容器只有0和1
	cout << "关键字为2的元素在哪个桶  " << mp.bucket(2) << endl;

	//哈希策略
	//mp.rehash(10);  //重组存储
	mp.reserve(200);
	cout << "正在使用的桶的数目  " << mp.bucket_count() << endl;
	cout << "能容纳的最多桶的数量  " << mp.max_bucket_count() << endl;
	cout << "第1个桶中有多少元素  " << mp.bucket_size(1) << endl;    //对于不允许重复的容器只有0和1
	cout << "关键字为2的元素在哪个桶  " << mp.bucket(2) << endl;


	for (const auto &m : mp)
		cout << "key = " << m.first << "  value = " << m.second << endl;


}


int main()
{
	//test00();
	test01();


	return 0;
}