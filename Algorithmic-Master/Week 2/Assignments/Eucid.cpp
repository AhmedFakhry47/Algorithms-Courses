#include <iostream>

using namespace std;

int GCD(int n1,int n2)
{
	if (n2==0){
		return n1;
	}
	int q = n1/n2;
	int r = n1%n2;
	return GCD(n2,r);
}
int main(){

	int n1,n2;
	cin >> n1 >> n2;
	int result = GCD(n1,n2);
	cout <<result <<endl;
}