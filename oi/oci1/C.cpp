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
const ll MAXN=1e6+5;

string f(ll x, string a){
	if(x&1)swap(a[0],a[1]),swap(a[2],a[3]);
	if(x&2)swap(a[0],a[2]),swap(a[1],a[3]);
	return a;
}
ll c[MAXN],vis[MAXN];
vector<ii> g[MAXN];
ll flag=0,q=0;
vector<ll>v;
void dfs(ll x, ll w){
	//cout<<"dfs "<<x<<" "<<w<<"\n";
	vis[x]=1;
	if(c[x]!=-1){
		if(c[x]!=w)flag=0;
		return;
	}
	q+=w;
	v.pb(x);
	c[x]=w;
	for(auto [y,b]:g[x])dfs(y,w^b);
}
void doit(ll x, ll w){
	//cout<<"doit "<<x<<" "<<w<<"\n";
	for(auto i:v)c[i]=-1;
	v.clear();
	flag=1;q=0;
	dfs(x,w);
}
int main(){FIN;
	ll n,m; cin>>n>>m; ll tipo; cin>>tipo;
	vector<vector<string>>a(n,vector<string>(m,string(1,'0')));
	fore(i,0,n)fore(j,0,m)cin>>a[i][j][0];
	vector<vector<string>>b(n,vector<string>(m,string(1,'0')));
	fore(i,0,n)fore(j,0,m)cin>>b[i][j][0];
	fore(i,0,(n+1)/2)fore(j,0,(m+1)/2){
		a[i][j]+=a[i][m-1-j]+a[n-1-i][j]+a[n-1-i][m-1-j];
		b[i][j]+=b[i][m-1-j]+b[n-1-i][j]+b[n-1-i][m-1-j];
	}
	mset(c,-1);
	fore(i,0,(n+1)/2)fore(j,0,(m+1)/2){
		vector<bool> good(4);
		fore(x,0,4)good[x]=f(x,a[i][j])==b[i][j];
		if(!good[0]&&!good[2])c[i]=1;
		if(!good[1]&&!good[3])c[i]=0;
		if(!good[0]&&!good[1])c[n+j]=1;
		if(!good[2]&&!good[3])c[n+j]=0;
		if(good==vector<bool>({0,1,1,0})||good==vector<bool>({1,0,0,1})){
			g[i].pb({n+j,good[1]});
			g[n+j].pb({i,good[1]});
		}
	}
	if(n&1)c[n/2]=0;
	if(m&1)c[n+m/2]=0;
	/*cout<<"rows\n";;fore(i,0,(n+1)/2)cout<<c[i]<<" ";;cout<<"\n";
	cout<<"cols\n";;fore(i,0,(m+1)/2)cout<<c[n+i]<<" ";;cout<<"\n";
	fore(i,0,n+m){
		cout<<i<<": ";
		for(auto i:g[i])cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	}*/
	ll res=0,can=1;
	
	fore(i,0,n+m)if(!vis[i]){
		doit(i,0);
		ll flag0=flag,q0=q;
		doit(i,1);
		ll ch=0;
		if(!flag0)ch=1;
		else if(!flag)ch=0;
		else if(q<q0)ch=1;
		else ch=0;
		if(!ch)doit(i,0);
		res+=q,can&=flag;
		v.clear();
	}
	res=0;
	fore(i,0,(n+1)/2)res+=c[i];
	fore(j,0,(m+1)/2)res+=c[n+j];
	//cout<<"rows\n";;fore(i,0,(n+1)/2)cout<<c[i]<<" ";;cout<<"\n";
	//cout<<"cols\n";;fore(i,0,(m+1)/2)cout<<c[n+i]<<" ";;cout<<"\n";
	fore(i,0,(n+1)/2)fore(j,0,(m+1)/2){
		ll x=2*c[n+j]+c[i];
		can&=f(x,a[i][j])==b[i][j];
	}
	if(can){
		cout<<"YES\n";
		if(tipo)cout<<res<<"\n";
	}
	else {
		cout<<"NO\n";
	}
	return 0;
}
