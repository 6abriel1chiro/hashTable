#pragma once
#define TAM 1009
#include "List.h"

template<class T>
class Hash
{
private:
	List<T>* hash;
	int len;
public:
	Hash();
	Hash(int len);
	~Hash();

	void insertToHash(T elem);
	void deleteFromHash(T elem);
	T findInHash(T elem);

	void showHash();

	unsigned long long getNum(string text);


	unsigned long long CharToInt(char text);



	int getLen();

	int getPos(int x );
	int getPos(string x );
};



template<class T>
inline Hash<T>::Hash()
{
	len = TAM;
	hash = new List<T>[len];
}

template<class T>
inline Hash<T>::Hash(int len)
{ 
	this->len = len;
	hash = new List<T>[len];

}

template<class T>
inline Hash<T>::~Hash()
{
}

template<class T>
inline void Hash<T>::insertToHash(T elem)
{
	int index = getPos(elem);
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

		for (int i = 0; i < len; i++)
		{
			cout << i << "-> ";
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

				int character = CharToInt(text[i]);
				if (character > 99)
				{
					output *= 1000;
				}
				else if (character > 9)
				{
					output *= 100;
				}

				output += character;
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
inline int Hash<T>::getLen()
{
	return len;
}

template<class T>
inline int Hash<T>::getPos(int x)
{
	return x % len;
}

template<class T>
inline int Hash<T>::getPos(string x)
{
	int num = getNum(x);
	return num % len;
}
