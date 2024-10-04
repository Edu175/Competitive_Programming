#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto fjhg:v)cout<<fjhg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<int> distribute_candies(vector<int> c, vector<int> l,
                                    vector<int> r, vector<int> v){
	ll n=SZ(c); ll q=SZ(l);
	vector<int>ans(n);
	fore(i,0,n){
		auto &res=ans[i];
		fore(j,0,q)if(l[j]<=i&&i<=r[j]){
			res+=v[j];
			res=min(res,c[i]);
			res=max(res,0);
		}
	}
	return ans;
}
									
