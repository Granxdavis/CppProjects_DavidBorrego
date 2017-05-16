#include "MiLista.h"
#include <list>


Mylist::Mylist() {
	size = 0;
	first = nullptr;
	last = nullptr;



}


Mylist::Mylist(Mylist &x) {
	
	Mylist temp = x;
	

	while (temp.first != temp.last)
	{
		node* y = new node;
		y = x.first;
		y = y->next;
		y = temp.first->next;
		temp.first = temp.first->next;

	}
	size = x.Size();

}


Mylist::~Mylist()
{
	node* tmp;//Para guardar el siguiente
	while (!isempty()) {//mientras que en la lista haya algo elimina el primero
		if (first->next != nullptr) {
			tmp = first->next;
			delete first;
			first = tmp;
			size--;
		}
	}

}

bool Mylist::isempty() {

	if (first == nullptr) {//Comprueba si el primero es nullptr
		return true;
	}
	return false;
}


int Mylist::Size() {

	/*int num = 0;
	node* temp = first;//Guardar donde apunta el primer elemento
	while (first != last) {
		first = first->next;
		num++;	
	}
	first = temp;//Volver a apuntar al primero*/


	return size;

}


int main() {


	return 0;
}