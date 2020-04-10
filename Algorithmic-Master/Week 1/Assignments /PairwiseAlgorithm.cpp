/*
Implementation of the bad algorithm from computation perspective.
*/

#include <iostream>
#include <vector>
using namespace std;

long long pairwise_max(vector <int> numbers_seq){
	long long result = 0;

	for (int i =0; i < numbers_seq.size();i++){
		for (int j =0; j < numbers_seq.size();j++){
			if ( i == j){continue;}

			if ((long long) numbers_seq[i]*numbers_seq[j] > result){
				result = (long long ) numbers_seq[i]*numbers_seq[j];
			} 
		}
	}

	return result;
}

int main(){
	int n;

	cin >>n;

	vector <int> numbers_seq;
	numbers_seq.resize(n);
	
	for (int i=0; i < n ;i++){
		cin >> numbers_seq[i];
	}

	long long result = pairwise_max(numbers_seq);
	if (result == 0){
		cout << " All elements are zeros !" << endl;
	}
	else {
		cout << result;
	}
	return 0;
}