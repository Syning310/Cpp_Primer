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
//		cout << "s1��capacityΪ" << s1.capacity() << endl;
//		s1.push_back("s");
//	}
//
//	cout << "s1һ����̬��չ��" << count << "��" << endl;
//
//}
//
//class Array
//{
//public:
//	//�вι��캯��
//	Array(size_t size) : m_size(size) 
//	{
//		this->data = new int[this->m_size];
//	}
//	////�������캯��,���
//	//Array(const Array& rhs)      
//	//{
//	//	this->m_size = rhs.m_size;
//	//	this->data = new int[this->m_size];
//	//	for (int i = 0; i < this->m_size; ++i)
//	//	{
//	//		this->data[i] = rhs.data[i];
//	//	}
//	//}
//	//���ظ�ֵ�����
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
//	//�ƶ��������캯��
//	Array(Array&& rhs)
//	{
//		this->data = rhs.data;
//		this->m_size = rhs.m_size;
//		rhs.data = nullptr;  //Ϊ�˷�ֹrhs����ʱdelete data����ǰ��Ϊ��ָ��
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