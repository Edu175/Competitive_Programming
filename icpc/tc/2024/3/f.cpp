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
typedef unsigned long long ull;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937_64 rng(rd());
#define bint __int128
struct Hash {
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<bint>h,pi;
	Hash(){}
	Hash(string &s){
		assert(P*PI%MOD==1);
		h.resize(SZ(s)+1),pi.resize(SZ(s)+1);
		h[0]=0; pi[0]=1; bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD; p=p*P%MOD;
		}
	}
	ll get(int s, int e){
		return (h[e]-h[s]+MOD)%MOD*pi[s]%MOD;
	}
};
int main(){JET
	ll n,q; cin>>n>>q;
	string s; cin>>s;
	vector<Hash>h(26);
	fore(i,0,26){
		string t(n,'.');
		fore(j,0,n)if(s[j]-'a'==i)t[j]='e';
		h[i]=Hash(t);
	}
	fore(i,0,q){
		auto get=[&](ll l, ll r)->vector<ll>{
			// cout<<"query i get "<<l<<","<<r<<endl;
			vector<ll>st;
			fore(i,0,26)st.pb(h[i].get(l,r));
			sort(ALL(st));
			return st;
		};
		ll l0,l1,k; cin>>l0>>l1>>k; l0--,l1--;
		// cout<<"query i "<<l0<<" "<<l1<<" "<<k<<"\n";
		
		if(get(l0,l0+k)==get(l1,l1+k))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}