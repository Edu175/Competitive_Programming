#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		vector<ll>a(k);
		fore(i,0,n){
			string s; cin>>s;
			fore(j,0,k)a[j]+=s[j]-'0';
		}
		vector<vector<int>>dp(k+3,vector<int>(2*n+5,-1));
		auto f=[&](ll i, ll c, auto &&f)->bool{
			if(c>2*n)return 0;
			auto &res=dp[i][c];
			if(res!=-1)return res;
			if(i==k)return res=(c==0);
			c+=s[i]-'0';
			auto use=[&](ll q)->bool{
				if(q<=c)return f(i+1,(c-q)*2,f);
				return 0;
			};
			return res=max(use(a[i]),use(n-a[i]));
		};
		if(!f(0,0,f)){
			cout<<"-1\n";
			continue;
		}
		string ans;
		auto build=[&](ll i, ll c, auto &&build)->void{
			auto &res=dp[i][c];
			if(i==k)return;
			c+=s[i]-'0';
			auto use=[&](ll q)->bool{
				if(q<=c)return f(i+1,(c-q)*2,f);
				return 0;
			};
			if(res==use(a[i])){
				ans.pb('0');
				build(i+1,(c-a[i])*2,build);
			}
			else {
				ans.pb('1');
				build(i+1,(c-(n-a[i]))*2,build);
			}
		};
		build(0,0,build);
		cout<<ans<<"\n";
	}
	return 0;
}
