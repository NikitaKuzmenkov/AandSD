#include <iostream>
#include <windows.h>
#include <list>
#include <ctime>
using namespace std;

struct stk {
	char x;
	stk* Next, *Head;
};

void add(char x, stk*& Mystk) {
	stk* temp = new stk;

	temp->x = x;
	temp->Next = Mystk->Head;
	Mystk->Head = temp;
}

void Print(stk* Mystk) {
	stk* temp = Mystk->Head;

	cout << temp->x << " ";
	temp = temp->Next;
}

void del(stk* Mystk) {
	stk* temp = Mystk->Head->Next;

	delete Mystk->Head;
	Mystk->Head = temp;
}

struct Node{
	int data;
	Node* next;
};

struct Queue{
	Node* first;
	Node* last;
};

void Creation(Queue* Q){
	Q->first = new Node;
	Q->first->next = NULL;
	Q->last = Q->first;
}

int Top(Queue* Q){
	return Q->first->next->data;
}

void Add(Queue* Q, int value){
	Q->last->next = new Node;
	Q->last = Q->last->next;
	Q->last->data = value;
	Q->last->next = NULL;
}

void Delete(Queue* Q){
	Q->first = Q->first->next;
}

struct dek {
	char x;
	dek* Next;
	dek* Head;
};

struct DEK {
	dek* pbeg;
	dek* pend;
};

void creation(DEK* d, char u) {
	d->pbeg = new dek;
	d->pbeg->x = u;
	d->pbeg->Next = d->pbeg->Head = NULL;
	d->pend = d->pbeg;

}

void addstart(DEK* d, char u) {
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

char dekend(DEK* d) {
	char temp = d->pend->x;
	dek* pv = d->pend;

	d->pend = d->pend->Next;

	delete pv;
	return temp;
}

char dekbegin(DEK* d) {
	char temp = d->pbeg->x;
	dek* pv = d->pbeg;

	d->pbeg = d->pbeg->Head;

	delete pv;
	return temp;
}

int i = 1;
int h = 1;

int main() {
	setlocale(LC_ALL, "");

	list<int> list_1 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14 };
	list<int> list_2 = { 1,2,3,4,5,6,7,8,9,10 };

	int R = 0;
	int L = 0;
	int T = 0;
	int N = 6;

	while (true) {
		srand(time(NULL));

		int k = rand() % 3 + 1;

		if (k == 1) {
			Queue Q;

			Creation(&Q);

			for (i = 1; i < N; i++) {
				Add(&Q, i);
			}

			cout << "*Студенты на пересдаче*" << endl;

			srand(time(NULL));

			k = rand() % 3 + 1;

			Sleep(2000);

			if (k == 1) {
				i++;
				Add(&Q, i);

				Sleep(2000);

				cout << "*Еще пришли студенты на пересдачу*" << endl;
			}

			i--;

			k = rand() % 3 + 1;

			if (k = 2) {
				h++;

				Sleep(2000);

				Delete(&Q);

				cout << "*Студент отправился на пересдачу*" << endl;
			}

			h++;

			Sleep(2000);

			cout << "*Студент отправился на пересдачу*" << endl;

			Sleep(2000);

			cout << "*Cтуденты ожидают в очереди*" << endl;

			Sleep(2000);

			Delete(&Q);

			Sleep(3000);

			system("cls");
		}

		if (k == 2) {
			cout << "Экзамен:" << endl;
			cout << "*Лежит 19 билетов, нужно вытянуть 1 сверху или 1 снизу...*" << endl;
			
			k = rand() % 3 + 1;
			
			Sleep(3000);
			
			if (k == 1) {
				cout << "*Студент вытянул верхний*" << endl;

				R = list_1.front();
				list_1.pop_front();
			}
			else {
				cout << "*Студент вытянул нижний*" << endl;

				Sleep(3000);

				R = list_1.back();
				list_1.pop_back();
			}

			Sleep(3000);
			system("cls");
		}
		if (k == 3) {
			Queue Q1;

			Creation(&Q1);

			int answer = 0;

			cout << "*Выбор задачи*" << endl;

			T = list_2.back();

			Sleep(3000);

			for (int i = 1; i <= h; i++) {
				Add(&Q1, i);
			}

			int y = Top(&Q1);

			if ((answer = rand() % 10) > 4) {
				Sleep(3000);

				cout << "*Студент сдал экзамен*" << endl;

				list_1.push_front(R);
				list_2.push_front(T);

				Delete(&Q1);
			}
			else {
				cout << "*Студент не сдал, теперь он в конце очереди...*" << endl;
				
				Sleep(3000);
				
				list_1.push_front(R);
				list_2.push_front(T);
				
				Delete(&Q1);
				
				N++;
			}
			Sleep(3000);
			system("cls");
		}

	}
	return 0;
}