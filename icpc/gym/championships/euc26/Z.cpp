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

ll m;
const int maxn = 1e5;
ll uf[maxn];

void uf_init(){
	memset((uf),-1,sizeof(uf));
}
ll uf_find(ll x){return uf[x] >=0 ? uf[x] = uf_find(uf[x]) : x;}

void uf_join(ll x, ll y){
	x = uf_find(x), y = uf_find(y);
	if(x == y) return;
	if(uf[y] < uf[x]) swap(x,y);
	uf[x]+=uf[y];
	uf[y] = x;
}

int main(){
	JET
	ll n,s; cin>>n>>s>>m;
	vv a(s);
	uf_init();
	fore(i,0,s){
		ll x; cin>>x;
		fore(j,0,x/2)uf_join(j,x-1-j);
	}
	ll res = 1;
	fore(i,0,n)if(uf[i] < 0){
		res*=2;
		res%=m;
	}
	cout<<res<<"\n";
	return 0;
}