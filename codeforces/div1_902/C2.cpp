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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MAXN=2e5+5,K=19;

ll a[MAXN],c[MAXN],gr[MAXN];

ll cnt[MAXN];

void color(ll x, ll w){
	if(c[x]){
		/*if(c[x]!=w){
			cout<<"-1\n";
			exit(0);
		}*/
		return;
	}
	c[x]=w;
	if(w==1)color(a[x],2);
	else {
		cnt[a[x]]++;
		if(/*!c[x]&&*/cnt[a[x]]==gr[a[x]])color(a[x],1);
	}
}
vector<ll>g[MAXN];
ll go[K][1ll<<K];
ll cy[MAXN];
ll vis[MAXN];
/*void dfs(ll x){
	vis[x]=1;
	cout<<x<<" ("<<gr[x]<<") {"<<c[x]<<"} ["<<cnt[x]<<"] ";
	//cout<<"vec "<<g[x]<<" ";
	for(auto y:g[x])if(!vis[y]){
		cout<<"> ";
		dfs(y);
		cout<<"< ";
	}
}*/

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--,gr[a[i]]++,g[a[i]].pb(i);
	fore(x,0,n){
		if(!gr[x])color(x,1);
	}
	//fore(x,0,n)if(!c[x])color(x,1);
	fore(i,0,n)go[0][i]=a[i];
	fore(k,1,K)fore(i,0,n)go[k][i]=go[k-1][go[k-1][i]];
	fore(i,0,n)cy[go[K-1][i]]=1;
	ll db=n>5;
	/*if(db){
		cout<<gr[0]<<endl;
		imp(g[0]);
		dfs(0);
	}*/
	fore(i,0,n){
		if(!((!cy[i])<=(c[i]>0)))cout<<i<<endl;
		assert((!cy[i])<=(c[i]>0));
	}
	fore(x,0,n){
		if(c[x])continue;
		c[x]=1;
		ll w=2;
		for(ll y=a[x];y!=x;y=a[y],w=3-w){
			//if(db)cout<<y<<endl;
			c[y]=w;
		}
		if(w==2){
			cout<<"-1\n";
			return 0;
		}
	}
	//assert(!db);
	vector<ll>res;
	fore(i,0,n)if(c[i]==1)res.pb(a[i]+1);
	cout<<SZ(res)<<"\n";
	imp(res);
	return 0;
}
