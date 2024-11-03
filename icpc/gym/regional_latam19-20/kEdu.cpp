#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;

vv multiply(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b))c[i+j]+=a[i]*b[j];
	return c;
}

int main(){ET;
	string s; cin>>s;
	vv p={1};
	fore(i,0,SZ(s)-1){
		if(s[i]!=s[i+1])p=multiply(p,{-(2*i+3),1});
	}
	if((p[0]<0)!=(s[0]=='A')){
		for(auto &i:p)i=-i;
	}
	reverse(ALL(p));
	cout<<SZ(p)-1<<"\n";
	for(auto i:p)cout<<i<<" ";
	cout<<"\n";
}