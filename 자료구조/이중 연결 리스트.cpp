#include <iostream>

using namespace std;

class node {
public:
	int data;
	node* prev;
	node* next;
	node(int _data) {	// 생성자, prev와 next는 모두 nullptr로 초기화
		data = _data;
		prev = nullptr;
		next = nullptr;
	}
};

class LinkedList {
	friend class node;	// node 클래스를 friend 클래스로 지정하면서 private member에 접근가능
public:
	node* head;
	node* tail;
	LinkedList() {	// 생성자
		head = nullptr;
		tail = nullptr;
	}

	bool isEmpty() {	// LinkedList가 비어있는지 확인
		if (head == nullptr) {
			return true;
		}
		return false;
	}

	void insert_back(int data) {	// push_back
		node* p = new node(data); // 새로운 노드 p 생성
		if (isEmpty()) {	// 만약 LinkedList가 비어 있다면
			head = tail = p;	// head와 tail은 p
		} 
		else {
			p->prev = tail;		// p의 prev는 tail
			tail->next = p;		// 기존 tail의 next는 p
			tail = p;			// tail은 p가 된다.
		}
	}

	void insert_front(int data) {	// push_front
		node* p = new node(data);	// 새로운 노드 p 생성
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
		if (head == tail) {	// 원소가 1개인 경우
			node* p = tail;
			head = tail = nullptr;
			delete p;
		}
		else if (!isEmpty()) {	// LinkedList가 비어있지 않으면
			node* p = tail;	// tail의 주소값을 저장하는 임시 노드 생성
			tail->prev->next = nullptr;	// tail 이전의 노드의 next는 nullptr 
			tail = tail->prev;	// tail->prev가 tail이 된다.
			delete p;	// 기존 tail의 메모리는 해제
		}
		else {
			cout << "리스트가 비어있습니다." << "\n";
		}
	}

	void remove_front() {
		if (head == tail) {	// 원소가 1개인 경우
			node* p = tail;
			head = tail = nullptr;
			delete p;
		}
		else if (!isEmpty()) {	// LinkedList가 비어있지 않으면
			node* p = head;	// head의 주소값을 저장하는 임시 노드 생성
			head->next->prev = nullptr;	// head 다음 노드의 prev는 nullptr 
			head = head->next;	// head->next가 head가 된다.
			delete p;	// 기존 head의 메모리는 해제
		}
		else {
			cout << "리스트가 비어있습니다." << "\n";
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
			cout << "리스트가 비어있습니다." << "\n";
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