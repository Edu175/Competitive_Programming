#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
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

ll lnds(vv a){
	vv v;
	for(auto i:a){
		ll p=upper_bound(ALL(v),i)-v.begin();
		if(p>=SZ(v))v.pb(i);
		else v[p]=i;
	}
	return SZ(v);
}

int main(){
    JET
	ll n; cin>>n;
	vv a(n);//,p(n);
	fore(i,0,n)cin>>a[i],a[i]--;//,p[a[i]]=i;
	vector<ii> rans;
	auto add_range=[&](ll l, ll r, ll fg){ // [,)
		// cout<<"range "<<l<<","<<r<<"\n";
		if(l<0||r>n)return;
		// cout<<"good\n";
		l*=2; r*=2;
		if(fg)r++;
		else l--;
		assert(l>=0&&r<=2*n);
		rans.pb({l,-r});
	};
	fore(i,0,n){
		ll x=a[i];
		// cout<<i<<" "<<x<<", i x :\n";
		add_range(x-(n-1-i), i, 1);
		add_range(i+1, n-1-(x-i)+1, 0);
		// cout<<"\n";
	}
	sort(ALL(rans));
	vv vec;
	for(auto [l,r]:rans)vec.pb(r);
	ll got=lnds(vec);
	ll res=n-got;
	// cerr<<"got "<<got<<"\n";
	cout<<res<<"\n";
    return 0;
}