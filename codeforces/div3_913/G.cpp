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
const ll MAXN=1e5+5;

ll a[MAXN],c[MAXN],sz[MAXN],vis[MAXN];
queue<ll>q;
vector<ll>res;

void cut(ll x){
	if(c[x])res.pb(x),c[a[x]]^=1,c[x]=0;
	sz[a[x]]--;
	if(sz[a[x]]==0)q.push(a[x]);
	vis[x]=1;
}

void bfs(){
	while(SZ(q)){
		auto x=q.front(); q.pop();
		cut(x);
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		fore(i,0,SZ(s))c[i]=s[i]-'0';
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n){
			sz[i]=0;
			vis[i]=0;
		}
		while(SZ(q))q.pop();
		res.clear();
		fore(i,0,n)sz[a[i]]++;
		fore(i,0,n)if(sz[i]==0)q.push(i);
		bfs();
		ll flag=1;
		fore(x,0,n)if(!vis[x]){
			ll y=x,cnt=0;
			vector<ll>b;
			do {
				cnt+=c[y];
				b.pb(y);
				//assert(sz[y]==1);
				vis[y]=1;
				y=a[y];
			}
			while(y!=x);
			if(cnt%2){
				flag=0;
				break;
			}
			vector<ll> can[2];
			ll xr=0;
			for(auto i:b){
				xr^=c[i];
				can[xr].pb(i);
			}
			if(SZ(can[0])>SZ(can[1]))swap(can[0],can[1]);
			for(auto i:can[0])res.pb(i);
		}
		//fore(i,0,n)if(c[i])flag=0;
		if(!flag){
			cout<<"-1\n";
			continue;
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
