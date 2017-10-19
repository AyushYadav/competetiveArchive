#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int count=n;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(j*i>n)count++;
		}
	}
	cout << count << endl;
	return 0;
}