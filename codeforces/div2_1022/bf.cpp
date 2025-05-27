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

const ll MAXN=1e5+5;

ll a[MAXN];
ll n;

ll doit(vv id){
	vv b(n);
	fore(i,0,n)b[i]=a[i];
	auto apply=[&](ll i){
		fore(j,0,b[i]){
			ll p=i+1+j;
			if(p<n)b[p]++;
		}
		b[i]=0;
	};
	for(auto i:id)apply(i);
	set<ll>st;
	// cout<<"dot "; imp(id) imp(b) cout<<"\n\n";
	fore(i,0,n-1)if(b[i]>b[i+1])return -1;
	fore(i,0,n)st.insert(b[i]);
	fore(i,0,n+5)if(!st.count(i))return i;
	assert(0);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		vv per(n);
		iota(ALL(per),0);
		ll res=-1; vector<vv> bst={};
		do{
			ll resi=doit(per);
			if(resi>res)res=resi,bst={per};
			if(res==resi)bst.pb(per);
		}while(next_permutation(ALL(per)));
		cout<<res<<":\n";
		for(auto i:bst)imp(i)
	}
	return 0;
}
