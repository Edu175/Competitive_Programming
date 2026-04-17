#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn=1e5+10;
int vis[maxn];
vector<ii> g[maxn];
ll rec[maxn];

struct st{
	ll n,r,d,a;
	st(ll n,ll r,ll d, ll a): n(n),r(r),d(d),a(a){} 
	bool operator == (st x){return (*this).r==x.r && (*this).d==x.d;} 
	bool operator < (st x) {
		if ((*this).d<x.d) return true;
		else if ((*this).d<x.d) return ((*this).r<x.r);
		else return false;
	}
};


int main(){
	#ifdef ONLINE_JUDGE
	freopen("ideal.in","r",stdin);     freopen("ideal.out","w",stdout);
	#endif
	JET
	ll n,m;
	cin>>n>>m;
	map<ii,ll> mp;
	fore(i,0,m){
		ll x,y,v;
		cin>>x>>y>>v;
		x--,y--;
		g[x].pb({y,v});
		g[y].pb({x,v});
		if(!mp.count({x,y})) mp[{x,y}]=1e15;
		mp[{x,y}]=min(mp[{x,y}],v);
		mp[{y,x}]=mp[{x,y}];
	}
	vector<st> rta;
	ll rank=0;
	rta.pb(st(n-1,0,0,-1));
	rank++;
	int i=0;
	rec[n-1]=-1;
	vis[n-1]=1;
	while(!vis[0]){
		vv agg;
		agg.pb(rta[i].n);
		ll dis = rta[i].d;
		i++;
		while(i<SZ(rta) && rta[i-1]==rta[i]){
			agg.pb(rta[i].n);
			i++;
		}
		vector<st> candidatos;
		for(auto x:agg){
			fore(i,0,SZ(g[x]))if(!vis[g[x][i].fst]){
				candidatos.pb(st(g[x][i].fst,g[x][i].snd,dis+1,x));	
			}
		}
		sort(ALL(candidatos));
		vector<st> proc;
		ll aux = -1;
		for(auto x: candidatos){
			if(aux!=x.r){
				for(auto y : proc){
					if(!vis[y.n]){
						rta.pb(st(y.n,rank,y.d,y.a));
						rec[y.n] = y.a;
					}
					vis[y.n]=1;
					
				}
				rank++;
				proc.clear();
				aux = x.r;
				proc.pb(x);
			}
			else proc.pb(x);
		}
	}
	int t = 0;
	int p = rec[0];
	vv rr;
	while(p!=-1){
		rr.pb(mp[{p,t}]);
		// cout<<"@@@"<<p<<" "<<t<<"\n";
		ll aa=t;
		t=p;
		p=rec[t];
	}	
	// reverse(ALL(rr));
	fore(i,0,n){
		cout<<rec[i]<<" ";
	}
	cout<<"\n";
		cout<<SZ(rr)<<"\n";
	for(auto x:rr)cout<<x<<" ";
	cout<<"\n";
	return 0;
}


// 4 6
// 1 2 1
// 1 3 2
// 3 4 3
// 2 3 1
// 2 4 4
// 3 1 1
// 4
// 1 0 3 0 
