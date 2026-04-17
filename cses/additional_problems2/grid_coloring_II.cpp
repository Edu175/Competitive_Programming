#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;
vv g[MAXN], gt[MAXN], ord;  //gt: transposed graph. ord: order for scc
ll vis[MAXN], cmp[MAXN], truth[MAXN], qcmp = 0, N; //cmp[x]:scc of x.truth[x]:bool value for 2sat
void dfs(ll x, ll t){
    if(t) cmp[x] = qcmp;; vis[x] = 1;
    for(auto y:t ? gt[x]:g[x])if(!vis[y]) dfs(y,t);
    if(!t) ord.pb(x);
}
void scc(){
	mset(vis,0);
    fore(i,0,N) if(!vis[i]) dfs(i,0);
    reverse(ALL(ord));mset(vis,0);
    for(auto x:ord)if(!vis[x]) dfs(x,1),qcmp++;
}
// 2SAT, first define n = 2 * vars
ll neg(ll x){return N-1-x;}
void add_edge(ll x, ll y){
	g[x].pb(y);
	gt[y].pb(x);
} 
bool satis(){
    scc();
    fore(i,0,N){
		// cerr<<i<<" "<<neg(i)<<": "<<cmp[i]<<" "<<cmp[neg(i)]<<"\n";
        if(cmp[i] == cmp[neg(i)]) return false;
        truth[i] = cmp[i] > cmp[neg(i)];
    }
    return true;
}

char tra(char b, ll x){ // x is 0 or 1
	x++;
	ll p=b-'A';
	ll q=(x+p)%3;
	return 'A'+q;
}
ll n,m;
ll cv(ll i, ll j){return m*i+j;}
ll nod(ll x, ll bo){return bo?neg(x):x;}

void __agr(ll x, char a, ll y, char b){
	// ll dbg=min(x,y)==1&&max(x,y)==5;
	// if(dbg)cerr<<"agr "<<x<<","<<a<<" "<<y<<","<<b<<"\n";
	fore(i,0,2){
		vv bad;
		char me=tra(a,i);
		fore(j,0,2){
			char he=tra(b,j);
			if(me==he)bad.pb(j);
		}
		// if(dbg){
		// 	cout<<i<<": ";
		// 	imp(bad)
		// }
		assert(SZ(bad)<=1);
		if(SZ(bad)){
			ll wh=bad[0];
			add_edge(nod(x,i),nod(y,wh^1));
		}
	}
}

vector<string> a;
void __agr(ll i, ll j, ll k, ll l){ // one-way
	__agr(cv(i,j),a[i][j],cv(k,l),a[k][l]);
}

void agr(ll i, ll j, ll k, ll l){ // both-ways
	// cerr<<"agr "<<i<<","<<j<<" "<<k<<","<<l<<"\n";
	__agr(i,j,k,l);
	__agr(k,l,i,j);
}

int main(){FIN;
	cin>>n>>m;
	N=2*n*m;
	a=vector<string>(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)fore(j,0,m){
		if(i)agr(i,j,i-1,j);
		if(j)agr(i,j,i,j-1);
	}
	if(!satis()){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	fore(i,0,n)fore(j,0,m){
		char c='.';
		fore(bo,0,2)if(truth[nod(cv(i,j),bo)])c=tra(a[i][j],bo);
		assert(c!='.');
		cout<<c;
		if(j==m-1)cout<<"\n";
	}
	return 0;
}
