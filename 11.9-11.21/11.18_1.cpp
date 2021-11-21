#include<iostream>
using namespace std;
#include<list>
#include<vector>
#include<algorithm>


//���ֵ�����  ��  back_inserter      front_inserter       inserter


void test(void)
{
	vector<int> vec = { 6, 0, 6, 0, 3, 3, 2, 5 };

	auto it1 = inserter(vec, vec.begin());
	it1 = 1;  //�൱��ִ��������Ĳ���
	//vec.insert(1, it1);    ++it1;  Ŀ����ָ��ԭ����Ԫ�أ�Ҳ����6
	for (auto &s : vec)
		cout << s << " ";
	cout << endl;

	it1 = 5;      //ǰ��++itʹitָ��ԭ����Ԫ�أ���������������5����Ԫ��6��ǰ��
	for (auto& s : vec)
		cout << s << " ";
	cout << endl;

	
	auto it2 = back_inserter(vec);
	it2 = 0;   //vec.push_back(0);  
	for (auto &s : vec)
		cout << s << " ";
	cout << endl;
	
	//vector������push_frone���������Բ���ʹ��front_inserter
}




void test00(void)
{
	list<int> lst = {1, 2, 3, 4};
	list<int> lst2, lst3, lst4;

	cout << "lst  :   " ;
	for (auto& s : lst)
		cout << s << " ";
	cout << endl;

	copy(lst.cbegin(), lst.cend(), front_inserter(lst2) );  //front_inserter(lst2)  �õ�lst2�Ĳ���������������������  lst2.push_front
	//����ԭ���������һ��Ԫ�أ�����Ŀ�������ĵ�һ����ԭ�����ĵ�һ�����Ŀ�����������һ��
	
	cout << "lst2 :   " ;
	for (auto &s : lst2)
		cout << s << " ";
	cout << endl;

	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin() ) );  //inserter(lst3, lst3.begin() ) �õ�lst3�Ĳ����������ִ�е���  lst.insert

	cout << "lst3 :   ";
	for (auto &s : lst3)
		cout << s << " ";
	cout << endl;

	copy(lst.cbegin(), lst.cend(), back_inserter(lst4));  //back_inserter(lst4) �õ�lst4�Ĳ����������ִ�е���  lst4.push_back
	                                                      //��Ϊ��β�巨��������ԭ����һ��

	cout << "lst4 :   ";
	for (auto &s : lst4)
		cout << s << " " ;
	cout << endl;

}



//��ϰ 10.27
void test01(void)
{
	vector<int> vec = {1, 5, 6, 6, 6, 0, 3, 3, 2, 5, 5, 5, 5, 6, 6, 6, 1, 1, 1, 1};
	list<int> lst_des;

	unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst_des) );  //unique_copy�������ǣ������ظ���Ч��Ԫ��ֻ���Ƶ�һ��
	                                                                 //�������ظ������Ǽ���ظ�

	cout << "vec = " ;
	for (auto it = vec.cbegin(); it != vec.cend(); ++it)
		cout << *it << "  ";
	cout << endl;

	cout << "des = " ;
	for (auto it = lst_des.cbegin(); it != lst_des.cend(); ++it)
		cout << *it << "  ";
	cout << endl;

}



//��ϰ10.28
void test02(void)
{
	vector<int> num_v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v1, v2;
	list<int> lst3;

	copy(num_v.cbegin(), num_v.cend(), inserter(v1, v1.begin()) );  
	cout << "v1 = ";
	for (auto &val : v1)
		cout << val << "  ";  //1 2 3 4 5 6 7 8 9  ��ԭ����һ��
	cout << endl;


	copy(num_v.cbegin(), num_v.cend(), back_inserter(v2) );
	cout << "v2 = ";
	for (auto &val : v2)
		cout << val << "  ";  //1 2 3 4 5 6 7 8 9   β�巨��ԭ����һ��
	cout << endl;


	//vector��֧��ͷ��
	copy(num_v.cbegin(), num_v.cend(), front_inserter(lst3) );  
	cout << "v3 = ";
	for (auto &val : lst3)
		cout << val << "  ";  //9 8 7 6 5 4 3 2 1   ͷ�巨��ÿ�β���Ԫ�ض��ǲ���������front��λ�ã�����Ԫ������ƶ�
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