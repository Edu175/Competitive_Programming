#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3005,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return fpow(a,MOD-1+b); // 
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vv g[MAXN];
ll n;
vector<ii> bfs(vv s){
	vv d(n,-1);
	queue<ll>q;
	for(auto i:s)d[i]=0,q.push(i);
	while(SZ(q)){
		auto x=q.front(); q.pop();
		for(auto y:g[x])if(d[y]==-1){
			q.push(y);
			d[y]=d[x]+1;
		}
	}
	// cout<<"bfs ";
	// for(auto i:s)cout<<i<<" ";;cout<<": ";
	// fore(i,0,n)cout<<d[i]<<" ";;cout<<"\n";
	vector<ii>a;
	fore(i,0,n)a.pb({d[i],i});
	sort(ALL(a));
	return a;
}
ll tag[MAXN],dis[MAXN];
void dfs1(ll x, ll fa){
	for(auto y:g[x])if(y!=fa){
		dis[y]=dis[x]+1;
		tag[y]=tag[x];
		dfs1(y,x);
	}
}
ll med=(MOD+1)/2;
ll count(vv s){ // s centro
	cout<<"\ncount ";
	for(auto i:s)cout<<i<<" ";;cout<<":\n";
	auto a=bfs(s);
	fore(i,0,n)cout<<a[i].fst<<","<<a[i].snd<<" ";;cout<<" a\n";
	ll par=SZ(s)>1;
	vv sumfrac(n+1),small(n+1);
	fore(i,1,n+1){
		ll p=i-1;
		
		// sumfrac
		ll term=mul(fpow(3,p),fpow(med,p));
		sumfrac[i]=add(sumfrac[i-1],term);
		
		// small
		ll now=mul(term,a[p].fst+par);
		small[i]=add(small[i-1],now);
		
		// cout<<"p "<<p<<": "<<term<<" "<<now<<"\n";
	}
	
	vv big(n+1);
	fore(i,1,n+1){
		ll p=i-1;
		big[i]=add(big[i-1],mul(fpow(2,p),a[p].fst+par));
	}
	ll res=0;
	ll x=s[0];
	if(par){
		ll y=s[1];
		dis[x]=0; tag[x]=0;
		dfs1(x,y);
		dis[y]=0; tag[y]=1;
		dfs1(y,x);
	}
	else {
		dis[x]=0; tag[x]=-1;
		ll cnt=0;
		for(auto y:g[x]){
			dis[y]=1; tag[y]=cnt++;
			dfs1(y,x);
		}
	}
	map<ii,ll>mp;
	map<ll,ll>hist;
	fore(i,0,n)cout<<tag[i]<<","<<dis[i]<<" ";;cout<<" tag,dis\n";
	fore(i,0,n){
		ll c=i+1;
		bool bo=c==1;
		auto [r,x]=a[i];
		ll cant=tag[x]==-1?1:hist[dis[x]]++-mp[{tag[x],dis[x]}]++;
		ll frac=mul(fpow(3,c-2+bo),fpow(med,c));
		ll s1=add(sub(big[n],big[c]),mul(r,sub(fpow(2,n),fpow(2,c))));
		s1=mul(s1,frac);
		
		ll s0=add(small[c-2+bo],mul(r,sumfrac[c-2+bo]));
		
		s0=mul(s0,fpow(2,c-3+bo)); // 
		// s0=mul(s0,fpow(2,c-3)); // 
		
		ll resi=add(s0,s1);
		cout<<c<<": "<<r<<" "<<x<<": "<<s0<<" "<<s1<<": "<<cant<<" "<<resi<<": "<<"("<<bo<<") "<< mul(cant,resi)<<"\n";
		// cout<<bo<<": "<<small[c-2+bo]<<" "<<sumfrac[c-2+bo]<<" bo... "<<c-2+bo<<"\n";
		res=add(res,mul(cant,resi));
	}
	cout<<"= "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)g[i].clear();
		vector<ii>ed;
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
			ed.pb({u,v});
		}
		ll res=0;
		fore(i,0,n)res=add(res,count({i}));
		for(auto [u,v]:ed)res=add(res,count({u,v}));
		cout<<res<<"\n";
	}
	return 0;
}
