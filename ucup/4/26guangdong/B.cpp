#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv; 

int main(){
    JET
	ll C=1005;
	vv is(C);
	fore(i,1,C){
		ll ci=i*i*i;
		if(ci>=C)break;
		fore(j,1,C){
			ll cj=j*j*j;
			if(ci+cj>=C)break;
			is[ci+cj]=1;
		}
	}
	fore(i,1,C)cout<<is[i];;cout<<"\n";
	cout<<"count "<<count(ALL(is),1)<<"\n";
    return 0;
}