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

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<string> a(n,string(m,'.'));
	fore(i,0,n)cin>>a[i];
	vector<vv>h(n+3,vv(m+3));
	auto add=[&](ll i0, ll i1, ll j0, ll j1){
		// cout<<"add "<<i0<<","<<i1<<" "<<j0<<","<<j1<<"\n";
		assert(j0==1);
		h[i0][j1]++;
		h[i1][j1]--;
	};
	auto fila=[&](vv a){ // {heights}
		// cout<<"fila "; imp(a)
		ll n=SZ(a);
		set<ll>st={-1,n};
		vector<ii> sa;
		fore(i,0,n)sa.pb({a[i],i});
		sort(ALL(sa));
		for(auto [x,i]:sa){
			ll l=0,r=0;
			ll le=*prev(st.lower_bound(i));
			ll ri=*st.lower_bound(i);
			if(le!=-1)l=a[le];
			if(ri!=n)r=a[ri];
			add(max(l,r)+1,x+1,1,ri-le-1);
			st.insert(i);
		}
	};
	
	vv v(m);
	fore(i,0,n){
		fore(j,0,m){
			v[j]++;
			if(a[i][j]=='*')v[j]=0;
		}
		fila(v);
	}
	
	vector<vv> ans(n+1,vv(m+3));
	vv s(m+3);
	fore(i,0,n+1){
		fore(j,0,SZ(s))s[j]+=h[i][j];
		ll d=0,q=0;
		for(ll j=m+2;j>=0;j--)q+=s[j],d+=q,ans[i][j]=d;
	}
	fore(i,1,n+1)fore(j,1,m+1)cout<<ans[i][j]<<" \n"[j==m];
	return 0;
}
