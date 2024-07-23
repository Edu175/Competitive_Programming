#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll N=20,MAXN=1ll<<N;

ll dp[MAXN],minsal[MAXN],sal[MAXN];
vector<ll>h[MAXN];
ll n;
ll f(ll mk, ll s){
	ll &res=dp[mk];
	if(res!=-1)return res;
	if(mk==0)return res=0;
	fore(i,0,n)if(mk>>i&1){
		ll resi=s<SZ(h[i])?h[i][s]:0;
		if(s+minsal[i]>=0)resi+=f(mk^(1ll<<i),s+sal[i]);
		res=max(res,resi);
	}
	// cout<<mk<<" "<<s<<": "<<res<<"\n";
	return res;
}

int main(){
	JET
	cin>>n;
	fore(i,0,n){
		string s; cin>>s;
		ll m=SZ(s);
		vector<ll>v(m);
		h[i]=vector<ll>(m+5);
		fore(i,0,m)v[i]=(i?v[i-1]:0)+(s[i]=='('?1:-1);
		// minsal[i]=v[0];
		sal[i]=v.back();
		fore(j,0,m){
			minsal[i]=min(minsal[i],v[j]);
			if(minsal[i]>=v[j])h[i][-v[j]]++;
		}
		// cout<<i<<": "<<minsal[i]<<" "<<sal[i]<<"\n";
		// for(auto j:h[i])cout<<j<<" ";;cout<<"\n";
	}
	mset(dp,-1);
	ll res=f((1ll<<n)-1,0);
	cout<<res<<"\n";

	return 0;
}


/*


4
()()())
(
(
)




*/