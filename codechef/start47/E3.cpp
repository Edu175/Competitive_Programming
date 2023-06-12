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
	ll t; cin>>t;
	while(t--){
		//eeeeeef
		//eeeef
		ll n; cin>>n;
		string a; cin>>a;
		ll flag=1;
		while(SZ(a)){
			if(SZ(a)%2){
				a.pop_back();
			}
			if(SZ(a)==0)break;
			string l,r;
			fore(i,0,SZ(a)/2)l.pb(a[i]);
			fore(i,SZ(a)/2,SZ(a))r.pb(a[i]);
			//cout<<l<<" "<<r<<"\n";
			if(l==r)a=l;
			else {
				flag=0;
				break;
			}
		}		
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
