#include <iostream>

using namespace std;

class node {
public:
	int data;
	node* prev;
	node* next;
	node(int _data) {	// ������, prev�� next�� ��� nullptr�� �ʱ�ȭ
		data = _data;
		prev = nullptr;
		next = nullptr;
	}
};

class LinkedList {
	friend class node;	// node Ŭ������ friend Ŭ������ �����ϸ鼭 private member�� ���ٰ���
public:
	node* head;
	node* tail;
	LinkedList() {	// ������
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty() {	// LinkedList�� ����ִ��� Ȯ��
		if (head == nullptr) {
			return true;
		}
		return false;
	}

	void insert_back(int data) {	// push_back
		node* p = new node(data); // ���ο� ��� p ����
		if (isEmpty()) {	// ���� LinkedList�� ��� �ִٸ�
			head = tail = p;	// head�� tail�� p
		} 
		else {
			p->prev = tail;		// p�� prev�� tail
			tail->next = p;		// ���� tail�� next�� p
			tail = p;			// tail�� p�� �ȴ�.
		}
	}

	void insert_front(int data) {	// push_front
		node* p = new node(data);	// ���ο� ��� p ����
		if (isEmpty()) {
			head = tail = p;
		}
		else {
			head->prev = p;
			p->next = head;
			head = p;
		}
	}

	void remove_back() {
		if (head == tail) {	// ���Ұ� 1���� ���
			node* p = tail;
			head = tail = nullptr;
			delete p;
		}
		else if (!isEmpty()) {	// LinkedList�� ������� ������
			node* p = tail;	// tail�� �ּҰ��� �����ϴ� �ӽ� ��� ����
			tail->prev->next = nullptr;	// tail ������ ����� next�� nullptr 
			tail = tail->prev;	// tail->prev�� tail�� �ȴ�.
			delete p;	// ���� tail�� �޸𸮴� ����
		}
		else {
			cout << "����Ʈ�� ����ֽ��ϴ�." << "\n";
		}
	}

	void remove_front() {
		if (head == tail) {	// ���Ұ� 1���� ���
			node* p = tail;
			head = tail = nullptr;
			delete p;
		}
		else if (!isEmpty()) {	// LinkedList�� ������� ������
			node* p = head;	// head�� �ּҰ��� �����ϴ� �ӽ� ��� ����
			head->next->prev = nullptr;	// head ���� ����� prev�� nullptr 
			head = head->next;	// head->next�� head�� �ȴ�.
			delete p;	// ���� head�� �޸𸮴� ����
		}
		else {
			cout << "����Ʈ�� ����ֽ��ϴ�." << "\n";
		}
	}

	void print() {
		if (!isEmpty()) {
			node* p = head;
			while (p != nullptr) {
				cout << p->data << " ";
				p = p->next;
			}
			cout << "\n";
		}
		else {
			cout << "����Ʈ�� ����ֽ��ϴ�." << "\n";
		}
	}
};

int main(void) 
{
	LinkedList list = LinkedList();
	bool a = true;
	while (a) {
		cout << "============== list ==============" << "\n";
		list.print();
		cout << "==================================" << "\n";
		cout << "1. insert_back, 2. insert_front, 3. remove_back, 4. remove_front, 0. terminate" << "\n";
		int k;
		cin >> k;
		switch (k) {
		int x;
		case 1:
			cout << "input: ";
			cin >> x;
			list.insert_back(x);
			break;
		case 2:
			cout << "input: ";
			cin >> x;
			list.insert_front(x);
			break;
		case 3:
			list.remove_back();
			break;
		case 4:
			list.remove_front();
			break;
		case 0:
			a = false;

		}

	}

	return 0;
}