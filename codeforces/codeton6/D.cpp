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
		vector<ll>c(n);
		fore(i,0,n)cin>>c[i];
		ll k; cin>>k;
		vector<ii>a;
		fore(i,0,n){
			while(SZ(a)&&c[i]<=a.back().fst)a.pop_back();
			a.pb({c[i],i});
		}
		a.pb({1e10,0});
		vector<ll>res(n+1);
		fore(i,0,SZ(a)-1){
			//cout<<i<<": "<<k<<"\n";
			ll l=0,r=k/a[i].fst;
			while(l<=r){
				ll m=(l+r)/2;
				if((k-m*a[i].fst)/a[i+1].fst+m==k/a[i].fst)r=m-1;
				else l=m+1;
			}
			res[a[i].snd]+=l;
			k-=l*a[i].fst;
		}
		//cout<<k<<"\n";
		for(ll i=n-1;i>=0;i--){
			res[i]+=res[i+1];
		}
		fore(i,0,n)cout<<res[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
