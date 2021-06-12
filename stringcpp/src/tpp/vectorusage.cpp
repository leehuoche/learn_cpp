#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int NUM = 5;


int vec11() {
	vector<int> rating(NUM);
	return 0;
}

struct Review {
	string title;
	int rating;
};

bool FillReview(Review& rr) {
	cout << "enter title ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;
	cout << "enter book rating ";
	cin >> rr.rating;
	if (!cin) {
		return false;
	}
	while (cin.get() != '\n') {
		continue;
	}
	return true;
}


void ShowReview(const Review& rr) {
	cout << rr.rating << "\t" << rr.title << endl;
}


bool operator<(const Review& r1, const Review& r2){
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating == r2.rating)
		return true;
	else
		return false;
}


bool worseThan(const Review& r1, const Review& r2) {
	if (r1.rating < r2.rating)
		return true;
	else
		return false;
}

int vec2() {
	vector<Review> books;
	Review temp;
	while (FillReview(temp)){
		books.push_back(temp);
	}
	int num = books.size();
	if (num > 0) {
		cout << "enter rating book\n";
		for (int i = 0; i < num; i++) {
			ShowReview(books[i]);
		}

		cout << "reprising:\n"
			<< "rating\tbook\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++) {
			ShowReview(*pr);
		}
		vector<Review> oldlist(books);
		if (num > 3) {
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "after erase\n";
			for (pr = books.begin(); pr != books.end(); pr++) {
				ShowReview(*pr);
			}
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "after insert\n";
			for (pr = books.begin(); pr != books.end(); pr++) {
				ShowReview(*pr);
			}
		}
		books.swap(oldlist);
		cout << "swaping \n";
		for (pr = books.begin(); pr != books.end(); pr++) {
			ShowReview(*pr);
		}
	}
	else {
		cout << "nothing entered,\n";
	}
	return 0;
}

int vec3() {
	vector<Review> books;
	Review temp;
	while (FillReview(temp)) {
		books.push_back(temp);
	}
	int num = books.size();
	if (num > 0) {
		cout << "enter rating book\n";
		for_each(books.begin(),books.end(),ShowReview);

		sort(books.begin(), books.end());
		cout << "sort by title\n";
		for_each(books.begin(), books.end(), ShowReview);


		sort(books.begin(), books.end(),worseThan);
		cout << "sort by rating\n";
		for_each(books.begin(), books.end(), ShowReview);


		random_shuffle(books.begin(), books.end());
		cout << "after shuffle\n";
		for_each(books.begin(), books.end(), ShowReview);
		
	}
	else {
		cout << "nothing entered,\n";
	}
	return 0;
}



int vmain() {
	//vec2();
	vec3();
	return 0;
}