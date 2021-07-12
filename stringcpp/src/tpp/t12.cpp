#include <string>
#include <iostream>
#include <array>
using namespace std;


class Cow {
	char name[20];
	char* hobby;
	double weight;
public:
	Cow() {
		memset(name, 0, 20);
		hobby = NULL;
		weight = 0;
	}
	Cow(const char* nm, const char* ho, double wt) {
		strncpy(name, nm, 20);
		hobby = new char[strlen(ho) + 1];
		strcpy(hobby, ho);
		weight = wt;
	}
	Cow(const Cow& c) {
		strncpy(name, c.name, 20);
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
		weight = c.weight;
	}
	~Cow()
	{
		delete[] hobby;
	}
	Cow& operator=(const Cow& c) {
		if (this == &c) {
			return *this;
		}

		strncpy(name, c.name, 20);
		delete[] hobby;
		hobby = new char[strlen(c.hobby) + 1];
		strcpy(hobby, c.hobby);
		weight = c.weight;
		return *this;
	}
	void ShowCow() const {
		cout << "show" << endl;
	}

};



void TestCow() {
	Cow a("a", "b", 10);
	a.ShowCow();
	Cow b("a1", "b1", 10);;
	b= a;

	b.ShowCow();
}






#include "string2.h"

int t2()
{
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3;

	cout << s2;
	s3="Fretta Farbo";
	s2 = "My name is " + s3;
	cout << s2 << endl;
	s2 = s2 + s1;
	s2.stringup();
	cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it" << endl;
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow();
		for (int i = 0; i < 3; ++i)
		{
			if (ans == rgb[i])
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again!" << endl;
	}
	cout << "Bye!" << endl;
	return 0;
}

void main12() {
	//TestCow();
	t2();
}