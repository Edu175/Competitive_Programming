#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	string s; cin>>s;
	ll n=SZ(s);
	vector<vector<ll>>hs(n+1,vector<ll>(26));
	fore(i,1,n+1){
		hs[i]=hs[i-1];
		hs[i][s[i-1]-'a']++;
	}
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		if(r-l==1)cout<<"Yes\n";
		else if(s[l]!=s[r-1])cout<<"Yes\n";
		else{
			ll c=0;
			fore(j,0,26)c+=hs[r][j]>hs[l][j];
			if(c>=3)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	return 0;
}

