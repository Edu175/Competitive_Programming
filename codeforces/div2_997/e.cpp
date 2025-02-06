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
// #define impr(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ //must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}

// number of Regular Bracket Sequences of size n (n ()'s)
ll rbs(ll n){
	return sub(nCr(2*n,n),nCr(2*n,n-1));
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		set<ii>st;
		fore(i,0,n)st.insert({i,i+1});
		vector<ii>a(m);
		fore(i,0,m)cin>>a[i].fst>>a[i].snd,a[i].fst--;
		sort(ALL(a),[&](ii a, ii b){return a.snd-a.fst<b.snd-b.fst;});
		a.pb({0,n});
		ll res=1;
		for(auto [l,r]:a){
			ll q=0;
			for(auto it=st.lower_bound({l,-1});it!=st.end()&&it->fst<r;q++,it=st.erase(it));
			st.insert({l,r});
			res=mul(res,rbs(q-1));
		}
		cout<<res<<"\n";
	}
	return 0;
}
