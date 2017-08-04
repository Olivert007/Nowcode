#include <iostream> 
#include <vector> 
#include <string>
#include <queue>
#include <stack>
using namespace std;

int maxres(int length) {
	if (length == 1)return 0;
	if (length == 2)return 1;
	if (length == 3)return 2;

	int* res = new int[length+1];
	int max = 0, tmp = 0;
	res[0] = 0; 
	res[1] = 1; 
	res[2] = 2; 
	res[3] = 3;
	for (int i = 4; i <= length; i++) {
		//max = 0;
		for (int j = 1; j <= i / 2; j++) {
			tmp = res[j] * res[i - j];
			if (tmp > max)
				max = tmp;
			res[i] = max;
		}
	}
	max = res[length];
	delete []res;
	return max;
}

int   main()
{
	int length;
	while (cin >> length) {
		cout << maxres(length) << endl;
	}
	getchar();
	return 0;
}
