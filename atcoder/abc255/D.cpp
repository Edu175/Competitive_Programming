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
	ll n,q; cin>>n>>q;
	ll a[n],sump[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	sump[0]=a[0];
	fore(i,1,n)sump[i]=sump[i-1]+a[i];
	while(q--){
		ll x; cin>>x;
		ll res=0;
		ll posl=lower_bound(a,a+n,x)-a;
		ll posr=upper_bound(a,a+n,x)-a;
		posl--;
		if(posl>=0)res+=x*(posl+1)-sump[posl];
		if(posr<n)res+=sump[n-1]-((!posr)?0:sump[posr-1])-x*(n-posr);
		pres;
	}
	return 0;
}
