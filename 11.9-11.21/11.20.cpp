#include<iostream>
using namespace std;
#include<unordered_map>


//����unordered_map
void test00(void)
{
	unordered_map<string, size_t> word_count;  //��������

	string word;
	while (cin >> word)
	{
		++word_count[word];
	
	}
	for (const auto &w : word_count)
		cout << "���ʣ� " << w.first << " ������ " << w.second << " ��" << endl;

}

void test01(void)
{
	unordered_map<size_t, string> mp;

	mp.insert(pair<size_t, string>(1, "��"));
	mp.insert(pair<size_t, string>(2, "��"));
	mp.insert(pair<size_t, string>(3, "��"));
	mp.insert(pair<size_t, string>(4, "ϣ"));
	mp.insert(pair<size_t, string>(5, "��"));
	mp.insert(pair<size_t, string>(6, "��"));
	
	cout << "����ʹ�õ�Ͱ����Ŀ  " << mp.bucket_count() << endl;
	cout << "�����ɵ����Ͱ������  " << mp.max_bucket_count() << endl;
	cout << "��1��Ͱ���ж���Ԫ��  " << mp.bucket_size(1) << endl;    //���ڲ������ظ�������ֻ��0��1
	cout << "�ؼ���Ϊ2��Ԫ�����ĸ�Ͱ  " << mp.bucket(2) << endl;

	//��ϣ����
	//mp.rehash(10);  //����洢
	mp.reserve(200);
	cout << "����ʹ�õ�Ͱ����Ŀ  " << mp.bucket_count() << endl;
	cout << "�����ɵ����Ͱ������  " << mp.max_bucket_count() << endl;
	cout << "��1��Ͱ���ж���Ԫ��  " << mp.bucket_size(1) << endl;    //���ڲ������ظ�������ֻ��0��1
	cout << "�ؼ���Ϊ2��Ԫ�����ĸ�Ͱ  " << mp.bucket(2) << endl;


	for (const auto &m : mp)
		cout << "key = " << m.first << "  value = " << m.second << endl;


}


int main()
{
	//test00();
	test01();


	return 0;
}