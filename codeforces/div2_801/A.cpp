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

ll area(pair<ll,ll>p , pair<ll,ll>q){
	return (abs(p.fst-q.fst)+1)*(abs(p.snd-q.snd)+1);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n][m];
		pair<ll,ll> pos;
		ll maxi=-1e10;
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
				if(a[i][j]>maxi)maxi=a[i][j], pos.fst=i, pos.snd=j;
			}
		}
		ll res=0;
		ll res1,res2,res3,res4;
		res1=area(pos,{0,0});
		res2=area(pos,{n-1,0});
		res3=area(pos,{0,m-1});
		res4=area(pos,{n-1,m-1});
		res=max({res1,res2,res3,res4});
		//cout<<pos.fst<<" "<<pos.snd<<"\n";
		//cout<<res1<<" "<<res2<<" "<<res3<<" "<<res4<<"\n";
		pres;
	}
	return 0;
}
