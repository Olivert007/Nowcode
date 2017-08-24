#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string& s1, string& s2) {
	string str1 = s1 + s2;
	string str2 = s2 + s1;
	return str1 < str2;
}

void MinCombination(vector<int> ary, int length) {
	vector<string> sary(length);
	
	for (int i = 0; i < length; i++) {
		stringstream ss;
		ss << ary[i];
		ss >> sary[i];
	}
	sort(sary.begin(), sary.end(), compare);
	for (int i = 0; i < length; i++) {
		cout << sary[i];
	}
	cout << endl;
}

int main() {
	int length;
	cin >> length;
	//int* ary = new int[length];
	vector<int> ary(length);
	for (auto &c : ary)
		cin >> c;

	MinCombination(ary, length);

	system("pause");
	return 0;
}
