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

vv lis(vv a){ // elements
	ll n=SZ(a);
	vv v;
	vv fa(n,-1);
	ll bst=0;
	fore(i,0,n){
		ll p=lower_bound(ALL(v),a[i])-v.begin();
		if(p>=SZ(v))v.pb(a[i]),bst=a[i];
		else v[p]=a[i];
		if(p)fa[a[i]]=v[p-1];
	}
	vv ret;
	for(ll x=bst;x!=-1;x=fa[x])ret.pb(x);
	reverse(ALL(ret));
	return ret;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vv b(m);
	fore(i,0,m)cin>>b[i],b[i]--;
	if(n<m)swap(n,m),swap(a,b);
	auto _a=a; a.clear();
	for(auto i:_a)if(i<m)a.pb(i);
	n=SZ(a);
	assert(n==m);
	vv pos(n);
	fore(i,0,n)pos[a[i]]=i;
	vv v;
	fore(i,0,n)v.pb(pos[b[i]]);
	auto got=lis(v);
	vv res;
	for(auto i:got)res.pb(a[i]);
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
	return 0;
}
