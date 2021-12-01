#pragma once
#include<iostream>
using namespace std;
#include<set>
#include<string>

////�ļ���
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
////��Ϣ
//class Message
//{
//	friend void swap(Message&, Message&);
//	friend class Folder;
//public:
//	//folders����ʽ��ʼ��Ϊ�ռ���
//	explicit Message(const string& str = " ") : m_contents(str) { }
//
//	//�������Ƴ�Ա����������ָ��Message��ָ��
//	Message(const Message&);  //�������캯��
//
//	Message& operator=(const Message& rhs);  //���ظ�ֵ�����
//
//	~Message();  //��������
//
//	//�Ӹ�����folder���������/ɾ����message
//	void save(Folder&);
//	void remove(Folder&);
//
//	void debug_print();
//
//private:
//	string m_contents;  //ʵ����Ϣ
//	set<Folder*> m_folders;  //������message��folder
//
//	//�������캯������ֵ�����������������ʹ�õĹ��ߺ���
//
//	//����Message��ӵ�ָ�������Folder��
//	void add_to_Folders(const Message&);
//
//	//��folders�е�ÿ��Folder��ɾ��Message
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
