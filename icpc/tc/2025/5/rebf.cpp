#include<bits/stdc++.h>
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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b); e>>=1;
	}
	return res;
}

ll n; // < 30
vv a;
ll res=0;
void f(ll s, ll v){
	if(s<0||v<0)return;
	if(SZ(a)==n){
		if(s==0&&v==0){
			res++;
			for(auto i:a)cerr<<i<<" ";;cerr<<"\n";
		}
		return;
	}
	fore(j,0,SZ(a)+1){
		ll ad=SZ(a)?a.back()<j:0;
		a.pb(j);
		f(s-j,v-ad);
		a.pop_back();
	}
}


int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll k,x; cin>>n>>k>>x;
		res=0;
		f(k,x);
		cout<<res<<"\n";
	}
	return 0;
}