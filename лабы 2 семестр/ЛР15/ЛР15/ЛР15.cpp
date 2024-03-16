#include <iostream>
using namespace std;


template<typename T>
class LinkedList {
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

public:
	LinkedList() : head(nullptr) {}

			
};




template <typename T>
class HashTable {
	LinkedList<T> Table;
	int size;
public:
	
	HashTable(int size) : size(size) {
		Table = new LinkedList<T>[size];
	}

	void insert(T data) {
		int index = getHash(data);
		Table[index].insert(data);
	}




};

int getHash(int data) {
	return data % 10;
}





int main()
{




	return 0;
}