#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" ";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MAXMK=1e6;

int dp[1594323+5][2];
ll pot[15];
ll n; // # of cards
ll get(vv &a){
	ll mk=0;
	fore(i,0,n)mk+=pot[i]*a[i];
	return mk;
};

vv all;

int f(vv a, ll p){
	auto &res=dp[get(a)][p];
	if(res!=-1)return res;
	auto go=[&](ll i, ll j){ // tiro i, agarro j
		vv ai=a;
		assert(ai[i]==p);
		ai[i]=2;
		if(j!=-1){
			assert(ai[j]==2);
			ai[j]=p;
		}
		auto ret=f(ai,p^1);
		// imp(a); cout<<"| "<<p<<" go "<<i<<" "<<j<<": "<<ret<<"\n";
		return ret;
	};
	res=1;
	fore(i,0,n)if(a[i]==p){
		res&=go(i,-1);
		fore(j,0,i)if(a[j]==2&&all[j]<all[i])res&=go(i,j);
	}
	res^=1;
	// imp(a); cout<<"| "<<p<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	pot[0]=1;
	fore(i,1,15)pot[i]=pot[i-1]*3;
	vv ns(3);
	fore(i,0,3)cin>>ns[i];
	mset(dp,-1);
	vv h[3];
	fore(k,0,3){
		h[k].resize(ns[k]);
		fore(i,0,ns[k])cin>>h[k][i],all.pb(h[k][i]);
	}
	n=SZ(all);
	sort(ALL(all));
	map<ll,ll>mp;
	auto id=[&](ll v){
		return (mp[v]++)+lower_bound(ALL(all),v)-all.begin();};
	vv t(n,-1);
	fore(k,0,3)for(auto i:h[k])t[id(i)]=k;
	// cout<<n<<" n\n";
	// imp(all); cout<<"\n";
	// imp(t); cout<<"\n";
	ll res=f(t,0);
	// cout<<res<<"\n";
	if(res)cout<<"Takahashi\n";
	else cout<<"Aoki\n";
	return 0;
}
