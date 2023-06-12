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
const ll MAXN=20;
ll n;
string a,b;
ll dp[MAXN][12][2][2];
ll f(ll i, ll x, ll c, ll d){
	ll &res=dp[i][x][c][d];
	if(res>=0)return res;
	if(i==n)return res=1;
	res=0;
	ll y=a[i]-'0',z=b[i]-'0';
	ll l=0,r=10;
	if(c)l=y;
	if(d)r=z+1;
	fore(j,l,r){
		if(j!=x)res+=f(i+1,(j==0&&x==10?10:j),c&&j==y,d&&j==z);
		//cout<<i<<" "<<x<<"\n";
	}
	/*if(c){
		if(y!=x)res+=f(i+1,(y==0&&x==10?10:y),c,(d&&y==z));
	}
	if(d){
		if(c&&d&&y==z);
		else if(z!=x)res+=f(i+1,(z==0&&x==10?10:z),(c&&y==z),d);
	}*/
	//cout<<i<<": "<<x<<"| "<<l<<" "<<r<<" = "<<res<<"\n";
	return res;
}
int main(){FIN;
	mset(dp,-1);
	string s;
	cin>>s>>b;
	//cout<<s<<"\n";
	string z(SZ(b)-SZ(s),'0');
	//cout<<z<<"\n";
	a=z+s;
	//cout<<a<<"\n";
	n=SZ(b);
	cout<<f(0,10,1,1)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
