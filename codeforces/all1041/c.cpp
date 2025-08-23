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
		ll n,asd; cin>>n>>asd;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst;
		ll fij=0;
		fore(i,0,n){
			cin>>a[i].snd;
			if(a[i].snd<a[i].fst)swap(a[i].snd,a[i].fst);
			fij+=a[i].snd-a[i].fst;
		}
		sort(ALL(a));
		ll mn=5e9;
		fore(i,0,n-1){
			mn=min(mn,a[i+1].fst-a[i].snd);
		}
		mn=max(mn,0ll);
		ll res=fij+2*mn;
		cout<<res<<"\n";
	}
	return 0;
}
