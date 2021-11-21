#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<algorithm>


//三种迭代器  ：  back_inserter      front_inserter       inserter


void test(void)
{
	vector<int> vec = { 6, 0, 6, 0, 3, 3, 2, 5 };

	auto it1 = inserter(vec, vec.begin());
	it1 = 1;  //相当于执行了下面的操作
	//vec.insert(1, it1);    ++it1;  目的是指向原来的元素，也就是6
	for (auto &s : vec)
		cout << s << " ";
	cout << endl;

	it1 = 5;      //前面++it使it指向原来的元素，所以在这里插入的5是在元素6的前面
	for (auto& s : vec)
		cout << s << " ";
	cout << endl;

	
	auto it2 = back_inserter(vec);
	it2 = 0;   //vec.push_back(0);  
	for (auto &s : vec)
		cout << s << " ";
	cout << endl;
	
	//vector不允许push_frone操作，所以不能使用front_inserter
}




void test00(void)
{
	list<int> lst = {1, 2, 3, 4};
	list<int> lst2, lst3, lst4;

	cout << "lst  :   " ;
	for (auto& s : lst)
		cout << s << " ";
	cout << endl;

	copy(lst.cbegin(), lst.cend(), front_inserter(lst2) );  //front_inserter(lst2)  得到lst2的插入迭代器，接下来会调用  lst2.push_front
	//所以原容器的最后一个元素，会变成目标容器的第一个，原容器的第一个变成目标容器的最后一个
	
	cout << "lst2 :   " ;
	for (auto &s : lst2)
		cout << s << " ";
	cout << endl;

	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin() ) );  //inserter(lst3, lst3.begin() ) 得到lst3的插入迭代器，执行的是  lst.insert

	cout << "lst3 :   ";
	for (auto &s : lst3)
		cout << s << " ";
	cout << endl;

	copy(lst.cbegin(), lst.cend(), back_inserter(lst4));  //back_inserter(lst4) 得到lst4的插入迭代器，执行的是  lst4.push_back
	                                                      //因为是尾插法，所以与原容器一样

	cout << "lst4 :   ";
	for (auto &s : lst4)
		cout << s << " " ;
	cout << endl;

}



//练习 10.27
void test01(void)
{
	vector<int> vec = {1, 5, 6, 6, 6, 0, 3, 3, 2, 5, 5, 5, 5, 6, 6, 6, 1, 1, 1, 1};
	list<int> lst_des;

	unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst_des) );  //unique_copy的作用是，连续重复等效的元素只复制第一个
	                                                                 //是连续重复，不是间隔重复

	cout << "vec = " ;
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		cout << *it << "  ";
	cout << endl;

	cout << "des = " ;
	for (auto it = lst_des.cbegin(); it != lst_des.cend(); ++it)
		cout << *it << "  ";
	cout << endl;

}



//练习10.28
void test02(void)
{
	vector<int> num_v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v1, v2;
	list<int> lst3;

	copy(num_v.cbegin(), num_v.cend(), inserter(v1, v1.begin()) );  
	cout << "v1 = ";
	for (auto &val : v1)
		cout << val << "  ";  //1 2 3 4 5 6 7 8 9  与原容器一样
	cout << endl;


	copy(num_v.cbegin(), num_v.cend(), back_inserter(v2) );
	cout << "v2 = ";
	for (auto &val : v2)
		cout << val << "  ";  //1 2 3 4 5 6 7 8 9   尾插法与原容器一样
	cout << endl;


	//vector不支持头插
	copy(num_v.cbegin(), num_v.cend(), front_inserter(lst3) );  
	cout << "v3 = ";
	for (auto &val : lst3)
		cout << val << "  ";  //9 8 7 6 5 4 3 2 1   头插法，每次插入元素都是插向容器的front的位置，其他元素向后移动
	cout << endl;

}


int main()
{
	test();
	//test00();
	//test01();
	//test02();

	return 0;
}