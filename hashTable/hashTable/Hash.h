#pragma once

#include "List.h"
#include <vector>

template<class T>
class Hash
{
private:
	List<T>* hash;
	int len;
public:
	Hash(int len);
	~Hash();
	void insertToHash(int(*funcGetNumero)(T*), T* dato);
	void showHash(void (*mostrarT)(T*));
	void deleteFromHash(int(*funcGetNumero)(T*), T* dato);
	void findInHash(T* dato);
	int HashFunction(int num);
	bool find(int(*funcGetNumero)(T*), T* dato);
	void getLen(int vect[10000]);
};
