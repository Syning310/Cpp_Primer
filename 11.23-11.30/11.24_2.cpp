//#include<iostream>
//using namespace std;
//
//#include<vector>
//
//void test00(void)
//{
//	vector<string> s1;
//	s1.push_back("s");
//	string *it = &s1.at(0);
//	static int count = 0;
//
//	for (int i = 0; i < 20; ++i)
//	{
//		if (it != &s1.at(0))
//		{
//			++count;
//			it = &s1.at(0);
//		}
//		cout << "s1的capacity为" << s1.capacity() << endl;
//		s1.push_back("s");
//	}
//
//	cout << "s1一共动态扩展了" << count << "次" << endl;
//
//}
//
//class Array
//{
//public:
//	//有参构造函数
//	Array(size_t size) : m_size(size) 
//	{
//		this->data = new int[this->m_size];
//	}
//	////拷贝构造函数,深拷贝
//	//Array(const Array& rhs)      
//	//{
//	//	this->m_size = rhs.m_size;
//	//	this->data = new int[this->m_size];
//	//	for (int i = 0; i < this->m_size; ++i)
//	//	{
//	//		this->data[i] = rhs.data[i];
//	//	}
//	//}
//	//重载赋值运算符
//	Array& operator=(const Array& rhs)  
//	{
//		delete[] this->data;
//		this->m_size = rhs.m_size;
//		this->data = new int[this->m_size];
//		for (int i = 0; i < this->m_size; ++i)
//		{
//			this->data[i] = rhs.data[i];
//		}
//	}
//	//移动拷贝构造函数
//	Array(Array&& rhs)
//	{
//		this->data = rhs.data;
//		this->m_size = rhs.m_size;
//		rhs.data = nullptr;  //为了防止rhs析构时delete data，提前置为空指针
//	}
//
//	
//	~Array()
//	{
//		delete[] this->data;
//	}
//
//	
//	size_t m_size;
//	int *data;
//};
//
//void test01(void)
//{
//	Array arr1(5);
//	arr1.data[0] = 1;
//	arr1.data[1] = 2;
//	arr1.data[2] = 3;
//	arr1.data[3] = 4;
//	arr1.data[4] = 5;
//
//	Array arr2(std::move(arr1));
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