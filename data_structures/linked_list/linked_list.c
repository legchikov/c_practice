#include <iostream>
#include <stdlib.h>

using namespace std;

void append(int data);
void remove(int value);
void display();
int length();
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
    cout << "Length of list: " << length() << endl;

    append(1);
    append(2);
    append(5);
    append(10);
    display();
    remove(2);
    remove(1);
    remove(5);
    display();

    is_empty_message();
    cout << "Length of list: " << length() << endl;

    cin.clear();
    cin.get();
    return 0;    
}

void append(int data){
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if(head == NULL){
        head = new_node;
        return;
    }

    struct node *current = head;
    while(current->next != NULL)
        current = current->next;

    current->next = new_node;
}

void remove(int value){
    struct node *current = head;
    struct node *prev = NULL;

    while(current != NULL){
        if(current->data == value){
            if(prev == NULL)
                head = current->next;
            else 
                prev->next = current->next;
            return;
        } else {
            prev = current;
            current = current->next;
        } 
    }
}

void display(){
    struct node *current = head;

    while(current != NULL){
        cout << "[" <<current->data << "] --> ";
        current = current->next;
    }
    cout << "[NULL]" << endl;
}

int length(){
    struct node *current = head;
    int length = 0;

    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
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