#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,t,p;
	p=0;
	cin>>n;
	int a[n*3];
	for(int i=0;i<n;i++){
		t=0;
		for(int i=0;i<3;i++){
		cin>>a[i];
		if(a[i]==1){
			t+=1;
		}
		}
		if(t>=2){
			p+=1;
		}
	}
	cout<<p;
	
	return 0;
}
