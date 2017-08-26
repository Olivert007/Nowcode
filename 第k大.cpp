#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& s, int l, int r)
{
	if (l< r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];
			while (i < j && s[i]< x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}

int FindNumK(vector<int> ary, int k) {
	quickSort(ary,0,ary.size()-1);
	return ary[ary.size()-k];
}

int findK(vector<int> A, int n, int k)
{
	for (int i = 0; i < k; i++)
		for (int j = n - 1; j > 0; j--)
			if (A[j] > A[j - 1])
			{
				int temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
	return A[k - 1];

}


int main()
{
	vector<int> ary;
	int a;
	while (cin >> a && getchar() != '\n') {
		ary.push_back(a);
	}
	ary.push_back(a);
	
	//do {
	//	cin >> a;
	//	ary.push_back(a);
	//} while (getchar() != '\n');
	
	//int n = ary.size();
	int k;
	cin >> k;
	cout << FindNumK(ary,k);
	system("pause");
	return 0;
}
