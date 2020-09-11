#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, i, result;
	int* a;
	result = 0;
	cout<<"How many numbers you want to enter  :   ";
	cin>>n;
	a = new int[n];
	cout<<"Start entering nos :  ";
	for(i = 0; i < n; i++) {
		cin>>a[i];
		result = result ^ a[i];
	}
	cout<<"No with odd occurence is "<<result<<endl;
	delete a;
	return 0;
}
