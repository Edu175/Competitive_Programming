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
const ll MAXN=4e3+5;

bool vis[MAXN];
vector<ll>g[MAXN];

vector<ll> comp[MAXN];
ll id[MAXN];

void uf_init(ll n){fore(i,0,n)comp[i].pb(i),id[i]=i;}
bool uf_join(ll a, ll b){
	if(id[a]==id[b])return 0;
	ll c=id[a], d=id[b]; // c --> d
	if(SZ(comp[c])>SZ(comp[d]))swap(c,d);
	for(auto i:comp[c]){
		comp[d].pb(i);
		id[i]=d;
	}
	comp[c].clear();
	return 1;
}

int main(){FIN;
	ll t; cin>>t;
	ll bn=0;
	while(t--){
		//cout<<"\n";
		fore(i,0,bn){
			g[i].clear();
			vis[i]=0;
			id[i]=0;
			comp[i].clear();
		}
		ll n; cin>>n;
		bn=n;
		uf_init(n);
		//fore(i,0,n)cout<<vis[i];
		//cout<<"\n";
		ll a[n][n];
		fore(i,0,n){
			fore(j,0,n){
				char b; cin>>b;
				a[i][j]=b-'0';
				if(a[i][j]){
					g[i].pb(j);
					uf_join(i,j);
				}
			}
		}
		/*fore(i,0,n){
			cout<<i<<": ";
			imp(g[i]);
		}
		cout<<"\n";
		fore(i,0,n){
			cout<<i<<": ";
			imp(comp[i]);
		}*/
		ll m=0;
		fore(i,0,n){
			if(SZ(comp[i]))m++;
		}
		if(m==1){
			cout<<"0\n";
			continue;
		}
		ll nc=-1;
		fore(i,0,n){
			ll is=1;
			for(auto j:comp[i]){
				if(SZ(g[j])!=SZ(comp[i])-1){
					is=0;
					//cout<<"!!! "<<i<<" "<<SZ(comp[i])<<" "<<SZ(g[j])<<"\n";
				}
			}
			if(!is){
				nc=i;
				break;
			}
		}
		//cout<<"\nnc: "<<nc<<"\n";
		if(nc!=-1){
			//imp(comp[nc]);
			cout<<"1\n";
			ll mini=-1;
			for(auto i:comp[nc]){
				if(mini==-1||SZ(g[i])<SZ(g[mini]))mini=i;
			}
			cout<<mini+1<<"\n";
			continue;
		}
		
		ll minc=-1;
		fore(i,0,n){
			if(!SZ(comp[i]))continue;
			if(minc==-1||SZ(comp[i])<SZ(comp[minc]))minc=i;
		}
		if(m==2||SZ(comp[minc])==1){
			cout<<SZ(comp[minc])<<"\n";
			for(auto i:comp[minc])cout<<i+1<<" ";
			cout<<"\n";
			continue;
		}
		cout<<"2\n1 ";
		fore(i,0,n){
			if(id[i]!=id[0]){
				cout<<i+1<<"\n";
				break;
			}
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
