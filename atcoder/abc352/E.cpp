#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<pair<ll,ii>>ed;
	fore(i,0,m){
		ll k,c; cin>>k>>c;
		vector<ll>a(k);
		fore(i,0,k)cin>>a[i],a[i]--;
		fore(i,0,k-1)ed.pb({c,{a[i],a[i+1]}});
	}
	sort(ALL(ed));
	uf_init();
	ll res=0;
	for(auto [w,e]:ed){
		auto [x,y]=e;
		if(uf_join(x,y))res+=w;
	}
	set<ll>st;
	fore(i,0,n)st.insert(uf_find(i));
	if(SZ(st)>1)cout<<"-1\n";
	else cout<<res<<"\n";
	return 0;
}
