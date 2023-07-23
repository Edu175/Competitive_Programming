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
		ll n; cin>>n;
		vector<ii> a(n); //fst < snd
		fore(i,0,n){
			cin>>a[i].fst>>a[i].snd;
			if(a[i].snd<a[i].fst)swap(a[i].fst,a[i].snd);
		}
		sort(ALL(a));
		ll u=a[n-1].fst;
		ll res=1e9+5;
		fore(i,0,n){
			ll r1=abs(u-a[i].fst),r2=abs(u-a[i].snd);
			if(i<n-1)res=min({res,r1,r2});
			swap(a[i].fst,a[i].snd);
		}
		sort(ALL(a)); //fst > snd
		fore(i,0,n){
			if(a[i].fst>=u){
				if(i)res=min(res,abs(a[i].fst-a[i-1].fst));
				if(i<n-1)res=min(res,abs(a[i].fst-a[i+1].fst));
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
