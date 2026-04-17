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
const ll INF=1e18;

ll both(ll w, ll h, ll k){
	while(k--)(w<h?w:h)++;
	return h*w;
}

ll esq(ll x, ll y, ll w, ll h, ll k){
	return max(w,x+k+1)*max(h,y+k+1);
}
ll doit(ll x, ll y, ll w, ll h, ll k){
	ll res=0;
	fore(i,0,2)fore(j,0,2){
		ll xc=x,yc=y;
		if(i)xc=w-1-xc;
		if(j)yc=h-1-yc;
		res=max(res,esq(xc,yc,w,h,k));
	}
	return res;
}
int main(){FIN;
	ll n,k; cin>>n>>k;
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	vv mn(2,INF),mx(2,-INF);
	vector<vv> a(n,vv(2));
	fore(i,0,n){
		fore(j,0,2){
			ll x; cin>>x;
			a[i][j]=x;
			mn[j]=min(mn[j],x);
			mx[j]=max(mx[j],x);
		}
	}
	ll w=mx[0]-mn[0]+1;
	ll h=mx[1]-mn[1]+1;
	ll res=both(w,h,k);
	fore(i,0,n)res=max(res,doit(a[i][0]-mn[0],a[i][1]-mn[1],w,h,k));
	cout<<res<<"\n";
	return 0;
}