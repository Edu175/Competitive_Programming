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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll q; cin>>q;
		ll l=-1,r=-1;
		while(q--){
			//cout<<"\n"<<l<<" "<<r<<": ";
			ll ty,a,b; cin>>ty>>a>>b; ty--;
			if(!ty){
				ll n; cin>>n;
				ll ri=(a-b)*(n-1)+a,li=(n>=2?((a-b)*(n-2)+a):0);
				if(l==-1||r==-1)l=li,r=ri,cout<<"1 ";
				else if(ri<=l||li>=r)cout<<"0 ";
				else l=max(l,li),r=min(r,ri),cout<<"1 ";
				continue;
			}
			ll f=(l-a+a-b-1)/(a-b)*(a-b);
			if(f==l-a)f+=(a-b);
			f=max(f,ll(0));
			if((f>l-a&&f<r-a)||l==-1||r==-1)cout<<"-1 ";
			else cout<<f/(a-b)+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
