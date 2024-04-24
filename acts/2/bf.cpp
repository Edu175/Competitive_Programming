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

pair<ll,ii> crit(ll m, ll n){// period m, length n
	return {n/m,{n%m,m}};
}
pair<ll,ii> maxi(pair<ll,ii>a, pair<ll,ii>b){
	if(a.fst!=b.fst)return max(a,b);
	if(a.snd.fst*b.snd.snd>b.snd.fst*a.snd.snd)return a;
	return b;
}
int main(){FIN;
	string a; cin>>a;
	ll n=SZ(a);
	pair<ll,ii> res={1,{0,1}};
	fore(l,0,n){
		ll m=1;
		fore(r,l+1,n){
			if(a[r]!=a[r-m])m=r-l+1;
			res=maxi(res,crit(m,r-l+1));
		}
	}
	ii r={res.fst*res.snd.snd+res.snd.fst,res.snd.snd};
	ll g=gcd(r.fst,r.snd);
	r.fst/=g,r.snd/=g;
	cout<<r.fst<<"/"<<r.snd<<"\n";
	return 0;
}
