#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

int consulta(int i,int W,int H);
map<pair<ll,pair<ll,ll>>,ll>did;
ll ask(ll i, ll w, ll h){
	w=max(w,ll(1)),h=max(h,(ll)1);
	pair<ll,pair<ll,ll>>p={i,{w,h}};
	if(did.count(p))return did[p];
	return did[p]=consulta(i,w,h);
}

int rectangulos(vector<int> x, vector<int> y) {
    ll n=SZ(x);
    /*cout<<n<<"\n";
    imp(xe); imp(ye);*/
    set<ll> sx,sy;
    fore(i,0,n)sx.insert(x[i]);
    vector<ll>bx;
    for(auto i:sx)bx.pb(i);
    /*fore(i,0,n)x[i]=xe[i],y[i]=ye[i];
      imp(x); imp(y);*/
     ll minx=0,miny=0;
    fore(i,0,n){
    	if(x[i]<x[minx])minx=i;
    	if(y[i]<y[miny])miny=i;
    }
    ll l=0,r=SZ(bx);
    while(l<=r){
    	ll m=(l+r)/2;
    	if(ask(minx+1,2*(bx[m]-x[minx]),2e9))r=m-1;
    	else l=m+1;
    }
    ll X=bx[l];
    fore(i,0,n)if(x[i]==X)sy.insert(y[i]);
    vector<ll>by;
    for(auto i:sy)by.pb(i);
    l=0,r=SZ(by);
    while(l<=r){
    	ll m=(l+r)/2;
    	if(ask(miny+1,2e9,2*(by[m]-y[miny])))r=m-1;
    	else l=m+1;
    }
    ll Y=by[l];
    ll res=0;
    fore(i,0,n)if(x[i]==X&&y[i]==Y)res=i;
    //cout<<X<<" "<<Y<<"\n";
    return res+1;
}
