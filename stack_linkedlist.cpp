#include<conio.h>
#include<iostream>
using namespace std;

class linkedlist {

struct node {
	int data;
	node *next;
}*top,*temp, *first;

public:
	
linkedlist(){
	top = NULL;
}

void push(){
	int d;
	cout<<"enter the data";
	cin>>d;
	first = new node;         // node *first = new node; // 
	first->data = d;
	first->next = top;
	top = first; 
}

int pop(){
	if(top == NULL){
		cout<<"satck is empty";
	}
	temp = top;          // node *temp = top; //
	top = temp->next;
	cout<<"deleted element is:"<<temp->data;
}

int display(){
	first = top;        // node *first = top; // 
	while(first != NULL){
		cout<<"\n"<<first->data;
		first = first->next;
	}
}
};

int main(){
	int ch;
	
	linkedlist l;
	cout<<"---------------------";
	cout<<"\n1.push operation";
	cout<<"\n2.pop operation";
	cout<<"\n3.display operation";
	cout<<"\n4.exit";
	do {
		cout<<"\nenter the choice";
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
			default:
				cout<<"wrong choice";
		}		
	}while(ch!=4);
	getch();
}
