#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	ll res=-1;
	fore(mk,0,1ll<<n){
		vv s[2];
		ll mex=0,flag=1;
		auto pop=[&](ll w){
			if(SZ(s[w])&&s[w].back()==mex){
				s[w].pop_back(),mex++;
				return 1;
			}
			return 0;
		};
		fore(i,0,n){
			while(pop(0)||pop(1));
			ll go=(mk>>i&1);
			if(SZ(s[go])&&s[go].back()<a[i])flag=0;
			s[go].pb(a[i]);
		}
		if(flag)res=mk;
	}
	if(res==-1)cout<<"IMPOSSIBLE\n";
	else {
		fore(i,0,n)cerr<<(res>>i&1)+1<<" ";;cout<<"\n";
	}
	return 0;
}