#include<conio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

// Node Declaration

struct node{
	int data;
	node *next;
}*start;

// Class Declaration

class singlelinkedlist{
		public:
			singlelinkedlist(){
				start = NULL;	
			}	
			node* create_node(int);
			void insert_begin();
			void insert_end();
			void insert_pos();
			void delete_pos();
			void display();
			void update();
			void sort();
			void search();
};

// creating a node

node *singlelinkedlist::create_node(int a){
	node *temp = new node;
		if(temp == NULL){
			cout<<"memory not allocated"<<endl;
			return 0;
		}else{
			temp->data = a;
			temp->next = NULL;
			return temp;
		}
	}

// Insert element at the Begin

void singlelinkedlist::insert_begin(){
	int data;	
	cout<<"enter the element to be inserted:"<<endl;
	cin>>data;
	struct node *temp, *save;
	temp = create_node(data);
		if(start == NULL){
			start = temp;
			start->next = NULL;
		}else{
			save = start;
			start = temp;
			start->next = save;
		}
	cout<<"element is inserted at beginning"<<endl;
}

// Insert element at the End

void singlelinkedlist::insert_end(){
		int data;
		cout<<"enter the element to be inserted:"<<endl;
		cin>>data;
		struct node *temp, *save;
		temp = create_node(data);
		save = start;
			if(save->next != NULL){
				save = save->next;
			}
	//	temp->next = NULL;
		save->next = temp;
		cout<<"element is inserted at the end"<<endl;
}

// Insert element at a particular position

void singlelinkedlist::insert_pos(){
		int data, pos, count=0;
		cout<<"enter the position where the element to be inserted:"<<endl;
		cin>>pos;
		cout<<"enter the element to be inserted:"<<endl;
		cin>>data;
		struct node *temp, *save, *ptr;
		temp = create_node(data);
		save = start;
			while(save != NULL){
				save = save->next;
				count++;
			}
			if(pos == 1){
				if(start == NULL){
					start = temp;
					start->next = NULL;
				}else{
					ptr = start;
					start = temp;
					start->next = ptr;
				}
			}else if(pos > 1 && pos <=count){
				save = start;
				for(int i=1;i<pos;i++){
					ptr = save;
					save = save->next;
				}
				ptr->next = temp;
				temp->next = save;
			}else{
				cout<<"position is out of range"<<endl;
			}
}

// Delete an element from a particular position

void singlelinkedlist::delete_pos(){
		int pos, count=0;
		if(start == NULL){
			cout<<"the list is empty"<<endl;
		}
		cout<<"enter the position of value to be deleted"<<endl;
		cin>>pos;
		struct node *s, *temp;
		s = start;
		if(pos == 1){
			start = s->next;
		}
		else{
			while(s != NULL){
				s = s->next;
				count++;
			}
			if(pos > 1 && pos <= count){
				s = start;
				for(int i=1;i<pos;i++){
					temp = s;
					s = s->next;
				}
				temp->next = s->next;
			}
			else{
				cout<<"position is out of range"<<endl;
			}
			free(s);
			cout<<"element is deleted"<<endl;
		}
}

// display the elements

void singlelinkedlist::display(){
	struct node *temp;
	if(start == NULL){
		cout<<"the linked list is empty"<<endl;	
	}
	temp = start;
	cout<<"the elements in the linkedlist are:"<<endl;
	while(temp != NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

// update a particular element in the list

void singlelinkedlist::update(){
		int value, pos, i;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node postion to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->data = value; 
    }
    else
    {
    	for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->data = value;  
    }
    cout<<"Node Updated"<<endl;
} 

// sorting the linkedlist

void singlelinkedlist::sort(){
	struct node *ptr, *s;
    int value;
    if (start == NULL)
    {
        cout<<"The List is empty"<<endl;
        return;
    }
    ptr = start;
    while (ptr != NULL)
    {
        for (s = ptr->next;s !=NULL;s = s->next)
        {
            if (ptr->data > s->data)
            {
                value = ptr->data;
                ptr->data = s->data;
                s->data = value;
            }
        }
        ptr = ptr->next;
    }
}

// search particular element in the list

void singlelinkedlist::search(){
	int data, pos=0;
	bool flag = false;
	if(start == NULL){
		cout<<"list is empty"<<endl;
	}
	cout<<"enter the element to be searched"<<endl;
	cin>>data;
	struct node *s;
	s = start;
	while(s != NULL){
		pos++;
		if(s->data == data){
			flag = true;
			cout<<"The entered element is found at:"<<pos<<endl;
		}
		s = s->next; 
		}
		// if(!flag)
		cout<<"The entered element is not in the list"<<endl;
	}

int main(){
	int ch;
    singlelinkedlist sl;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert Node at beginning"<<endl;
        cout<<"2.Insert node at last"<<endl;
        cout<<"3.Insert node at position"<<endl;
        cout<<"4.Sort Link List"<<endl;
        cout<<"5.Delete a Particular Node"<<endl;
        cout<<"6.Update Node Value"<<endl;
        cout<<"7.Search Element"<<endl;
        cout<<"8.Display Linked List"<<endl;
        cout<<"9.Exit "<<endl;
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            sl.insert_begin();
            cout<<endl;
            break;
        case 2:
            sl.insert_end();
            cout<<endl;
            break;
        case 3:
            sl.insert_pos();
            cout<<endl;
            break;
        case 4:
            sl.sort();
            cout<<endl;
            break;
        case 5:
            sl.delete_pos();
            break;
        case 6:
            sl.update();
            cout<<endl;
            break;
        case 7:
            sl.search();
            cout<<endl;
            break;
        case 8:
            sl.display();
            cout<<endl;
            break;
        case 9:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}



