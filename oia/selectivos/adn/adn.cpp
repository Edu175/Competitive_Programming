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
const ll MAXN=2e5+5;
#define INF 20

ll n,m,k;
string a,b;
ll dp[MAXN][23]; // -11

ll f(ll i, ll d){
	return dp[i][d+11];
}
int main(){FIN;
	ifstream cin;   cin.open("adn.in", ios::in);
	ofstream cout; cout.open("adn.out", ios::out);
	cin>>n>>m>>k>>a>>b;
	for(ll i=n;i>=0;i--)for(ll d=11;d>=-11;d--){
		ll &res=dp[i][d+11];
		if(d>k||d<-k){res=INF;continue;}
		res=1+f(i,d+1); //agregar
		if(i==n){
			if(i+d==m)res=0;
			continue;
		}
		if(i+d>=m){res=INF;continue;}
		res=min({res,(a[i]!=b[i+d])+f(i+1,d),1+f(i+1,d-1)});
	}
	ll res=f(0,0);
	if(res>k)cout<<"Muy distintas.\n";
	else cout<<res<<"\n";
	return 0;
}
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
