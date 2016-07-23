#include <iostream>

using namespace std;

int main() {
	int a=10, b=12;

	//cout << "lambda geenrated sum is - " << [a,b] (int x, int y) { return a+b;} << endl;
	auto f = [a,b] (int x=10, int y=20) { return (a+b < x+y)? a+b : x+y;} ;

	cout << "lambda geenrated sum is - " << f() << endl;
	return 0;
}
