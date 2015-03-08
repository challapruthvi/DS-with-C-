#include<iostream>
#include<conio.h>
# define MAX 10
using namespace std;

class Stack {
	private:
		int top, num, a[MAX];
	public:
		void init();
		void push(int);
		void pop();
		void display();
		void count();
};

void Stack::init(){
	top == -1;
}

void Stack::push(int num){
	if(top== MAX-1){
		cout<<"\nstack is full";
		return;
	} else
	{
		top++;
		a[top]=num;
	}
}

void Stack::pop(){
	if(top<0){
		cout<<"stack is empty";
		return;
	}else{
		cout<<"\n popped out element is:"<<a[top];
		top--;
	}
}

void Stack::display(){
	cout<<"the elements are:";
	for(int i=top;i>=0;i--)
	{
		cout<<a[i]<<"\t";
	}
}

void Stack::count(){
	cout<<"the number of elements in the stack";
	cout<<(top+1);
}

int main(){
	int data, ch;
	Stack s;
	s.init();
	cout<<"---------------------";
	cout<<"\n1.push operation";
	cout<<"\n2.pop operation";
	cout<<"\n3.display operation";
	cout<<"\n4.count";
	cout<<"\n5.exit";
	do {
		cout<<"\nenter the choice";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"enter element to be inserted";
				cin>>data;
				s.push(data);
				break;
			case 2:
				s.pop();
				break;
			case 3:
				s.display();
				break;
			case 4:
				s.count();
				break;
			case 5:
				exit(0);
			default:
				cout<<"wrong choice";
		}		
	}while(ch!=5);
	getch();
}
