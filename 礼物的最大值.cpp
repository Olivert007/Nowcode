#include<iostream>
#include<algorithm>
using namespace std;

int MaxGift(const int* values, int rows, int cols) {
	if (values == nullptr || rows <= 0 || cols <= 0)
		return 0;
	int* *MaxValue = new int*[rows];
	for (int i = 0; i < rows; i++) {
		MaxValue[i] = new int[cols];
	}
	//int up = 0, left = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int up = 0, left = 0;
			if (i > 0)
				up = MaxValue[i - 1][j];
			if (j > 0)
				left = MaxValue[i][j - 1];
			MaxValue[i][j] = max(up, left) + values[i*cols+j];
		}
	}
	int res = MaxValue[rows - 1][cols - 1];
	for (int i = 0; i < rows; i++)
		delete[]MaxValue[i];
	delete[]MaxValue;
	return res;
}

//1, 2, 3
//4, 5, 6
//7, 8, 9
int main() {
	int values[][3] = {
		1,2,3,4,5,6,7,8,9
	};
	cout<<MaxGift(*values, 3, 3);

	system("pause");
	return 0;
}
