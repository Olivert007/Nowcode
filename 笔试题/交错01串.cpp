//https://www.nowcoder.com/question/next?pid=6291726&qid=112730&tid=9915152
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	int static count = 0;
	vector<int> res;
	if (s.size() == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < s.size()-1; i++) {
		int a = s[i];
		int b = s[i + 1];//1 ascii is 49, 0 is 48
		if (a + b == 97) {
			count++;
			res.push_back(count + 1);
		}
		else
		{
			res.push_back(count);
			count = 0;
		}
	}

	vector<int>::iterator max = max_element(res.begin(), res.end());
	if (*max == 0) {
		cout << 1;
	}
	else
		cout << *max;

	system("pause");
	return 0;
}
