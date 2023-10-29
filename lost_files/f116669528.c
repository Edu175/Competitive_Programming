#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=103,MAXD=(MAXN/2)*(MAXN/2)*2+5,C=(MAXN/2)*(MAXN/2)+2,INF=4*MAXN;

ll dp[2][MAXN][MAXD];
//dif=s01-s10
ll f(ll i, ll c0, ll dif){
	if(c0<0||c0>=MAXN||dif+C<0||dif+C>=MAXD)return INF;
	return dp[i%2][c0][dif+C];
}
int main(){FIN;
	ll n;
	string s; cin>>s;
	n=SZ(s);
	vector<ll>a;
	fore(i,0,n)a.pb(s[i]-'0');
	ll cnt[2]={};
	fore(i,0,n)cnt[a[i]]++;
	for(ll i=n;i>=0;i--)fore(c0,0,i+1)fore(dif,-C,C+1){
		ll &res=dp[i%2][c0][dif+C];
		ll c1=i-c0;
		if(c0>i||c1>i){res=INF;continue;}
		if(i==n){
			if(c0==cnt[0]&&c1==cnt[1]&&dif==0)res=0;
			else res=INF;
			continue;
		}
		//0
		res=(a[i]!=0)+f(i+1,c0+1,dif-c1);
		res=min(res,(a[i]!=1)+f(i+1,c0,dif+c0));
	}
	ll res=f(0,0,0);
	cout<<res/2<<"\n";
	return 0;
}
