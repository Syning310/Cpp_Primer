#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<list>
#include<string>

//��ϰ10.34  ʹ�÷����������ӡ����vector
void test00(void)
{
	vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	//��βԪ�ص���Ԫ�صķ��������
	for (vector<int>::reverse_iterator rit = vec.rbegin();
		rit != vec.rend();
		++rit)
	{
		cout << *rit << "  ";
	}
	cout << endl;


	sort(vec.rbegin(), vec.rend());  //��sort����һ�Է������������vector����Ϊ����

	for (auto &v : vec)
		cout << v << "  ";
	cout << endl;

}

//��ϰ10.35  ʹ����ͨ�����������ӡvector
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


//��ϰ10.36��ʹ��find��һ��int��list�в������һ��ֵΪ0��Ԫ��
void test02(void)
{
	list<int> lst = {1, 8, 5, 0, 1, 1, 7, 0, 1, 5, 0, 6, 6, 7 };

	auto index = find(lst.rbegin(), lst.rend(), 0);  //���һ��ֵΪ0��Ԫ�أ����ص���һ�����������

	//��ӡ0֮���ֵ
	list<int> lst2(index.base(), lst.end());    //index.base();  �����������ת������ͨ���������� ++ �����ͨ������
	for (auto &val : lst2)
		cout << val << "  ";
	cout << endl;
	
}



void print_str(void)
{
	string line = "FIRST,MIDDLE,LAST";

	//��ӡline�еĵ�һ������
	auto comma = find(line.cbegin(), line.cend(), ',');  //find���ص�һ�����ŵĵ����������û�ж��ţ�����cend()
	cout << string(line.cbegin(), comma) << endl;


	//��ӡ���һ������
	auto rcomma = find(line.crbegin(), line.crend(), ',');  //����ж��ţ����ط����һ�����ţ�û�ж��ŷ���crend()

	//cout << string(line.crbegin(), rcomma) << endl;  //TSAL �����⽫����������ʵ��ַ�
	//����ʹ�õ��Ƿ�����������ᷴ����string��
	//�����Ҫ����˳���ӡ��rcomma��ʼ��lineĩβ���ַ����Ͳ���ʹ�÷��������
	//Ӧ�ð�rcommaת����һ����ͨ��������reverse_iterator�ĳ�Ա����base�������ת�����������Ӧ����ͨ������

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