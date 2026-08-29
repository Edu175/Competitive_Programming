#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 1e6+100;
ll l[maxn], r[maxn];
set<ii> g[maxn]; 
vector<ii> in[maxn];
const int inf  = 1e8;

void imposible(){
	cout<<"IMPOSSIBLE\n";
	exit(0);
}

void reducir(int x){
	sort(ALL(in[x]));
	reverse(ALL(in[x]));
	while(SZ(in[x]) > 1){
		auto [y,m] = in[x].back();
		in[x].pop_back();
		g[y].erase({x,m});
		in[in[x].back().fst].pb({y,m});
		g[y].insert({in[x].back().fst,m});
		if(m) l[y] = min(l[y],in[x].back().fst);
		else r[y] = min(r[y],in[x].back().fst);
	}	
}

vv res;


void f(int x, int maxi){
	if(x == maxi) return;
	if(l[x] < 1e7 && l[x] >= maxi)imposible();
	if(r[x] < 1e7 && r[x] >= maxi) imposible();
	if(l[x] < 1e7 && r[x]<=l[x])imposible();
	
	
	if(l[x] < 1e7) f(x+1,min(maxi,r[x]));
	res.pb(x);
	if(l[x] > 1e7) f(x+1,maxi);
	if(l[x] < 1e7 && r[x] < 1e7)f(r[x],maxi);
}


int main(){
	JET
	fore(i,0,maxn)l[i] = inf,r[i] = inf;
	ll n,m; cin>>n>>m;
	ll b = 0;
	fore(i,0,m){
		string s;
		ll x,y; cin>>x>>y>>s;x--,y--;
		if(x>=y) b = 1;
		ll mode = s[0] == 'L';
		g[x].insert({y,mode});
		if(mode) l[x] = min(l[x],y);
		else r[x] = min(r[x],y);
		in[y].pb({x,mode});
	}
	if(b) imposible();
	for(ll i = n-1;i>=0;i--) reducir(i);
	fore(i,0,n) cout<<l[i]<<" "<<r[i]<<"\n";
	f(0,n);
	for(auto x:res) cout<<x+1<<" ";
	cout<<"\n";
	return 0;
}