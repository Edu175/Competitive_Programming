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
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef struct item *pitem;
const ll maxn=2e5,mod=1e9+7;
ll addm(ll a, ll b){a+=b; return a<mod?a:a-mod;}
ll subm(ll a, ll b){a-=b; return a<0?a+mod:a;}
ll uf[maxn];
ll d[maxn];
ll find(ll x){
	if(uf[x]<0) return x;
	ll old=uf[x];
	uf[x]=find(uf[x]);
	d[x]=addm(d[x],d[old]);
	return uf[x];
}
ll dst(ll x){
	find(x); return d[x];
}
ll rta=0;
void uni(ll x, ll y, ll w){ //x -> y, weight=w
	if(w>=0)w=addm(w,dst(x));
	else w=subm(dst(x),-w);
	rta=addm(w,rta);
	x=find(x); y=find(y);
	assert(x!=y);
	uf[x]=y;
	d[x]=addm(d[x],w);
}

int main(){
	JET
	ll n; cin>>n;
	mset(uf,-1);
	mset(d,0);
	fore(i,0,n){
		ll k; cin>>k;
		while(k--){
			ll v,w; cin>>v>>w; v--;
			uni(v,i,w);
		}
	}
	cout<<rta<<"\n";
	return 0;
}