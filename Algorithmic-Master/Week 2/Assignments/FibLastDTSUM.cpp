#include <iostream>
#include <vector>

using namespace std;

int main(){

	int n ;
	cin >> n;

	int pisano_period = 60;
	n %= pisano_period;

	vector <int> F10;
	F10.resize(n+1);
	F10[0] = 0;
	F10[1] = 1;

	int result = 1;
	for (int i =2; i<n+1 ; i++){
		F10[i] += (F10[i-1] + F10[i-2])%10;
		result += F10[i];
	}
	result %=10;
	cout << result << endl;
}