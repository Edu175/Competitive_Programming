#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll h=0,good=1;
		queue<ll>q;
		fore(i,0,n){
			ll l,r; cin>>l>>r;
			if(a[i]==-1)q.push(i);
			else h+=a[i];
			if(h<l){
				ll c=l-h;
				h+=c;
				fore(_,0,c){
					if(!SZ(q)){good=0;break;}
					a[q.front()]=1; q.pop();
				}
				// acum-=c;
				// good&=acum>=0;
			}
			good&=h<=r;
			if(!good)continue;
			while(SZ(q)>r-h)a[q.front()]=0,q.pop();
			// acum=min(acum,r-h);
		}
		while(SZ(q))a[q.front()]=0,q.pop();
		if(!good)cout<<"-1\n";
		else {
			imp(a)
		}
	}
	return 0;
}
