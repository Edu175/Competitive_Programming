#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

map<string,ll> dp;

bool valid(string s){
	return !(count(ALL(s),'x')<=1&&s[1]!='x');
}

ll f(string s){
	if(dp.count(s))return dp[s];
	auto &res=dp[s];
	set<ll> st;
	fore(i,0,3)if(s[i]=='x'){
		string t=s;
		t[i]='.';
		if(!valid(t))continue;
		st.insert(f(t));
	}
	ll mex=0;
	while(st.count(mex))mex++;
	return res=mex;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll xr=0;
		fore(i,0,n){
			string s; cin>>s;
			string t=s[0]=='='?s.substr(3):s.substr(0,3);
			xr^=f(t);
		}
		if(xr)cout<<"Monocarp\n";
		else cout<<"Polycarp\n";
	}
	return 0;
}