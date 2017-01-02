#include <iostream>
#include <stdlib.h>

using namespace std;

void append(int data);
void display();

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *next = NULL;

int main(){
    cout << "Hello Linked List" << endl;
    append(1);
    append(2);
    append(5);
    display();
    
    cin.clear();
    cin.get();
    return 0;    
}

void display(){
    struct node *ptr = head;
    cout << "\n";

    while(ptr != NULL){
        cout << "[" <<ptr->data << "] --> ";
        ptr = ptr->next;
    }

    cout << "[NULL]";
}

void append(int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;
    link->next = NULL;

    if(head == NULL){
        head = link;
        return;
    }
    
    struct node *current = head;

    while(current->next != NULL){
        current = current->next;
    }
    current->next = link;
}