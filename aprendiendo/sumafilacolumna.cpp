#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int res=0;
		for(int j=0;j<m;j++){
			res+=a[i][j];
		}
		cout<<res<<" ";
	}
	cout<<"\n";
	for(int j=0;j<m;j++){
		int res=0;
		for(int i=0;i<n;i++){
			res+=a[i][j];
		}
		cout<<res<<" ";
	}
	
	return 0;
}

