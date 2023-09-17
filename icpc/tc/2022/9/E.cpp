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
	ll n,a,b; cin>>n>>a>>b;
	ll bo=0;
	ll dnf=0;
	fore(i,0,n){
		ll t; cin>>t;
		if(t==1){
			if(a>0)a--;
			else if(b>0)b--,bo++;
			else if(bo>0)bo--;
			else dnf++;
		}
		if(t==2){
			if(b>0)b--;
			else dnf+=2;
		}
	}
	cout<<dnf;
	return 0;
}
