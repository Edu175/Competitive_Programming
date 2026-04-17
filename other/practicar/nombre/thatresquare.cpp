#include<bits/stdc++.h>

using namespace std;
int divtecho(int a,int b){
	int res;
	if(a/b*b==a){
		res=a/b;
	}else{
		res=a/b+1;
	}
	return res;
}
int main(){
	int n,m,a;
	cin>>n>>m>>a;
	//cout<<divtecho(n,m);
	int p;
	p=divtecho((n*m),(a*a));
	if(p%2!=0){
		p+=1;
	}
	cout<<p;
		
	return 0;
}
