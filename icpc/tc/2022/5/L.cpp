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
	ll m,t,r; cin>>m>>t>>r;
	ll w[m];
	fore(i,0,m)cin>>w[i];
	vector<ll>c;
	if(t<r)cout<<-1;
	else {
		fore(i,0,m){
			ll lwb=0;
			if(SZ(c))lwb=lower_bound(ALL(c),w[i])-c.begin();
			ll fcan=r-(SZ(c)-lwb);
			fore(j,0,fcan)c.pb(w[i]-fcan+j+t);
			//imp(c);
		}
		cout<<SZ(c);
	}
	return 0;
}
