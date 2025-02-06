#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e10;

int main(){
	JET
	ll n,k,q; cin>>n>>k>>q;
	vv a(n),po(n),sp(n+1);
	fore(i,0,n)cin>>a[i];
	ll prev=0;
	while(q--){
		ll l,r; cin>>l>>r;
		l^=prev; r^=prev; r++;
		// cout<<"query "<<l<<" "<<r<<"\n";
		auto out=[&](ll m){return m<l||r<=m;};
		ll res=0;
		vv ops;
		fore(i,l,r){
			ll p=n-1-i;
			if(out(p)&&a[p]>a[i])ops.pb(a[p]-a[i]);
			res+=a[i];
		}
		sort(ALL(ops));
		reverse(ALL(ops));
		fore(i,0,min(SZ(ops),k))res+=ops[i];
		cout<<res<<"\n";
		// cout<<endl;
		prev=res;
	}
	return 0;
}