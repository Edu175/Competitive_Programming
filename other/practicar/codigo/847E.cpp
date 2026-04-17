#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	auto can=[&](ll x)->bool{
		vector<ll>a;
		queue<ll>q;
		fore(i,0,n){
			if(s[i]=='P')a.pb(i);
			if(s[i]=='*')q.push(i);
		}
		for(auto i:a){
			ll d=i+x;
			if(SZ(q)&&q.front()<i){
				ll k=i-q.front();
				if(x<k)return 0;
				d=max(i+(x-k)/2,i+x-2*k);
			}
			while(SZ(q)&&q.front()<=d)q.pop();
		}
		return SZ(q)==0;
	};
	ll l=0,r=2*n+5;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}
