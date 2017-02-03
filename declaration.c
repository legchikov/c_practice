/*
Приоритеты:
1. Скобки, объединяющие части объявления.
2. Постфиксные операторы: круглые скобки (),
   обозначающие функцию, и квадратные [], обозначающие массив.
3. Префиксный оператор: звёздочка *, обозначающая указатель.

char foo;
char *foo;
char foo[5];
char* foo[5];
char(*foo)[5];
char* (*foo)[5];
char* foo(char*);
char* (*foo)(char*);
char* (*foo[5])(char*);
char* (*(*foo[5])(char*))[];
*/

#include <stdio.h>

int main(int argc, char const *argv[]) {
  char(* foo)[5];
  // foo - это...
  // foo - это указатель на...
  // foo - это указатель на массив из пяти...
  // foo - это указатель на массив из пяти символов
  // foo is a pointer to an array of five chars

  char* (*foo)(char*);
  // foo - это...
  // foo - это указатель на...
  // foo - это указатель на функцию, принимающую указатель на символ...
  // foo - это указатель на функцию, принимающую указатель на символ, возвращающую указатель на...
  // foo - это указатель на функцию, принимающую указатель на символ, возвращающую указатель на символ
  // foo is a pointer to a function that accepts a pointer to a char and returns a pointer to a char

  char* (*(*foo[5])(char*))[];
  // foo - это...
  // foo - это массив из 5...
  // foo - это массив из 5 указателей на...
  // foo - это массив из 5 указателей на функцию, принимающую указатель на символ...
  // foo - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на...
  // foo - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на массив из...
  // foo - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на массив из указателей на...
  // foo - это массив из 5 указателей на функцию, принимающую указатель на символ и возвращающую указатель на массив из указателей на символ
  // foo is an array of 5 pointers to a function that accepts a pointer to a char and returns a pointer to an array of pointers to a char.

  return 0;
}