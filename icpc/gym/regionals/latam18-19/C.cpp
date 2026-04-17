#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const int maxn = 1e4+5;
vector<ii> a;
ll dp[maxn][120][6];

ll calc(ll x, ll v){
	if(v == 0) return x;
	if(v == 1) return x/2;
	return x/4;
}

ll f(int i, ll t, ll v){
	if(i == SZ(a)) return 0;
	if(t>=120 || v>=6) return f(i,0,0);
	ll &r= dp[i][t][v];
	if(r!=-1) return r;
	ll op1 = f(i+1,t+a[i].fst,v+1) + calc(a[i].snd,v);
	ll op2 = f(i+1,a[i].fst,1) + a[i].snd;
	r = min(op1,op2);
	return r;
}

int main(){
	JET
	ll n; cin>>n;
	mset(dp,-1);
	fore(i,0,n){
		ll x,y; cin>>x>>y;
		y*=4;
		a.pb({x,y});
	}
	vector<string> v = {".00",".25",".50",".75"};
	ll x = f(0,0,0);
	cout<<x/4<<v[x%4]<<"\n";
	return 0;
}