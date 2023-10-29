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
typedef int ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>l(n),r(n),c(n);
		fore(i,0,n)cin>>l[i]>>r[i]>>c[i];
		ll lm, rm;
		lm=l[0];ll poslm=0;
		rm=r[0];ll posrm=0;
		ll tot=c[0];
		cout<<tot<<"\n";
		ll t;
		fore(s,1,n){
			if(l[s]>=lm&&r[s]<=rm&&(l[s]==lm||r[s]==rm)){
				if(l[s]<=lm)lm=l[s],poslm=s;
				if(r[s]>=rm)rm=r[s],posrm=s;
				t=c[poslm]+c[posrm];
				if(poslm==posrm)t=c[poslm];
				tot=min(tot,t);
			}
			else{
				if(l[s]<=lm)lm=l[s],poslm=s;
				if(r[s]>=rm)rm=r[s],posrm=s;
				tot=c[poslm]+c[posrm];
				if(poslm==posrm)tot=c[poslm];
			}
			cout<<tot<<"\n";
		}
	}
	 return 0;
}
