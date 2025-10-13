#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105,B=MAXN;
typedef bitset<B> mask;
struct matrix{
	vector<mask>x;
	matrix(): x(B){}
	bool add(mask v){
		if(v==0)return 0;
		fore(j,0,B)if(v[j])v^=x[j];
		if(v!=0){x[v._Find_first()]=v;return 1;}
		return 0;
	}
};

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<mask> g(n);
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		g[u][v]=g[v][u]=1;
	}
	fore(i,0,n){
		if(g[i].count()&1)g[i][i]=1;
	}
	// I'll add vector columns (but it's symmetric so it doesn't matter)
	matrix mt;
	fore(i,0,n)mt.add(g[i]);
	mask all;
	fore(i,0,n)all[i]=1;
	if(!mt.add(all))cout<<"Y\n";
	else cout<<"N\n";
	return 0;
}