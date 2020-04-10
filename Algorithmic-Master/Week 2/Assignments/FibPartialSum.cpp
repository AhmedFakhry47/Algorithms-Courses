#include <iostream>
#include <vector>

using namespace std;

int main(){

	int begin,end;
	cin >> begin >> end;


	int pisano_period = 60;

	begin %= pisano_period;
	end   %= pisano_period;

	vector <int> F10;
	F10.resize(end);

	F10[0] = 0;
	F10[1] = 1;

	int result =0;
	for(int i =2 ; i < end+1 ; i++){
		F10[i] = (F10[i-1] + F10[i-2])%10;

		if(i >= begin){
			result += F10[i];
		}
	}

	cout << (result %10) << endl; 
	return 0;
}