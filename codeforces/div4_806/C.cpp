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
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll m[n];
		fore(i,0,n){
			m[i]=0;
			ll b; cin>>b;
			ll mov=0;
			fore(j,0,b){
				char c; cin>>c;
				if(c=='U')mov++;
				else mov--;
			}
			m[i]+=mov;
			m[i]%=10;
			m[i]+=10;
			m[i]%=10;
			a[i]-=m[i];
			a[i]%=10;
			a[i]+=10;
			a[i]%=10;
		}
		imp(a);
	}
	return 0;
}
