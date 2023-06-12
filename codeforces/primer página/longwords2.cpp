#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i].size()<=10){cout<<a[i]<<"\n";
		}else{
			cout<<a[i][0]<<a[i].size()-2<<a[i][a[i].size()-1]<<"\n";
		}
	}
	return 0;
}
