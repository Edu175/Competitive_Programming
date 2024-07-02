#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	string s; cin>>s;
	ll c[2]={0,0};
	for(auto i:s){
		c['a'<=i&&i<='z']++;
	}
	if(c[1]>c[0]){
		for(auto &i:s)i=tolower(i);
	}
	else {
		for(auto &i:s)i=toupper(i);
	}
	cout<<s<<"\n";
	return 0;
}
