//https://www.nowcoder.com/question/next?pid=6291726&qid=112724&tid=9909496
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> NumOfEach(26);
	for (int i = 0; i < s.size(); i++) {
		if (s[i]<'A' || s[i]>'Z') {
			cout << 0;
			return 0;
		}
		int index = s[i];
		NumOfEach[index-65]++;
	}
	int count = 0;
	for (int i = 0; i < 26; i++) {
		if (NumOfEach[i] != 0)
			count++;
	}
	
	if (count == 0)
		cout << 0;
	if (count == 1)
		cout << 1;
	if (count == 2)
		cout << 2;
    if (count>2)
        cout<<0;

	system("pause");
	return 0;
}
