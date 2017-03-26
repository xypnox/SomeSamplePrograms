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

		cout <<  endl << " Stack : [ ";

		while (temp != NULL) {
			cout << temp -> num << " ";

			temp = temp -> Next;
		}

		cout << "]" << endl;
	}

	void eraser() {
		Node *temp = top, *xr;

		while (temp!= NULL) {
			xr = temp;
			delete xr;
			temp = temp -> Next;
		}
	}
};

int main() {
	cout << "Hello World" << endl;

	char com;

	Stack stk;



	do {
		cout << endl;
		cout << " Watt do ya wanna do" << endl;
		cout << " i: insert number" << endl;
		cout << " d: delete top element" << endl;
		cout << " v: view stack" << endl;
		cout << " q: close app" << endl;

		cout << " >>";
		cin >> com;

		switch (com) {
			case 'i' :
				int z;
				cout << endl << "Enter number to be inserted" << endl;
				cin >> z;
				stk.push(z);
			break;
			case 'd' :
				stk.pop();
			break;
			case 'v' :
				stk.traverse();
			break;
			case 'q' :
				stk.eraser();
				return 0;
			break;
			default :
				cout << endl << "Monkey Monkey Type Donkey"<< endl;
		}
	} while (com != 'q');


	return 0;
}
