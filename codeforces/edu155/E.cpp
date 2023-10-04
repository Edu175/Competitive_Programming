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
ll t=-1,flag=1;
set<ll>dif;
void dfs(ll x){
	for(auto y:g[x]){
		c[y]=c[x]^1;
		dif.insert(c[y]);
		dfs(y);
	}
	if(x&&SZ(g[x])==1){
		//cout<<"solo "<<x<<"\n";
		if(t==-1)t=c[x];
		else if(t!=c[x])flag=0;
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
	fore(i,1,n){
		ll x; cin>>x; x--;
		g[x].pb(i);
		p[i]=x;
	}
	c[0]=1;
	ll k=0;
	dfs(0);
	/*fore(i,0,n){
		cout<<i<<": ";
		imp(g[i]);
		cout<<c[i]<<"\n\n";
	}*/
	//cout<<flag<<" "<<t<<"\n";
	if(flag){
		k=SZ(dif);
		cout<<k<<endl;
		fore(i,1,n)cout<<c[i]+1<<" ";
		cout<<endl;
	}
	else {
		c[0]=-1;
		dfs2(0);
		k=3;
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
			fore(i,0,k)if(q[i]){
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
			else cout<<t+1<<endl;
		}
	}
	return 0;
}
