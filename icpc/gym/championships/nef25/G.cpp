#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size()) 
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<endl;}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET 
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll mn=*min_element(ALL(a));
		mn|=1,mn--;
		for(auto &i:a)i-=mn;
		auto ptr=find(ALL(a),0);
		ll p=ptr-a.begin();
		rotate(a.begin(),a.begin()+(p+1)%n,a.end());
		show(a);
		ll sum=mn*n;
		vv b(n);
		fore(i,0,n-1){
			ll q=min(a[i],a[i+1]);
			b[i]=q;
			a[i]-=q,a[i+1]-=q;
		}
		show(a);
		// assert(a==vv(n,0));
		ll cant=mn/2+*max_element(ALL(b));
		sum+=accumulate(ALL(b),0ll);
		ll res=max(cant,(sum+n-2)/(n-1));
		cout<<res<<"\n";
	}
    return 0;
}
