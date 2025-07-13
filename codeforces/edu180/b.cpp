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

void mkmn(ll &a, ll b){
	if(b!=-1&&(a==-1||b<a))a=b;
}
ll get(vv a){
	ll n=SZ(a);
	ll res=-1;
	fore(i,0,n-1){
		ll l=a[i+1],r=l;
		ll cur=-1;
		fore(j,i+1,n){
			l=min(l,a[j]);
			r=max(r,a[j]);
			ll bad=a[i]<l-1||r+1<a[i];
			if(!bad)mkmn(cur,j-i-1);
		}
		mkmn(res,cur);
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll res=get(a);
		reverse(ALL(a));
		mkmn(res,get(a));
		cout<<res<<"\n";
	}
	return 0;
}
