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
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==1){
			cout<<"1\n";
			continue;
		}
		vector<string>res;
		fore(k,0,n){
			string z(k,'0');
			string s="9"+z+"6"+z+"1";
			if(SZ(s)>n)break;
			string r(n-SZ(s),'0');
			s+=r;
			res.pb(s);
		}
		fore(k,0,n){
			string z(k,'0');
			string s="1"+z+"6"+z+"9";
			if(SZ(s)>n)break;
			string r(n-SZ(s),'0');
			s+=r;
			res.pb(s);
		}
		string s(n-3,'0');
		res.pb("196"+s);
		/*cout<<SZ(res)<<endl;
		imp(res);
		cout<<endl;*/
		fore(i,0,n)cout<<res[i]<<"\n";
	}
	return 0;
}
