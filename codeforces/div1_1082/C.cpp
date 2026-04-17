#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
#define addig(a,b) a=add(a,b)
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vv a(n);
		fore(i,0,n)a[i]=s[i]==')';
		ll sa=0;
		vv b(n);
		fore(i,0,n){
			sa+=a[i]?-1:1;
			b[i]=sa;
		}
		vv bad(n);
		fore(i,0,n)bad[i]=b[i]<2;
		// imp(a)
		// imp(b)
		// imp(bad)
		ll dp[n+3][2][2][2];
		mset(dp,0);
		fore(deb,0,2)fore(j,0,2)dp[n][deb][deb][j]=1;
		for(ll i=n-1;i>=0;i--)fore(u,0,2)fore(deb,0,2)fore(vi,0,2){
			auto &res=dp[i][u][deb][vi];
			res=dp[i+1][u][deb][vi||bad[i]];
			if(a[i]==u){
				addig(res,dp[i+1][u][deb][vi||bad[i]]);
			}
			else {
				ll can=1;
				if(deb&&vi&&u==0)can=0;
				// if(!can){
				// 	cout<<"no can "<<i<<" "<<u<<" "<<deb<<" "<<vi<<"\n";
				// }
				if(can){
					addig(res,dp[i+1][a[i]][deb][bad[i]]);
				}
			}
			// if(deb)cout<<i<<" "<<u<<" "<<deb<<" "<<vi<<": "<<res<<"\n";
		}
		ll res=0;
		fore(deb,0,2){
			ll cur=dp[0][deb][deb][0];
			cur=sub(cur,1);
			addig(res,cur);
			// cout<<"deb "<<deb<<": "<<cur<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
