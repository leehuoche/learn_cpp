
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
// use string constructor
void string_constructor() {

	

	string one("lottery winner");
	cout << one << endl;
	string two(20, '$');

	string three(one);
	cout <<two << three << endl;
	one += " ops";
	cout << one << endl;

	two = " that was";
	three[0] = 'P';

	string four;
	four = two + three;
	cout << four << endl;

	char alls[] = " all is well,that ends well";
	string five(alls, 20);
	cout << five << endl;

	string six(alls + 6, alls + 10);
	cout << six << ',';
	string seven(&five[6], &five[10]);
	cout << seven << "...\n"<< "five is a object,so it is not ptr"<<endl;

	string eight(four, 7, 16);
	cout << eight << endl;
	



}


int read_file() {

	ifstream fin;
	fin.open("tobuy.txt");

	if (fin.is_open() == false) {
		cerr << "open fail" << endl;
		exit(EXIT_FAILURE);
	}

	string item;
	int count = 0;
	getline(fin, item, ';');
	while (fin) {
		++count;
		cout << count << ";" << item << endl;
		getline(fin, item,';');
	}

	cout << " Done\n";
	fin.close();
	return 0;

}


const int NUM = 26;
const string wordlist[NUM] = { "apiary","bettle","cereal",
"danger","ensign","florid","garage","health","insult",
"jackal","keeper","loaner","manage","nonce","onset",
"plaid","quilt","remote","stolid","train","useful",
"vaild","whence","xenon","yearn","zippy"
};

#include <ctime>
#include <cstdlib>
#include <cctype>

int hanman() {
	srand(time(0));
	char play;
	cout << " will you paly a word game<y/n>";
	cin >> play;
	while (play == 'y') {
		string target = wordlist[rand() % NUM];
		int length = target.size();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "guess my word. it has " << length
			<< " letters, and you guess\n"
			<< " one / time,you get " << guesses
			<< "  wrong guesses.\n";
		cout << " your word: " << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << " guess a letter  ";
			cin >> letter;
			if (badchars.find(letter) != string::npos ||
				attempt.find(letter) != string::npos) {
				cout << " you guess" << endl;
				continue;
			}

			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "bad guess\n";
				--guesses;
				badchars += letter;
			}
			else {
				cout << "good guess\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc!=string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "your word: " << attempt << endl;
			if (attempt != target) {
				if (badchars.size() > 0) {
					cout << " bad chars: " << badchars << endl;
				}
				cout << guesses << " bad guesse left\n";
			}
				
		}

		if (guesses > 0) {
			cout << "right\n";
		}
		else {
			cout << "wrong bye <y/n>\n";
			cin >> play;
		}
	}
	return 0;
}



void str2() {
	string empty;
	string small = "bit";
	string larger = "elephants are a girl' best friends";
	cout << "\tempty: " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "capacity \n";
	cout << "\tempty: " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	//empty.reserve(16);
	empty.resize(16);
	cout << "afer reserve 50,empty: " << empty.capacity() << endl;
}

int string_all() {
	string md = "afer reserve 50,empty:";
	cout << *md.begin() << " "<<*md.cbegin()<< " " << *md.rbegin() << " " << *md.crbegin() << endl;
	//cout << *md.end() << " " << *md.cend() << endl;
	//cout << *md.rend() << " " << *md.crend() << endl;
	cout << md.size() << " " << md.max_size() << endl;
	cout << *md.data() <<  endl;


	cout << md[2] << " " << md.at(2) << endl;
	cout << md.substr(2, 3);

	//cout << md.front() << " " << md.back() << endl;

	string cc{ 'c','d' };
	cout << cc << endl;

	string longer("that is a funny hat.");
	string shorter("hat");
	size_t loc1 = longer.rfind(shorter);
	
	size_t loc2 = longer.rfind(shorter,loc1-1);

	string shorter1("fluke");
	size_t loc3 = longer.find_first_of(shorter1);
	size_t loc4 = longer.find_first_of(shorter);

	size_t loc5 = longer.find_last_of(shorter);
	size_t loc6 = longer.find_last_of(shorter);


	shorter = "This";
	size_t loc7 = longer.find_first_not_of(shorter);
	size_t loc8 = longer.find_first_not_of("Thatch");
	return 0;
}


void str_cmp() {
	string s1("bellflower");
	string s2("bell");
	string s3("cat");

	int al3 = s1.compare(s3);
	int al2 = s1.compare(s2);

	cout << endl;
}


void str_assign() {
	string test;
	string stuf = "set tubs clones";
	test.assign(stuf, 1, 5);
	cout << test << endl;
	test.assign(6, '#');
	cout << test << endl;
}



void str_insert() {
	
	string stuf = "The banker";
	stuf.insert(4, "fromer ");
	cout << stuf << endl;
	

	stuf.erase(0, 2);
	cout << stuf << endl;
	stuf.erase(stuf.begin());
	cout << stuf << endl;
	stuf.pop_back();
	cout << stuf << endl;

	stuf.replace(1, 4, "###");
	cout << stuf << endl;

	char dst[128] = { 0 };
	stuf.copy(dst, 3, 0);
	cout << dst << endl;

	string kk(dst);
	stuf.swap(kk);
	cout << stuf << kk<< endl;
}

int main() {
	//string_constructor();
	//read_file();
	//hanman();
	//str2();
	//string_all();
	//str_cmp();
	//str_assign();
	str_insert();
	return 0;
}