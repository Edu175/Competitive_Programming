#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 1e6+100;
vv g[maxn];
ll a[maxn], t[maxn], dp[maxn][2];


void init(int n){
	fore(i,0,n+10){
		g[i].clear();
		dp[i][0] = -1, dp[i][1] = -1;
	}
}

pair<ii,ll> sig(int i, int fat){
	ii max3 = {-1,-1}; ll maxi = -1;
	ll p = 0;
	sort(ALL(g[i]),[&](int x, int y){return a[x] > a[y];});
	for(auto x:g[i]){
		if(x == fat) continue;
		if(maxi < 0) maxi = x;
		if(t[x] == 3){
			if(!p) max3.fst = x;
			else if(p == 1) max3.snd = x;
			p++;
		}
	}
	return {max3,maxi};
}

ll f(int x, bool ag, int fat){
	ll &r = dp[x][ag];
	if(r!=-1) return r;
	ll sum = 0;
	for(auto y:g[x]) if(y!=fat) sum+=f(y,1,x);	
	if(!ag) return r = sum;
	auto [max3, maxi] = sig(x,fat);
	if(maxi == -1) return r = 0;
	r = sum + a[maxi];
	if(max3.fst == -1) return r;
	for(auto y:g[x])if(y!=fat){
		ll op = sum - f(y,1,x) + f(y,0,x) + a[y];
		if(y == max3.fst && max3.snd != -1) op += a[max3.snd];
		else if(y!=max3.fst) op += a[max3.fst];
		r = max(r,op);
	}
	return r;
}



int main(){
	JET 
	ll tc; cin>>tc;
	while(tc--){
		ll n; cin>>n;
		init(n);
		fore(i,0,n) cin>>a[i];
		fore(i,0,n) cin>>t[i];
		fore(i,1,n){
			ll x,y; cin>>x>>y; x--,y--;
			g[x].pb(y); g[y].pb(x);
		}
		cout<<f(0,1,-1) + a[0]<<"\n";
	}
	return 0;
}
