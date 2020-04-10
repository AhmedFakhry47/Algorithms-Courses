#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector <int> arr;
	arr.resize(n+1);

	//Initialize your fibonacci
	arr[0]=0;
	arr[1]=1;

	for (int i = 2; i < n+1 ; i++){
		arr[i] = arr[i-1]+arr[i-2];
	}

	cout << arr.back() << endl;
}