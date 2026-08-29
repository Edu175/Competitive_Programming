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
const ll MAXL=100005,MOD=1e4+7;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
string s;

ll dp[MAXL][10][2];

ll f(ll i, ll d, ll b){ // < s
	auto &res=dp[i][d][b];
	if(res!=-1)return res;
	if(i==SZ(s))return !b;
	ll e=!b?10:s[i]-'0'+1;
	ll od=(SZ(s)-i)%2;
	res=0;
	fore(j,0,e)if(!od||j==d){
		res=add(res,f(i+1,j,b&&j==e-1));
	}
	return res;
}

// char get(char a, char b){
// 	if(a<=b)return a;
// }

// ll f(string s){ // <=
// 	if(SZ(s)&1)s.insert(s.begin(),'0');
// 	string t;
// 	fore(i,0,SZ(s))if(i%2==0){
// 		t.pb(min(s[i],s[i+1]));
// 	}
// 	ll res=0;
// 	for(auto i:t)res=add(mul(res,10),i-'0');
// 	return res;
// }

ll get(string _s){
	s=_s;
	mset(dp,-1);
	return f(0,0,1);
	// if(SZ(s)&1)s=s.substr(1);
}

int main(){FIN;
	string l,r; cin>>l>>r;
	ll res=sub(get(r),get(l));
	ll fg=SZ(r)%2==0;
	if(fg){
		fore(i,0,SZ(r))if(i%2==0)fg&=r[i]==r[i+1];
		res=add(res,fg);
	}
	cout<<res<<"\n";
	return 0;
}
