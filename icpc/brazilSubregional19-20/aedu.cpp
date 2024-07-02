#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
ll sq(ll a){return a*a;}
ll dis(ii a, ii b){
	return sq(a.fst-b.fst)+sq(a.snd-b.snd);
}
const ll MAXN=1010;
ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll uf_join(ll x, ll y){
	x=uf_find(x),y=uf_find(y);
	if(x==y)return 0;
	if(-uf[x]<-uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
	return 1;
}
int main(){FIN
	ll n,m,k; cin>>n>>m>>k;
	uf_init();
	vector<pair<ii,ll>>a;
	fore(i,0,k){
		ll x,y,r; cin>>x>>y>>r;
		a.pb({{x,y},r});
	}
	fore(i,0,k)fore(j,i+1,k){
		if(dis(a[i].fst,a[j].fst)<=sq(a[i].snd+a[j].snd))uf_join(i,j);
	}
	fore(i,0,k){
		auto [p0,r]=a[i];
		auto [x,y]=p0;
		if(x<=r)uf_join(i,k+0);
		if(y<=r)uf_join(i,k+1);
		if(x+r>=n)uf_join(i,k+2);
		if(y+r>=m)uf_join(i,k+3);
	}
	ll res=1;
	fore(i,0,4)fore(j,1,3)res&=uf_find(k+i)!=uf_find(k+(i^j));
	if(res)cout<<"S\n";
	else cout<<"N\n";
	return 0;
} 