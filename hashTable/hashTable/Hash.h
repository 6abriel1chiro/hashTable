#pragma once
#define TAM 56009
#define TAMCOL 50
#include "List.h"
#include <math.h>

template<class T>
class Hash
{
private:
	List<T> hash[TAM];
public:
	Hash();
	~Hash();

	void insertToHash(T elem);
	void deleteFromHash(T elem);
	T findInHash(T elem);

	void showHash();

	unsigned long long getNum(string text);


	unsigned long long CharToInt(char text);



	int getTAM();

	int getPos(int x);
	int getPos(string x);


	void countCollisions();
};



template<class T>
inline Hash<T>::Hash()
{

}

template<class T>
inline Hash<T>::~Hash()
{
}

template<class T>
inline void Hash<T>::insertToHash(T elem)
{

	int index = getPos(elem);

	if (index <0)
	{
		index = index * -1;
	}
	hash[index].InsertFirst(elem);
}

template<class T>
inline void Hash<T>::deleteFromHash(T elem)
{
	int index = getPos(elem);
	hash[index].DeleteElem(elem);
}

template<class T>
inline T Hash<T>::findInHash(T elem)
{
	int index = getPos(elem);

	return hash[index].SearchNoRec(elem);

}

template<class T>
inline void Hash<T>::showHash()
{
	for (int i = 0; i < TAM; i++)
	{
		cout << i << " . ";
		hash[i].showList();
		cout << endl;
	}

}

template<class T>
inline unsigned long long Hash<T>::getNum(string text)
{
	unsigned long long output = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i + 1] == '\0' && i == 0)
			output += CharToInt(text[i]);
		else
		{
			if (i == 0)
			{
				output += CharToInt(text[i]);
				continue;
			}
			else
			{

				int miChar = CharToInt(text[i]);
				if (miChar > 99)
				{
					output *= 1000;
				}
				else if (miChar > 9)
				{
					output *= 100;
				}

				output += miChar;
			}


		}
	}
	return output;
}

template<class T>
inline unsigned long long Hash<T>::CharToInt(char text)
{
	unsigned long long output;
	output = text;
	return output;
}

template<class T>
inline int Hash<T>::getTAM()
{
	return TAM;
}

template<class T>
inline int Hash<T>::getPos(int x)
{
	return x % TAM;
}

template<class T>
inline int Hash<T>::getPos(string x)
{
	int num = getNum(x);
	return num % TAM;
}

template<class T>
inline void Hash<T>::countCollisions()
{
	int boxes[TAMCOL];

	// TODO EN 0
	for (int i = 0; i < TAMCOL; i++)
	{
		boxes[i] =0;
	}

	for (int i = 0; i < TAM; i++)
	{
		int nElements = hash[i].countElements();
		boxes[nElements] = boxes[nElements]+1;
	}

	for (int i = 0; i < TAMCOL; i++)
	{
		cout << i <<" : "<< boxes[i] << endl;
	}

}
