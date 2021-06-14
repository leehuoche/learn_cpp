#include<fstream>
#include<cstring>
#include <iostream>
using namespace std;
struct SalaryInfo
{
	unsigned id;
	double salary;

};

int main() {
	SalaryInfo employee1 = { 600001,8000 };
	ofstream os("payroll", ios_base::out | ios_base::binary);
	os.write(reinterpret_cast<char*>(&employee1), sizeof(employee1));
	os.close();


	ifstream is("payroll", ios_base::in | ios_base::binary);
	if (is) {
		SalaryInfo employee2;
		is.read(reinterpret_cast<char*>(&employee2), sizeof(employee2));
		cout << employee1.id << " " << employee2.salary << endl;

	}
	else
		cout << "error:cannot open" << endl;
	is.close();


	return 0;

}
