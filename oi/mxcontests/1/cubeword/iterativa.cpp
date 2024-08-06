#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
// #pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MOD=998244353,MAXA=62;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(LL a, LL b){return a*b%MOD;}

ll A; //alphabet
vector<vector<ll>> g={
	{},
	{0},
	{0},
	{0},
	{1,2},
	{1,3},
	{2,3},
	{4,5,6}
};
ll q[62][62];
vector<ll>bor={0,0,0,1,0,1,2,4},tam={1,2,3,3,4,4,3,0,0};
vector<ll>pot(6);

vector<ll>dp[8];

ll get(ll i, ll j, ll h){
	ll p=i-1-j;
	ll ret=h/pot[p]%A;
	// cout<<"get "<<i<<" "<<j<<" "<<h<<": "<<p<<": "<<ret<<"\n";
	return ret;
}
ll go(ll i, ll h, ll c){
	return (h*A+c)%pot[tam[i]];
}
ll solve(vector<string>&a){
	if(!SZ(a))return 0;
	// cout<<"solve "; imp(a);
	ll n=SZ(a);
	vector<char>c;
	fore(i,0,n)c.pb(a[i][0]),c.pb(a[i].back());
	sort(ALL(c));
	vector<char> ci;
	fore(i,0,SZ(c))if(!i||c[i]!=c[i-1])ci.pb(c[i]);
	c=ci;
	for(auto &s:a){
		auto change=[&](char &j){
			ll p=lower_bound(ALL(c),j)-c.begin();
			j=p;
		};
		change(s[0]); change(s.back());
	}
	// imp(a);
	A=SZ(c);
	set<string> st[A][A];
	for(auto s:a){
		st[int(s[0])][int(s.back())].insert(s);
		reverse(ALL(s));
		st[int(s[0])][int(s.back())].insert(s);
	}
	fore(i,0,A)fore(j,0,A)q[i][j]=SZ(st[i][j]);
	/*fore(i,0,A){
		imp(q[i]);
	}*/
	pot[0]=1;
	fore(i,1,6)pot[i]=pot[i-1]*A;
	
	//dp
	vector<ll>dp[2];
	fore(i,0,2)dp[i].resize(pot[4]);
	dp[8&1][0]=1;
	for(ll i=7;i>=0;i--){
		ll w=i&1;
		fore(h,0,pot[(i?tam[i-1]:0)]){
			ll &res=dp[w][h]; res=0;
			fore(c,0,A){// pongo c
				ll resi=1;
				for(auto j:g[i]){
					ll d=get(i,j,h);
					resi=mul(resi,q[c][d]);
				}
				// cout<<i<<""
				if(resi)res=add(res,mul(resi,dp[w^1][go(i,h,c)]));
			}
		}
		// cout<<i<<" "<<h<<": "<<res<<"\n";
	}
	ll res=dp[0][0];
	return res;
}
const ll MAXV=11;
int main(){FIN;
	ll n; cin>>n;
	vector<string> b[MAXV];
	fore(i,0,n){
		string s; cin>>s;
		b[SZ(s)].pb(s);
	}
	ll res=0;
	fore(i,0,MAXV){
		res=add(res,solve(b[i]));
	}
	// res=solve(b[5]);
	cout<<res<<"\n";
	return 0;
}