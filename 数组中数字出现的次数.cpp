#include<iostream>
#include<vector>
using namespace std;

bool isBit1(int a,int pos) {
	a=a >> pos;
	return (a & 1);
}

unsigned int FindFirst1(int a) {//找到最右边一位的1
	int pos = 0;
	cout << "sizeof(int): " << sizeof(int)<<endl;
	while ((a & 1) == 0)  {
		a = a >> 1;
		++pos;
	}
	return pos;
}

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

void FindNumber(vector<int> ary, int length, int &num0, int& num1) {
	int XORnum = 0;
	for (int i = 0; i < length; i++) {
		XORnum ^= ary[i];
	}
	int index = FindFirstBitIs1(XORnum);
	cout << index << endl;
	int index_my = FindFirst1(XORnum);
	cout << index_my << endl;
	for (int i = 0; i < length; i++) {
		if (isBit1(ary[i], index))
			num1 ^= ary[i];
		else
			num0 ^= ary[i];
	}
}


int main() {
	int length;
	//cin >> length;
	//vector<int> ary(length);
	//for (auto &c : ary)
	//	cin >> c;
	length = 8;
	vector<int> ary = { 2,4,3,6,3,2,5,5 };

	int num0 = 0, num1 = 0;
	FindNumber(ary, length, num0, num1);
	cout << "It's " << num0 << " " << num1 << endl;
	system("pause");
	return 0;
}
