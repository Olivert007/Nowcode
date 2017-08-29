#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<int> MaxWindow(vector<int> num, int width) {
	vector<int> res;
	deque<int> index;
	for (int i = 0; i < width; i++) {
		while (!index.empty() && num[i] > index.back()) {
			index.pop_back();//当前输入的数如果比之前的大，则先把前面小的先删掉
		}
		index.push_back(i);//输入的是下表号
	}
	for (int i = width; i < num.size(); i++) {
		res.push_back(num[index.front()]);

		while (!index.empty() && num[i] > index.back()) {
			index.pop_back();//当前输入的数如果比之前的大，则先把前面小的先删掉
		}
		if (!index.empty() && (i - index.back()) >= width) {
			index.pop_front();
		}
		index.push_back(i);
	}
	res.push_back(num[index.front()]);
	return res;
}

int main() {
	vector<int> ary = { 2,3,4,2,6,2,5,1 };
	int width = 3;
	vector<int> res = MaxWindow(ary, width);
	for (auto c : res)
		cout << c << " ";
	system("pause");
	return 0;
}
