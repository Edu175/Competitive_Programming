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
		ll a[2][2];
		ll u=0,z=0;
		fore(i,0,2){
			fore(j,0,2){
				cin>>a[i][j];
				if(a[i][j])u++;
				else z++;
			}
		}
		ll res=1;
		if(u==0)res=0;
		else if(z==0)res=2;
		pres;
	}
	return 0;
}
