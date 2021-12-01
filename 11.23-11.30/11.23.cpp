//#include<iostream>
//using namespace std;
//#include<string>
//#include<set>
//
//
////简单实现智能指针
//class HasPtr
//{
//public:
//	//构造函数分配新的string和新的计数器，将计数器置为1
//	HasPtr(const string& s = " ") : ps(new string(s)), i(0), use(new size_t(1)) {  }
//
//	//拷贝构造函数拷贝所有三个数据成员，并递增计数器
//	HasPtr(const HasPtr& rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++* use; }
//
//	HasPtr& operator=(HasPtr& rhs)
//	{
//		if (-- * (this->use) == 0)  //递减本对象的引用计数，如果引用计数为0
//		{
//			delete this->ps;      //释放本对象分配的成员指针
//			delete this->use;
//		}
//		this->ps = rhs.ps;     //拷贝给this对象，堆区string
//		this->use = rhs.use;   //拷贝给this对象，引用计数
//		this->i = rhs.i;
//
//		++* (this->use);  //增加计数器
//
//		return *this;
//	}
//
//	~HasPtr()
//	{
//		if (-- * use == 0) //如果计数器为0
//		{
//			delete ps;     //释放string内存
//			delete use;    //释放计数器内存
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
//		cout << "有参构造函数的调用" << endl;
//		this->age = age;
//		this->name = name;
//	}
//	person(person& p)
//	{
//		cout << "拷贝构造函数的调用" << endl;
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
//	cout << "func的调用" << endl;
//}
//
//person func2(void)
//{
//	person p(20, "ning");
//	return p;
//}
//void test00(void)
//{
//	person p(10, "chen");  //有参
//	person p2 = p;   //拷贝
//	func(p);  //拷贝
//
//	func2();  //有参，拷贝
//
//}
//
////练习13.17
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
//void f(numbered s)  //传入的参数会调用合成拷贝构造而不是调用默认构造，所以都是1
//{
//	cout << s.mysn << endl;
//}
//void test01(void)
//{
//	numbered a, b = a, c = b;  //a调用的是默认构造，而b和c调用的是编译器提供的合成拷贝构造或合成赋值运算符
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
//	persona& operator=(const persona &rhs)  //赋值运算符，不是拷贝构造函数，不是一个刚刚构造出来的对象
//	{                                     //而这个对象本身就有指向一个堆区，所以要先释放它
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
