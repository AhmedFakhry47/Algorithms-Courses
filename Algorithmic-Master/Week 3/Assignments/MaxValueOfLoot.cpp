/*
greedy algorithm to solve the classical knapsack problem
*/

#include <iostream>
#include <vector>

using namespace std;

struct knapsack{
	float value;
	float weight;
	float val_weight;
};


void merge_back(knapsack *arr,int l,int m,int r){

	int i , j , k;
	int n1 = m - l +1;
	int n2 = r - m;

	//Create a coby of left half and right half of the array in order not to miss around with original places
	knapsack L[n1], R[n2]; 

	for(i = 0 ; i < n1 ;i++){
		L[i] = arr[l + i];}

	for(j = 0; j < n2 ;j++){
		R[j] = arr[m + 1 + j];}

	i = 0;
	j = 0;
	k = l;

	while(i < n1 && j < n2){
		if(L[i].val_weight <= R[j].val_weight)
		{
			arr[k] = L[i];
			i++; }
		else{
			arr[k] = R[j];
			j++;}
		k++;}

	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;}

	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;}
}

void merge_sort(knapsack *arr,int l,int r){

	if(l < r){
		int m = l+ (r-l)/2;

		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);
		//Merge arrays back from down to top
		merge_back(arr,l,m,r);
	}
}


int main(){
	int size,t_weight;
	cin >> size >> t_weight;

	knapsack arr[size];
	float value=0.0;

	//Get Values
	int k =0;  
	for (int i=0; i < 2*size ; i++){
		if(i%2==0){
			cin >> arr[k].value;}
		else{
			cin >> arr[k].weight;
			arr[k].val_weight = arr[k].value/arr[k].weight;
			k+=1;
		}
	}


	//Sort in case not sorted
	int Low=0;
	int High=size-1;
	merge_sort(arr,Low,High);
	//Greedy Algorithm

	for (int j=size-1; j >= 0; j--){
		while(arr[j].weight !=0){
			try{
				if(t_weight <= 0){throw true;}

				arr[j].weight -=1;
				t_weight-=1;

				value += arr[j].val_weight;
				}
			catch (bool x){
				break;
			}
		}
	}	

	cout << value << endl;	
	return 0;
}
 