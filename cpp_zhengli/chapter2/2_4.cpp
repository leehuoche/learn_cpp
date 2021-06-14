#include <iostream>
using namespace std;
int main(){
	int day;
	cin>>day;
	switch(day){
	case 0:
		cout<<"sunday"<<endl;
		break;
	case 1:
		cout<<"monday"<<endl;
		break;
	case 2:
		cout<<"tuesday"<<endl;
		break;
	case 3:
		cout<<"wednesday"<<endl;
		break;
	case 4:
		cout<<"thursday"<<endl;
		break;
	case 5:
		cout<<"friday"<<endl;
		break;
	case 6:
		cout<<"saturday"<<endl;
		break;
	default:
		cout<<"day out of range sunday...saturday"<<endl;
		break;
	}
	return 0;
}
