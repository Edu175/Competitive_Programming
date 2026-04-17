#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<ii> points, use;
const ll inf = 1e18;
ll raiz(ll x){
	ll sq = sqrtl(x);
	sq = max(sq-3,0LL);
	while(sq * sq <= x) sq++;
	sq --;
	assert(sq * sq <= x && (sq+1)*(sq+1) > x);
	return sq;	
}

ll d(ii a, ii b){
	ll x = abs(a.fst - b.fst), y = abs(a.snd - b.snd);
	return x*x+y*y;
}

ll proc(int i){
	ll mn = inf;
	for(auto p:use) mn = min(mn,d(p,points[i]));
	use.pb(points[i]);
	return mn;
}

int main(){
	JET
	ll n; cin>>n;
	points.resize(n);
	vector<ii> vec(n);
	fore(i,0,n){
		cin>>points[i].fst>>points[i].snd;
		cin>>vec[i].fst;
		vec[i].snd = i;
	}
	sort(ALL(vec)); reverse(ALL(vec));
	vv rta(n);
	for(auto [h,i]:vec){
		ll x = proc(i);
		rta[i] = min(h,raiz(x));
		// cout<<"para "<<i<<" el proc me da "<<x<<"\n";
	}
	for(auto x:rta) cout<<x<<"\n";
	return 0;
}
