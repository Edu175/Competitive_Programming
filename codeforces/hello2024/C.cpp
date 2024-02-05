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
const ll INF=2e5+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>b[2];
		b[0]=b[1]={INF};
		ll res=0;
		fore(i,0,n){
			if((a[i]>b[0].back())^(a[i]>b[1].back())){
				if(a[i]<=b[0].back())b[0].pb(a[i]);
				else b[1].pb(a[i]);
			}
			else {
				res+=(a[i]>b[0].back());
				if(b[0].back()<=b[1].back())b[0].pb(a[i]);
				else b[1].pb(a[i]);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
