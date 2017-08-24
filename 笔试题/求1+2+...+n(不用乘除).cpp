#include<iostream>
#include<vector>
using namespace std;
//Solution1
class Sums {
public:
	Sums() {
		n++;
		sum += n;
	}
	static int Getsum() {
		return sum;
	}
	static void Setsum() {
		sum = 0;
		n = 0;
	}

private:
	static int n;
	static int sum;
};
int Sums::n = 0; 
int	Sums::sum = 0;

//Solution2
class A {
public:
	virtual int SumV(int n) {
		return 0;
	}
};

A* Array[2];

class B :public A {
public:
	virtual int SumV(int n) {
		return Array[!!n]->SumV(n - 1) + n;
	}
};

//Solution3
typedef int (*fun)(int);
fun f[2];
int Teminator(int n) {
	return 0;
}
int SumP(int n) {
	f[0] = Teminator;
	f[1] = SumP;
	return n + f[!!n](n - 1);//还是用!!n替代if进行判断
}

int main() {
	int n;
	cin >> n;

	//Solution1
	Sums::Setsum();
	Sums* ob = new Sums[n];
	delete ob;
	cout <<"Constructor: "<< Sums::Getsum() << endl;

	//Solution2
	A a;
	B b;
	Array[0] = &a;
	Array[1] = &b;
	int value = Array[1]->SumV(n);
	cout << "Virtual: " << value << endl;

	//Solution3
	cout << "Function pointer: " << SumP(n) << endl;

	getchar();
	getchar();
	return 0;
}
