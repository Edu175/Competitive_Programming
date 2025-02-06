#include <bits/stdc++.h>
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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005;


ll nodos,aristas;

set<ll> g[MAXN];

set<ii> deg;

ll rta[MAXN][MAXN];
ll act=1e7;
ll kikito = 0;
ll n,m;

void act_rta(int x, int y, int z){
	// cout<<"entro con x "<<x<<" y "<<y<<" z "<<z <<" act "<<act<<endl;
	fore(i,0,n){
		if(i==y || i==x) continue;
		if(rta[i][x]==-1){
			rta[i][x]=act;
			rta[x][i]=act;
			act--;
		}
		if(z){
			if(rta[i][y]==-1){
				rta[i][y]=act;
				rta[y][i]=act;
				act--;
			}
		}
		
	}
	rta[x][y]=act;
	rta[y][x]=act;
	act--;
	// cout<<"salgo con act "<<act<<endl;
	return ;
	
}


int main(){
	JET
	cin>>n>>m;
	nodos=n;aristas=m;
	mset(rta,-1);
	if(m>n || n>2*m){
		fore(i,0,m){
			int x,y; cin>>x>>y;
		}
		cout<<-1<<"\n";
		return 0;
	}
	fore(i,0,m){
		ll x,y; cin>>x>>y;
		x--,y--;
		g[x].insert(y);
		g[y].insert(x);		
	}
	fore(i,0,n){
		if(SZ(g[i]))deg.insert({SZ(g[i]),i});
		else{
			cout<<"-1\n";
			return 0;
		}
	}
	while(deg.begin()!=deg.end() && (*deg.begin()).fst!=2){
		ll x = (*deg.begin()).fst;
		// assert(x<2);
		assert(x==1);
		ll node = (*deg.begin()).snd;
		// cout<<"acabo de agarrar "<<node<<" con degree "<<x<<endl;
		deg.erase(deg.begin());
		if(x==1){
			//mato a este y a su arista
			nodos--;
			aristas--;
			assert(SZ(g[node])>0);
			ll y = *g[node].begin();
			// cout<<"y es "<<y<<endl;
			auto it = deg.lower_bound({SZ(g[y]),y});
			deg.erase(it);
			g[y].erase(node);
			if(!SZ(g[y])){
				nodos--;
				act_rta(node,y,1);
			}
			else{
				deg.insert({SZ(g[y]),y});
				act_rta(node,y,0);
			}
			g[node].erase(y);
		}
		if(aristas>nodos || aristas*2<nodos){
			cout<<-1<<"\n";
			return 0;
		}
	}
	fore(i,0,n){
		if(SZ(g[i])){
			assert(SZ(g[i])==2);
			auto it = g[i].begin();
			ll x = *it;
			it++;
			ll y = *it;
			// act_rta(i,x,y);
			if(rta[i][x]==-1){
				rta[i][x]=kikito;
				rta[x][i]=kikito;
				kikito++;
			}
			if(rta[i][y]==-1){
				rta[i][y]=kikito;
				rta[y][i]=kikito;
				kikito++;
			}
			
		}
	}
	fore(i,0,n){
		// ll cnt=0;
		fore(j,i+1,n){
			// assert(rta[i][j]>=0);
			// if(rta[i][j]>=0) cnt++;
			(rta[i][j]==-1)?cout<<act--<<" ":cout<<rta[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
