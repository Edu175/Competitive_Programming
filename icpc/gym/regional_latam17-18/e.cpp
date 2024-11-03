#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005;

ll dp[MAXN][MAXN];
string s;
ll pot[MAXN];
ll k,n;
ll f(ll i, ll r){
	ll &res=dp[i][r];
	if(res!=-1)return res;
	if(i==n)return res=r==0;
	auto pongo=[&](ll d){
		return f(i+1,(r+d*pot[i])%k);
	};
	if(s[i]!='?')return res=pongo(s[i]-'0');
	res=0;
	fore(d,(i?0:1),10)res|=pongo(d);
	return res;
}

string ans;
void build(ll i, ll r){
	if(i==n)return;
	auto pongo=[&](ll d){
		return f(i+1,(r+d*pot[i])%k);
	};
	ll d=-1;
	if(s[i]!='?')d=s[i]-'0';
	else {
		fore(j,(i?0:1),10)if(pongo(j)){d=j;break;}
	}
	assert(d!=-1);
	ans.pb('0'+d);
	build(i+1,(r+d*pot[i])%k);
}

int main(){ET;
	cin>>s>>k;
	n=SZ(s);
	pot[n-1]=1%k;
	for(ll i=n-2;i>=0;i--)pot[i]=pot[i+1]*10%k;
	mset(dp,-1);
	ll can=f(0,0);
	if(!can){
		cout<<"*\n";
		return 0;
	}
	build(0,0);
	cout<<ans<<"\n";
}