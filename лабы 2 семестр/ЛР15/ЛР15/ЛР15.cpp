#include <iostream>
using namespace std;
class Node {
    string data;
    string key;
    Node* next;
public:
    Node(string data) : data(data), next(nullptr) {}
    Node(string data, string key) : data(data), key(key), next(nullptr) {}
    string getData() { return data; }
    string getKey() { return key; }
    Node* getNext() { return next; }
    void setNext(Node* next) { this->next = next; }
    void setData(string data) { this->data = data; }
    void setKey(string key) { this->key = key; }
};

class LinkedList {
    Node* head;
    int size;
public:

    LinkedList() : head(nullptr), size(0) {}
    int getSize() { return size; }

    void push(string data, string key) {
        if (size == 0) {
            head = new Node(data, key);
		}
		else {
			Node* current = head;
            while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(new Node(data, key));
        }
        size++;

    }

    string get(string key) {
        if (size == 0) {
            cout << "List is empty";
            return "";
        }
        else if (size == 1) {
            return head->getData();
        }
        else {
            Node* current = head;
            while (current) {
                if (current->getKey() == key) {
                    return current->getData();
                }
                current = current->getNext();
			}
            cout << "Element not found";
            return "";
        }
    }
    Node* get(int index) {
        if (index < 0 || index >= size) {
			cout << "Index out of range";
			return nullptr;
		}
        else {
			Node* current = head;
            for (int i = 0; i < index; i++) {
				current = current->getNext();
			}
			return current;
		}
	}

    void deleteNode(string key) {
        if (size == 0) {
            cout << "List is empty";
            return;
        }
        else if (size == 1) {
            delete head;
            head = nullptr;
            size = 0;
            return;
        }
        else {
            Node* current = head;
            Node* prev = nullptr;
            while (current) {
                if (current->getKey() == key) {
                    if (prev) {
						prev->setNext(current->getNext());
					}
                    else {
						head = current->getNext();
					}
					delete current;
                    delete prev;
					size--;
					return;
				}
				prev = current;
				current = current->getNext();
			}
        }
        cout << "Element not found" << endl;
    }

};

class HashTable {
    LinkedList* arr;
    int size;
public:
    HashTable(int size) : size(size) {
        arr = new LinkedList[size];
    }

    void Add(string key, string data) {
        int hash = getHash(key);
        arr[hash].push(data, key);
    }

    int getHash(string data) {
        int sum = 0;
        for (int i = 0; i < data.length(); i++) {
            sum += data[i] / 1;
        }
        return sum % size;
    }

    string get(string key) {
        int hash = getHash(key);
        return arr[hash].get(key);
    }

    void Delete(string key) {
        int hash = getHash(key);
        arr[hash].deleteNode(key);
    }


    
    void ViewHashTable() {
        for (int i = 0; i < size; i++) {
            if (arr[i].getSize() != 0) {
                for (int j = 0; j < arr[i].getSize(); j++) {
                    Node* temp  = arr[i].get(j);
                    cout << temp->getKey() << " \t:\t " << temp->getData() << endl;
                }
            }
        }
    }

};

int main() {
    HashTable table(2000);

    table.Add("123", "Hello");
    table.Add("Petya", "Exlent");
    table.Add("Vasya", "Good");
    table.Add("Kolya", "Bad");
    table.Add("Masha", "Nice");

    table.ViewHashTable();
    cout << "==========================" << endl;

    table.Delete("Petya");
    table.Delete("Vasya");
	table.ViewHashTable();

    cout << "==========================" << endl;

    cout << table.get("123") << endl;

    return 0;
}
