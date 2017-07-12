// Queues implementation using array and linked list
#include <iostream>
using namespace std;

// Array Implementation
const int MaxSize=101;
class Queue{
	int arr[MaxSize];
	int front,rear;
public:
	Queue(){
		front= rear = -1;
	}
	bool IsEmpty(){
		if(front == -1 && rear == -1)
			return true;
		else 	return false;
	}
	bool IsFull(){
		return ((rear+1)%MaxSize == front)?true:false;
	}
	void EnQueue(int x){
		cout<<"Enquening "<<x<<" \n";
		if(IsEmpty())
			front = rear = 0;
		else if (IsFull()){
			cout<<"Error Queue is Full";
			return;
		}
		else
			rear = (rear+1)%MaxSize;
		arr[rear]= x;
	}
	void DeQueue(){
		if (IsEmpty()){
			cout<<"Error Queue is Empty\n";
			return;
		}
		else if (front == rear)
			front = rear = -1;
		front = (front+1)%MaxSize;
	}
	int Front(){
		if(front == -1){
			cout<<"Error Queue is Empty\n";
			return -1;
		}
		return arr[front];
	}
	void Display(){
		int count = (rear+MaxSize - front)%MaxSize;
		cout<<"Queue : ";
		for(int i=0;i<count;i++){
			int index = (front +i)%MaxSize;
			cout<<arr[index]<<" ";
		}
		cout<<"\n";
	}
};

// Linked List Implementation
struct Node{
	int data ;
	Node *next;
};
Node *front = NULL;
Node *rear = NULL;
void EnQueue(int x){
	Node *temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}
void DeQueue(){
	Node *temp = front;
	if(front == NULL){
		cout<<"Error Queue is Empty\n";
		return;
	}
	else if (front == rear)
		front = rear = NULL;
	else
		front = temp->next;
	delete temp;
}
int Front(){
	if(front == NULL){
		cout<<"Error Queue is Empty \n";
		return -1;
	}
	return front->data;
}

void Print(){
	Node *temp  = front;
	cout<<"Queue :";
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

int main() {
	Queue q;
	q.EnQueue(1);
	q.EnQueue(2);
	q.EnQueue(3);
	q.EnQueue(4);
	q.Display();
	cout<<q.Front()<<"\n";
	q.DeQueue();
	q.Display();
	cout<<"===============================\n";
	EnQueue(1);
	EnQueue(2);
	EnQueue(3);
	EnQueue(4);
	Print();
	cout<<Front()<<endl;
	DeQueue();
	Print();
	return 0;
}
