#include"11.21_StrBlob.h"

StrBlob::StrBlob() : data( make_shared<vector<string> >() )
{

}

StrBlob::StrBlob(initializer_list<string> il) : data( make_shared<vector<string> > (il) )
{

}

size_type StrBlob::size(void)const
{
	return data->size();
}

bool StrBlob::empty(void) const
{
	return (*data).empty();
}

	//β���βɾ
void StrBlob::push_back(const string& t)
{
	data->push_back(t);
}
void StrBlob::pop_back(void)
{
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

	//����Ԫ��
string& StrBlob::front(void)const
{
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back(void)const
{
	check(0, "back on empty StrBlob");
	return data->back();
}


string& StrBlob::front(void)
{
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::back(void)
{
	check(0, "back on empty StrBlob");
	return data->back();
}

	//private
	//���data[i] ���Ϸ����׳�һ���쳣
void StrBlob::check(size_type i, const string& msg)const
{
	if (i >= data->size() )
	{
		throw out_of_range(msg);
	}

}