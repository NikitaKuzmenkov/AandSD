#include <iostream>
#include <windows.h>

using namespace std;

struct stk {
	int x;
	stk *Next, *Head;
};

void add(int x, stk *&Mystk) {
	stk *temp = new stk;

	temp->x = x;
	temp->Next = Mystk->Head;
	Mystk->Head = temp;
}

void Print(stk *Mystk) {
	stk *temp = Mystk->Head;

	while (temp != NULL) {
		cout << temp->x << "     ";
		temp = temp->Next;
	}

	cout << endl;
}

void del(stk *Mystk) {
	stk *temp = Mystk->Head->Next;
	delete Mystk->Head;
	Mystk->Head = temp;
}

struct dek {
	int x;
	dek* Next;
	dek* Head;
};

struct DEK {
	dek* pbeg;
	dek* pend;
};

void creation(DEK* d, int u) {
	d->pbeg = new dek;
	d->pbeg->x = u;
	d->pbeg->Next = d->pbeg->Head = NULL;
	d->pend = d->pbeg;

}


void addstart(DEK* d, int u) {
	dek* pv = new dek;

	pv->x = u;
	pv->Next = NULL;
	pv->Head = d->pbeg;
	d->pbeg->Next = pv;
	d->pbeg = pv;
}

void addend(DEK* d, int u) {
	dek* pv = new dek;

	pv->x = u;
	pv->Head = NULL;
	pv->Next = d->pend;
	d->pend->Head = pv;
	d->pend = pv;
}

int dekend(DEK* d) {
	int temp = d->pend->x;
	dek* pv = d->pend;

	d->pend = d->pend->Next;

	delete pv;
	return temp;
}

int dekbegin(DEK* d) {
	int temp = d->pbeg->x;
	dek* pv = d->pbeg;

	d->pbeg = d->pbeg->Head;

	delete pv;
	return temp;
}

struct Node{
	int data;
	Node *next;
};

struct Queue{
	Node *first;
	Node *last;
};

void Creation(Queue *Q)
{
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
}

int Top(Queue *Q){
	return Q->first->next->data;
}

void Add(Queue *Q, int value){
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value;
	Q->last->next = NULL;
}

void Delete(Queue *Q){
	Q->first = Q->first->next;
}


int main() {
	setlocale(LC_ALL, "");

	while (true) {

		cout << "1 - стек\n2 - очередь\n3 - дек\n" << endl;

		int p;

		cin >> p;

		if (p == 1) {
			stk *Mystk = new stk;

			Mystk->Head = NULL;

			cout << "\nКоличество элементов: ";

			int r;
			int N;

			cin >> N;

			cout << "\nВведите их: ";

			for (int i = 0; i < N; i++) {
				cin >> r;
				add(r, Mystk);
			}

			cout << "\nСтек: ";

			Print(Mystk);
			del(Mystk);

			delete Mystk;

			system("pause");
			system("cls");
			return main();
		}
		if (p == 2) {
			Queue Q;

			Creation(&Q);

			cout << "\nКоличество элементов: ";

			int N;

			cin >> N;

			cout << "\nВведите их: ";

			for (int i = 0; i < N; i++) {
				int a;
				cin >> a;
				Add(&Q, a);
			}

			cout << "\nОчередь: ";

			for (int i = 0; i < N; i++) {
				cout << Top(&Q) << "\t";
				delte(&Q);
			}

			system("pause");
			system("cls");
			return main();
		}
		if (p == 3) {
			DEK d;

			cout << "\nКоличество элементов: ";

			int N;

			cin >> N;

			cout << "\nПервый элемент дека: " << endl;

			int p;

			cin >> p;

			cout << "\n";

			creation(&d, p);

			for (int i = 0; i < N - 1; i++) {
				int r;

				cout << "\nВведите элемент: ";

				cin >> r;

				cout << "\n1. - конец;\n2. - начало;\n";

				int u;

				cin >> u;

				cout << "\n";

				if (u == 1) {
					addend(&d, r);
				}
				if (u == 2) {
					addstart(&d, r);
				}
			}
			cout << "\nДек: ";

				for (int i = 0; i < N; i++) {
					cout << dekbegin(&d) << "\t";
				}

			system("pause");
			system("cls");
			return main();
		}
		else {
			break;
		}
	}

	cin.get();
	return 0;
}