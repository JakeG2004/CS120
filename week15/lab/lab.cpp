#include<iostream>

using namespace std;
struct node{
    string item;
    int value;
    node *next;
};

    void printnode(node);
    void printlist(node *);
    void addtail(node *,node *);
    int totalValue(node*);
    
    int main(){
        node *temp,*head;
        temp = new node;
        temp->item = "torch";
        temp->value = 5;
        temp->next = NULL;
        head = temp;
        printlist(head);
        cout << endl;

        temp = new node;
        temp->item = "candle stick";
        temp->value = 20;
        temp->next = head;
        head = temp;
        printlist(head);
        cout << endl;

        temp = new node;
        temp->item = "mop";
        temp->value = 2;
        temp -> next = head;
        head = temp;
        printlist(head);
        cout << endl;

        temp = new node;
        temp -> item = "T-Bone Steak";
        temp -> value = 50;
        temp -> next = head;
        head = temp;
        printlist(head);
        cout << endl;

        temp = new node;
        temp->item = "soap";
        temp->value = 2;
        addtail(head,temp);
        printlist(head);
        cout << endl;

        temp = new node;
        temp->item = "toast";
        temp->value = 2;
        addtail(head,temp);
        printlist(head);

        cout << "Total Value: " << totalValue(head) << endl;;
}

void printnode(node n){
    cout << "Item: " << n.item;
    cout << " worth " << n.value << endl;
}

void printlist(node *p){
    printnode(*p);
    if(p->next != NULL){
        printlist(p->next);
    }
}

void addtail(node *current, node *add){
    if(current->next == NULL){ // at tail
        current->next = add;
    } else {
        addtail(current->next,add);
    }
}

int totalValue(node* head){
    static int value;
    if(head -> next  != NULL){
        totalValue(head -> next);
    }
    value += head -> value;
    return value;
}
