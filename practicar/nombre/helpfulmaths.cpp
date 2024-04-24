#include<bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin>>s;
	s.erase(remove(s.begin(), s.end(), '+'), s.end());
	sort(s.begin(),s.end());
	for(int i=0;i<s.size();i++){
		cout<<s[i];
		if(i==s.size()-1){
			break;
		}
		cout<<'+';
	}
	return 0;
}
