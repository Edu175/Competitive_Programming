#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for (int i=a,edu=b;i<edu;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
using namespace std;
const ll MAXN=60003,INF=18000999;

ll n;
ll a[MAXN];
ll dp[MAXN][303];

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("pajaros.in", ios::in);
	cout.open("pajaros.out", ios::out);
	cin>>n;
	fore(i,0,n)cin>>a[i];
	for(ll i=n-1; i>=0; i--){
		fore(h,0,303){
			ll &res=dp[i][h];
			if(h<1||h>300) res=INF;
			else {
				res=abs(a[i]-h);
				res+=min(dp[i+1][h+1],dp[i+1][h-1]);
			}
		}
	}
	cout<<dp[0][1]<<"\n";
	return 0;
}
