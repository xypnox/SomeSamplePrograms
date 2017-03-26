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

class Queue {
	Node *front, *rear;

	public:

	Queue() {
		front = rear = NULL;
	}

	void Qinsert (int x) {
		Node *nn = createNode(x);

		if (rear == NULL) {
			front = rear = nn;
		} else {
			rear -> Next = nn;
			rear = nn;
		}
	}

	void Qdelete() {
		if (front == NULL) {
			cout << "Empty Queue Bro" << endl;
		} else {
			Node *t = front;
			front = front -> Next;
			t -> Next = NULL;
			delete t;
		}
	}

	void traverse() {
		Node *temp = front;

		cout <<  endl << " Queue : [ ";

		while (temp != NULL) {
			cout << temp -> num << " ";

			temp = temp -> Next;
		}

		cout << "]" << endl;
	}

	void eraser() {
		Node *temp = front, *xr;

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

	Queue q;



	do {
		cout << endl;
		cout << " Watt do ya wanna do" << endl;
		cout << " i: insert number at rear" << endl;
		cout << " d: delete front element" << endl;
		cout << " v: view queue" << endl;
		cout << " q: close app" << endl;

		cout << " >>";
		cin >> com;

		switch (com) {
			case 'i' :
				int z;
				cout << endl << "Enter number to be inserted" << endl;
				cin >> z;
				q.Qinsert(z);
			break;
			case 'd' :
				q.Qdelete();
			break;
			case 'v' :
				q.traverse();
			break;
			case 'q' :
				q.eraser();
				return 0;
			break;
			default :
				cout << endl << "Monkey Monkey Type Donkey"<< endl;
		}
	} while (com != 'q');


	return 0;
}
