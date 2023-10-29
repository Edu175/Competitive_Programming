#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll val[MAXN];
struct node{
	vector<ll>v;
	ll sum=0,dad=-1;
	node(ll x):v(1,x),sum(val[x]),dad(x){}
	node(){}
};
node cmp[MAXN]; ll id[MAXN];
ll fat[MAXN];
void uf_init(ll n){
	fore(i,0,n){
		cmp[i]=node(i);
		id[i]=i;
	}
}
bool join(ll a, ll b){
	a=id[a],b=id[b];
	if(a==b)return 0;
	if(SZ(cmp[a].v)>SZ(cmp[b].v))swap(a,b);
	for(auto i:cmp[a].v)cmp[b].v.pb(i),id[i]=b;
	cmp[b].sum+=cmp[a].sum;
	ll x=cmp[a].dad,y=cmp[b].dad;
	if(val[y]>val[x])fat[x]=y;
	else fat[y]=x,cmp[b].dad=x;
	cmp[a].v.clear(); cmp[a].sum=0; cmp[a].dad=-1;
	return 1;
}
vector<ll> g[MAXN];
ll ans[MAXN],fl[MAXN];
ll dp[MAXN];

ll f(ll x){
	ll &res=dp[x];
	if(res!=-1)return res;
	res=ans[x];
	if(fat[x]!=-1&&ans[x]>val[fat[x]])res=max(res,f(fat[x]));
	return res;
}
int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	fore(i,0,n)cin>>val[i];
	mset(ans,-1);
	mset(fat,-1);
	uf_init(n);
	fore(x,0,n){ //special nodes
		fl[x]=1;
		for(auto y:g[x])if(val[y]<val[x])fl[x]=0;
	}
	vector<ii>a;
	fore(x,0,n)a.pb({val[x],x});
	sort(ALL(a));
	vector<ll>b;
	fore(i,0,n+1){ //meto todos (mismo valor) a la vez, dsp calculo
		ll x=a[i].snd;
		//cout<<x<<" ";
		for(auto y:g[x])if(val[y]<=val[x])join(x,y);
		b.pb(x);
		if(i==n-1||a[i].fst!=a[i+1].fst){
			for(auto j:b)ans[j]=cmp[id[j]].sum;
			b.clear();
		}
	}
	//cout<<"\n";
	mset(dp,-1);
	fore(x,0,n){
		f(x);
		ll res=0;
		if(fl[x])res=val[x];
		else res=dp[x];
		cout<<res<<" ";
	}
	cout<<"\n";
	/*cout<<"\n";
	fore(i,0,n){
		cout<<i<<" "<<fat[i]<<": "<<ans[i]<<" "<<dp[i]<<" "<<fl[i]<<"\n";
	}*/
	return 0;
}

