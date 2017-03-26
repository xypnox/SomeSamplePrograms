#include <iostream>

using namespace std;

class CircularQ {
	int front, rear, size, a[5];

	public:

	CircularQ() {
		front = rear = -1;
		size = 5;
	}

	void CQinsert(int x) {

		if ((front == 0 && rear == size-1) || front == rear+1) {
			cout << "What is it, FULL!!!";
		} else if(rear==-1) {
			rear = front = 0;
			a[rear] = x;
		} else if(rear == size-1) {
			rear = 0;
			a[rear] = x;
		} else {
			a[++rear] = x;
		}
	}

	void CQdelete() {
		if (front == rear && front != -1) {
			front =  rear = -1;
		} else if (front == size-1){
			front = 0;
		} else if (front >= 0) {
			front++;
		} else {
			cout << "MT CQ BRO CHILL" << endl;
		}
	}

	void traverse() {


		cout <<  endl << " CQ : [ ";

		if (front <= rear && front != -1) {
			int i = front;
			while(i != rear+1) {
				cout << a[i++] << " ";
			}
		} else if( front > rear && front !=-1) {
			int i = front;
			while( i < size ) {
				cout << a[i++] << " ";
			}
			i = 0;
			while(i<= rear) {
				cout << a[i++] << " ";
			}
		}

		cout << "]" << endl;
	}
};

int main() {
	cout << "Hello World" << endl;

	char com;

	CircularQ cq;



	do {
		cout << endl;
		cout << " Watt do ya wanna do" << endl;
		cout << " i: insert number at rear" << endl;
		cout << " d: delete front element" << endl;
		cout << " v: view cq" << endl;
		cout << " q: close app" << endl;

		cout << " >>";
		cin >> com;

		switch (com) {
			case 'i' :
				int z;
				cout << endl << "Enter number to be inserted" << endl;
				cin >> z;
				cq.CQinsert(z);
			break;
			case 'd' :
				cq.CQdelete();
			break;
			case 'v' :
				cq.traverse();
			break;
			case 'q' :
				return 0;
			break;
			default :
				cout << endl << "Monkey Monkey Type Donkey"<< endl;
		}
	} while (com != 'q');


	return 0;
}
