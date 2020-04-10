#include <iostream>
#include <vector>

using namespace std;

struct all{
	int min_number = INT32_MAX;
	vector <int> n_inway;
};

int main(){

	int arr[] = {0,1,2};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	int number;
	cin >> number;

	vector <all> n_operations(number+1);

	n_operations[0].min_number=0;
	n_operations[0].n_inway.push_back(0);

	n_operations[1].min_number=0;
	n_operations[1].n_inway.push_back(1);

	for(int j=2 ; j <= number+1 ; j++ ){
		if(j-1 >=0){
			n_operations[j].min_number = (n_operations[j-1].min_number)+1 ;
		}

		if((j % 2) ==0 ){
			if(n_operations[j/2].min_number+1 < n_operations[j].min_number){
				n_operations[j].min_number = (n_operations[j/2].min_number)+1	;
			}

		}

		if((j%3) ==0 ){
			if(n_operations[j/3].min_number+1 < n_operations[j].min_number){
				n_operations[j].min_number = (n_operations[j/3].min_number)+1	;
			}
		}
	}

	cout << n_operations.back().min_number << endl;
	return 0;
}