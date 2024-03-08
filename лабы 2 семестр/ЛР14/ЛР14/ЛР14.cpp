#include <iostream>
#include <string>

using namespace std;
template <typename T>
class Tree {
	class TreeNode {
		T data;
		TreeNode* left;
		TreeNode* right;
	public:
		TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
		void setLeft(TreeNode* left) {
			this->left = left;
		}
		void setRight(TreeNode* right) {
			this->right = right;
		}
		T getData() {
			return data;
		}
		TreeNode* getLeft() {
			return left;
		}
		TreeNode* getRight() {
			return right;
		}
	};

	TreeNode* root;
public:
	Tree() : root(nullptr) {}


	void Create(string expression) {
		int countOperators = 1;
		for (int i = 0; i < expression.size(); i++) {
			if (expression[i] == ' ') continue;
			TreeNode* node = new TreeNode(expression[i]);
			if (isOperator(node->getData())) {
				node->setRight(root);
				TreeNode* needNode = root;
				if (isOperator(root->getData())) {
					for (int j = 0; j < countOperators; j++) {
						needNode = needNode->getLeft();
					}
					countOperators++;
				}
				else {
					needNode = root;
				}

				node->setLeft(needNode->getRight());
				needNode->setRight(nullptr);
			}
			else {
				node->setRight(root);
			}
			root = node;
		}
	}

	string getNewExp() {
		return createExp(root);
	}

	string createExp(TreeNode* node) {
		if (node == nullptr) return "";
		if (node->getLeft() == nullptr && node->getRight() == nullptr) {
			return string(1,node->getData());
		}
		string left = createExp(node->getLeft());
		string right = createExp(node->getRight());
		//cout << left << "\t " << right  << "\t " << node->getData() << endl;
		if(left.size() == 1 && right.size() != 1) return left + " " + node->getData() + " (" + right + ")";
		if(right.size() == 1 && left.size() != 1) return "(" + left + ") " + node->getData() + " " + right;
		if(left.size() != 1 && right.size() != 1) return "(" + left + ") " + node->getData() + " (" + right + ")";
		return left + " " + node->getData() + " " + right;
	}

	bool isOperator(char c) {
		return c == '+' || c == '-' || c == '*' || c == '/';
	}

	void Clear(TreeNode* node) {
		if(node == nullptr) return;
		Clear(node->getLeft());
		Clear(node->getRight());
		delete node;
	}

	TreeNode* getRoot() {
		return root;
	}
};




int getPriority(char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	cout << "Error" << endl;
	return 0;
}


//1 2 - 3 4 /5 6 / + +
//1-2+3/4+5/6
//





int main()
{
	Tree<char> tree;
	
	
	string expression = "3 1 +";
	string expression2 = "1 2 - 3 4 /5 6 / + +";
	string expression3 = "1 2 + 3 4 - *";
	
	
	cout << expression << endl;
	tree.Create(expression);
	cout << tree.getNewExp() << endl << endl;
	
	Tree<char> tree2;
	cout << expression2 << endl;
	tree2.Create(expression2);
	cout << tree2.getNewExp() << endl << endl;

	Tree<char> tree3;
	cout << expression3 << endl;
	tree3.Create(expression3);
	cout << tree3.getNewExp() << endl << endl;
	

	return 0;
}