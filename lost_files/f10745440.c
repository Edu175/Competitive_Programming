#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll maxn=100005;
ll n;
ll a[maxn][3];
ll dp[maxn][3];

ll activ(ll i,ll ac){
	if(dp[i][ac]!=-1)return dp[i][ac];
	set<ll>st={0,1,2};
	if(i)st.erase(ac);
	ll maxi=0;
	for(auto j:st)maxi=max(maxi,a[i][j]);
	if(i==n-1)return dp[i][ac]=maxi;
	ll res=0;
	for(auto j:st)res=max(res,a[i][j]+activ(i+1,j));
	return dp[i][ac]=res;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)fore(j,0,3)cin>>a[i][j];
	mset(dp,-1);
	cout<<activ(0,0);
	return 0;
}
