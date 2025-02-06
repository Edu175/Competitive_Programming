#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;

int uf[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(ll x, ll y){
	x=uf_find(x); y=uf_find(y);
	if(x==y)return 0;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y]; uf[y]=x;
	return 1;
}

vector<array<ll,3>>all,root;
const ll INF=2e9*MAXN;
ll n;
ll mst(){ // partially filled uf
	ll res=0;
	for(auto [w,x,y]:all)if(uf_join(x,y))res+=w;
	// cout<<"mst "<<res<<"\n";
	return (-uf[uf_find(0)]==n?res:INF);
}

int main(){
	JET
	ll m,k; cin>>n>>m>>k;
	fore(i,0,m){
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		if(!u||!v)root.pb({u,v,w});
		else all.pb({w,u,v});
	}
	sort(ALL(all));
	m=SZ(root);
	if(k>m){cout<<"-1\n";return 0;}
	ll res=INF;
	vv per(m); fore(i,m-k,m)per[i]=1;
	do{
		mset(uf,-1);
		ll cost=0;
		fore(i,0,m)if(per[i])uf_join(root[i][0],root[i][1]),cost+=root[i][2];
		// for(auto i:per)cout<<i<<" ";;cout<<"\n";
		res=min(res,mst()+cost);
	}while(next_permutation(ALL(per)));
	if(res>=INF)res=-1;
	cout<<res<<"\n";
	return 0;
}