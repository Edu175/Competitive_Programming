#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

const ll MAXN=1005;
ll dpmin[MAXN][MAXN];
ll dpmax[MAXN][MAXN];
ll a[MAXN][MAXN];
ll n,m;
ll MINMN=-n-m-5;

ll fmax(ll i,ll j){
	if(dpmax[i][j]>MINMN)return dpmax[i][j];
	if(!i&&!j)return dpmax[i][j]=a[0][0];
	if(!j)return dpmax[i][j]=a[i][j]+fmax(i-1,j);
	if(!i)return dpmax[i][j]=a[i][j]+fmax(i,j-1);
	return dpmax[i][j]=a[i][j]+max(fmax(i,j-1),fmax(i-1,j));
}

ll fmin(ll i,ll j){
	if(dpmin[i][j]>MINMN)return dpmin[i][j];
	if(!i&&!j)return dpmin[i][j]=a[0][0];
	if(!j)return dpmin[i][j]=a[i][j]+fmin(i-1,j);
	if(!i)return dpmin[i][j]=a[i][j]+fmin(i,j-1);
	return dpmin[i][j]=a[i][j]+min(fmin(i,j-1),fmin(i-1,j));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
				dpmin[i][j]=MINMN;
				dpmax[i][j]=MINMN;
			}
		}
		if(((m+n)%2)&&(fmin(n-1,m-1)<=0&&fmax(n-1,m-1)>=0))cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
