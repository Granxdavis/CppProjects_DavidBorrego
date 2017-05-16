#pragma once



class  Mylist
{
public:

	struct node
	{
		int data;
		node* next;
		node* previus;

	};
	
	node* first;
	node* last;


	 Mylist();
	 Mylist(Mylist &x);
	~ Mylist();

	bool isempty();
	int Size();

	
private:
	int size;
};


 

 //Constructor por defecto, por copia, y el destructor