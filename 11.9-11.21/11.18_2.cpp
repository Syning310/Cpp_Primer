#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include<numeric>

void test00(void)
{
	//istream_iterator

	istream_iterator<int> enter_int(cin);  //��cin��ȡint
	istream_iterator<int> eof;       //β�������


	vector<int> vec(enter_int, eof);    //������캯����cin�ж�ȡ���ݣ�ֱ�������ļ�β��������һ������int������Ϊֹ
										//�����ж�ȡ�����ݱ���������vec

	//vector<int> vec;
	//while (enter_int != eof)
	//	vec.push_back(*enter_int++);

	for (auto &s : vec)
		cout << s << "  ";
	cout << endl;
}

void test01(void)
{
	istream_iterator<int> in(cin);  //��cin��ȡint
	istream_iterator<int> eof;      //β�������

	cout << accumulate(in, eof, 0) << endl;  //accumulate�������ӱ�׼�����ȡֵ�ĺͣ�������intֵ��ͣ����

}


void test02(void)
{
	vector<int> vec = {1, 5, 6, 0, 6, 0, 3, 3, 2, 5, 0};

	ostream_iterator<int> out_it(cout, " ");
	for (auto &s : vec)
		*out_it++ = s;    //д�� out_it = s;  Ҳ��һ��    
	//*out_it++  ֻ�Ǳ�����⣬���ӿɶ��ԣ���ʵ�����ã�ǰ��++������++������out_it���Բ���ִ���κβ���
    //���Ƿ��ر���
	cout << endl;

	//�˳���vec��ÿ��Ԫ��д��cout��ÿ��Ԫ�غ��һ���ո�ÿ����out_it��ֵʱ��д�����ͻᱻ�ύ

	copy(vec.begin(), vec.end(), out_it);
	cout << endl;


}


int main()
{
	//test00();
	//test01();
	test02();


	return 0;
}