/*
testing both algorithms [ Results and Computation time] 
*/
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

long long pairwise_fast(vector <int> numbers_seq){
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

	while(true)
	{
		int n = rand()%1000 +2;
		cout << " Size of vector is: " << n <<endl;
		vector <int> numbers_seq;
		
		for (int i=0; i < n ;i++){
			numbers_seq.push_back(rand()%100000);
			cout<<numbers_seq[i] << ' ';
		}
		cout <<endl;
		long long result0 = pairwise_fast(numbers_seq);
		long long result1 = pairwise_max(numbers_seq);

		if (result0==result1){
			cout <<"Ok\n";
		}
		else{
			cout <<"Wrong Answer: "<< result0 << ' ' << result1 << "\n"; 
			break;
		}	
	}
	
	return 0;
}