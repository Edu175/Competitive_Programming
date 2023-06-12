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
		ll n,x; cin>>n>>x;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		ll res=0;
		ll l=a[0]-x,r=a[0]+x;
		fore(i,1,n){
			ll li=a[i]-x, ri=a[i]+x;
			//cout<<l<<" "<<r<<": "<<li<<" "<<ri<<"\n";
			if(li>=l&&li<=r)l=li;
			else if(ri>=l&&ri<=r)r=ri;
			else if(li>r||ri<l)res++,r=ri,l=li;
		}
		pres;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
