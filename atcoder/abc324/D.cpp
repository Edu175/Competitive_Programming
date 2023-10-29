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

ll C=4e6;
ll n;
vector<ll> oc(string s){
	vector<ll>res(10);
	for(auto i:s)res[i-'0']++;
	return res;
}

void fill(string &s){
	string r(n-SZ(s),'0');
	for(auto i:s)r.pb(i);
	s=r;
}

int main(){FIN;
	cin>>n;
	string s; cin>>s;
	vector<ll> p=oc(s);
	ll res=0;
	fore(i,0,C){
		ll x=i*i;
		//ll db=(x==324||x==2304);
		string t=to_string(x);
		if(SZ(t)>n)break;
		fill(t);
		/*if(db){
			cout<<i<<": "<<x<<" "<<t<<": "; imp(oc(t));
		}*/
		if(p==oc(t))res++;
	}
	cout<<res<<"\n";
	return 0;
}
