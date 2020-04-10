#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){

	int end;
	cin >> end;

	end %= 60;
	vector <unsigned long long int> F10;
	F10.resize(end+1);

	F10[0] = 0;
	F10[1] = 1;

	unsigned long long int result=1;
	int i=0;
	for(i =2 ; i < end+1 ; i++){
		F10[i] = pow(F10[i-1],2) + pow(F10[i-2],2);
		result+= F10[i];
	}

	cout << result %10 << endl; 
	return 0;
}