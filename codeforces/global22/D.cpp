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
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll b[n];
		set<ll>st;
		vector<ll> id[n+2];
		ll x=0;
		fore(i,0,n){
			cin>>b[i];
			id[b[i]].pb(i+1);
			st.insert(b[i]);
			if(b[i]==n+1)x=n+1;
		}
		ll l=0,r=n+1;//[l,r)
		vector<ll>res;
		ll des=0;
		if(x==0)des=1;
		while(x>=0){
			if(x!=n+1&&x!=0)res.pb(x);
			ll xi=-1;
			for(auto i:id[x]){
				if(des)r=min(r,i);
				else l=max(l,i);
				if(st.count(i))xi=i;
				else res.pb(i);
			}
			x=xi;
			des^=1;
		}
		cout<<l<<"\n";
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
