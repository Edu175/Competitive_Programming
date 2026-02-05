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

ll k;
vector<array<ll,3>> s; // sum,-idx,is
bool can(ll m){
	ll n=SZ(s);
	assert(m<=k);
	vv po={1,n-k+1},cnt={k-m,m};
	vector<array<ll,3>> b;
	for(auto [sum,idx,is]:s){
		ll typ=cnt[is]>0; // 1 es arriba
		cnt[is]-=typ;
		sum+=po[typ]++;
		b.pb({sum,idx,is});
	}
	sort(ALL(b));
	reverse(ALL(b));
	ll got=0;
	fore(i,0,k)got+=b[i][2];
	return got>=m;
}

int main(){FIN;
	ll n; cin>>n>>k;
	s=vector<array<ll,3>>(n,{0,0,0});
	fore(i,0,n){
		ll is; cin>>is;
		fore(j,0,4){
			ll x; cin>>x;
			s[i][0]+=x;
		}
		s[i][1]=-i;
		s[i][2]=is;
	}
	sort(ALL(s));
	reverse(ALL(s));
	ll l=-1,r=k+1;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(m))l=m;
		else r=m;
	}
	ll m=l;
	cout<<m<<"\n";
	return 0;
}
