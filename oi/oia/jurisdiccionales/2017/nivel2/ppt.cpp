#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string a;
	string b;
	cin>>a>>b;
	ll res=0;
	if(a[2]=='j'){
		if(b[2]=='p')res=1;
		if(b[2]=='e')res=2;
	}
	if(a[2]=='p'){
		if(b[2]=='j')res=2;
		if(b[2]=='e')res=1;
	}
	if(a[2]=='e'){
		if(b[2]=='p')res=2;
		if(b[2]=='j')res=1;
	}
	if(res){
		if(res==1)cout<<"Ana";
		else cout<<"Bartolo";
	} else cout<<"Empate";
	cout<<"\n";
	return 0;
}
