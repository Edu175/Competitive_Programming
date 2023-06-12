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

ll to2(ll n){return n*(n-1)/2;}
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),b(n),pa(n),pb(n);
	fore(i,0,n)cin>>a[i],a[i]--,pa[a[i]]=i;
	fore(i,0,n)cin>>b[i],b[i]--,pb[b[i]]=i;
	ll l=min(pa[0],pb[0]),r=max(pa[0],pb[0]);
	ll res=to2(n-r)+to2(l+1)+to2(r-l);
	//cout<<res<<"\n";
	fore(i,1,n){
		//cout<<i<<" "<<pa[i]<<","<<pb[i]<<": ["<<l<<","<<r<<"] ";
		if((pa[i]<l||pa[i]>r)&&(pb[i]<l||pb[i]>r)){
			//cout<<"si ";
			ll r1=0,r2=0;
			if(pa[i]<l){
				if(pb[i]<l)r1=n-r,r2=l-max(pa[i],pb[i]);
				else r1=l-pa[i],r2=pb[i]-r;
			}
			else{
				if(pb[i]<l)r1=l-pb[i],r2=pa[i]-r;
				else r1=l+1,r2=min(pa[i],pb[i])-r;
			}
			res+=r1*r2;
			//cout<<r1<<" * "<<r2;
		}
		//cout<<"\n";
		l=min({l,pa[i],pb[i]});
		r=max({r,pa[i],pb[i]});
	}
	cout<<res+1<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
