#include<iostream>
using namespace std;
#include<random>



void test00(void)
{
	default_random_engine e;

	for (int i = 0; i < 10; ++i)
	{
		cout << e() << endl;
	}

}

void test01(void)
{
	//���� 0 �� 9 ֮����ȷֲ��������
	uniform_int_distribution<unsigned> u(0, 9);
	default_random_engine e;  //�����޷����������
	for (size_t i = 0; i < 10; ++i)
	{
		//�� u ��Ϊ�����Դ
		//ÿ�����÷�����ָ����Χ�ڲ����Ӿ��ȷֲ���ֵ
		cout << u(e) << endl;
	}

}

void test02(void)
{
	default_random_engine ra;

	cout << "��Сֵ�� " << ra.min() << "   ���ֵ�� " << ra.max() << endl;

}

void test03(void)
{
	default_random_engine e1;              //Ĭ������
	default_random_engine e2(2147483646);  //ʹ�ø���������ֵ

	cout << "e1 : " << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << e1() << endl;
	}

	cout << "e2 : " << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << e2() << endl;
	}

	default_random_engine e3(2147483646); //��e2һ��������ֵ
	cout << "e3 : " << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << e3() << endl;
	}

}

void test04(void)
{
	uniform_int_distribution<unsigned> un(0, 9);
	default_random_engine rqa(time(nullptr));  //����ʱ�����������

	for (int i = 0; i < 10; ++i)
	{
		cout << un(rqa) << endl;
	}

}

void test05(void)
{
	default_random_engine e;  //�����޷����������
	
	// 0 �� 1 �ľ��ȷֲ�
	uniform_real_distribution<double> up(0, 1);

	for (int i = 0; i < 10; ++i)
	{
		cout << up(e) << endl;
	}

}

void test06(void)
{
	default_random_engine le;         //�����������
	normal_distribution<> n(4, 1.5);  //��ֵ4����׼��1.5

	vector<unsigned> vals(9);         //9��Ԫ�ؾ�Ϊ0

	for (int i = 0; i != 200; ++i)
	{
		unsigned v = lround(n(le));    //���뵽��ӽ�������
		if (v < vals.size())           //�������ڷ�Χ��
			++vals[v];                 //ͳ��ÿ���������˶��ٴ�
	}

	for (int i = 0; i != vals.size(); ++i)
		cout << i << ": " << string(vals[i], '*') << endl;

}

bool play(bool q)
{
	return q;
}
void test07(void)
{
	string resp;
	default_random_engine e;        //eӦ����״̬�����Ա�����ѭ���ⶨ��
	bernoulli_distribution b;       //Ĭ���� 50/50 �Ļ���
	do
	{
		bool first = b(e);     //���Ϊtrue�����������
		cout << (first ? "We go first" : "You get to go first") << endl;
		//����˭���е�ָ�������Ϸ
		cout << ((play(first)) ? "sorry, you lost" : "congrats, you won") << endl;
		cout << "play again? Enter 'yes' or 'no' " << endl;
	}while (cin >> resp && resp[0] == 'y');


}

int main()
{
	//test00();
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();



	system("pause");
	return 0;
}