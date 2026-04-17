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
typedef int ll;
typedef long long LL;
typedef pair<LL,LL> ii;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
pair<ll,ii> crit(ll m, ll n){// period m, length n
	return {n/m,{n%m,m}};
}
pair<ll,ii> maxi(pair<ll,ii>a, pair<ll,ii>b){
	if(a.fst!=b.fst)return max(a,b);
	if(a.snd.fst*b.snd.snd>b.snd.fst*a.snd.snd)return a;
	return b;
}
//const ll C=400;
int main(){FIN;
	string a; cin>>a;
	ll n=SZ(a);
	pair<ll,ii> res={1,{0,1}};
	vector<ll>ls;
	fore(l,0,n)ls.pb(l);
	srand(175);
	random_shuffle(ALL(ls));
	
	for(auto l:ls){
		ll m=1;
		fore(r,l+1,n){
			if(clock()>0.499*CLOCKS_PER_SEC)goto end;
			if((n-l)/m<res.fst)break;
			if(a[r]!=a[r-m])m=r-l+1;
			res=maxi(res,crit(m,r-l+1));
		}
	}
	end:
	ii r={res.fst*res.snd.snd+res.snd.fst,res.snd.snd};
	ll g=gcd(r.fst,r.snd);
	r.fst/=g,r.snd/=g;
	cout<<r.fst<<"/"<<r.snd<<"\n";
	return 0;
}
