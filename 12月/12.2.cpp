#include<iostream>
using namespace std;


namespace syning
{
	template<typename T>
	void sort_up(T& pr, int len)
	{
		for (int i = 0; i != len - 1; ++i)
		{
			for (int j = 0; j != len - i - 1; ++j)
			{
				if (!(pr[j] < pr[j + 1]))
				{
					auto tmp = pr[j];
					pr[j] = pr[j + 1];
					pr[j + 1] = tmp;
				}
			}
		}
	}
}
namespace s = syning;



void test00(void)
{
	using s::sort_up;

	int arr[10] = {5, 1, 2, 4, 8, 9, 0, 3, 6, 7};
	sort_up<>(arr, 10);

	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << "  " ;
	}
	cout << endl;


	

}


int main()
{
	test00();


	system("pause");
	return 0;
}