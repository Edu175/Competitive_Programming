#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	ll N,V; cin>>N>>V;
	ll n=rng()%(N-2)+3;
	cout<<"1\n";
	vector<ii>ed;
	fore(i,1,n)ed.pb({rng()%i,i});
	ll g[n][n]={};
	fore(i,0,n)g[i][i]=1;
	for(auto [u,v]:ed)g[u][v]=g[v][u]=1;
	ll m=rng()%(n*(n-1)/2-(n-1)+1)+n-1;
	vector<ll>av,deg(n);
	fore(i,0,n){
		ll c=n-count(g[i],g[i]+n,1);
		if(c)av.pb(i),deg[i]=c;
	}
	fore(_,n-1,m){
		ll x=av[rng()%SZ(av)];
		ll j=rng()%deg[x],y=-1;
		fore(i,0,n)if(!g[x][i]){
			if(!j){
				y=i;
				break;
			}
			j--;
		}
		assert(y!=-1);
		deg[x]--; deg[y]--;
		g[x][y]=g[y][x]=1;
		ed.pb({x,y});
	}
	ll k=rng()%(V*m/2+1)+1;
	
	cout<<n<<" "<<m<<" "<<k<<"\n";
	cout<<rng()%n+1<<" "<<rng()%n+1<<"\n";
	ll l=rng()%V+1,r=rng()%V+1;
	if(l>r)swap(l,r);
	cout<<l<<" "<<r<<"\n";
	for(auto [u,v]:ed){
		cout<<u+1<<" "<<v+1<<" "<<rng()%V+1<<"\n";
	}
	return 0;
}