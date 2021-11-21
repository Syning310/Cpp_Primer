#include<iostream>
using namespace std;

#include<algorithm>
#include<vector>
#include<string>


void test(void)
{
	vector<string> word = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turle"};

	sort(word.begin(), word.end());

	auto end_unique = unique(word.begin(), word.end());  //unique的作用是独一无二，把重复的元素放到后面，并返回一个不重复值范围的末尾迭代器

	word.erase(end_unique, word.end());  //删除两个迭代器之间的元素

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