#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j, k, result, count, tmp;
	int* a;
	int* p1;
	int* p2;
	result = 0;
	count = 0;
	cout<<"How many numbers you want to enter  :   ";
	cin>>n;
	a = new int[n];
	cout<<"Start entering nos :  ";
	for(i = 0; i < n; i++) {
		cin>>a[i];
		result = result ^ a[i];
	}
	result;
	while(result) {
		if( (result & 1) == 1) {
//			cout<<count<<"th bit is set"<<endl;
			break;
		}
		count++;
		result >>= 1;
	}

	p1 = new int[n];
	p2 = new int[n];
	int no = (1 << count);	//no is number having kth bit set
	cout<<"no is "<<no<<endl;
	for(i = 0, j = 0, k = 0; i < n; i++) {
		if((a[i] & no) == no) {
			//kth bit is set. put it into 1st partition
			p1[j++] = a[i];
		}
		else {
			p2[k++] = a[i];
		}
	}
	result = 0;
	for(i = 0; i < j; i++) {
		result = result ^ p1[i];
	}
	int n1 = result;
	result = 0;
	for(i = 0; i < k; i++) {
		result = result ^ p2[i];
	}
	int n2 = result;
	cout<<"No with odd occurences are "<<n1 << " and "<<n2<<endl;
	delete a;
	delete p1;
	delete p2;
	return 0;
}
