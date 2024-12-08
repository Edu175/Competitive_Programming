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
		vv c(3);
		vv a(n);
		fore(i,0,n)cin>>a[i],c[a[i]]++;
		vv b;
		fore(i,0,3)fore(j,0,c[i])b.pb(i);
		vector<ii>res;
		auto sw=[&](ll i, ll j){
			res.pb({i,j});
			assert(abs(a[i]-a[j])==1);
			swap(a[i],a[j]);
		};
		auto ans=[&](){
			assert(SZ(a)<=n&&a==b);
			cout<<SZ(res)<<"\n";
			for(auto [i,j]:res)cout<<i+1<<" "<<j+1<<"\n";
		};
		ll s=c[0];
		ll p=s+1;
		fore(i,0,n){
			while(p<n&&a[p]==1)p++;
			if(a[i]==1&&b[i]!=1&&p<n&&b[p]==1)sw(i,p);
		}
		if(a==b){ans();continue;}
		if(a[s]==1)sw(s,0);
		vv de[3][3];
		fore(i,0,n)if(a[i]!=b[i])de[b[i]][a[i]].pb(i);
		ll x=-1;
		fore(i,0,n)if(b[i]!=1&&a[i]==1)x=b[i];
		// imp(a);
		// cout<<x<<endl;
		vv ind;
		ind.pb(de[x][1][0]);
		while(1){
			x^=2;
			auto &v=de[x][x^2];
			if(!SZ(v)){
				ind.pb(de[1][x^2][0]);
				break;
			}
			ind.pb(v.back());
			v.pop_back();
		}
		fore(i,0,SZ(ind)-1)sw(ind[i],ind[i+1]);
		ans();
	}
	return 0;
}
