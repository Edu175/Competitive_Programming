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
		vector<ii>a(n);
		// ll sum=0;
		fore(i,0,n)cin>>a[i].fst;//,sum+=a[i].fst;
		fore(i,0,n)cin>>a[i].snd;//,sum+=a[i].snd;
		sort(ALL(a),[&](ii a, ii b){return a.fst+a.snd>b.fst+b.snd;});
		auto get=[&](ll i){return a[i].fst+a[i].snd;};
		ll s=0,res=0;
		fore(i,0,k-1)s+=get(i);
		cout<<s<<"\n";
		fore(i,0,n){
			ll resi=max(a[i].fst,a[i].snd);
			if(i<k-1){
				resi+=s-get(i)+get(k-1);
			}
			else resi+=s;
			res=max(res,resi);
			cout<<i<<": "<<resi<<"\n";
		}
		cout<<res+1<<"\n";
	}
	return 0;
}
