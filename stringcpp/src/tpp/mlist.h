#pragma once


#include <string>
#include <iostream>
#include <array>

typedef  int Item;
typedef void visit(void (*pf)(Item&));

class Mlist {
	Item v[32];
	int size;
public:
	Mlist();
	~Mlist()
	{

	}

	void Insert(Item a);
	bool IsEmpty()const;
	bool IsFull() const;
	void Vsi(void (*pf)(Item&)) const;
};