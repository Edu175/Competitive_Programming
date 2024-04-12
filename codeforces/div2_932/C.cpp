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
		ll n,k; cin>>n>>k;
		vector<ii>a(n);
		fore(i,0,n)cin>>a[i].snd>>a[i].fst;
		sort(ALL(a));
		ll res=0;
		fore(i,0,n)if(a[i].snd<=k)res=1;
		fore(l,0,n){
			priority_queue<ll>si,no;
			ll sum=a[l].snd-a[l].fst,_sum=sum;
			fore(r,l+1,n)if(_sum+a[r].fst+a[r].snd<=k){
				sum+=a[r].fst+a[r].snd;
				while(sum<=k&&SZ(no))si.push(-no.top()),sum+=-no.top(),no.pop();
				while(sum>k)no.push(-si.top()),sum-=si.top(),si.pop();
				//cout<<l<<","<<r<<": "<<sum<<"\n";
				sum-=a[r].fst+a[r].snd;
				no.push(-a[r].snd);
				res=max(res,(ll)SZ(si)+2);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
