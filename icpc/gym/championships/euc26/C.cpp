#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ll INF  = 1e15;
const int M = 2e7+10; 
short pre[M];

vv v = {2,3,4,5,6,7,11,13,17,19};

ll f(ll x, ll y){
	if(x<M) return pre[x];
	if(y){
		assert(!(x%y)); 
		return f(x/y,0) + 2 + y;
	}
	ll res = INF;
	for(auto i:v){
		ll g = (x/i)*i;
		res = min(res,f(g,i)+x-g);
	}
	return res;
}


int main(){
	JET
	fore(i,0,8) pre[i] = i;
	fore(x,8,M){
		pre[x] = 1000;
		for(auto i:v){
			ll g = (x/i)*i;
			if(g == x) pre[x] = min(pre[x], short(pre[x/i] + short(2 + i)));
			pre[x] = min(pre[x],short(pre[g]+short(x-g)));
		}
	}
	// for(auto x:pre) cout<<x<<" ";
	
	ll x; cin>>x;
	cout<<f(x,0)<<"\n";	
	return 0;
}