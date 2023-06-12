#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		string s=a[i];
		int v=0;
		for(int i=0;i<s.size()/2;i++){
			if(s.size()%2!=0){
				break;
			}
			if(s[i]==s[i+s.size()/2]){
				v++;
			}
		}if(v==s.size()/2&&s.size()!=1){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}
