#include <iostream>
#include<list>
using namespace std;

int getLastNum(int n, int m) {
	if (n < 0 || m < 0)
		return -1;
	list<int> myls;
	for (int i = 0; i < n; i++) {
		myls.push_back(i);
	}
	list<int>::iterator it = myls.begin();
	while (myls.size() > 1) {

		for (int i = 1; i < m; i++) {
			it++;
			if (it == myls.end())
				it = myls.begin();
		}
		list<int>::iterator next = ++it;
		if (next == myls.end())
			next = myls.begin();

		it--;
		myls.erase(it);
		it = next;
	}
	return *(it);
}

int main()
{
	int n, m;
	cin >> n >> m;
	cout << getLastNum(n, m) << endl;

	system("pause");
	return 0;
}
