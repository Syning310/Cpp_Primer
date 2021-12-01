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
//	void free();         //销毁元素并释放内存
//	void reallocate();   //获得更多内存并拷贝已有元素
//	string *elements;    //指向数组首元素的指针
//	string *first_free;  //指向数组第一个空闲元素的指针
//	string *cap;         //指向数组尾后位置的指针
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
//	//将分配当前大小两倍的内存空间
//	auto newcapacity = size() ? 2 * size() : 1;  //size()不为0的话乘2；为0的话给一个内存
//	//分配新内存
//	auto newdata = alloc.allocate(newcapacity);
//	//将数据从旧内存移动到新内存
//	auto dest = newdata;  //指向新数组中下一个空闲位置
//	auto elem = elements; //指向旧数组中下一个元素
//
//	for (size_t i = 0; i != size(); ++i)
//	{
//		alloc.construct(dest++, std::move(*(elem++)));
//	}
//
//	free();  //一旦完成移动，就释放就内存空间
//	//更新我们的数据结构，执行新元素
//	elements = newdata;
//	first_free = dest;
//	cap = elements + newcapacity;
//}
//
