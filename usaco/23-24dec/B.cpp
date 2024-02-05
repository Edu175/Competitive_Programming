#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,usaco=b;i<usaco;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	vector<ii>a;
	ll q=0,bor=1;
	fore(i,0,n){
		if(s[i]=='0'){
			if(q)a.pb({q,bor}),q=0;
			bor=0;
		}
		else q++;
	}
	if(q)a.pb({q,1});
	ll d=n;
	for(auto [x,t]:a){
		if(t)d=min(d,x-1);
		else d=min(d,(x+1)/2-1);
	}
	ll res=0;
	for(auto [x,t]:a)res+=(x+2*d)/(2*d+1);
	cout<<res<<"\n";
	return 0;
}
