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
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
const ll MAXK=27;
// counting k strong codes
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
string R; // count <
ll k;
// bo: prefix equal to R
gp_hash_table<int,ll> dp[MAXK][MAXK][2][2];

ll antes=clock(),cont=0;
ll f(ll i, ll s, ll bo, ll did, ll mk){
	if(i==SZ(R))return !bo;
	auto &ht=dp[i][s][bo][did];
	auto it=ht.find(mk);
	if(it!=ht.end())return it->snd;
	auto &res=ht[mk];
	res=0;
	
	cont++;
	if(clock()-antes>3*CLOCKS_PER_SEC){
		cerr<<i<<" "<<s<<" "<<bo<<" "<<did<<" "<<mk<<"\n";
		cerr<<cont<<"\n";
		antes=clock();
	}
	ll e=bo?R[i]-'0':9;
	// ll E=e;
	// if(SZ(R)-i>=k)E=0;
	fore(d,0,e+1){
		ll s2=(s+d)%k;
		ll did2=did||(d!=0);
		if(did2&&(mk>>s2&1))continue;
		mk^=did2<<s2;
		res+=f(i+1,s2,bo&&d==e,did2,mk);
		mk^=did2<<s2;
	}
	assert(res<MOD);
	return res;
}

ll doit(string r){
	if(SZ(r)>=k){
		r=string(k,'0');
		r[0]++;
	}
	fore(i,0,MAXK)fore(j,0,MAXK)fore(k,0,2)fore(l,0,2)dp[i][j][k][l].clear();
	R=r;
	ll res=f(0,0,1,0,1);
	return res;
}
ll val(string s){
	ll res=0;
	for(auto i:s){
		i-='0';
		res=add(mul(res,10),i);
	}
	return res;
}
int main(){FIN;
	// mset(dp,-1);
	ll t; cin>>t;
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		string l,r; cin>>l>>r>>k;
		
		// sumo 1 a r
		ll p=-1;
		fore(i,0,SZ(r))if(r[i]!='9')p=i;
		if(p==-1)r.insert(r.begin(),'0'),p++;
		r[p]++;
		fore(i,p+1,SZ(r))r[i]='0';
		// done
		
		ll res=doit(r)-doit(l);
		assert(res<MOD);
		
		ll ans=sub(val(r),val(l));
		ans=sub(ans,res);
		cerr<<res<<" ";
		cout<<ans<<"\n";
	}
	return 0;
}
