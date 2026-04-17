#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// calculating res
// without original fij

int main(){
	FIN;
	ll n; cin>>n;
	
	vector<vv>a(n);
	ll sum=0;
	fore(i,0,n){
		ll m; cin>>m;
		sum+=m;
		a[i].resize(m);
		fore(j,0,m)cin>>a[i][j];
	}
	auto val=[&](vector<vv>s){
		ll fij=0;
		
		vv b;
		fore(i,0,n){
			fore(j,0,SZ(a[i])){
				if(s[i][j])fij+=i*a[i][j];
				else fij+=(n-1-i)*a[i][j];
				fore(_,0,a[i][j])b.pb(s[i][j]);
			}
		}
		ll q=0,res=0;
		for(auto i:b){
			if(i)res+=q;
			else q++;
		}
		return fij+res;
	};
	ll res=0;
	fore(mk,0,1ll<<sum){
		vector<vv>s;
		vv tmp;
		ll p=0;
		fore(i,0,sum){
			while(p<n&&SZ(tmp)==SZ(a[p]))s.pb(tmp),p++,tmp.clear();
			tmp.pb(mk>>i&1);
		}
		while(p<n&&SZ(tmp)==SZ(a[p]))s.pb(tmp),p++,tmp.clear();
		res=max(res,val(s));
	}
	cout<<res<<"\n";
	return 0;
}