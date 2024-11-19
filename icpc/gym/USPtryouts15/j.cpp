#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<cv(i)<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef vector<ld> vld;
typedef pair<ll,ll> ii;
string cv(ld n){
	string s=to_string(n);
	// cerr<<s<<"\n";
	// exit(0);
	while(s.back()=='0')s.pop_back();
	if(s.back()=='.')s.pb('0');
	reverse(ALL(s));
	s+=string(20-SZ(s),' ');
	reverse(ALL(s));
	return s;
}
const ll INF=1e9;
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		string a,b; cin>>a>>b; a.pb('$'),b.pb('$');
		vector<vld> dp(n+2,vld(m+2)),
		fil(n+2,vld(m+2)), cua(n+2,vld(m+2));
		for(ll i=n;i>=0;i--)for(ll j=m;j>=0;j--){
			auto &res=dp[i][j];
			if(a[i]==b[j])res=dp[i+1][j+1];
			else {
				res=INF;
				if(i<n)res=min(res,1+dp[i+1][j]);
				if(j<m)res=min(res,1+dp[i][j+1]);
				ll r=i-(i==n),c=j-(j==m); // enunciado raro
				res=min(res,k+cua[r+1][c+1]/((n-r)*(m-c)));
				assert(r+1<=n&&c+1<=m);
			}
			// cout<<i<<" "<<j<<": "<<res<<"\n";
			fil[i][j]=fil[i][j+1]+res;
			cua[i][j]=cua[i+1][j]+fil[i][j];
		}
		// fore(i,0,n+2)imp(dp[i]);;cout<<"\n";
		// fore(i,0,n+2)imp(fil[i]);;cout<<"\n";
		// fore(i,0,n+2)imp(cua[i]);;cout<<"\n";
		
		cout<<fixed<<setprecision(15)<<dp[0][0]<<"\n";
	}
	return 0;
}