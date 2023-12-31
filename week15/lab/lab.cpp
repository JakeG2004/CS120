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
    bool isInList(node*, string);
    string nthItem(node*, int);
    
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

        cout << "Total Value: " << totalValue(head) << endl;

        cout << isInList(head, "mop") << endl;

        cout << nthItem(head, 3) << endl;
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

bool isInList(node* head, string itemQ){
    if(head -> item == itemQ)
        return 1;
    if(head -> next != NULL)
        return isInList(head -> next, itemQ);
    return 0;
}

string nthItem(node* head, int pos){
    if(pos == 0)
        return head -> item;
    if(head -> next == NULL && pos > 0)
        return "N exceeds size of list";
    return(nthItem(head -> next, pos - 1));
}
