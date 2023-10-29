#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		s.pb('a'-1);
		ll k; cin>>k; k--;
		vector<pair<char,ll>>p;
		vector<ll>ix;
		fore(i,0,n+1){
			while(SZ(p)&&s[i]<p.back().fst)ix.pb(p.back().snd),p.pop_back();
			p.pb({s[i],i});
		}
		ll w=0,ni=n;
		while(k>=ni)k-=ni,ni--,w++;
		vector<ll>vis(n);
		fore(i,0,w)vis[ix[i]]=1;
		string res;
		fore(i,0,n)if(!vis[i])res.pb(s[i]);
		cout<<res[k];
	}
	cout<<"\n";
	return 0;
}
