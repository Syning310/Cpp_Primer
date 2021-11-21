#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<list>
#include<string>

//练习10.34  使用反向迭代器打印逆序vector
void test00(void)
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	//从尾元素到首元素的反向迭代器
	for (vector<int>::reverse_iterator rit = vec.rbegin();
		rit != vec.rend();
		++rit)
	{
		cout << *rit << "  ";
	}
	cout << endl;


	sort(vec.rbegin(), vec.rend());  //向sort传递一对反向迭代器，将vector整理为降序

	for (auto &v : vec)
		cout << v << "  ";
	cout << endl;

}

//练习10.35  使用普通迭代器逆序打印vector
void test01(void)
{
	vector<int> vec = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	vector<int>::iterator it;
	for (it = vec.end() - 1; it != vec.begin(); --it)
	{
		cout << *it << "  ";
	}
	cout << *it ;
	cout << endl;

}


//练习10.36：使用find在一个int的list中查找最后一个值为0的元素
void test02(void)
{
	list<int> lst = {1, 8, 5, 0, 1, 1, 7, 0, 1, 5, 0, 6, 6, 7 };

	auto index = find(lst.rbegin(), lst.rend(), 0);  //最后一个值为0的元素，返回的是一个反向迭代器

	//打印0之后的值
	list<int> lst2(index.base(), lst.end());    //index.base();  将反向迭代器转换成普通迭代器，并 ++ 这个普通迭代器
	for (auto &val : lst2)
		cout << val << "  ";
	cout << endl;
	
}



void print_str(void)
{
	string line = "FIRST,MIDDLE,LAST";

	//打印line中的第一个单词
	auto comma = find(line.cbegin(), line.cend(), ',');  //find返回第一个逗号的迭代器，如果没有逗号，返回cend()
	cout << string(line.cbegin(), comma) << endl;


	//打印最后一个单词
	auto rcomma = find(line.crbegin(), line.crend(), ',');  //如果有逗号，返回反向第一个逗号，没有逗号返回crend()

	//cout << string(line.crbegin(), rcomma) << endl;  //TSAL 错误！这将逆序输出单词的字符
	//我们使用的是反向迭代器，会反向处理string；
	//如果想要正常顺序打印从rcomma开始到line末尾的字符，就不能使用反向迭代器
	//应该把rcomma转换成一个普通迭代器，reverse_iterator的成员函数base可以完成转换，返回其对应的普通迭代器

	cout << string(rcomma.base(), line.cend()) << endl;




}

int main()
{
	print_str();
	//test00();
	//test01();
	//test02();


	return 0;
}