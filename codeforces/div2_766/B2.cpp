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
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m;cin>>n>>m;ll a[n][m];
		ll res=n/2+m/2;
		vector<pair<ll,ll>> mid(4); 
		mid[0].fst+=n/2;
		mid[0].snd+=m/2;
		ll edu=1;
		if(n%2==0){
			mid[1].fst+=n/2-1;
			mid[1].snd+=m/2;
			edu++;
		}
		if(m%2==0){
			mid[2].fst+=n/2;
			mid[2].snd+=m/2-1;
			edu++;
		}
		if(n%2==0&&m%2==0){
			mid[3].fst+=n/2-1;
			mid[3].snd+=m/2-1;
			edu++;
		}
		/*for(auto i:mid)cout<<i.fst<<","<<i.snd<<" ";
		cout<<"\n";*/
		vector<ll> d(n/2+m/2);
		set<ll>st;
		fore(i,0,n){
			fore(j,0,m){
				ll mini=100005;
				fore(h,0,edu)mini=(min(mini,abs(mid[h].fst-i)+abs(mid[h].snd-j)));
				d[mini]++;
				//cout<<mini<<" ";
			}
		}
		/*cout<<"\n";
		for(auto i:d)cout<<i<<" ";
		cout<<"\n";*/
		fore(i,1,n/2+m/2+1)d[i]+=d[i-1];
		ll x=0;
		/*for(auto i:d)cout<<i<<" ";
		cout<<"\n";*/
		fore(i,0,n*m){
			if(x>=n/2+m/2||i>=d[x]){
				res++;
				x++;
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	 return 0;
}
