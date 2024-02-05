#include<bits/stdc++.h>

using namespace std;
long long divtecho(int a,int b){
	int res;
	if(a/b*b==a){
		res=a/b;
	}else{
		res=a/b+1;
	}//(a+b-1)/b
	return res;
}
int main(){
	int n,m,a;
	cin>>n>>m>>a;
	//cout<<divtecho(n,m);
	cout<<divtecho(n,a)*divtecho(m,a);
	
	return 0;
}
