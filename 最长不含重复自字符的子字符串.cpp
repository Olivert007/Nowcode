#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int LongestSentence(const string& str) {
	vector<int> eachLong(str.size());
	eachLong[0] = 1;
	vector<int> appearPos(26, -1);//表示这个字母之前出现的位置
	appearPos[str[0] - 'a']=0;//第一个字母出现在第0位
	for (int i = 1; i < str.size(); i++) {
		if (appearPos[str[i] - 'a'] == -1)//Not appears before
			eachLong[i] = eachLong[i - 1] + 1;
		else {
			int d = i - appearPos[str[i] - 'a'];
			appearPos[str[i] - 'a'] = i;
			if (d <= eachLong[i - 1])
				eachLong[i] = d;
			else
				eachLong[i] = eachLong[i - 1] + 1;
		}
		appearPos[str[i] - 'a'] = i;//record position of each letter
	}
	int res= *max_element(eachLong.begin(), eachLong.end());
	return res;
}

int main() {
	string str;
	cin >> str;
	cout << LongestSentence(str) << endl;
	system("pause");
	return 0;
}
