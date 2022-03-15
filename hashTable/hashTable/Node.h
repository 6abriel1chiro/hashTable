#pragma once
#include <iostream>
using namespace std;
template <class T>
class Node
{
private:
	Node<T>* next;
	T elem;
public:
	Node(T elem, Node<T>* next);
	~Node();
	Node* getNext();
	T getElem();
	void setElem(T elem);
	void setNext(Node<T>* next);
};
template <class T>
Node<T>::Node(T elem, Node<T>* next)
{
	this->elem = elem;
	this->next = next;
}
template <class T>
Node<T>::~Node()
{

}
template <class T>
Node<T>* Node<T>::getNext()
{
	return next;
}
template <class T>
T Node<T>::getElem()
{
	return elem;
}
template <class T>
void Node<T>::setElem(T elem)
{
	this->elem = elem;
}
template <class T>
void Node<T>::setNext(Node<T>* next)
{
	this->next = next;
}