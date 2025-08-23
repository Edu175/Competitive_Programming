#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=705,MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
string s;
ll n;
ll dp[MAXN][10][MAXN][2];
ll num(ll i, ll d, ll q, ll bo){
	if(q<0)return 0;
	auto &res=dp[i][d][q][bo];
	if(res!=-1)return res;
	if(i==n)return res=q==0;
	ll e=s[i]-'0';
	if(!bo)e=9;
	res=0;
	fore(j,0,e+1){
		res=add(res,num(i+1,d,q-(j>=d),bo&&j==e));
	}
	return res;
}


int main(){
	JET
	mset(dp,-1);
	cin>>s;
	n=SZ(s);
	ll res=0;
	fore(d,1,10){
		ll sum=1;
		fore(q,1,n+1){
			ll cant=num(0,d,q,1);
			res=add(res,mul(sum,cant));
			// cout<<d<<": "<<sum<<" "<<cant<<": "<<mul(sum,cant)<<"\n";
			sum=mul(sum,10);
			sum=add(sum,1);
		}
	}
	cout<<res<<"\n";
	
	return 0;
}


