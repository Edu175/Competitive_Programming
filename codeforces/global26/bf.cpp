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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		set<string> st;
		ll n=SZ(s);
		fore(l,0,n)fore(r,l+1,n+1){
			ll z=r-l;
			string t=s.substr(l,z);
			if(t=="a")continue;
			vv can(n+1); can[n]=1;
			for(ll i=n-1;i>=0;i--){
				if(s[i]=='a')can[i]|=can[i+1];
				if(s.substr(i,z)==t)can[i]|=can[i+z];
			}
			if(can[0])st.insert(t);
		}
		cout<<SZ(st)<<"\n";
	}
	return 0;
}
