#include <iostream>
#include <stdlib.h>

using namespace std;

void append(int data);
void display();
bool is_empty();
void is_empty_message();

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *next = NULL;

int main(){
    cout << "Linked List:" << endl;

    is_empty_message();

    append(1);
    append(2);
    append(5);
    display();
    
    is_empty_message();
    
    cin.clear();
    cin.get();
    return 0;    
}

void display(){
    struct node *ptr = head;

    while(ptr != NULL){
        cout << "[" <<ptr->data << "] --> ";
        ptr = ptr->next;
    }
    cout << "[NULL]" << endl;
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

void is_empty_message(){
    if(is_empty()){
        cout << "List is empty" << endl;
    } else {
        cout << "List is not empty" << endl;
    }
}

bool is_empty(){
    return head == NULL;
}