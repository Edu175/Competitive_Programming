#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define xs first 
#define ys second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn=1e5+5;
ii p[maxn],b[maxn];
vv bu[2][2*maxn],rbu[2][2*maxn];
void add(ll i, ll t){
	ll x=b[i].xs;
	ll y=b[i].ys;
	if(t) swap(x,y);
	x+=maxn;
	bu[t][x].pb(y);
	rbu[t][x].pb(-y);
}
void pross_all(){
	fore(t,0,2){
		for(auto &v:bu[t]){
			sort(ALL(v));
		}
		for(auto &v: rbu[t]){
			sort(ALL(v));
		}
	}
}
ll where(ll x){
	return x+maxn;
}
ll d[maxn];
int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,n) cin>>p[i].xs>>p[i].ys;
	fore(i,0,m) cin>>b[i].xs>>b[i].ys;
	fore(i,0,m) add(i,0),add(i,1);
	
	pross_all();
	ll ub=m-1;
	fore(i,0,n){
		ll j=(i+1)%n;
		ll x,t;
		ll y1,y2;
		
		if(p[i].xs==p[j].xs){
			x=p[i].xs;
			t=0;
			y1=p[i].ys,y2=p[j].ys;
		}
		else x=p[i].ys,t=1,y1=p[i].xs,y2=p[j].xs;
		
		assert(y1!=y2);
		ll id=where(x);
		auto &B=(y1<y2?bu[t][id]:rbu[t][id]);
		
		if(y1>y2) y1=-y1,y2=-y2;
		ll l=lower_bound(ALL(B),y1)-B.begin();
		ll r=lower_bound(ALL(B),y2)-B.begin();
		
		assert(l<=r);
		
		ll uv=y1;
		fore(k,l,r){
			d[ub]+=B[k]-uv;
			ub=(ub+1)%m;
			uv=B[k];
		}
		d[ub]+=y2-uv;
	}
	
	ll r=0,mn=0;
	fore(i,0,m){
		// cout<<d[i]<<"di\n";
		mn=max(d[i],mn);
		r+=d[i];
	}
	cout<<r-mn<<"\n";
	return 0;
}