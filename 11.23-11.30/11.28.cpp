//#include<iostream>
//using namespace std;
//
//
//class Base
//{
//public:
//	virtual int func()  //Base���麯��
//	{
//		cout << "Base���麯��func���ã�" << endl;
//		return 0;
//	}
//};
//class D1 : public Base
//{
//public:
//	int func(int)  //�β��б�ͬ���������ػ����funcû����д�麯��
//	{
//		cout << "D1��func�вε��ã�" << endl;
//		return 0;
//	}
//	virtual void f2()  //D1���麯��
//	{
//		cout << "D1���麯��f2���ã�" << endl;
//	}
//};
//class D2 : public D1
//{
//public:
//	int func(int)  //����D1��func����
//	{
//		cout << "D2��func�вε��ã�" << endl;
//		return 0;
//	}
//	int func()    //��д�˴�D1�̳�����func�麯����D1���Ǵ�Base�̳�����
//	{
//		cout << "D2���麯��func���ã�" << endl;
//		return 0;
//	}
//	void f2()    //��д��D1���麯��
//	{
//		cout << "D2���麯��f2���ã�" << endl;
//	}
//
//};
//
//void test00(void)
//{
//	Base bobj; 
//	D1 d1obj;
//	D2 d2obj;
//
//	Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
//
//	bp1->func();   //����ã�Base���麯��func����
//	bp2->func();   //����ã�Base���麯��func����
//	bp3->func();   //����ã�D2���麯��func����
//
//	D1 *d1p = &d1obj;
//	D2 *d2p = &d2obj;
//
//	//bp2->f2();  //����ָ��������Base��Baseû��f2
//	d1p->f2();    //����ã�D1���麯��f2����
//	d2p->f2();    //����ã�D2���麯��f2����
//
//}
//
//class base
//{
//public:
//	base(int age, string name) : m_age(age), m_name(name){ }
//	virtual ~base()
//	{
//		cout << "base��������������" << endl;
//	}
//
//	int m_age;
//	string m_name;
//private:
//	string m_cat;
//};
//class Derived : public base
//{
//public:
//	Derived(int age, string name) : base(age, name){}
//	~Derived() 
//	{
//		cout << "Derived��������������" << endl;
//	}
//	
//	using base::base;
//};
//
//void test01(void)
//{
//	base *bp = new Derived(20, "��");
//	delete bp;  //�������д��������������˲������ͷ�������Ķ�̬�ռ�
//
//
//	cout << sizeof(base) << endl;
//	cout << sizeof(Derived) << endl;
//
//}
//
//int main()
//{
//	//test00();
//	test01();
//
//
//	system("pause");
//	return 0;
//}