#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu+1<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i],a[i]--;
		ll res[n];
		ll did=-1;
		fore(i,0,n){
			if(did>=0)res[i]=did,did=-1;
			else if(i!=a[i])res[i]=i;
			else if(i<n-1)res[i]=i+1, did=i;
			else res[i]=res[i-1], res[i-1]=i;
		}
		if(n==1)cout<<-1<<"\n";
		else imp(res);
	}
	return 0;
}
