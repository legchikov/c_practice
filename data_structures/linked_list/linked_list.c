#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void append(int data);
void delete(int value);
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
    printf("Linked List:");

    is_empty_message();
    printf("Length of list: %d\n", length());

    append(1);
    append(2);
    append(5);
    append(10);
    display();
    printf("Length of list: %d\n", length());
    delete(2);
    delete(1);
    delete(5);
    display();

    is_empty_message();
    printf("Length of list: %d\n", length());

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

void delete(int value){
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
        printf("[ %d ] --> \n", current->data);
        current = current->next;
    }
    printf("[NULL]\n");
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
        printf("List is empty\n");
    } else {
        printf("List is not empty\n");
    }
}

bool is_empty(){
    return head == NULL;
}
