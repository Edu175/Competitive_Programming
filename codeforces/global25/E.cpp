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

string cv(pair<char,ll> a){
	string s;
	fore(i,0,a.snd)s.pb(a.fst);
	return s;
}

void answer(vector<string>&res){
	cout<<"YES\n";
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i<<" ";
	cout<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		ll n=SZ(s);
		string rs=s; reverse(ALL(rs));
		if(s!=rs){
			answer({s});
			continue;
		}
		vector<pair<char,ll>>a;
		ll q=1;
		fore(i,1,n){
			if(s[i]!=s[i-1])a.pb({s[i-1],q}),q=1;
			else q++;
		}
		a.pb({s[n-1],q});
		if(SZ(a)==1){
			cout<<"NO\n";
			continue;
		}
		if(SZ(a)%2==0){
			vector<string>res;
			fore(i,0,SZ(a))if(i%2==0){
				res.pb(cv(a[i])+cv(a[i+1]));
			}
			answer(res);
			continue;
		}
		n=SZ(a);
		ll p=-1;
		fore(i,1,SZ(a)-1)if(a[i].snd>1)p=i;
		if(p!=-1){
			vector<string>res;
			fore(i,0,SZ(a)){
				if(i+1==p)
			}
			continue;
		}
		if(SZ(a)<=3){
			cout<<"NO\n";
			continue;
		}
		
	}
	return 0;
}
