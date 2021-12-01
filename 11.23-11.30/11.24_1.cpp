//#include<iostream>
//using namespace std;
//#include<string>
//#include<memory>
//
//
//
//
//int main()
//{
//
//
//	return 0;
//}
//
//
//
//
//
//
//class StrVec
//{
//public:
//	StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
//	StrVec(const StrVec&);
//	StrVec& operator=(const StrVec&);
//	~StrVec();
//	void push_back(const string&);
//	size_t size(void) const
//	{
//		return first_free - elements;
//	}
//	size_t capacity(void) const
//	{
//		return cap - elements;
//	}
//	string* begin(void) const
//	{
//		return elements;
//	}
//	string* end(void) const
//	{
//		return first_free;
//	}
//
//private:
//	static allocator<string> alloc;
//	void chk_n_alloc()
//	{
//		if (size() == capacity())
//			reallocate();
//	}
//	pair<string*, string*> alloc_n_copy(const string *, const string*);
//	void free();         //����Ԫ�ز��ͷ��ڴ�
//	void reallocate();   //��ø����ڴ沢��������Ԫ��
//	string *elements;    //ָ��������Ԫ�ص�ָ��
//	string *first_free;  //ָ�������һ������Ԫ�ص�ָ��
//	string *cap;         //ָ������β��λ�õ�ָ��
//};
//
//
//class per
//{
//public:
//	int age;
//};
//
//
//
//StrVec::StrVec(const StrVec &s)
//{
//	auto newdata = alloc_n_copy(s.begin(), s.end());
//	elements = newdata.first;
//	first_free = cap = newdata.second;
//}
//
//StrVec& StrVec::operator=(const StrVec &rhs)
//{
//	auto data = alloc_n_copy(rhs.begin(), rhs.end());
//	free();
//	elements = data.first;
//	first_free = cap = data.second;
//	return *this;
//}
//
//StrVec::~StrVec()
//{
//	free();
//}
//
//void StrVec::push_back(const string &s)
//{
//	chk_n_alloc();
//	alloc.construct(first_free++, s);
//}
//
//pair<string *, string *>
//StrVec::alloc_n_copy(const string *b, const string *e)
//{
//	auto data = alloc.allocate(e - b);
//	return {data, uninitialized_copy(b, e, data)};
//}
//
//
//void StrVec::free(void)
//{
//	if (elements != nullptr)
//	{
//		for (auto p = first_free; p != elements; )
//		{
//			alloc.destroy(--p);
//		}
//		alloc.deallocate(elements, cap - elements);
//	}
//}
//
//void StrVec::reallocate(void)
//{
//	//�����䵱ǰ��С�������ڴ�ռ�
//	auto newcapacity = size() ? 2 * size() : 1;  //size()��Ϊ0�Ļ���2��Ϊ0�Ļ���һ���ڴ�
//	//�������ڴ�
//	auto newdata = alloc.allocate(newcapacity);
//	//�����ݴӾ��ڴ��ƶ������ڴ�
//	auto dest = newdata;  //ָ������������һ������λ��
//	auto elem = elements; //ָ�����������һ��Ԫ��
//
//	for (size_t i = 0; i != size(); ++i)
//	{
//		alloc.construct(dest++, std::move(*(elem++)));
//	}
//
//	free();  //һ������ƶ������ͷž��ڴ�ռ�
//	//�������ǵ����ݽṹ��ִ����Ԫ��
//	elements = newdata;
//	first_free = dest;
//	cap = elements + newcapacity;
//}
//
