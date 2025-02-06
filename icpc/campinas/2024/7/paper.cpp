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

void check(vector<ll>a){
	auto as=a;
	sort(ALL(as));
	if(a==as)cout<<"Phew\n";
	else cout<<"Lie\n";
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	map<ll,vector<ll>>pos;
	ll mx=0;
	fore(i,0,n){
		cin>>a[i];
		mx=max(mx,a[i]);
		pos[a[i]].pb(i);
	}
	ll ult=n-1;
	while(SZ(pos[mx])&&pos[mx].back()==ult)pos[mx].pop_back(),ult--;
	if(!SZ(pos[mx])){
		check(a);
		return 0;
	}
	ll e=pos[mx].back();
	vector<ll>b;
	fore(i,e+1,n)b.pb(a[i]);
	fore(i,0,e+1)b.pb(a[i]);
	check(b);
	return 0;
}
