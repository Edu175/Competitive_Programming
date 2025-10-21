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
const ll INF=1e18,MOD=1e9+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	ll q; cin>>q;
	set<ll> st={-INF,INF};
	ll res=1;
	ll L=-INF,R=INF;
	while(q--){
		string ty; ll p; cin>>ty>>p;
		if(ty=="ADD")st.insert(p);
		else {
			auto it=st.lower_bound(p);
			ll izq=*prev(it),der=*next(it);
			// cout<<p<<": "<<L<<","<<R<<" "<<izq<<" "<<der<<"\n";
			if(der<=L||R<=izq)res=0;
			if(L<p&&p<R)res=mul(res,2);
			L=izq,R=der;
			st.erase(it);
		}
	}
	ll cant=0;
	for(auto p:st)cant+=(L<p&&p<R);
	res=mul(res,cant+1);
	cout<<res<<"\n";
	return 0;
}
