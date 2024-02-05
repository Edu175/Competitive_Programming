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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ii a,b; cin>>a.fst>>a.snd>>b.fst>>b.snd;
		a.fst--,a.snd--,b.fst--,b.snd--;
		ll g=abs(a.fst-b.fst)%2;
		ll p=0;
		while(a.fst<b.fst){
			if(p==0){
				a.fst++;
				if(g){
					if(a.snd<b.snd)a.snd++;
					if(a.snd>b.snd)a.snd--;
				}
				else {
					if(a.snd<b.snd)a.snd--;
					if(a.snd>b.snd)a.snd++;
				}
				a.snd=max(a.snd,(ll)0);
				a.snd=min(a.snd,m-1);
			}
			else {
				b.fst--;
				if(g){
					if(a.snd<b.snd)b.snd++;
					if(a.snd>b.snd)b.snd--;
				}
				else {
					if(a.snd<b.snd)b.snd--;
					if(a.snd>b.snd)b.snd++;
				}
				b.snd=max(b.snd,(ll)0);
				b.snd=min(b.snd,m-1);
			}
			p^=1;
		}
		ll res=-1;
		if(a==b)res=!g;
		if(res==0)cout<<"Alice\n";
		else if(res==1)cout<<"Bob\n";
		else cout<<"Draw\n";
	}
	return 0;
}
