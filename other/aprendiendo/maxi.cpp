#include<bits/stdc++.h>

using namespace std;
int maxi(int x,int y){
	int res;
	if(x>y){
		res=x;
	}else {
		res=y;
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int m=a[0];
	for(int i=0;i<n;i++){
		m=maxi(m,a[i]);
	}
	cout<<m;
	
	return 0;
}

