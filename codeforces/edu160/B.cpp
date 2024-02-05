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
	ll t; cin>>t;
	while(t--){
		ll q[2]={};
		string s; cin>>s;
		ll n=SZ(s);
		for(auto i:s)q[i-'0']++;
		ll w=0;
		if(q[1]>q[0])w=1;
		q[w]-=q[w^1];
		q[w^1]=0;
		ll res=0;
		//cout<<w<<" "<<q[w]<<"\n";
		for(ll i=n-1;i>=0;i--){
			if(q[w]==0)break;
			res++;
			if(s[i]-'0'==w)q[w]--;
		}
		cout<<res<<"\n";
	}
	return 0;
}
