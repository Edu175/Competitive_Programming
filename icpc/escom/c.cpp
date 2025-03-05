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
const ll MOD=998244353; // como qu eno era 1e9+7
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
int main(){FIN;
	vector<ll> es,dig;
	string s;
	fore(j,0,2){
		cin>>s;
		fore(i,0,SZ(s)){
			es.pb(i);
			dig.pb(s[i]-'0');
		}
	}
	sort(ALL(es));
	sort(ALL(dig));
	ll res=0;
	fore(i,0,SZ(es)){
		res=add(res,mul(dig[i],fpow(10,es[i])));
	}
	cout<<res<<"\n";
	return 0;
}
