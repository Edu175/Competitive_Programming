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
	vector<ll>pot(5);
	pot[0]=1;
	fore(i,1,5)pot[i]=pot[i-1]*A;
	vector<ll>dp(pot[3]);
	fore(mk,0,SZ(dp)){	
		ll &res=dp[mk]; res=1;
		vector<ll>a(3);
		ll mki=mk;
		fore(i,0,3)a[i]=mki%A,mki/=A;
		fore(c,0,A){
			fore(i,0,3)res=mul(res,q[a[i]][c]);
		}
	}
	
}
const ll MAXV=11;
int main(){FIN;
	ll n; cin>>n;
	vector<string> b[MAXV];
	fore(i,0,n){
		string s;cin>>s;
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