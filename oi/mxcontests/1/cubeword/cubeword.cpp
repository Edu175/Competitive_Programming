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
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MOD=998244353,MAXA=62;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(LL a, LL b){return a*b%MOD;}

ll A; //alphabet
vector<vector<ll>> q,g={
	{},
	{0},
	{0},
	{0},
	{1,2},
	{1,3},
	{2,3},
	{4,5,6}
};
vector<ll>bor={0,0,0,1,0,1,2,4},tam={1,2,3,3,4,4,3,0};
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
vector<ii>vis;
inline ll f(ll i, ll h){
	if(i==8)return 1;
	ll &res=dp[i][h];
	if(res!=-1)return res;
	res=0;
	vis.pb({i,h});
	fore(c,0,A){// pongo c
		ll resi=1;
		for(auto j:g[i]){
			ll d=get(i,j,h);
			resi=mul(resi,q[c][d]);
		}
		// cout<<i<<""
		if(resi)res=add(res,mul(resi,f(i+1,go(i,h,c))));
	}
	// cout<<i<<" "<<h<<": "<<res<<"\n";
	return res;
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
	q=vector<vector<ll>>(A,vector<ll>(A));
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
	ll res=f(0,0);
	cout<<"visited "<<SZ(vis)<<" states"<<endl;
	for(auto [i,j]:vis)dp[i][j]=-1;
	vis.clear();
	return res;
}
const ll MAXV=11;
int main(){FIN;
	ll n; cin>>n;
	vector<string> b[MAXV];
	fore(i,0,n){
		string s;cin>>s;
		b[SZ(s)].pb(s);
	}
	vector<ll>POT={1};
	fore(i,0,5)POT.pb(POT.back()*MAXA);
	fore(i,0,8){
		dp[i]=vector<ll>(POT[(i?tam[i-1]:0)],-1);
		// cout<<i<<": "<<SZ(dp[i])<<"\n";
	}
	// imp(POT); cout<<endl;
	ll res=0;
	fore(i,0,MAXV){
		res=add(res,solve(b[i]));
	}
	// res=solve(b[5]);
	cout<<res<<"\n";
	return 0;
}