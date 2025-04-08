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

ll mex(vv a){
	set<ll>st;
	for(auto i:a)st.insert(i);
	ll ret=0;
	while(st.count(ret))ret++;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll mn=-1,mx=-1,did=0;
		fore(l,1,n-1)fore(r,l+1,n){
			vv lhs,mhs,rhs;
			fore(i,0,n){
				if(i<l)lhs.pb(a[i]);
				else if(i<r)mhs.pb(a[i]);
				else rhs.pb(a[i]);
			}
			if(mex(lhs)==mex(mhs)&&mex(mhs)==mex(rhs)){
				ll resi=accumulate(ALL(lhs),0ll)-accumulate(ALL(mhs),0ll)+accumulate(ALL(rhs),0ll);
				if(!did||resi<mn)mn=resi;
				if(!did||resi>mx)mx=resi;
				did=1;
			}
		}
		cout<<mn<<" "<<mx<<"\n";
		
	}
	return 0;
}
