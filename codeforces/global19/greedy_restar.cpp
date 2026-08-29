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
		fore(i,0,n)cin>>a[i],a[i]--;
		vv is(n); // is o
		ll inv=0;
		fore(i,0,n)fore(j,i+1,n)inv+=a[i]>a[j];
		auto val=[&](ll i){
			ll dif=0;
			fore(j,0,i)if(!is[j])dif+=a[j]>a[i]?-1:1;
			return dif;
		};
		auto getAll=[&](){
			ll dif=0;
			fore(i,0,n)if(is[i])dif+=val(i);
			return dif;
		};

		cout<<inv<<" ";
		fore(_,0,n){
			ll mx=-1,cand=-1;
			fore(i,0,n)if(!is[i]){
				is[i]=1;
				ll cur=getAll();
				is[i]=0;
				if(mx==-1||cur<=cand)mx=i,cand=cur;
			}
			is[mx]=1;
			ll dif=getAll();
			// cout<<"\n"<<dif<<": ";
			// imp(is)
			
			cout<<inv+dif<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
