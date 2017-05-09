#pragma once

#include <iostream>
#include <stack>
#include <list>

class  Mystack
{

	struct node
	{
		int data;
		node* next;
	};

	node* first;
public:
	Mystack();
	~Mystack();
	Mystack(const Mystack &x);
	Mystack(int* &array);

	void pop();
	void push(int element);
	void front(int primero);
	void isempty(bool vacio);
	void size(int tamaño);

};
