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


ll dp[5000][5000];
string a;

ll pingo(string s){
	ll n=SZ(s);
	ll res=0,c=0;
	fore(i,0,n){
		c++;
		if(i==n-1||s[i+1]!=s[i]){
			if(s[i]=='D' || s[i]=='L' || s[i]=='V')res+=c;
			else res+=(c+2)/3;
			c=0;
		}
	}
	return res;
}

ll f(int x, int y){
	if(x>y) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	ll rta=1e10;
	ll aux=1e10;
	fore(i,x,y-1){
		if(a[i]==a[i+2] && a[i]=='X' && a[i+1]=='I'){
			aux = 1+f(x,i-1)+f(i+3,y);
		}
		if(a[i]==a[i+2] && a[i]=='C' && a[i+1]=='X'){
			aux = 1+f(x,i-1)+f(i+3,y);
		}
		if(a[i]==a[i+2] && a[i]=='M' && a[i+1]=='C'){
			aux = 1+f(x,i-1)+f(i+3,y);
		}
		rta=min(rta,aux);
	}
	aux=pingo(a.substr(x,y-x+1));
	dp[x][y]=min(aux,rta);
	// cout<<x+1<<" "<<y+1<<" "<<dp[x][y]<<"\n";
	return dp[x][y];
}

int main(){
	JET
	int n; cin>>n;
	cin>>a;
	mset(dp,-1);
	cout<<f(0,n-1)<<"\n";	
	// cout<<pingo(a.substr(4,7-4+1))<<"\n";
}