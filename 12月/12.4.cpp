#include<iostream>
using namespace std;
 
void test00(void)
{
	int sum = 0;
	int n = 100;
	for (int i = 1; i <= n; ++i)
	{
		sum += i;
	}
	cout << sum << endl;

	//高斯算法
	int g_sum = 0;
	g_sum = (1 + n) * n / 2;
	cout << "高斯算法：" << g_sum << endl;

}

void test01(void)
{
	int x = 0;
	int sum = 0;
	int n = 100;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			++x;
			sum += x;
		}
	}
	cout << "sum = " << sum << endl;


}




int main()
{
	test00();
	test01();





	system("pause");
	return 0;
}