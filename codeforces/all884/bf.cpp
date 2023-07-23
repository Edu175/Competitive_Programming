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
const ll MAXN=2e3+5;

ll a[MAXN][MAXN];

ll n,m;
void check(){
	ll flag=1;
	fore(i,0,n)fore(j,0,m){
		if(i&&a[i][j]==a[i-1][j])flag=0;
		if(j&&a[i][j]==a[i][j-1])flag=0;
		if(i&&j){
			set<ll>st={a[i-1][j-1],a[i-1][j],a[i][j-1],a[i][j]};
			if(SZ(st)<3)flag=0;
		}
	}
	if(flag){
		fore(i,0,n){
			fore(j,0,m)cout<<a[i][j];
			cout<<"\n";
		}
		cout<<"\n";
	}
}

void f(ll i, ll j){
	if(i>=n){check();return;}
	fore(h,0,3){
		a[i][j]=h;
		if(j<m-1)f(i,j+1);
		else f(i+1,0);
	}
}

int main(){//FIN;
	cin>>n>>m;
	f(0,0);
	return 0;
}
