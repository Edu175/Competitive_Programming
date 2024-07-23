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
	JET
	int n,m; cin>>n>>m;
	int a[n][m];
	ll rta=0;
	fore(i,0,n) fore(j,0,m){
		cin>>a[i][j];
		rta+=a[i][j];
	} 
	
	for(int i=n-1; i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(a[i][j]==0){
				int value=100000;
				if(i<n-1) value=min(value,a[i+1][j]-1);
				if(j<m-1) value=min(value,a[i][j+1]-1);
				if(j>0 && a[i][j-1]>=value){
					cout<<"-1 \n";
					return 0;
				}
				if(i>0 && a[i-1][j]>=value){
					cout<<"-1 \n";
					return 0;
				}
				a[i][j]=value;
				rta+=value;
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
	cout<<rta<<"\n";
}