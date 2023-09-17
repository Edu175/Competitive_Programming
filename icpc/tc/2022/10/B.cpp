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
	ll n,x; cin>>n>>x;
	ll sad=0;
	fore(i,0,n){
		char sig; cin>>sig;
		ll d; cin>>d;
		if(sig=='+')x+=d;
		else if(x-d>=0)x-=d;
		else sad++;
	}
	cout<<x<<" "<<sad;
	return 0;
}
