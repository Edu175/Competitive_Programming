#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	int n,m; cin>>n>>m;
	int a[n][m]; ll res=0;
	fore(i,0,n) fore(j,0,m){
		cin>>a[i][j];
		res+=a[i][j];
	}
	fore(i,1,n){
		fore(j,1,m){
			if(a[n-i][m-j]==0) {
				a[n-i][m-j]=min(a[n+1-i][m-j],a[n-i][m+1-j])-1;
				res+=a[n-i][m-j];
				if(a[n-i][m-j]<=0) {cout<<"-1\n"; return 0;}
			}
		}
	}	
	fore(i,0,n){
		fore(j,1,m){
			if (a[i][j]<=a[i][j-1]){
				cout<<"-1 \n";
				return 0;
				
			}
		}
	}
	fore(i,1,n){
		fore(j,0,m){
			if (a[i][j]<=a[i-1][j]){
				cout<<"-1 \n";
				return 0;
				
			}
		}
	}
	
	cout<<res<<"\n";
	return 0;
}