#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<string> dias={"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
ll trad(string s){
	fore(i,0,SZ(dias))if(s==dias[i])return i;
	assert(0);
}

int main(){
	ET
	string s; ll n; cin>>s>>n;
	ll t=trad(s);
	ll res=60;
	fore(i,0,n){
		ll d; cin>>d;
		if(!d){
			d=-30;
			ll r=(t+2)%7;
			if(r==5||r==6)d-=7-r,r=0;
			res=min(res,-d);
			continue;
		}
		ll r=(t-d%7+7)%7;
		
		while(d>0){
			if(r==0)d%=91;
			d-=30,r=(r+2)%7;
			if(r==5||r==6)d-=7-r,r=0;
		}
		res=min(res,-d);
	}
	cout<<res<<"\n";
	
}