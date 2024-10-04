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
const ll MAXN=2e5*15;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

void add(ll x, ll y){
	uf_join(x,y);
}
ll cnt=0;
struct Rang{
	ll n,t; vector<ll>k;
	Rang(){}
	Rang(ll n):n(n),t(t),k(2*n+5){
		fore(i,0,n){
			k[i]=cnt++;
			k[i+n]=i;
		}
		fore(i,1,n){
			add(k[i],k[2*i]);
			add(k[i],k[2*i+1]);
		}
	}
	void query(ll l, ll r, ll c){
		for(l+=n,r+=n;l<r;l/=2,r/=2){
			if(l&1)add(c,k[l++]);
			if(r&1)add(c,k[--r]);
		}
	}
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		
	}
	return 0;
}
