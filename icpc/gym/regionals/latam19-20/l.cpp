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
const ll MAXN=1e3+5;
bool G[MAXN][MAXN];
ll C[MAXN][MAXN];
ll n, m;
bool can(ll h){
	fore(j,0,m-h+1){
		ll x=0;
		fore(i,0,n){
			if(C[i][j]>=h)x++;
			else x=0;
			if(x==h) return true;
		}
	}
	return false;
}
int main(){ET
	 cin>>n>>m;
	fore(i,0,n)fore(j,0,m){
		char a; cin>>a;
		G[i][j]= (a=='G');
	}
	fore(i,0,n){
		fore(j,0,m){
			if(!j) {C[i][m-1-j]=1;continue;}
			C[i][m-1-j]=1+(G[i][m-1-j]==G[i][m-j]?C[i][m-j]:0);
		}
	}
	ll l=1, r=min(n,m);
	while(l<=r){
		ll h=(l+r)>>1;
		if(can(h)) l=h+1;
		else r=h-1;
		//cout<<"h "<<h<<"\n";
		//cout<<can(h)<<"\n";
		
	}
	cout<<r*r<<"\n";
	
}