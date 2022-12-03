#ifndef LINKED_LIST_CLASS_H
#define LINKED_LIST_CLASS_H

class numList{
	private:
		struct Item{
			int num;
			Item* next;
		};
		Item* head;
	public:
		numList();
		~numList();
		void addItem(int number);
		void print();
};

#endif
