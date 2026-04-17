#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const int MAXN = 110;
ll F[MAXN];
vv g[MAXN];

void bad_o(){
	cout<<"Bad oriented forest"<<endl;
	exit(0);
}

void bad_s(int x){
	cout<<"Bad segment at "<<x<<endl;
	exit(0);
}


ll l[MAXN],r[MAXN],wg[MAXN];
set<ll> mal;

void dfs(int x){
	l[x] = x, r[x] = x;
	wg[x] = 1;
	for(auto y:g[x]){
		dfs(y);
		l[x] = min(l[x],l[y]);
		r[x] = max(r[x],r[y]);
		wg[x] += wg[y];
	}
	if(r[x] - l[x] + 1!=wg[x]) mal.insert(x);
}

void join(int x, int y){
	if(F[y] != -1) bad_o();
	ll aux = x;
	while(F[aux] != -1){
		if(aux == y) bad_o();
		aux = F[aux];
		if(aux == y) bad_o();
	}
	g[x].pb(y);
	F[y] = x;
	fore(i,0,MAXN) dfs(i);
	if(SZ(mal)){
		cout<<"tito\n";
		for(auto x:mal) cout<<x<<" ";
		cout<<"\n";
		exit(0);
	}
}

int main(){
	ll n; cin>>n;
	mset(F,-1);
	fore(i,1,n){
		ll x, y;  cin>>x>>y;
		join(x,y);
		cout<<"Good"<<endl;
	}	
	
	return 0;
}