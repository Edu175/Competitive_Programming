#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m;cin>>n>>m;
		ll res=n/2+m/2;
		ll mid=1;
		ll vacio=0,x=0;
		if(n%2==0)mid*=2;
		if(m%2==0)mid*=2;
		ll MID=mid;
		fore(i,0,n*m){
			if(i>=mid){
				res++,mid+=mid+4-vacio;
				x++;
				if(x>=ceil(n/2))vacio+=MID;
				if(x>=ceil(m/2))vacio+=MID;
			}
			
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	 return 0;
}
