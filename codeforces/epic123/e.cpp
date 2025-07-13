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
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i]>>b[i];
		stack<ii>s; // color,time of death
		ll fst=0;
		fore(i,0,n){
			ll t=0;
			auto doit=[&](){
				t=0;
				while(SZ(s)&&s.top().fst!=b[i]&&s.top().snd<=a[i]){
					t=s.top().snd;
					s.pop();
				}
			};
			while(1){
				doit();
				if(SZ(s)&&s.top().fst==b[i]){
					a[i]+=s.top().snd-t;
					t=0;
					s.pop();
					continue;
				}
				if(!SZ(s))fst=a[i];
				s.push({b[i],a[i]});
				break;
			}
			cout<<fst<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
