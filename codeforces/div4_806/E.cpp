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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		char a[n][n];
		fore(i,0,n){
			fore(j,0,n)cin>>a[i][j];
		}
		ll res=0;
		fore(i,0,(n+1)/2){
			fore(j,0,n/2){
				ll z=0, un=0;
				ll y=i,x=j;
				fore(h,0,4){
					if(a[y][x]=='1')un++;
					else z++;
					if(h==0)y=j,x=n-1-i;
					if(h==1)y=n-1-j,x=i;
					if(h==2)y=n-1-i,x=n-1-j;
				}
				//cout<<i<<" "<<j<<": "<<z<<" "<<un<<"\n";
				res+=min(un,z);
			}
		}
		pres;
	}
	return 0;
}
