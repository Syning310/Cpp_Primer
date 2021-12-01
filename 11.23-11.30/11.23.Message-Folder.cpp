//#include"11.23.Message-Folder.h"
//
//
//
//void swap(Message& lhs, Message& rhs)
//{
//	using std::swap;
//
//	for (auto f : lhs.folders)
//		f->remMsg(&lhs);
//	for (auto f : rhs.folders)
//		f->remMsg(&rhs);
//
//	swap(lhs.contents, rhs.contents);
//	swap(lhs.folders, rhs.folders);
//
//	for (auto f : lhs.folders)
//		f->addMsg(&lhs);
//	for (auto f : rhs.folders)
//		f->addMsg(&rhs);
//}
//
//void Message::save(Folder& f)
//{
//	folders.insert(&f);
//	f.addMsg(this);
//}
//
//void Message::remove(Folder& f)
//{
//	folders.erase(&f);
//	f.remMsg(this);
//}
//
//void Message::add_to_Folders(const Message& msg)
//{
//	for (auto f : msg.folders)
//		f->addMsg(this);
//}
//
//void Message::remove_from_Folders()
//{
//	for (auto f : folders)
//		f->remMsg(this);
//}
//
//Message::Message(const Message& msg) :
//	contents(msg.contents), folders(msg.folders)
//{
//	add_to_Folders(msg);
//}
//
//Message::~Message()
//{
//	remove_from_Folders();
//}
//
//Message&
//Message::operator=(const Message& rhs)
//{
//	contents = rhs.contents;
//	remove_from_Folders();
//	folders = rhs.folders;
//	add_to_Folders(rhs);
//	return *this;
//}
//
//void Message::addFolder(Folder* fp)
//{
//	folders.insert(fp);
//}
//
//void Message::remFolder(Folder* fp)
//{
//	folders.erase(fp);
//}
//
//void Message::debug_print()
//{
//	cerr << "Message:\n\t" << contents << endl;
//	cerr << "Appears in " << folders.size() << " Folders" << endl;
//}
//
//
//void Folder::save(Message& m)
//{
//	messages.insert(&m);
//	m.addFolder(this);
//}
//
//void Folder::remove(Message& m)
//{
//	messages.erase(&m);
//	m.remFolder(this);
//}
//
//void Folder::addMsg(Message* m)
//{
//	messages.insert(m);
//}
//
//void Folder::remMsg(Message* m)
//{
//	messages.erase(m);
//}
//
//void Folder::add_to_Messages(const Folder& f)
//{
//	for (auto m : f.messages)
//		m->addFolder(this);
//}
//
//void Folder::remove_from_Messages()
//{
//	for (auto m : messages)
//		m->remFolder(this);
//}
//
//Folder::Folder(const Folder& f) : messages(f.messages)
//{
//	add_to_Messages(f);
//}
//
//Folder& Folder::operator=(const Folder& f)
//{
//	remove_from_Messages();
//	messages = f.messages;
//	add_to_Messages(f);
//	return *this;
//}
//
//Folder::~Folder()
//{
//	remove_from_Messages();
//}
//
//void Folder::debug_print()
//{
//	cerr << "Folder contains " << messages.size() << " messages" << endl;
//	int ctr = 1;
//	for (auto m : messages)
//		cerr << "Message " << ctr++ << ":\n\t" << m->contents << endl;
//}
