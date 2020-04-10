/*
Dynamic Programming Approach to solve the changing money probem.
*/
#include <iostream>
#include <vector>
#include <limits>

using namespace std;


int main(){

	int arr[] = {1,3,4};
	int arr_size = sizeof(arr)/sizeof(arr[0]);

	int number;
	cin >> number;
	cin.ignore();

	vector <int> lcp(number+1); //Least Change Possible

	lcp[0] = 0;
	lcp[1] = 1;

	int least_change=INT32_MAX;
	
	//Time complexity O(nm)
	for(int j=2; j< lcp.size(); j++){
		for(int k=0 ; k < arr_size ; k++){
			if(j >= arr[k]){
				if((lcp[j-arr[k]] + 1) < least_change){
					least_change = lcp[j-arr[k]] +1;
				}			
			}
		}

		lcp[j] = least_change;
		least_change=INT32_MAX;
	}

	cout << lcp.back() << endl;
	return 0;
}