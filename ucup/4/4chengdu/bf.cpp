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
		ll n,L,k; cin>>n>>L>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll m=6*n+5;
		ll res=0;
		fore(s,0,n){
			ll old=a[s];
			fore(t,0,m){
				a[s]=t;
				ll cant=0;
				fore(p,0,m){
					ll cur=0;
					fore(i,0,n)cur+=a[i]<=p&&p<a[i]+L;
					cant+=cur==k; // == !!!
				}
				res=max(res,cant);
			}
			a[s]=old;
		}
		cout<<res<<"\n";
	}
	return 0;
}
