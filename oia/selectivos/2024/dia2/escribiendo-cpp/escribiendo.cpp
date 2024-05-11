#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fdkjg:v)cout<<fdkjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1505;

ll uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return 0;
	if(uf[x]<uf[y])swap(x,y);
	uf[y]+=uf[x];
	uf[x]=y;
	return 1;
}
long long escribiendo(long long C, vector<long long> &a) {
    ll n=SZ(a);
    auto cost=[&](ll x, ll y){
    	ll g=__gcd(x,y);
    	return x/g+y/g;
    };
    vector<pair<ll,ii>>ed;
    fore(i,0,n)fore(j,i+1,n){
    	ed.pb({min(cost(a[i],a[j]),C),{i,j}});
    }
    sort(ALL(ed));
    mset(uf,-1);
    ll res=C;
    for(auto i:ed){
    	ll w=i.fst,x=i.snd.fst,y=i.snd.snd;
    	if(uf_join(x,y))res+=w;
//    	,cout<<x<<","<<y<<" "<<w<<"\n";
    }
    return res;
}
