#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);
#define imp(v) {for(auto i:v)cerr<<i<<" ";cerr<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;
const ll MAXN=2e5+5;

vv lis(vv a){
	vv v;
	vv ans(SZ(a));
	ll idx=0;
	for(auto i:a){
		ll p=lower_bound(ALL(v),i)-v.begin();
		if(p>=SZ(v))v.pb(i);
		else v[p]=i;
		ans[idx]=SZ(v);
		idx++;
	}
	// cerr<<"lis ";
	// imp(a)
	// imp(ans)
	return ans;
}

ll n;
ll a[MAXN];
ll ans[MAXN];
void rec(ll l, ll r, vector<array<ll,3>> qs){
	if(!SZ(qs))return;
	ll m=(l+r)/2;
	
	// cerr<<"\nrec "<<l<<","<<r<<"\n";
	// cerr<<"barra "<<m<<"\n";
	vv al,ar;
	fore(i,l,m)al.pb(a[i]);
	fore(i,m,r)ar.pb(a[i]);
	reverse(ALL(al));
	for(auto &i:al)i=-i;
	vv lisl=lis(al); reverse(ALL(lisl));
	vv lisr=lis(ar);
	// imp(lisl)
	vector<array<ll,3>> L,R;
	for(auto [s,e,i]:qs){
		if(e<=m)L.pb({s,e,i});
		else if(m<=s)R.pb({s,e,i});
		else {
			ll pl=lisl[s-l];
			ll pr=lisr[e-1-m];
			if(pl==1&&pr==1){
				ans[i]=1+(a[m-1]<a[m]);
			}
			else {
				ans[i]=max(pl,pr)*3/2;
			}
			// cerr<<"ans "<<i<<": "<<s<<","<<e<<": "<<pl<<" "<<pr<<"\n";
		}
	}
	// exit(0); // 
	if(r-l>1){
		rec(l,m,L);
		rec(m,r,R);
	}
}

int main(){
	FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>n>>q;
		fore(i,0,n)cin>>a[i];
		vector<array<ll,3>> qs(q);
		fore(i,0,q){
			ll l,r; cin>>l>>r; l--;
			qs[i]={l,r,i};
			if(r-l==1)ans[i]=1;
		}
		rec(0,n,qs);
		fore(i,0,q)cout<<ans[i]<<"\n";
	}
	return 0;
}