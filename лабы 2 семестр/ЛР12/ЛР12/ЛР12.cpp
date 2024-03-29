#include <iostream>

using namespace std;


template <typename T>
class Queue {
	class Node {
		T data;
		Node* next;
	public:
		Node(T data, Node* next = nullptr) : data(data), next(next) {}
		T getData() { return data; }
		Node* getNext() { return next; }
		void setNext(Node* next) { this->next = next; }
		void setData(T data) { this->data = data; }
	};

	Node* head;
	int size;
public:
	Queue() : head(nullptr), size(0) {}
	void push(T data) {
		if (head == nullptr) {
			head = new Node(data);
		}
		else {
			Node* current = head;
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(new Node(data));
		}
		size++;
	}
	T pop() {
		if (head == nullptr) {
			throw "Queue is empty";
		}
		T data = head->getData();
		Node* temp = head;
		head = head->getNext();
		delete temp;
		size--;
		return data;
	}
	T front() {
		if (head == nullptr) {
			throw "Queue is empty";
		}
		return head->getData();
	}
	int getSize() {
		return size;
	}
	bool isEmpty() {
		return size == 0;
	}
	T tail() {
		if (head == nullptr) throw "queue is empty";
		Node* temp = head;
		for (int i = 0; i < size - 1; i++) temp = temp->getNext();
		return temp->getData();
	}

	void swapIFNaC(Node* prev, Node* curr, Node* next, Node* H) {
		if (curr != nullptr && next != nullptr && curr->getData() < next->getData()) {
			if (prev == nullptr) {
				Node* temp = curr;
				curr->setNext(next->getNext());
				next->setNext(temp);
				head = next;
			}
			else {
				Node* temp = curr;
				prev->setNext(curr->getNext());
				temp->setNext(temp->getNext()->getNext());
				prev->getNext()->setNext(temp);
			}
		}
		else {
			return;
		}
		
	}

	void BubleSort() {
		if (head == nullptr) return;
		Node* prev;
		Node* curr;

		for (int i = 0; i < size; i++) {
			prev = nullptr;
			curr = head;

			for (int j = 0; j < size; j++) {
				if (curr == nullptr) break;
				swapIFNaC(prev, curr, curr->getNext(), head);
				prev = curr;
				curr = curr->getNext();
			}
		}


	}
};


int main() {

	int* arr = new int[20];

	for (int i = 1; i < 21; i++) {
		arr[i-1] = i;
	}

	Queue<int > odd;
	Queue<int > even;


	for (int i = 1; i < 21; i++) {
		if ((i )% 2 == 0) {
			even.push(arr[i-1]);
		}
		else {
			odd.push(arr[i-1]);
		}
	}



	cout << "Odd queue: " << endl;
	cout << "Head: " << odd.front() << endl;
	cout << "Tail: " << odd.tail() << endl;
	size_t size1 = odd.getSize();
	odd.BubleSort();

	for (int i = 0; i < size1; i++) {
		cout << odd.pop() << " ";
	}
	
	cout << endl;
	
	
	cout << "Even queue: " << endl;
	cout << "Head: " << even.front() << endl;
	cout << "Tail: " << even.tail() << endl;
	even.BubleSort();


	size_t size2 = even.getSize();
	for (int i = 0; i < size2; i++) {
		cout << even.pop() << " ";
	}
	cout << endl;

	Queue<bool> t;
	t.BubleSort();




	return 0;
}