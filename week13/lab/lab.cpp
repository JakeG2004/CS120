#include<iostream>
#include<string>
using namespace std;

class node{
    private:
        node *next;
        string name;
    public:
        void setnext(node *n){next = n;} // inline function
        void setdata(string n){name = n;}  // inline function
        void print(); // defined below
        void printReverse();
};

void node::print(){
    cout << name << endl;
    if(next != NULL)
        next -> print();
}

void node::printReverse(){
    if(next != NULL)
        next -> printReverse();
    cout << name << endl;
}

int main(){

    //Add Sally
    node *head, *temp;  // pointers to a node object
    temp = new node();  // create a new node object
    temp -> setdata("Sally"); // add data
    temp -> setnext(NULL);  // make the next object Null
    head = temp;           // make head point to the beginning of the list

    //Add Fred
    temp = new node();  // create another new node object
    temp -> setdata("Fred"); // add data
    temp -> setnext(head); // 'point' the new object to the beginning of the list
    head = temp;          // make head point to the new beginning of the list

    //Add Anne
    temp = new node();    // repeat
    temp -> setdata("Anne");
    temp -> setnext(head);
    head = temp;

    //Add Alan
    temp = new node();    // repeat
    temp -> setdata("Alan");
    temp -> setnext(head);
    head = temp;

    //Get how many bobs to add
    int numBob;
    cout << "Enter how many bobs you would like in the list\n> ";
    cin >> numBob;

    //Add bobs
    for(int i=0; i<numBob; i++){
        temp = new node();    // repeat
        temp -> setdata("Bob " + to_string(i+1));   //Give Bobs a unique name
        temp -> setnext(head);
        head = temp;
    }

    //Print results
    head->print();       // print the list
    cout << "\nNow reverse\n\n";
    head->printReverse();
}

