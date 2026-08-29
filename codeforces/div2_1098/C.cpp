#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string _s; cin>>_s;
		vv a;
		for(auto i:_s)a.pb(i-'0');
		ll num=stoll(_s);
		a.insert(a.begin(),0);
		ll n; cin>>n;
		vv ds(n);
		fore(i,0,n)cin>>ds[i];
		vv is(10);
		for(auto d:ds)is[d]=1;
		ll res=1e18;
		// vv pot(19); pot[0]=1; fore(i,1,SZ(pot))pot[i]=pot[i-1]*10;
		ll m=SZ(a);
		fore(p,0,m+1){
			ll good=1;
			fore(i,0,p)good&=!i||is[a[i]];
			if(!good)continue;
			if(p>=m){res=0;break;}
			ll w=a[p];
			do{ // abajo
				if(!w)continue;
				ll ab=w-1;
				while(ab>=0&&!is[ab])ab--;
				if(ab==-1){
					if(p==1&&m>2)ab=0;
					else continue;
				}
				ll cur=0;
				fore(i,0,p)cur=cur*10+a[i];
				cur=cur*10+ab;
				ll mx=ds.back();
				fore(j,p+1,m)cur=cur*10+mx;
				ll cand=abs(num-cur);
				res=min(res,cand);
			}while(0);
			
			do{ // arriba
				ll ar=w+1;
				while(ar<10&&!is[ar])ar++;
				if(ar>=10)continue;
				ll cur=0;
				fore(i,0,p)cur=cur*10+a[i];
				cur=cur*10+ar;
				ll mn=ds[0];
				fore(j,p+1,m)cur=cur*10+mn;
				ll cand=abs(num-cur);
				res=min(res,cand);
			}while(0);
		}
		cout<<res<<"\n";
	}
	return 0;
}
