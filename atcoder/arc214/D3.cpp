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

#define maxig(a,b) a=max(a,b)

int main(){FIN;
	ll n; cin>>n;
	vector<vv> a(n,vv(n));
	vector<pair<ii,ll>> paths={{{0,0},0}};
	ll d=2*n-1;
	vector<vector<ii>> pos(d);
	fore(i,0,n)fore(j,0,n)pos[i+j].pb({i,j});
	fore(k,1,d-1){
		ll mx=0; for(auto i:paths)mx=max(mx,i.snd);
		// if(k==d-1){
		// 	// cerr<<"mx "<<mx<<"\n";
		// 	break;
		// }
		mx++;
		auto &v=pos[k];
		reverse(ALL(v));
		for(auto [i,j]:v)if((i)%2==(n-1)%2){
			a[i][j]=mx;
		}
		map<ii,ll> mp;
		for(auto [fst,s]:paths){
			auto [i,j]=fst;
			if(i==n-1||j==n-1)continue;
			if(i+1<n-(0))maxig((mp[{i+1,j}]),s+a[i+1][j]);
			if(j+1<n-(0))maxig((mp[{i,j+1}]),s+a[i][j+1]);
		}
		paths.clear();
		for(auto i:mp)paths.pb(i);
	}
	auto check=[&](){
		set<ll> st;
		ll cnt=0;
		auto f=[&](ll i, ll j, ll s, auto &&f){
			s+=a[i][j];
			if(i==n-1&&j==n-1){
				cnt++;
				st.insert(s);
				return;
			}
			if(i+1<n)f(i+1,j,s,f);
			if(j+1<n)f(i,j+1,s,f);
		};
		f(0,0,0,f);
		cout<<endl;
		cerr<<"mx "<<*st.rbegin()<<"\n";
		cerr<<SZ(st)<<" "<<cnt<<"\n";
		assert(cnt==SZ(st));
	};
	fore(i,0,n){
		imp(a[i])
	}
	check();
	return 0;
}
