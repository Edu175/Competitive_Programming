#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;
typedef pair<string,string> nom;
int main(){
	FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<nom> a(n);
		map<string,ll>oc1,oc2;
		fore(i,0,n){
			nom p; cin>>p.fst>>p.snd;
			oc1[p.fst]++;
			oc2[p.snd]++;
			a[i]=p;
		}
		ll bad=0;
		fore(i,0,n){
			auto p=a[i];
			if(i){
				auto q=a[i-1];
				ll dif=(p.fst==q.fst)+(p.snd==q.snd);
				if(!dif&&(oc1[q.fst]||oc2[q.snd]))bad=1;
				// cout<<i<<": "<<dif<<"\n";
			}
			oc1[p.fst]--;
			oc2[p.snd]--;
		}
		if(bad)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}