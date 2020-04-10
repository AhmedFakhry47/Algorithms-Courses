#include <iostream>
#include <vector>

using namespace std;


int get_pisano(int m){

	int previous=0;
	int current =1;
	for (int j =0; j< m*m; j++){
		previous = current;
		current  = (previous+current)%m;

		if(previous==0 && current ==1){
			return j+1;
		}
	}
}

int main(){
	long long n;
	int m;
	cin >> n >> m;

	int period = get_pisano(m);
	cout << "Period is equal to :"<<period <<endl;
	n %= period;

	vector <int> fib;	
	fib.resize(n+1);
	fib[0] =0;
	fib[1] =1;

	for (int i =2; i < n+1; i++){
		fib[i] = (fib[i-1]+fib[i-2])%m;
	}	

	cout << fib.back() <<endl;
	return 0;
}