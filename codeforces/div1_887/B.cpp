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
		ll n; cin>>n;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].fst,a[i].snd=i;
		sort(ALL(a)); reverse(ALL(a));
		vector<ll>b(n);
		ll flag=1;
		fore(i,0,n){
			if(a[i].fst>i)b[i]=n-i;
			else { //last a[j]>i
				ll l=0,r=i-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(a[m].fst>i)l=m+1;
					else r=m-1;
				}
				//cout<<i<<": "<<r<<" "<<(r==-1?-1:b[r])<<"\n";
				if(r==-1)b[i]=-n;
				else b[i]=-b[r]+1;
				if(a[i].fst!=r+1)flag=0;
			}
		}
		//imp(b);
		vector<ll>res(n);
		fore(i,0,n)res[a[i].snd]=b[i];
		if(flag){
			cout<<"YES\n";
			imp(res);
		}
		else cout<<"NO\n";
	}
	return 0;
}
