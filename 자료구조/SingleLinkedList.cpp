#include <iostream>

using namespace std;

class node {
	friend class SingleLinkedList;
private:
	int data;
	node* next;

	node() {
		data = 0;
		next = nullptr;
	}
	node(int d, node *n) {	// 데이터 값,다음 노드의 주소
		data = d;
		next = n;
	}
};

class SingleLinkedList {
	node *head;
	node *tail;
public:
	SingleLinkedList()
	{
		head = tail = nullptr;
	}
	SingleLinkedList(int data) 
	{
		head = tail = new node(data, nullptr);
	}
	void InsertTail(int data)
	{
		node* newNode = new node(data, nullptr);
		if (head == nullptr) { head = newNode; }
		else { tail->next = newNode; }
		tail = newNode;
	}
	void RemoveFirst() 
	{
		if (head != nullptr) {
			node* removefirst = head;
			head = head->next;
			delete removefirst;
		}
	}
	bool IsEmpty()const 
	{
		if (head == nullptr)
			return true;
		return false;
	}
	void print()const
	{
		if (!IsEmpty()) {
			node* current = head;
			while (current != nullptr) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
		else
			cout << "list is empty" << endl;
	}
};

int main(void)
{
	SingleLinkedList list;

	while (1) {
		list.print();
		cout << "(0)terminate (1)insert (2)front_pop" << endl;
		int ch;
		cin >> ch;
		if (ch == 0)
			break;
		switch (ch) {
		case 1:
			int data;
			cout << "데이터 입력: ";
			cin >> data;
			list.InsertTail(data);
			break;
		case 2:
			list.RemoveFirst();
			break;
		}
	}
	system("pause");
	return 0;
}