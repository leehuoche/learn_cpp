#include <iostream>
using namespace std;
enum GameResult {WIN,LOSE,TIE,CANCEL};
int main(){
	GameResult result;
//	enum GameResult omit=CANCEL;
	for(int count=WIN;count<=CANCEL;count++){
		result=GameResult(count);
		if(result==CANCEL)
			cout<<"the game is canceled"<<endl;
		else{
			cout<<"the game is playing ";
			if(result==WIN)
				cout<<"we won";
			if(result==LOSE)
				cout<<"we lost";
			cout<<endl;
		}
	}
	return 0;
}



