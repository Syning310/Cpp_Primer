#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void test01(void)
{
	vector<int> v = { -1, 8, -5, -2, -4, 3, -6, 7, 9 };
	for (auto& vec : v)
		cout << vec << "  ";
	cout << endl;

	//¾ø¶ÔÖµ
	transform(v.begin(), v.end(), v.begin(),
		[](int i) -> int
		{
			if (i < 0)
				return -i;
			else
				return i;
		});

	for (auto& vec : v)
		cout << vec << "  ";
	cout << endl;

}

int main()
{

	test01();


	return 0;
}