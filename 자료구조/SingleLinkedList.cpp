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
	node(int d, node *n) {	// ������ ��,���� ����� �ּ�
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
		cout << "=============mylist=============" << endl;
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
		cout << "================================" << endl;
	}
	int searchdata(int data)const
	{
		int k =-1;
		int size = 0;
		if (!IsEmpty()) {
			k = 0;
			node* current = head;
			while (current != nullptr) {
				if (current->data == data) {
					return k;
				}
				current = current->next;
				k++;
				size++;
			}
		}
		if (size == k)
			return -1;
		else
			return k;
	}

	void Clear() 
	{
		if (!IsEmpty()) {
			while (head!= nullptr) {
				node* removenode = head;
				head = head->next;
				delete removenode;
			}
		}
	}
	~SingleLinkedList()
	{
		if (!IsEmpty()) {
			while (head != nullptr) {
				node* removenode = head;
				head = head->next;
				delete removenode;
			}
		}
	}

};

int main(void)
{
	SingleLinkedList list;

	while (1) {
		list.print();
		cout << "(0)terminate (1)insert (2)front_pop (3)Search (4)Clear " << endl;
		int ch;
		cin >> ch;
		if (ch == 0)
			break;
		switch (ch) {
			int x;
			int k;
			int data;
		case 1:
			cout << "�����͸� �Է��ϼ���: ";
			cin >> data;
			list.InsertTail(data);
			break;
		case 2:
			list.RemoveFirst();
			break;
		case 3:
			cout << "ã�� �����͸� �Է��ϼ���: ";
			cin >> x;
			k = list.searchdata(x);
			if (k < 0) cout << "ã�� ����" << endl;
			else cout << k << "��° �ε����� �ֽ��ϴ�." << endl;
			break;
		case 4:
			list.Clear();
			break;
		}
	}
	system("pause");
	return 0;
}