#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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
		if(L[i] >= R[j]){
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
	int n_slots;
	cin >> n_slots;
	cin.ignore();

	vector <int> revenue;
	vector <int> n_clicks;

	string buffer;

	stringstream iss ;


	float value=0;
	for(int j =0; j < 2;j++){

		getline(cin,buffer);
		iss.str(buffer);
		if(j==0){
			while(iss >> value){
				revenue.push_back(value);
			}
			iss.clear();
		}
		else{
			while(iss >> value){
				n_clicks.push_back(value);
			}
		}
	}

	int Low=0;
	int High_r = revenue.size()-1;
	int High_c = n_clicks.size()-1;

	merge_sort(revenue,Low,High_r);
	merge_sort(n_clicks,Low,High_c);

	float t_revenue=0;

	for(int slot=0; slot < n_slots; slot++ ){
		t_revenue += n_clicks[slot] * revenue[slot];
	}

	cout << "Total Revenue : " << t_revenue << endl;
	return 0;
}