#include <iostream>
using namespace std;
int main(){
	

	int array2[3][3]={{11,12,13},{5,1,80},{20,50,1}};
	cout<<"matrix test:"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<*(array2[i]+j)<<" ";
	cout<<endl;
	}
	return 0;
}