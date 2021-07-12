

#include "mlist.h"
using namespace std;




Mlist::Mlist() {
	size = 0;
}
void Mlist::Insert(Item a) {
	v[size++] = a;
}

bool Mlist::IsEmpty() const{
	return size == 0;
}

bool Mlist::IsFull()const {
	return size == 32-1;
}

void Mlist::Vsi(void (*pf)(Item&))const {
	for (auto i : v) {
		pf(i);
	}
}