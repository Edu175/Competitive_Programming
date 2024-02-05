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
		ll n,k,m; cin>>n>>k>>m;
		vector<ll>c(k);
		ll w=k;
		string s; cin>>s;
		string b;
		fore(i,0,m){
			if(c[s[i]-'a']==0)w--;
			c[s[i]-'a']=1;
			if(w==0)b.pb(s[i]),c=vector<ll>(k,0),w=k;
		}
		fore(i,0,k)if(!c[i]){b.pb('a'+i);break;}
		while(SZ(b)<n)b.pb('a');
		if(SZ(b)>n)cout<<"YES\n";
		else cout<<"NO\n"<<b<<"\n";
	}
	return 0;
}
