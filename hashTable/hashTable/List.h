#pragma once
#include "Node.h"
template <class T>
class List
{
private:
	Node<T>* first;
	Node<T>* last;
	int len;
public:
	List();
	~List();
	int getlen();
	void InsertFirst(T elem);
	void InsertLast(T elem);
	bool DeleteFirst();
	void showList(void (*f)(T*));
	void showList();
	bool DeleteLast();
	bool DeleteElem(T Elem);
	void ordenar(bool (comparar)(T*, T*));
	T SearchNoRec(T elem);
	T SearchRec(T elem, int pos);
	T SearchPos(int pos);
	T operator[](int pos);

	int countElements();

	Node<T>* getFirst();
	Node<T>* getLast();

};
template <class T>
List<T>::List()
{
	first = NULL;
	last = NULL;
	len = 0;
}
template <class T>
List<T>::~List()
{

}
template <class T>
int List<T>::getlen()
{
	return len;
}
template <class T>
void List<T>::InsertFirst(T elem)
{
	Node<T>* aux;
	if (first == NULL)
	{
		first = new Node<T>(elem, NULL);
		last = first;
	}
	else
	{
		aux = new Node<T>(elem, first);
		first = aux;
	}
}


template <class T>
void List<T>::InsertLast(T elem)
{
	Node<T>* aux;
	if (first == NULL)
	{
		first = new Node<T>(elem, NULL);
		len++;
	}
	else
	{
		aux = first;
		while (aux->getNext() != NULL)
		{
			aux = aux->getNext();
		}
		aux = new Node<T>(elem, NULL);
	}
}
template <class T>
bool List<T>::DeleteFirst()
{
	bool res;
	if (first == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (first == last) // 1 elemento
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			Node<T>* aux;
			aux = first->getNext();
			delete first;
			first = aux;
			first->setNext(aux);
		}
	}
	return res;
}
template <class T>
T List<T>::SearchRec(T elem, int pos)
{
	T* value = NULL;
	Node<T>* aux = first;
	if (*aux->getElem() == elem)
	{
		value = aux->getElem();
	}
	else if (aux != NULL)
	{
		SearchRec(elem, pos + 1);
		aux = aux->getNext();
	}
	return value;
}
template <class T>
void List<T>::showList(void (*f)(T*))
{
	Node<T>* aux = first;
	if (first == NULL)
	{
		cout << "Empty List";
	}
	while (aux != NULL)
	{
		(*f)(aux->getElem());
		aux = aux->getNext();
	}
}
template <class T>
void List<T>::showList()
{
	Node<T>* aux = first;

	while (aux != NULL)
	{
		cout << aux->getElem() << endl;
		aux = aux->getNext();
	}
}
template <class T>
T List<T>::SearchNoRec(T elem)
{
	Node<T>* aux = first;
	while (aux != NULL)
	{
		if (aux->getElem() == elem)
		{
			return aux->getElem();
		}
		aux = aux->getNext();
	}
	return NULL;
}
template <class T>
T List<T>::SearchPos(int pos)
{
	int posS = 0;
	Node<T>* aux = first;
	while (aux != NULL)
	{
		if (posS == pos)
		{
			return aux->getElem();
		}
		aux = aux->getNext();
		posS++;
	}
	return NULL;
}
template <class T>
T List<T>::operator[](int pos)
{
	int posS = 0;
	Node<T>* aux = first;
	while (aux != NULL)
	{
		if (posS == pos)
		{
			return aux->getElem();
		}
		aux = aux->getNext();
		posS++;
	}

}
template <class T>
void List<T>::ordenar(bool (comparar)(T*, T*))
{
	Node<T>* primer = first;
	Node<T>* aux = NULL;
	T* auxEncon;
	while (primer != NULL)
	{
		aux = primer->getNext();

		while (aux != NULL)
		{
			if ((*comparar)(primer->getElem(), aux->getElem()))
			{
				auxEncon = aux->getElem();
				aux->setElem(primer->getElem());
				primer->setElem(auxEncon);
			}
			aux = aux->getNext();
		}
		primer = primer->getNext();
	}

}
template <class T>
bool List<T>::DeleteLast()
{
	bool res;
	if (first == NULL)
	{
		res = false;
	}
	else
	{
		res = true;
		if (first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			Node<T>* aux = first;
			while (aux->getNext()->getNext() != NULL)
			{
				aux = aux->getNext();
			}
			delete last;
			last = aux;
			last->setNext(NULL);
		}
	}
	return res;
}

template <class T>
bool List<T>::DeleteElem(T elemento)
{
	bool result = false;
	if (first == NULL)
	{
		result = false;
	}
	else
	{
		if (first->getElem() == elemento)
		{
			result = DeleteFirst();
		}
		else if (last->getElem() == elemento)
		{
			result = DeleteLast();
		}
		else
		{
			Node<T>* aux = first;
			while (aux->getNext()->getElem() != elemento && aux->getNext() != last)
			{
				aux = aux->getNext();
				if (aux->getNext() == last && aux->getNext()->getElem() == elemento)
				{
					delete aux->getNext();
					last = aux;
					last->setElem(NULL);
					result = true;
				}
				else
				{
					if (aux->getNext()->getElem() == elemento)
					{
						Node<T>* ayuda = aux->getNext()->getNext();
						delete aux->getNext();
						aux->setNext(ayuda);
						result = true;
					}
				}
			}
		}
	}
	return result;
}


template <class T>
int List<T>::countElements()
{
	int counter = 0;
	Node<T>* aux = first;
	if (first == NULL)
	{
		cout << "Empty List";
	}
	while (aux != NULL)
	{
		counter++;
		aux = aux->getNext();
	}
	return counter;
}

template<class T>
inline Node<T>* List<T>::getFirst()
{
	return first;
}

template<class T>
inline Node<T>* List<T>::getLast()
{
	return last;
}
