#include<iostream>
using namespace std;


//������ֹ�ݹ鲢��ӡ���һ��Ԫ�صĺ���
//�˺��������ڿɱ�����汾��print����֮ǰ
template<typename T>
ostream& print(ostream& os, const T& t)
{
	return os << t;
}
//���г������һ��Ԫ��֮�⣬����Ԫ�ض����������汾��print
template<typename T, typename... A>
ostream& print(ostream& os, const T& t, const A&... rest)
{
	os << t << ",";              //��ӡ��һ��ʵ��
	return print(os, rest...);   //�ݹ���ã���ӡ����ʵ��
}



void test01(void)
{
	print(cout, "i", "s", 42, 1, 2, 3, 4, 5, 6, 7, 8, 9, '\n');
	


}

template<typename T>
int compare(const T &v1, const T &v2)
{
	if (v1 < v2)
		return -1;
	if (v2 < v1)
		return 1;
	return 0;
}
void test00(void)
{
	int (*pf1)(const int&, const int&) = compare;

	int (*pf2)(const string&, const string&) = compare;


	


}

int main()
{
	//test00();
	test01();
	system("pause");
	return 0;
}