#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	string s; cin>>s;
	ll n=SZ(s);
	// ll n; cin>>n;
	set<string> se;
	se.insert("I");
	se.insert("II");
	se.insert("III");
	se.insert("V");
	se.insert("X");
	se.insert("XX");
	se.insert("XXX");
	se.insert("XIX");
	se.insert("L");
	se.insert("C");
	se.insert("CC");
	se.insert("CCC");
	se.insert("CXC");
	se.insert("D");
	se.insert("M");
	se.insert("MM");
	se.insert("MMM");
	se.insert("MCM");
	vv dp(n+3);
	dp[n]=0;
	for(ll i=n-1;i>=0;i--){
		ll &res=dp[i];
		res=dp[i+1]+1;
		fore(j,i,min(n+1,i+5)){
			if(se.count(s.substr(i,j-i)))res=min(res,1+dp[j]);
		}
	}
	vector<string> res;
	ll i=0;
	while(i<n){
		ll go=-1;
		fore(j,i,min(n+1,i+5)){
			if(se.count(s.substr(i,j-i))&&dp[i]==1+dp[j])go=j;
		}
		res.pb(s.substr(i,go-i));
		i=go;
	}
	cout<<dp[0]<<"\n";
	for(auto i:res)cout<<i<<"\n";
}