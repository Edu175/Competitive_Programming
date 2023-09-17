#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n; cin>>n;
	map<string,ll>mp;
	bool res[n];
	fore(i,0,n){
		string s; cin>>s;
		mp[s]++;
		if(mp[s]>=2)res[i]=1;
		else res[i]=0;
	}
	fore(i,0,n){
		if(res[i])cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
