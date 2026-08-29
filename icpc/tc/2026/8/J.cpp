#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn=1e4+5;
vector<ii> g[maxn];

int n,m;
int mt[maxn],mt2[maxn],ds[maxn];
int q[maxn];
bool bfs(const ll &K){
	mset(ds,-1); bool r=false;
	int L=0,R=0;
	fore(i,0,n)if(mt2[i]<0)ds[i]=0,q[R++]=i;
	while(L<R){
		int x=q[L++];
		for(auto [y,w]: g[x])if(w<=K){
			if(mt[y]>=0&&ds[mt[y]]<0)ds[mt[y]]=ds[x]+1,q[R++]=mt[y];
			else if(mt[y]<0) r=true;
		}
	}
	return r;
}
bool dfs(int x,const ll &K){
	for(auto [y,w]:g[x])if(w<=K&&(mt[y]<0||ds[mt[y]]==ds[x]+1&&dfs(mt[y],K))){
		mt[y]=x;mt2[x]=y; return true;
	}
	ds[x]=1<<30; return false;
}
int mm(const ll &K){
	int r=0; mset(mt,-1); mset(mt2,-1);
	while(bfs(K)) fore(i,0,n)if(mt2[i]<0)r+=dfs(i,K);
	return r;
}

const ll INF=int(1e9)+5;
int main(){
	JET
	cin>>n>>m;
	fore(i,0,m){
		ll u,v,d; cin>>u>>v>>d; u--,v--;
		g[u].pb({v,d});
	} 
	ll l=0,r=INF;
	while(l<=r){
		ll m=(l+r)>>1;
		if(mm(m)==n) r=m-1;
		else l=m+1;
	}
	cout<<(l>=INF?-1:l)<<"\n";
	return 0;
}