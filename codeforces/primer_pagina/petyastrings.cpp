#include<bits/stdc++.h>

using namespace std;

int main(){
	int p=0;
	string a;
	string b;
	cin>>a>>b;
	for(int i=0;i<a.size();i++){
		if(a[i]<=90){a[i]+=32;}
		if(b[i]<=90){b[i]+=32;}
		
		if(a[i]<b[i]){
			p=-1;
			i=a.size();
		}if(b[i]<a[i]){
			p=1;
			i=a.size();
		}
	}
	cout<<p;
	return 0;
}
