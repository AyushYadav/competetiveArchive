#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a=5;
	int k=1+log2(a);
    int mask=(1<<k) -1
    a= a^mask;
	cout << a << endl;
	return 0;
}