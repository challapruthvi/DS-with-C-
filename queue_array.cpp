#include<conio.h>
#include<iostream>
# define MAX 64
using namespace std;

class queuearray {
	
	private:
		int arr[MAX], front, rear;
	public:
		void init(){
			front = rear = -1;	
		}
		
		void push(int a){
			if(rear == (MAX-1)){
				cout<<"queue is overflow";
			}
			else{
				arr[++rear] = a;
			}
		}
		
		void pop(){
			if(front == rear){
				cout<<"no elements in queue";
			}
			else{
				cout<<"popped out element is"<<arr[++front]<<"\n";
			}
		}
		
		void display(){
			int i;
			for(i=front+1;i<=rear;i++){
				cout<<arr[i]<<" ";
			}
		}
};

int main(){
	int ch, data;
	queuearray q;
	q.init();
	cout<<"1.push\n";
	cout<<"2.pop\n 3.display\n 4.exit\n";
	do{
		cout<<"enter the choice";
		cin>>ch;
		switch(ch){
			case 1:
				cout<<"enter the data";
				cin>>data;
				q.push(data);
				break;
			case 2:
				q.pop();
				break;
			case 3:
				q.display();
				break;
			case 4:
				exit(0);
		}
	}while(ch<=4);
	getch();
}
