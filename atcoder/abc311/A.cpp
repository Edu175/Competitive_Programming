#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll res=0;
	vector<ll>oc(3);
	fore(i,0,n){
		oc[s[i]-'A']++;
		if(oc[0]&&oc[1]&&oc[2]){
			res=i;
			break;
		}
	}
	cout<<res+1<<"\n";
	return 0;
}
