#include <bits/stdc++.h>
using namespace std;
int maxOccuringElement(int* a, int n, int k) {
	//2 3 3 3 4 4  3 3 3 4 5 
	int i, max;
	for(i = 0; i < n; i++) {
		a[a[k] % k] = a[a[k] % k] + k;
	}
	max = 0;	
	for(i = 0; i < n; i++) {
		if(a[max] > max)  
			max = i;
		//To Restore back orginal array
		a[i] = a[i] % k;
	}
	
	return max;
}
int main() {
	int n;
	int i;
	int* a;
	
	cout<<"How many nos you want to enter    :  ";
	cin>>n;
	a = new int[n];
	cout<<"Enter numbers  "<<endl;
	for(i = 0; i < n; i++) {
		cin>>a[i];
	}


	//Print Array
	int c= maxOccuringElement(a, n, 32);
	cout<<"Maximum occuring element is " << c<<endl;
	for(i = 0; i < n; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	delete a;
	return 0;
}
