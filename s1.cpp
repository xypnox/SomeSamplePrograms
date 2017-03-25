#include <iostream>

using namespace std;

struct Node {
	int num;
	Node *Next;
};

Node* createNode(int x) {
	Node *nn = new Node;
	nn -> num = x;
	nn -> Next = NULL;

	return nn;
}

class Stack {
	Node *top;

	public:

	Stack() {
		top = NULL;
	}

	void push(int x) {
		Node *nn = createNode(x);

		if (top == NULL) {
			top = nn;
		} else {
			nn -> Next = top;
			top = nn;
		}
	}

	void pop() {
		if (top == NULL) {
			cout << "Empty Stack Bro" << endl;
		} else {
			Node *t = top;
			top = top -> Next;
			t -> Next = NULL;
			delete t;
		}
	}

	void traverse() {
		Node *temp = top;

		cout << " Stack : [ ";

		while (temp != NULL) {
			cout << temp -> num << " ";

			temp = temp -> Next;
		}

		cout << "]" << endl;
	}
};

int main() {
	cout << "Hello World" << endl;

	char com;

	Stack stk;



	do {
		cout << " Watt do ya wanna do" << endl;
		cout << " i: insert number" << endl;
		cout << " d: delete top element" << endl;
		cout << " v: view stack" << endl;
		cout << " x: close app" << endl;

		cout << " >>";
		cin >> com;

		switch (com) {
			case 'i' :


	return 0;
}
