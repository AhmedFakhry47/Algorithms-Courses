/**
A comparison between different solrting algorithms
**/

#include <iostream>
#include <vector>

using namespace std;

void swap(int *first,int *second){
	int temp = *first;

	*first = *second;
	*second=  temp;
	return;
}

//Time complexity O(n^2) --> Nested Loop
void bubble_sort(vector<int> &items){
	int vec_size = items.size();

	for (int i =0; i < vec_size ; i++){
		bool flag = false;

		for (int j=0; j < vec_size-1 ; j++){
			if(items[j] > items[j+1]){
				swap(&items[j],&items[j+1]);
				flag= true;
			}
		}
		if(flag == false){
			break;
		}
	}
	return;
}

//Worst case time complexity O(n^2)
void insertion_sort(vector <int> &items){
	int vec_size = items.size();

	for (int i=1; i < vec_size ; i++){
		int value_to_insert  = items[i];
		int current_position = i;

		while (current_position >0 && items[current_position-1] > value_to_insert){
			items[current_position] = items[current_position-1];
			current_position -=1 ;
		}	

		items[current_position] = value_to_insert;
	}
	return ;
}


//Time complexity worse case O(n^2)
void selection_sort(vector <int> &items){
	int vec_size = items.size();

	for(int i =0;i<vec_size;i++){
		int min = i;

		for(int j =i+1; j<vec_size;j++){
			if(items[j] < items[min]){
				min = j;	
			}
		}
		
		if (min != i){
			swap(&items[min],&items[i]);
		}
	}
}

void merge_back(vector <int> &arr,int l,int m,int r){

	int i , j , k;
	int n1 = m - l +1;
	int n2 = r - m;

	//Create a coby of left half and right half of the array in order not to miss around with original places
	int L[n1], R[n2]; 

	for(i = 0 ; i < n1 ;i++){
		L[i] = arr[l + i];
	}
	for(j = 0; j < n2 ;j++){
		R[j] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = l;


	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++; 
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j<n2){
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(vector <int> &arr,int l,int r){

	if(l < r){
		int m = l+ (r-l)/2;

		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);

		//Merge arrays back from down to top
		merge_back(arr,l,m,r);
	}
}


int main(){
	int value = 0;
	int n ;
	cin >> n;

	vector<int> items;

	for (int i=0; i < n; i++){
		cin >> value;
		items.push_back(value);
	}

	int Low = 0;
	int High= items.size()-1;

	merge_sort(items,Low,High);

	for (int j=0; j < n; j++){
		cout << items[j] <<' ';
	}
	cout<<endl;
	return 0;
}
