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
		ll n,k; cin>>n>>k;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<ii>ev;
		fore(i,0,n)ev.pb({a[i],0}),ev.pb({b[i],1});
		sort(ALL(ev));
		ll q=n,neg=0,res=0;
		fore(i,0,SZ(ev)){
			if(i==0||ev[i].fst!=ev[i-1].fst){
				if(neg<=k)res=max(res,q*ev[i].fst);
			}
			if(ev[i].snd)neg--,q--;
			else neg++;
			
		}
		cout<<res<<"\n";
	}
	return 0;
}
