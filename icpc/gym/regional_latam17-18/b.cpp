#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool isvoc(char a){
	return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
}

int main(){ET;
	string s; cin>>s;
	vv v;
	fore(i,0,SZ(s)){
		if(isvoc(s[i])) v.pb(i);
	}
	if(!isvoc(s[0])){
		if(!SZ(v))cout<<"1\n"; 
		else cout<<"0\n";
		return 0;
	}
	ll r=1;
	ll j=v[SZ(v)/2]+((SZ(v)&1)?1:-1);
	while(j<SZ(s)){
		if(isvoc(s[j])) break;
		r++;
		j+=((SZ(v)&1)?1:-1);
	}
	cout<<r<<"\n";
	return 0;
}