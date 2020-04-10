#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int last_digit(int number){
	return number%10;
}

int first_digit(int number){

	while(number >=10){
		number /=10;
	}
	return number;
}

void modified_merge_back(vector <int> &arr,int l,int m,int r){

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

	int cont1;
	int cont2;
	int last1;
	int last2;

	while(i < n1 && j < n2){
		cont1 = first_digit(L[i]);
		cont2 = first_digit(R[j]);

		if(cont1 > cont2){
			arr[k] = L[i];
			i++; 
		}
		else if (cont1 == cont2){
			last1= last_digit(L[i]);
			last2= last_digit(L[j]);

			if(last1 > last2){
				arr[k] = L[i];
				i++;
			}
			else{
				arr[k] = R[j];
				j++;
			} 
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
		modified_merge_back(arr,l,m,r);
	}
}

int main(){

	int n;
	cin >> n;
	cin.ignore();

	vector <int> numbers;

	string buffer;
	getline(cin,buffer);
	istringstream iss(buffer); 

	float value=0;
	while(iss >> value){
		numbers.push_back(value);
	}

	int Low=0;
	int High= numbers.size()-1;
	merge_sort(numbers,Low,High);

	int t_number;
	//Gready Algorithm 
	for (int j=0; j < n; j++){
		cout <<numbers[j];
	}
	cout << endl;;
	return 0;
}