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

vector<vector<ll>>all;

vector<ll> p;
void f(ll s, ll i){
	if(i==45){
		if(s==41)all.pb(p);
		return;
	}
	if(s+i<=41){
		p.pb(i);
		f(s+i,i);
		p.pop_back();
	}
	f(s,i+1);
}

ll prod(vector<ll>&a){
	ll res=1;
	for(auto i:a)res*=i;
	return res;
}

int main(){FIN;
	f(0,1);
	//for(auto i:all){imp(i);}
	//cout<<SZ(all)<<"\n";
	/*ll mx=0;
	fore(i,0,SZ(all)){
		mx=max(mx,prod(all[i]));
	}
	cout<<mx<<"\n";*/
	//vector<ll>P(1e7);
	map<ll,ll>mp;
	fore(i,0,SZ(all)){
		ll p=prod(all[i]);
		if(!mp.count(p)||SZ(all[i])<SZ(all[mp[p]]))mp[p]=i;
	}
	ll _t; cin>>_t;
	fore(_,1,_t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		if(!mp.count(n))cout<<"-1\n";
		else {
			vector<ll>res=all[mp[n]];
			cout<<SZ(res)<<" ";
			imp(res);
		}
	}
	return 0;
}
