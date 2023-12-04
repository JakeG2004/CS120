/*
Jake Gendreau
Linked Lists assignment

Added:
Age member to node class
setAge function as inline function
setData to set name and age as inline function
Modified print functions to include age
Added insert to end function
Added insert to start function
Added insert after name function
Added find function
*/

#include<iostream>
#include<string>
using namespace std;

class node{
    private:
        node *next;
        string name;
        int age;
    public:
        void setNext(node *n){next = n;} // inline function
        void setName(string n){name = n;}  // inline function
        void setAge(int n){age = n;}  // inline function
        void setData(int a, string n){age = a, name = n;}  // inline function
        void print(); // defined below
        void printReverse(); //defined below
        void insertEnd(int, string);
        void insertMiddle(int, string, string);
        bool find(string);
};

node* insertStart(int, string, node*);

bool node::find(string nameQuery){
    if(name == nameQuery){
        return 1;
    }
    if(next != NULL){
        return next->find(nameQuery);
    }
    return 0;
}

void node::insertEnd(int age, string name){
    //Go to next node if not at end of list
    if(next != NULL){
        next -> insertEnd(age, name);
    } else {
        node *tmp = new node();
        tmp -> setData(age, name);
        tmp -> setNext(NULL);
        next = tmp;
    }
}

void node::insertMiddle(int age, string nameInsert, string query){
    //Go to next node if not at end of list
    if(name != query){
        next -> insertMiddle(age, nameInsert, query);
    } else {
        node *tmp = new node();
        tmp -> setData(age, nameInsert);
        tmp -> setNext(next);
        next = tmp;
    }

    if(next == NULL)
        cout << "Unable to insert after " << query << endl;
}

void node::print(){
    cout << "Name: " << name << "\tAge: " << age << endl;
    if(next != NULL)
        next -> print();
}

void node::printReverse(){
    if(next != NULL)
        next -> printReverse();
    cout << "Name: " << name << "\tAge: " << age << endl;
}

int main(){

    node *head = NULL, *temp = NULL;

    head = insertStart(1, "a", head);
    head = insertStart(1, "b", head);
    head = insertStart(1, "c", head);
    head = insertStart(1, "d", head);

    //MENU

    int choice;
    int age;
    string name;
    string query;

    do {
        cout << "What would you like to do?\n"
            <<"1) Print list\n"
            <<"2) Insert new Node at end of list\n"
            <<"3) Insert new Node at start of list\n"
            <<"4) Insert new Node after name\n"
            <<"5) Find Name\n"
            <<"6) Exit Program\n";

        cin >> choice;

        switch(choice){
            case 1:
                head -> print();
                break;

            case 2:
                cout << "Age? ";
                cin >> age;
                
                cout << "Name? ";
                cin >> name;

                head -> insertEnd(age, name);
                break;

            case 3:
                cout << "Age? ";
                cin >> age;
                
                cout << "Name? ";
                cin >> name;

                head = insertStart(age, name, head);
                break;

            case 4:
                cout << "Age? ";
                cin >> age;
                
                cout << "Name? ";
                cin >> name;

                cout << "Name to insert after? ";
                cin >> query;

                head -> insertMiddle(age, name, query);
                break;

            case 5:
                cout << "Name? ";
                cin >> name;

                if((head -> find(name)) == true){
                    cout << name << " is in the list" << endl;
                    break;
                }
                cout << name << " is not in the list" << endl;
                break;
        }
    }while (choice != 6);
}

node* insertStart(int age, string name, node* head){
    node* temp;
    temp = new node();  // create a new node object
    temp -> setData(age, name); // add data
    temp -> setNext(head);
    if(head == NULL){
        temp -> setNext(NULL);  // make the next object Null
    }
    return temp;
}