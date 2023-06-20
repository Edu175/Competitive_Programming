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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MAXN=1e5+5;

ll n;
vector<ll>g[MAXN];
vector<ll>ord;
ll p=0;
ll s[MAXN];
void dfs(ll x, ll f){
	if(s[x]==-1)s[x]=SZ(ord);
	ord.pb(p);
	for(auto y:g[x])if(y!=f){
		p++;
		dfs(y,x);
		p--;
		ord.pb(p);
	}
}

const ll K=20;
ll st[K][1ll<<K];
#define oper min
void st_init(vector<ll>a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll query(ll l, ll r){
	ll k=63-__builtin_clzll(r-l);
	return oper(st[k][l],st[k][r-(1ll<<k)]);
}
ll dis(ll a, ll b){
	if(s[a]>s[b])swap(a,b);
	ll f=query(s[a],s[b]+1);
	return ord[s[a]]-f+ord[s[b]]-f;
}
ll d[MAXN];
void bfs(vector<ll> s){
	mset(d,-1);
	queue<ll> q;
	for(auto i:s)q.push(i),d[i]=0;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			d[y]=d[x]+1;
			q.push(y);
		}
	}
}

const ll B=2e2;
int main(){FIN;
	ll q; cin>>n>>q;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	mset(s,-1);
	dfs(0,-1);
	/*cout<<ord<<"\n";
	fore(i,0,n)cout<<i<<": "<<s[i]<<"\n";*/
	//ll B=sqrt(q)+.5;
	st_init(ord);
	vector<ll> c={0};
	vector<ll> b;
	//cout<<"qs\n";
	ll qus=0;
	fore(i,0,q){
		if(qus%B==0)bfs(c);
		//cout<<i<<"\n";
		ll ty,x; cin>>ty>>x; ty--,x--;
		if(!ty){
			c.pb(x);
			b.pb(x);
		}
		else {
			//cout<<x<<" |"<<SZ(d)<<"|\n";
			ll res=d[x];
			//cout<<d<<" ";
			for(auto i:b)res=min(res,dis(x,i));//,cout<<i<<"="<<dis(x,i)<<" ";
			//cout<<"\n";
			cout<<res<<"\n";
		}
		//	cout<<"\n";
	}
	return 0;
}
