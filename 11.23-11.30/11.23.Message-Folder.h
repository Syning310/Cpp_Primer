#pragma once
#include<iostream>
using namespace std;
#include<set>
#include<string>

////文件夹
//class Folder
//{
//	friend void swap(Message&, Message&);
//	friend class Massage;
//public:
//	Folder() = default;
//	Folder(const Folder&);
//	Folder& operator=(const Folder&);
//	~Folder();
//
//	void save(Message&);
//	void remove(Message&);
//
//	void debug_print();
//
//private:
//	set<Message*> m_messages;
//	void add_to_Message(const Folder&);
//	void remove_form_Message();
//	void addMsg(Message*);
//	void remMsg(Message*);
//};
//
//
////消息
//class Message
//{
//	friend void swap(Message&, Message&);
//	friend class Folder;
//public:
//	//folders被隐式初始化为空集合
//	explicit Message(const string& str = " ") : m_contents(str) { }
//
//	//拷贝控制成员，用来管理指向本Message的指针
//	Message(const Message&);  //拷贝构造函数
//
//	Message& operator=(const Message& rhs);  //重载赋值运算符
//
//	~Message();  //析构函数
//
//	//从给定的folder集合中添加/删除本message
//	void save(Folder&);
//	void remove(Folder&);
//
//	void debug_print();
//
//private:
//	string m_contents;  //实际消息
//	set<Folder*> m_folders;  //包含本message的folder
//
//	//拷贝构造函数、赋值运算符和析构函数所使用的工具函数
//
//	//将本Message添加到指向参数的Folder中
//	void add_to_Folders(const Message&);
//
//	//从folders中的每个Folder中删除Message
//	void remove_from_Folders();
//
//	void addFolder(Folder *);
//	void remFolder(Folder *);
//
//};


class Folder;

class Message {
	friend void swap(Message&, Message&);
	friend class Folder;
public:
	explicit Message(const string& str = "") :
		contents(str) { }
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void save(Folder&);
	void remove(Folder&);
	void debug_print();
private:
	string contents;
	set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void addFolder(Folder*);
	void remFolder(Folder*);
};

class Folder {
	friend void swap(Message&, Message&);
	friend class Message;
public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void save(Message&);
	void remove(Message&);
	void debug_print();
private:
	set<Message*> messages;
	void add_to_Messages(const Folder&);
	void remove_from_Messages();
	void addMsg(Message*);
	void remMsg(Message*);
};
