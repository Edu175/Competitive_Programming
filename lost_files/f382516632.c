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
		ll f=c[0];
		bool flag=1;
		fore(s,1,n){
			if(l[s]==lm){
				if(c[s]<c[poslm])lm=l[s],poslm=s;
			}
			if(r[s]==rm){
				if(c[s]<c[posrm])rm=r[s],posrm=s;
			}
			if(l[s]<lm)lm=l[s],poslm=s,flag=0,f=1000000005;
			if(r[s]>rm)rm=r[s],posrm=s,flag=0,f=1000000005;
			if(l[s]==lm&&r[s]==rm)flag=1,f=min(f,c[s]);
			if(flag)tot=min(c[poslm]+c[posrm],f);
			else tot=c[poslm]+c[posrm];
			cout<<tot<<"\n";
		}
	}
	return 0;
}
