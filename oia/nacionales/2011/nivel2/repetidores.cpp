#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,oia=b;i<oia;++i)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=3e5+5,INF=5*MAXN;

vector<ll>g[MAXN];
ll id[MAXN];
vector<ll>ord;
void dfs(ll x){
	for(auto i:g[x])dfs(i);
	ord.pb(x);
}
ll dp[MAXN][3][3];
ll p[MAXN];
void cnt(){
	mset(dp,0);
	for(auto x:ord){
		fore(e,0,3){
			fore(d,0,3){
				ll &res=dp[x][e][d];
				if(e==d){
					res=INF;
					continue;
				}
				ll ch=0;
				fore(i,0,3)if(i!=e&&i!=d)ch=i;
				if(id[x]!=d)res++;
				if(p[x]!=-1)dp[p[x]][e][ch]+=res;
			}
		}
	}
}

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("repetidores.in", ios::in);
	cout.open("repetidores.out", ios::out);
	ll n; cin>>n;
	mset(p,-1);
	fore(i,0,n){
		ll x; cin>>x; x--;
		char c; cin>>c;
		id[x]=c-'A';
		ll m; cin>>m;
		fore(i,0,m){
			ll y; cin>>y; y--;
			g[x].pb(y);
			p[y]=x;
		}
	}
	ll s=0,e=-1,res=INF;
	while(p[s]!=-1)s=p[s];
	dfs(s);
	cnt();
	fore(i,0,3){
		fore(j,0,3){
			ll resi=dp[s][i][j];
			if(resi<res)e=i,res=resi;
		}
	}
	cout<<res<<" ";
	vector<char>r;
	fore(i,0,3)if(i!=e)r.pb('A'+i);
	cout<<r[0]<<" "<<r[1]<<"\n";
	return 0;
}
