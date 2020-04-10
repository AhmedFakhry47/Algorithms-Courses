#include <iostream>
#include <vector>

using namespace std;


int main(){

	cout << "Fibonacci --Last Digit Cycle every 60 elements--" <<endl;
	cout << "Enter a number : ";
	int n;
	cin >> n;

	vector <int> arr;
	arr.resize(n+1);

	//Initialize your fibonacci
	arr[0]=0;
	arr[1]=1;

	for (int i = 2; i < n+1 ; i++){
		arr[i] = (arr[i-1]+arr[i-2])%10;
	}

	cout << "element number :" << arr.back() << endl;
	cout << "Whole series " << endl;

	for (int j =0; j< n+1; j++){
		cout << arr[j] << ' ';
	}
	cout << endl;
	return 0;
}