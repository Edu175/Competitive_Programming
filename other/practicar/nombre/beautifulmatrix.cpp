#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	int a[n][m];
	int p=0;
	int q=0;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>a[i][j];
			if(a[i][j]==1){
				p=i+1;q=j+1;
				//cout<<i<<" "<<j<<"\n";
			}
		}
	}
	//cout<<p<<" "<<q<<"\n";
	if(p<=3){
		p=3-p;
	}else{
		p=p-3;
	}
	if(q<=3){
		q=3-q;
	}else{
		q=q-3;
	}
	//cout<<p<<" "<<q<<"\n";
	cout<<p+q;
	
	return 0;
}

