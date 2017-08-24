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

int FindNumber(vector<int> ary, int length) {
	vector<int> sum(32);
	int bit = 1;
	for (int i = 31; i >= 0; i--) {
		for (int j = 0; j < length; j++) {
			if ((ary[j] & bit) == bit) {
				++sum[i];
			}
		}
		bit = bit << 1;
	}
	int res_tmp = 0;
	int res = 0;
	for (int i = 0; i <32; ++i) {
		res = res << 1;
		res += sum[i]%3;
	}
	return res;
}


int main() {
	int length;
	length = 7;
	vector<int> ary = { 1, 1, 2, 2, 2, 1, 3 };
	cout << FindNumber(ary,ary.size()) << endl;
	system("pause");
	return 0;
}
