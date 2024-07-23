#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105;
struct UF{
	ll uf[MAXN];
	void init(){mset(uf,-1);};
	ll find(ll x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	ll join(ll x, ll y){
		x=find(x),y=find(y);
		if(x==y)return 0;
		if(uf[x]>uf[y])swap(x,y);
		uf[x]+=uf[y],uf[y]=x;
		return 1;
	}
};

int main(){JET
	ll n,m; cin>>n>>m;
	vector<UF> uf(m);
	fore(i,0,m)uf[i].init();
	fore(i,0,m){
		ll a,b,c; cin>>a>>b>>c; a--,b--,c--;
		uf[c].join(a,b);
	}
	ll q; cin>>q;
	while(q--){
		ll x,y; cin>>x>>y; x--,y--;
		ll res=0;
		fore(c,0,m){
			res+=uf[c].find(x)==uf[c].find(y);
		}
		cout<<res<<"\n";
	}
	return 0;
}