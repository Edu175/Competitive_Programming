#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x=0;
	for(int i=0;i<n;i++){
		if(a[i]=="++X"||a[i]=="X++"){
			x++;
		}else{
			x--;
		}
	}
	cout<<x;
	
	return 0;
}
