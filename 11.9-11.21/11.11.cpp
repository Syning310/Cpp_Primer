#include<iostream>
using namespace std;

#include<algorithm>
#include<vector>
#include<string>


void test(void)
{
	vector<string> word = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turle"};

	sort(word.begin(), word.end());

	auto end_unique = unique(word.begin(), word.end());  //unique�������Ƕ�һ�޶������ظ���Ԫ�طŵ����棬������һ�����ظ�ֵ��Χ��ĩβ������

	word.erase(end_unique, word.end());  //ɾ������������֮���Ԫ��

	for (vector<string>::iterator it = word.begin(); it != word.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

}

int main()
{
	test();


	return 0;
}