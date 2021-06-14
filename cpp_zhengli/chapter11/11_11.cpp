#include <iostream>
using namespace std;
#include<fstream>


int main() {
	
	ifstream file("integers", ios_base::in | ios_base::binary);
	if (file) {
		int v, i = 8;
		file.read(reinterpret_cast<char*>(&v), sizeof(int));
		cout << "ok" << endl;
		if (file&&v==0)
			cout << "position is: " << i<<"is 0"<< endl;	

	}
	else
		cout << "error:cannot open" << endl;
	file.close();
	return 0;

}
