#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll w,n;
const int maxn = 1005;
vector<ii> pts;
vector<ii> a,b;
ll vis[maxn];
ii auxl={0,1}, auxr={w,1};
const ld eps = 1e-8;


ld dist(ii x, ii y){
	ll xx = abs(x.fst - y.fst), yy = abs(x.snd - y.snd);
	return sqrtl(xx*xx+yy*yy);
}


void dfs(ll i, ld d){
	vis[i] = 1;
	a.pb(pts[i]);
	fore(j,0,n) if(!vis[j] && dist(pts[i],pts[j]) <= d) dfs(j,d);
}

bool can(ld d){
	a.clear(),b.clear();
	mset(vis,0);
	fore(i,0,n)if(!vis[i] && pts[i].fst <= d){
		dfs(i,d);
	}
	swap(a,b);
	fore(i,0,n)if(!vis[i] && w-pts[i].fst <= d){
		dfs(i,d);
	}
	swap(a,b);
	fore(i,0,2){
		for(auto [x,y] : a){
			ll k = (i ? x : w-x);
			if(k <= 2*d){
				auxl = (i ? (ii){0,y} : (ii){x,y});
				auxr = (i ? (ii){x,y} : (ii){w,y});
				return true;
			}
		}
		swap(a,b);
	}
	for(auto x:a) for(auto y:b) if(dist(x,y) <= 2*d){
		auxl = x;
		auxr = y;
		return true;
	}
	return false;
}

int main(){
	JET
	#ifdef ONLINE_JUDGE
	freopen("froggy.in","r",stdin);     freopen("froggy.out","w",stdout);
	#endif
	cin>>w>>n;
	auxr.fst=w;
	pts.resize(n);
	fore(i,0,n)cin>>pts[i].fst>>pts[i].snd;
	if(n){
		ld l = 0, r = 1e9+100;
		while(r - l > eps){
			ld m = (l+r)/2;
			if(can(m)) r = m;
			else l = m;
		}
		assert(can(r));
		// cout<<r<<"\n";
	}
	cout<<fixed<<setprecision(2)<<(ld(auxl.fst) + ld(auxr.fst)) / 2<<" "<<(ld(auxl.snd) + ld(auxr.snd)) / 2<<"\n";
	return 0;
}