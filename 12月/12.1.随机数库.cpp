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
	//生成 0 到 9 之间均匀分布的随机数
	uniform_int_distribution<unsigned> u(0, 9);
	default_random_engine e;  //生成无符号随机整数
	for (size_t i = 0; i < 10; ++i)
	{
		//将 u 作为随机数源
		//每个调用返回在指定范围内并服从均匀分布的值
		cout << u(e) << endl;
	}

}

void test02(void)
{
	default_random_engine ra;

	cout << "最小值： " << ra.min() << "   最大值： " << ra.max() << endl;

}

void test03(void)
{
	default_random_engine e1;              //默认种子
	default_random_engine e2(2147483646);  //使用给定的种子值

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

	default_random_engine e3(2147483646); //与e2一样的种子值
	cout << "e3 : " << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << e3() << endl;
	}

}

void test04(void)
{
	uniform_int_distribution<unsigned> un(0, 9);
	default_random_engine rqa(time(nullptr));  //按照时间随机的种子

	for (int i = 0; i < 10; ++i)
	{
		cout << un(rqa) << endl;
	}

}

void test05(void)
{
	default_random_engine e;  //生成无符号随机整数
	
	// 0 到 1 的均匀分布
	uniform_real_distribution<double> up(0, 1);

	for (int i = 0; i < 10; ++i)
	{
		cout << up(e) << endl;
	}

}

void test06(void)
{
	default_random_engine le;         //生成随机整数
	normal_distribution<> n(4, 1.5);  //均值4，标准差1.5

	vector<unsigned> vals(9);         //9个元素均为0

	for (int i = 0; i != 200; ++i)
	{
		unsigned v = lround(n(le));    //舍入到最接近的整数
		if (v < vals.size())           //如果结果在范围内
			++vals[v];                 //统计每个数出现了多少次
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
	default_random_engine e;        //e应保持状态，所以必须在循环外定义
	bernoulli_distribution b;       //默认是 50/50 的机会
	do
	{
		bool first = b(e);     //如果为true，则程序先行
		cout << (first ? "We go first" : "You get to go first") << endl;
		//传递谁先行的指令，进行游戏
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