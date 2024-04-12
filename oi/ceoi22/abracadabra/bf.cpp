#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ceoi=b;i<ceoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto kdjfhg:v)cout<<kdjfhg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<ll> f(vector<ll>a){
	vector<ll>l,r;
	ll n=SZ(a);
	fore(i,0,n/2)l.pb(a[i]);
	fore(i,n/2,n)r.pb(a[i]);
	vector<ll>b;
	reverse(ALL(l)); reverse(ALL(r));
	while(SZ(l)+SZ(r)){
		if(!SZ(r)||(SZ(l)&&l.back()<r.back()))b.pb(l.back()),l.pop_back();
		else b.pb(r.back()),r.pop_back();
	}
	return b;
}

int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vector<vector<ll>>b={a};
	while(1){
		//imp(a);
		auto a_=f(a);
		if(a_==a)break;
		a=a_;
		b.pb(a);
	}
	while(q--){
		ll t,i; cin>>t>>i; i--;
		t=min(t,(ll)SZ(b)-1);
		cout<<b[t][i]+1<<"\n";
	}
	return 0;
}
