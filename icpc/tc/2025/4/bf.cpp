#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

#define ppc __builtin_popcountll

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(l,0,n)fore(r,l+1,n+1){
		ll mn=a[l],mx=a[l];
		fore(i,l,r){
			mn=min(mn,a[i]);
			mx=max(mx,a[i]);
		}
		if(ppc(mn)==ppc(mx)){
			if(r-l>1)cerr<<l<<" "<<r<<"\n";
			res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}