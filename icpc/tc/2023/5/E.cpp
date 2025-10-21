#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<int> kmppre(string& t){ // r[i]: longest border of t[0,i)
	vector<int> r(t.size()+1);r[0]=-1;
	int j=-1;
	fore(i,0,t.size()){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}

int main(){FIN;
	string a,b,v; cin>>a>>b>>v;
	vector<int> r=kmppre(v);
	auto go=[&](ll j, char c){
		while(j>=0&&c!=v[j])j=r[j];
		return ++j;
	};
	ll n=SZ(a),m=SZ(b),k=SZ(v);
	vector<vector<vv>> dp(n+3,vector<vv>(m+3,vv(k+3)));
	// vector<vector<vv>> to(n+3,vector<vv>(m+3,vv(k+3,-1)));
	forr(i,0,n)forr(j,0,m)fore(l,0,k){
		auto &res=dp[i][j][l];
		res=dp[i+1][j][l];
		res=max(res,dp[i][j+1][l]);
		if(a[i]==b[j]){
			ll lp=go(l,a[i]);
			if(lp<k){ // no lo quiero contener
				ll cur=1+dp[i+1][j+1][lp];
				res=max(res,cur);
				// if(cur>res)to[i][j][l]=lp,res=cur;
			}
		}
	}
	ll i=0,j=0,l=0;
	string ans;
	while(i<n&&j<m){
		auto &res=dp[i][j][l];
		if(res==dp[i+1][j][l])i++;
		else if(res==dp[i][j+1][l])j++;
		else {
			char c=a[i]; assert(b[j]==c);
			ans.pb(c);
			l=go(l,c);
			i++,j++;
		}
	}
	assert(SZ(ans)==dp[0][0][0]);
	if(!SZ(ans))ans="0";
	cout<<ans<<"\n";
	return 0;
}
