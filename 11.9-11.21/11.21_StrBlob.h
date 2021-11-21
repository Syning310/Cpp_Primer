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

	//尾插和尾删
	void push_back(const string &t);
	void pop_back(void);

	//访问元素
	string& front(void)const;
	string& back(void)const;
	string& front(void);
	string& back(void);


private:
	shared_ptr<vector<string> > data;

	//如果data[i] 不合法，抛出一个异常
	void check(size_type i, const string &msg)const;

};



