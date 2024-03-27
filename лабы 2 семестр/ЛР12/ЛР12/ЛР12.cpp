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
	Node* get(int in) {
		Node* cur = head;
		if (in > size || in < 0) return nullptr;
		for (int i = 0; i < in; i++) {
			cur = cur->getNext();
		}
		return cur;
	}


	void BubleSort() {
		/*for (int i = 0; i < size; i++)
		{
			Node* temp = head;
			Node* prev = nullptr;

			for (int j = 0; j < size-1 ; j++) {
				if (temp->getData() < temp->getNext()->getData()){
					if (prev != nullptr) {

					}
				}

				prev = temp;
				temp = temp->getNext();
			}
		}*/

	}
};


int main() {

	int* arr = new int[10];

	for (int i = 1; i < 11; i++) {
		arr[i-1] = i;
	}

	Queue<int > odd;
	Queue<int > even;


	for (int i = 1; i < 11; i++) {
		if ((i )% 2 == 0) {
			even.push(arr[i-1]);
		}
		else {
			odd.push(arr[i-1]);
		}
	}



	cout << "Odd queue: " << endl;
	cout << "Head: " << odd.front() << endl;
	size_t size1 = odd.getSize();
	for (int i = 0; i < size1; i++) {
		cout << odd.pop() << " ";
	}
	
	cout << endl;
	
	
	cout << "Even queue: " << endl;
	cout << "Head: " << even.front() << endl;

	even.BubleSort();

	size_t size2 = even.getSize();
	for (int i = 0; i < size2; i++) {
		cout << even.pop() << " ";
	}
	cout << endl;






	return 0;
}