#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){JET
	ll n,k,s; cin>>n>>k>>s; s--;
	vector<vv> a(n);
	vector<vector<ld>> p(n);
	fore(i,0,n){
		a[i].resize(n);
		ll sum=0;
		fore(j,0,n)cin>>a[i][j],sum+=a[i][j];
		p[i].resize(sum);
		ll q; cin>>q;
		fore(j,0,sum)cin>>p[i][j],p[i][j]/=q;
		sort(ALL(p[i]));
	}
	vector<ld>pw(n); pw[s]=1;
	fore(_,0,k){
		vv per(n); iota(ALL(per),0);
		sort(ALL(per),[&](ll i, ll j){return pw[i]<pw[j];});
		auto pwi=pw;
		fore(i,0,n){
			auto f=a[i];
			ll po=0;
			ld res=0;
			fore(j,0,SZ(p[i])){
				while(po<n&&!f[per[po]])po++;
				res+=p[i][j]*pw[per[po]];
				f[per[po]]--;
			}
			pwi[i]=res;
		}
		swap(pw,pwi);
	}
	cout<<fixed<<setprecision(15)<<pw[0]<<"\n";
}