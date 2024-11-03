#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
const ll MOD=1e9+7;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
const ll MAXN=5005;

ll dp[MAXN][MAXN];
ll con[MAXN][MAXN];
ll esc[MAXN][MAXN];
void upd(ll i, ll j, ll v){
	con[i][j]=v;
	esc[i][j]=mul(j,v);
	if(i<MAXN-1&&j){
		con[i][j]=add(con[i][j],con[i+1][j-1]);
		esc[i][j]=add(esc[i][j],esc[i+1][j-1]);
	}
	// cout<<"upd "<<i<<","<<j<<": "<<con[i][j]<<" "<<esc[i][j]<<"\n";
}
ll query(ll i, ll j, ll c){
	ll co=sub(con[0][i+j],(j?con[i+1][j-1]:0));
	ll es=sub(esc[0][i+j],(j?esc[i+1][j-1]:0));
	es=sub(es,mul(co,j));
	es=add(es,mul(co,c));
	return es;
}
ll bf(ll n, ll k){
	cout<<"bf\n";
	vector<vv>dp(n+1,vv(k+5));
	fore(t,0,n+1)fore(s,0,k+5){
		ll &res=dp[t][s];
		if(s==0)res=1;
		else if(t==0)res=0;
		else {
			fore(z,1,min(t,s)+1){
				res=add(res,mul(dp[z][s-z],t+1-z));
			}
		}
		cout<<t<<" "<<s<<": "<<res<<"\n";
	}
	return dp[n][k-n];
}
int main(){ET
	ll n,k; cin>>n>>k;
	fore(s,0,k+5)fore(t,0,n+1){
		ll &res=dp[t][s];
		if(s==0)res=1;
		else if(t==0)res=0;
		else {
			ll h=min(t,s);
			res=query(h,s-h,t+1-h);
		}
		upd(t,s,res);
		// cout<<t<<" "<<s<<": "<<res<<"\n";
	}
	ll res=dp[n][k-n];
	cout<<res<<"\n";
	// cout<<bf(n,k)<<"\n";
}


/*

bf
0 0: 1
0 1: 0
0 2: 0
0 3: 0
0 4: 0
0 5: 0
0 6: 0
0 7: 0
0 8: 0
0 9: 0
0 10: 0
1 0: 1
1 1: 1
1 2: 1
1 3: 1
1 4: 1
1 5: 1
1 6: 1
1 7: 1
1 8: 1
1 9: 1
1 10: 1
2 0: 1
2 1: 2
2 2: 3
2 3: 4
2 4: 5
2 5: 6
2 6: 7
2 7: 8
2 8: 9
2 9: 10
2 10: 11
3 0: 1
3 1: 3
3 2: 5
3 3: 8
3 4: 12
3 5: 16
3 6: 21
3 7: 27
3 8: 33
3 9: 40
3 10: 48


*/