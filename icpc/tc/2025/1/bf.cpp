#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll k;
bool good(vv a){
	ll n=SZ(a);
	ll fg=0;
	fore(e,1,n){
		ll mn=a[0],mx=a.back();
		fore(i,0,n){
			if(i<e)mn=min(mn,a[i]);
			else mx=max(mx,a[i]);
		}
		fg|=mn+mx==k;
	}
	return fg;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0;
		fore(l,0,n)fore(r,l+1,n+1){
			vv b;
			fore(i,l,r)b.pb(a[i]);
			if(good(b)){
				cerr<<l<<" "<<r<<"\n";
				res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}