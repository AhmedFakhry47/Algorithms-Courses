#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

float nano = sqrt(-1);

int isnan(float number){
	if(number == nano){
		return 1;
	}
	else{
		return -1;
	}
}

void swap(int *first,int *second){
	int temp = *first;

	*first = *second;
	*second=  temp;
	return;
}

void sort(vector <int> &weights,vector <int> &values){

	int size = values.size();

	for (int i = 0 ; i < size ; i++ ){
		int min = i;
		float val_weight = 0; 	
		float current_val_weight = (float)values[min]/weights[min];

		for (int j=i+1 ; i < 3 ;j++ ) {
			val_weight = (float)values[j]/weights[j];

			if(isnan(val_weight) == 1)
				cout<<"true"<<endl;

			}
			cout << val_weight << endl;
			if(val_weight < current_val_weight){
				min = j;
				current_val_weight = (float)values[min]/weights[min];
				if(isnan(current_val_weight) == 1)
					cout<<"true"<<endl;		
				cout << current_val_weight << endl;
			}

		if(min != i){
			swap(&values[i],&values[min]);
			swap(&weights[i],&weights[min]);
		}
	}
}

int main(){

	int n;
	cin >> n;

	vector <int> weights;
	vector <int> values;

	int value =0;

	for(int i=0; i< 2*n ; i++){
		cin >> value;
		if(i%2 ==0){weights.push_back(value);}
		else{values.push_back(value);}
	}

	//vector <int> A;
	//int V;

	sort(weights,values);

	for(int j=0; j< 3;j++){
		cout << values[j] <<' ';
	}
	cout << endl;
	for(int j=0; j< 3;j++){
		cout<< weights[j] <<' ';
	}
	cout << endl;
	
	//V,A  = greedy(W,items);
}