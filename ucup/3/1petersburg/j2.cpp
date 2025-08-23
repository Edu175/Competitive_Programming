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
typedef int ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll L = 2e6, R = 3e6, MAXN = 105;
random_device rd;
mt19937 rng(rd());
ll n;
ll a[MAXN], ori[MAXN];
ll MOD, obj;
char dp[MAXN][R+10];
bitset<R+10> rec[MAXN];
vector<ii> vis;


int sum(int x, int y){
	x+=y;
	if(x>=MOD) x-=MOD;
	return x;
}

char f(int i, ll w){
	// cout<<"entrando a "<<i<<" "<<w<<"\n";
	if(i == n) return (w == obj) ? true:false;
	char& r = dp[i][w];
	if(r != char(255)) return r;
	vis.pb({i,w});
	if(f(i+1,sum(w,a[i]))){
		r = 1;
		rec[i][w] = 1;
		return r;
	}
	if(f(i+1,w)){
		r = 1;
		rec[i][w] = 0;
		return r;
	}
	r = 0;
	rec[i][w] = 0;
	// cout<<"con "<<i<<" "<<w<<" no se puede\n";
	return r;
}
const ll TOP=1e9;
const ll maxit=40;
int main(){
	FIN;
	cin>>n;
	fore(i,0,n) cin>>ori[i];
	ll cnt=0;
	vector<char> rta;
	mset(dp,-1);
	while(1){
		// if(++cnt==maxit) {cout<<"PINGO\n"; break;}
		MOD = rng()%(R-L)+L;
		while(gcd(MOD,TOP)>1){
			MOD=rng()%(R-L)+L;
		}
		// MOD = 400;
		fore(i,0,n) a[i] = ori[i]%MOD;
		obj = TOP %MOD;
		// obj = 20;
		if(!f(0,0)){
			cout<<"PINGO\n";
			return 0;
		}
		ll w = 0;
		fore(i,0,n){
			// assert(rec[i][w] !=-1);
			if(rec[i][w]){
				rta.pb(i);
				w= sum(w,a[i]);
			}
		}
		ll check = 0;
		for(auto x:rta) check+=ori[int(x)];
		if(check == TOP){
			cout<<SZ(rta)<<" ";
		// if(check == 20){
			for(auto x:rta) cout<<x+1<<" ";
			cout<<"\n";
			break;
		}
		rta.clear();
		for(auto [x,y] : vis) dp[x][y] = char(255),rec[x][y] = 0;
		vis.clear();
	}
}