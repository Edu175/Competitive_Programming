#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
    JET
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		multiset<ll>l,r; ll suml=0,sumr=0;
		ll sz=0;
		auto saca=[&](multiset<ll> &st, ll x){
			st.erase(st.find(x));};
		auto balance=[&](){
			if(SZ(l)<sz/2){
				ll x=*r.begin();
				l.insert(x); suml+=x,sumr-=x;
				saca(r,x);
			}
			if(SZ(l)>sz/2){
				ll x=*l.rbegin();
				r.insert(x); sumr+=x,suml-=x;
				saca(l,x);
			}
		};
		auto add=[&](ll x){
			sz++;
			r.insert(x); sumr+=x;
			if(SZ(l)&&SZ(r)){
				ll xl=*l.rbegin(),xr=*r.begin();
				if(xl>xr){
					suml+=xr-xl;
					sumr+=xl-xr;
					saca(l,xl);
					saca(r,xr);
					l.insert(xr);
					r.insert(xl);
				}
			}
			balance();
		};
		auto remove=[&](ll x){
			sz--;
			if(l.count(x))saca(l,x),suml-=x;
			else saca(r,x),sumr-=x;
			balance();
		};
		auto good=[&]()->bool{
			if(!sz)return 1;
			ll med=*r.begin();
			ll dist=sumr-med*SZ(r)+med*SZ(l)-suml;
			return dist<=k;
		};
		
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]-=i;
		// for(auto i:a)cout<<i<<" ";;cout<<"\n";
		ll p=-1,res=0;
		fore(i,0,n){
			while(p<n&&good()){
				if(p==n-1)p++;
				else add(a[++p]);
			}
			res=max(res,p-i);
			remove(a[i]);
			// cout<<i<<": "<<p<<"\n";
			// cout<<suml<<" "<<sumr<<"\n";
			// for(auto i:l)cout<<i<<" ";;cout<<"| ";
			// for(auto i:r)cout<<i<<" ";;cout<<"\n\n";
		}
		cout<<res<<"\n";
	}
    return 0;
}

// g++ -Wall -Wextra -std=c++17 -D_GLIBCXX_DEBUG -g tempate.cpp -o a
// for i in {a..z}; do cp tempate.cpp $i.cpp;done