//#include<iostream>
//using namespace std;
//#include<string>
//#include<set>
//
//
////��ʵ������ָ��
//class HasPtr
//{
//public:
//	//���캯�������µ�string���µļ�����������������Ϊ1
//	HasPtr(const string& s = " ") : ps(new string(s)), i(0), use(new size_t(1)) {  }
//
//	//�������캯�����������������ݳ�Ա��������������
//	HasPtr(const HasPtr& rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++* use; }
//
//	HasPtr& operator=(HasPtr& rhs)
//	{
//		if (-- * (this->use) == 0)  //�ݼ�����������ü�����������ü���Ϊ0
//		{
//			delete this->ps;      //�ͷű��������ĳ�Աָ��
//			delete this->use;
//		}
//		this->ps = rhs.ps;     //������this���󣬶���string
//		this->use = rhs.use;   //������this�������ü���
//		this->i = rhs.i;
//
//		++* (this->use);  //���Ӽ�����
//
//		return *this;
//	}
//
//	~HasPtr()
//	{
//		if (-- * use == 0) //���������Ϊ0
//		{
//			delete ps;     //�ͷ�string�ڴ�
//			delete use;    //�ͷż������ڴ�
//		}
//	}
//private:
//public:
//	string* ps;
//	int i;
//	size_t* use;
//};
//
//
//
//void test02(void)
//{
//	HasPtr p1("like you");
//	HasPtr p2(p1);
//	HasPtr p3;
//	p3 = p2;
//
//	cout << "p1.ps = " << *p1.ps << "  p1.use = " << *(p1.use) << endl;
//	cout << "p2.ps = " << *p2.ps << "  p1.use = " << *(p2.use) << endl;
//	cout << "p3.ps = " << *p3.ps << "  p1.use = " << *(p3.use) << endl;
//
//}
//
//
//class person
//{
//public:
//	person(int age, string name)
//	{
//		cout << "�вι��캯���ĵ���" << endl;
//		this->age = age;
//		this->name = name;
//	}
//	person(person& p)
//	{
//		cout << "�������캯���ĵ���" << endl;
//		this->age = p.age;
//		this->name = p.name;
//	}
//	person& operator=(const person& p)
//	{
//		this->age = p.age;
//		this->name = p.name;
//		return *this;
//	}
//
//	int age;
//	string name;
//
//};
//
//void func(person p)
//{
//	cout << "func�ĵ���" << endl;
//}
//
//person func2(void)
//{
//	person p(20, "ning");
//	return p;
//}
//void test00(void)
//{
//	person p(10, "chen");  //�в�
//	person p2 = p;   //����
//	func(p);  //����
//
//	func2();  //�вΣ�����
//
//}
//
////��ϰ13.17
//static size_t index = 0;
//class numbered
//{
//public:
//	numbered()
//	{
//		this->mysn = ++index;
//	}
//
//
//	size_t mysn;
//};
//
//void f(numbered s)  //����Ĳ�������úϳɿ�����������ǵ���Ĭ�Ϲ��죬���Զ���1
//{
//	cout << s.mysn << endl;
//}
//void test01(void)
//{
//	numbered a, b = a, c = b;  //a���õ���Ĭ�Ϲ��죬��b��c���õ��Ǳ������ṩ�ĺϳɿ��������ϳɸ�ֵ�����
//
//	f(a);
//	f(b);
//	f(c);
//
//}
//
//
//class persona
//{
//	persona(const string &s = " ") : ps(new string(s)), i(0)
//	{
//
//	}
//	persona(const persona &rhs) : ps(new string(*(rhs.ps))), i(rhs.i)
//	{
//
//	}
//
//	persona& operator=(const persona &rhs)  //��ֵ����������ǿ������캯��������һ���ոչ�������Ķ���
//	{                                     //��������������ָ��һ������������Ҫ���ͷ���
//		auto newp = new string(*(rhs.ps));
//		delete this->ps;
//
//		this->ps = newp;
//		this->i = rhs.i;
//		return *this;
//	}
//
//	~persona()
//	{
//		delete ps;
//	}
//
//private:
//	string *ps;
//	int i;
//};
//
//
//
//
//void test03(void)
//{
//	float y = 0;
//	float x = 0;
//	float a = 0;
//	for (y = 1.5f; y > -1.5f; y -= 0.1f)
//	{
//		for (x = -1.5f; x < 1.5f; x += 0.05f)
//		{
//			a = x * x + y * y - 1;
//			cout << (a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
//		}
//		cout << endl;
//	}
//}
//
//
//int main()
//{
//	//test00();
//	//test01();
//	//test02();
//	//test03();
//
//	system("pause");
//	return 0;
//}
//
