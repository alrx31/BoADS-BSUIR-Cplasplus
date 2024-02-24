#include <iostream>

using namespace std;
template <typename T>
class Stack {
	int size;
	T* arr;
	
public:
	Stack() {
		size = 0;
		T* arr = new T[size+1];
	}

	void add(T data) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = data;
		delete[] arr;
		arr = temp;
		size++;
	}

	T pop() {
		return arr[--size];
	}


};

template <typename T>
class Queue {
	
    int size;
	T* arr;
public:
	Queue() {
		size = 0;
		T* arr = new T[size + 1];
	}
	void add(T data) {
		T* temp = new T[size + 1];
		for (int i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		temp[size] = data;
		delete[] arr;
		arr = temp;
		size++;
	}
	T pop() {
		T* temp = new T[size - 1];
		for (int i = 0; i < size - 1; i++) {
			temp[i] = arr[i + 1];
		}
		T res = arr[0];
		delete[] arr;
		arr = temp;
		size--;
		return res;
	}

	int getSize() {
		return size;
	}

};

class Task {
	int type;
	int difficulty;

public:
	Tack(int Type, int Difficulty) 
	{
		this->type = Type;
		this->difficulty = Difficulty;
	}
	int getType() {
		return this->type;
	}
	int getDifficulty() {
		return this->difficulty;
	}
};



int main() {
	
	Queue<Task> queue;
	Stack<Task> stack;
	

	queue.add(Task(1, 1));
	queue.add(Task(1, 2));
	queue.add(Task(2, 2));
	queue.add(Task(2, 3));
	queue.add(Task(3, 3));
	queue.add(Task(3, 4));


	


	return 0;
}