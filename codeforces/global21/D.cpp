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
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv ma(n),me(n);
		for(ll i=n-1;i>=0;i--){
			for(ma[i]=i+1;ma[i]!=n&&!(a[i]<a[ma[i]]);ma[i]=ma[ma[i]]);
			for(me[i]=i+1;me[i]!=n&&!(a[i]>a[me[i]]);me[i]=me[me[i]]);
		}
		auto get_nxt=[&](ll p, vv &ma, vv &me){
			ll r=me[p],q=ma[p];
			while(ma[q]<r)q=ma[q];
			return q;
		};
		ll res=0;
		for(ll p=0;p<n-1;){
			res++;
			if(a[p+1]>a[p])p=get_nxt(p,ma,me);
			else p=get_nxt(p,me,ma);
		}
		cout<<res<<"\n";
	}
	return 0;
}
