#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv get(vv a){
	vv v;
	ll n=SZ(a);
	vv ans(n);
	fore(i,0,n){
		ll p=lower_bound(ALL(v),a[i])-v.begin();
		ans[i]=p;
		if(p>=SZ(v))v.pb(a[i]);
		else v[p]=a[i];
	}
	return ans;
}

int main(){
	
	#ifdef ONLINE_JUDGE
	freopen("improvements.in","r",stdin);     freopen("improvements.out","w",stdout);
	#endif

	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n){
		ll p; cin>>p; p--;
		a[p]=i;
	}
	// cout<<"a: ";for(auto i:a)cout<<i<<" ";;cout<<"\n";
	vv l=get(a);
	// cout<<"l: ";for(auto i:l)cout<<i<<" ";;cout<<"\n";
	reverse(ALL(a));
	vv r=get(a);
	reverse(ALL(r));
	// cout<<"r: ";for(auto i:r)cout<<i<<" ";;cout<<"\n";
	ll res=0;
	fore(i,0,n)res=max(res,l[i]+1+r[i]);
	cout<<res<<"\n";
	return 0;
	
}