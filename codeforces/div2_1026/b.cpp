#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool is(string s){
	ll c=0;
	for(auto i:s){
		if(i=='(')c++;
		else c--;
		if(c<0)return 0;
	}
	assert(!c);
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		reverse(ALL(s));
		s.pop_back();
		reverse(ALL(s));
		// s.erase(s.begin());
		s.pop_back();
		if(is(s))cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
