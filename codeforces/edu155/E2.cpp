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
const ll MAXN=105;

vector<ll>g[MAXN];

ll c[MAXN],p[MAXN];
void dfs(ll x){
	for(auto y:g[x]){
		c[y]=c[x]^1;
		dfs(y);
	}
}
void dfs2(ll x){
	for(auto y:g[x]){
		c[y]=(c[x]+1)%3;
		//cout<<x<<"--"<<y<<": "<<c[x]<<"--"<<c[y]<<"\n";
		dfs2(y);
	}
}

int main(){FIN;
	ll n; cin>>n;
	ll d1=1;
	fore(i,1,n){
		ll x; cin>>x; x--;
		g[x].pb(i);
		p[i]=x;
		if(x!=0)d1=0;
	}
	if(d1){
		cout<<"1\n";
		fore(i,0,n-1)cout<<"1 ";
		cout<<endl;
		while(1){
			ll x; cin>>x;
			if(x!=0)exit(0);
			cin>>x;
			cout<<1<<endl;
		}
		return 0;
	}
	mset(c,-1);
	ll flag=1;
	fore(i,1,n){
		if(SZ(g[i])==1){
			for(ll x=i,ci=0;x;x=p[x],ci^=1){
				if(c[x]==-1)c[x]=ci;
				else if(c[x]!=ci)flag=0;
				else break;
			}
		}
	}
	ll k=0;
	if(!flag){
		c[0]=-1;
		dfs2(0);
		k=3;
		cout<<k<<endl;
		fore(i,1,n)cout<<c[i]+1<<" ";
		cout<<endl;
	}
	else {
		for(auto s:g[0]){
			if(c[s]==-1)c[s]=0;
			dfs(s);
		}
		k=2;
		cout<<k<<endl;
		fore(i,1,n)cout<<c[i]+1<<" ";
		cout<<endl;
	}
	while(1){
		ll x; cin>>x;
		if(x!=0)exit(0);
		ll q[k]={};
		fore(i,0,k)cin>>q[i];
		if(!flag){
			vector<ll>can;
			fore(i,0,k)if(q[i]==1){
				can.pb(i);
			}
			if(SZ(can)==1)cout<<can[0]+1<<endl;
			else {
				if(!q[1])cout<<3<<endl;
				if(!q[0])cout<<2<<endl;
				if(!q[2])cout<<1<<endl;
			}
		}
		else {
			vector<ll>can;
			fore(i,0,k)if(q[i]==1){
				can.pb(i);
			}
			if(SZ(can)==1)cout<<can[0]+1<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}
