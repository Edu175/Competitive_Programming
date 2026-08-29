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
		ll a,b,c; cin>>a>>b>>c;
		ll res=a+b+c;
		fore(_,0,2){
			vv v={a/2,(a+1)/2,c};
			ll mx=*max_element(ALL(v));
			ll h=b;
			for(auto &i:v){
				ll q=mx-i;
				i+=q;
				h-=q;
			}
			ll cur=mx;
			if(h>0){
				cur+=(h+2)/3;
			}
			res=min(res,cur);
			swap(a,c);
		}
		cout<<res<<"\n";
	}
	return 0;
}
