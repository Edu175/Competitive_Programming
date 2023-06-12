#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int s=0;
	for(int i=0;i<n;i++){
		if(a[i]%2==0&&i%2==1){
			s+=a[i];
		}
	}
	cout<<s;
	return 0;
}
