/*
classical money change problem & The solution using greedy algorithm
*/

#include <iostream>
#include <vector>

using namespace std;


int main(){
	int arr[] = {10,5,1};	// It should be sorted before though
	int size = sizeof(arr)/sizeof(arr[0]);

	int n ;
	cin >> n;

	int n_coins = 0;

	for(int i=0; i < size ; i++){
		
		while (n>=arr[i]){
			n -= arr[i];
			n_coins +=1;
		}
	} 
	cout << n_coins << endl;;
}