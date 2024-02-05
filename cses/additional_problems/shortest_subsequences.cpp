#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e6+5;

string adn="ACGT";
ll dp[MAXN][4];
string s;
ll n;
ll f(ll i, ll c){
	ll &res=dp[i][c];
	if(res!=-1)return res;
	if(i==n+1)return res=0;
	res=n+5;
	if(i==0||s[i]==adn[c]){
		fore(j,0,4)res=min(res,1+f(i+1,j));
	}
	else res=f(i+1,c);
	return res;
}
string ans;
void build(ll i, ll c){
	if(i==n+1)return;
	ll res=f(i,c);
	if(i==0||s[i]==adn[c])fore(j,0,4){
		if(res==1+f(i+1,j)){
			ans.pb(adn[j]);
			build(i+1,j);
			return;
		}
	}
	else build(i+1,c);
}
int main(){FIN;
	cin>>s;
	n=SZ(s);
	s="."+s;
	mset(dp,-1);
	build(0,0);
	cout<<ans<<"\n";
	return 0;
}
