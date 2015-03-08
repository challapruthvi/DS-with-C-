#include<conio.h>
#include<iostream>
using namespace std;

class linkedlist{
	
	struct node{
		int data;
		node *next;
	}*rear, *front, *temp, *rem, *p;
	
	public:
		linkedlist(){
			rear = front = NULL;
		}	
		
		void push(){
			int d;
			cout<<"enter the data";
			cin>>d;
		    temp = new node;
		    temp->data=d;
		    temp->next= NULL;
		    if(front == NULL){
		    	front = temp;
			}else{
				rear->next = temp;
			}
			rear = temp;
		}
		
		int pop(){
			if(front == NULL){
				cout<<"no elements are there in the queue";
			}else{
				rem = front;
				front = front->next;
				cout<<"deleted element is:"<<rem->data;
			}
		}
		
		int display(){
			p = new node;
			p = front;
			if(front == NULL){
				cout<<"no elements are there to be displayed";
			}else{
				while(p!= NULL){
					cout<<p->data<<" ";
					p = p->next;
				}
			}
		}
};

int main(){
	int ch;
	linkedlist l;
	cout<<"---------------\n";
	cout<<"1.push\n 2.pop\n 3.display\n 4.exit\n";
	cout<<"---------------\n";
	do{
		cout<<"enter the choice:";
		cin>>ch;
		switch(ch){
			case 1:
				l.push();
				break;
			case 2:
				l.pop();
				break;
			case 3:
				l.display();
				break;
			case 4:
				exit(0);
	}
	}while(ch<=4);
	getch();
}
