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
	ll _; cin>>_;
	while(_--){
		ll res=-1;
		ll y,x; cin>>y>>x;
		if(y>x){
			if(y&1)res=(y-1)*(y-1)+x;
			else res=y*y-x+1;
		}
		else{
			if(x&1)res=x*x-y+1;
			else res=(x-1)*(x-1)+y;
		}
		pres;
	}
	return 0;
}
