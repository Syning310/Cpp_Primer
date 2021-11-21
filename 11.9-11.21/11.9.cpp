#include<iostream>
using namespace std;

#include<vector>


//有序容器vector的二分查找,未优化
int g_count = 0;
vector<int>::const_iterator my_search(const vector<int>& scr, int sought);
void test01(void)
{
	vector<int> v;
	for (int i = 0; i < 5000; ++i)
	{
		v.push_back(i + 1);
	}
	int sought = 1;
	auto i = my_search(v, sought);

	cout << g_count << endl;

}
int main()
{
	test01();

	return 0;
}

vector<int>::const_iterator my_search(const vector<int>& scr, int sought)
{
	auto beg = scr.begin();
	auto end = scr.end();
	auto mid = beg + (end - beg) / 2;

	while (*mid != sought && mid != end)
	{
		++g_count;
		if (sought < *mid)
		{
			end = mid - 1;
		}
		else if (sought > *mid)
		{
			beg = mid + 1;
		}
		mid = beg + (end - beg) / 2;
	}
	return mid;

}


#include<forward_list>

int main()
{
	forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	

	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if ((*curr % 2) != 0 || (*curr == 0))
		{
			curr = flst.erase_after(prev);
		}
		else
		{
			prev = curr;
			++curr;
		}
	}



	for (auto it = flst.begin(); it != flst.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	return 0;
}