/*
Faster mplementation of the pairwise algorithm 
*/
#include <iostream>
#include <vector>
using namespace std;

long long pairwise_fast(vector <int> &numbers_seq){
	int max_indx=-1;
	int smax_indx=-1;

	for(int i=0 ; i< numbers_seq.size();i++){
		if(numbers_seq[i]>numbers_seq[max_indx]){
		 	max_indx=i;
		}
	}

	for(int j=0 ; j <numbers_seq.size();j++){
		if(numbers_seq[j]>numbers_seq[smax_indx] && (j != max_indx)){
			smax_indx=j;
		}
	}

	return (long long) numbers_seq[max_indx]*numbers_seq[smax_indx];
}
int main(){
	int n;

	cin >>n;

	vector <int> numbers_seq;
	numbers_seq.resize(n);
	
	for (int i=0; i < n ;i++){
		cin >> numbers_seq[i];
	}

	long long result = pairwise_fast(numbers_seq);
	cout << result;

	return 0;
}
