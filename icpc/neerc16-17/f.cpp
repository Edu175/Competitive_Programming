#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005;

ll uf[MAXN];
ll mk[MAXN];
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return 0;
	if(-uf[x]<-uf[y])swap(x,y);
	mk[x]|=mk[y];
	uf[x]+=uf[y],uf[y]=x;
	return 1;
}
vector<ii>g[MAXN];
ll c[MAXN],vis[MAXN];
void dfs(ll x, ll d){
	cout<<"dfs "<<x<<" "<<d<<endl;
	if(vis[x]){
		assert(d==c[x]);
		return;
	}
	c[x]=d;
	vis[x]=1;
	for(auto [y,w]:g[x])dfs(y,d+w);
}

int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	mset(uf,-1);
	ll n,m; cin>>n>>m;
	vector<ii>ed;
	fore(i,0,m){
		string s; cin>>s;
		ll x=0,y=0,w=0; char c;
		fore(i,0,SZ(s)){
			if(s[i]<'0'||s[i]>'9')w=1,c=s[i];
			else {
				if(!w)x=x*10+(s[i]-'0');
				else y=y*10+(s[i]-'0');
			}
		}
		x--,y--;
		if(c=='=')uf_join(x,y);
		else {
			if(c=='>')swap(x,y);
			mk[uf_find(x)]|=1;
			mk[uf_find(y)]|=2;
			ed.pb({x,y});
		}
	}
	mset(c,-1);
	fore(i,0,n){
		ll x=uf_find(i);
		if(mk[x]==3)c[x]=1;
	}
	for(auto [x,y]:ed){
		x=uf_find(x),y=uf_find(y);
		if(c[x]==1)c[y]=2;
		if(c[y]==1)c[x]=0;
		// g[x].pb({y,1});
		// g[y].pb({x,-1});
	}
	// fore(i,0,n){
	// 	ll x=uf_find(i);
	// 	if(mk[x]==3)dfs(x,1);
	// }
	string pingo="BRW";
	fore(i,0,n){
		ll x=uf_find(i);
		if(c[x]==-1)cout<<"?";
		else {
			cout<<pingo[c[x]];
		}
	}
	cout<<"\n";
	return 0;
 }