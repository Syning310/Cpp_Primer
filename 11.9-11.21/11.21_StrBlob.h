#pragma once

#include<iostream>
using namespace std;
#include<vector>
#include<string>


typedef vector<string>::size_type size_type;

class StrBlob
{
public:

	StrBlob();

	StrBlob(initializer_list<string> il);

	size_type size(void) const;

	bool empty(void) const;

	//β���βɾ
	void push_back(const string &t);
	void pop_back(void);

	//����Ԫ��
	string& front(void)const;
	string& back(void)const;
	string& front(void);
	string& back(void);


private:
	shared_ptr<vector<string> > data;

	//���data[i] ���Ϸ����׳�һ���쳣
	void check(size_type i, const string &msg)const;

};



