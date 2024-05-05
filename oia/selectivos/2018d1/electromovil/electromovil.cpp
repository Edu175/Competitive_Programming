#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfjg:v)cout<<kdfjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<int> electromovil(int E, vector<int> U, vector<int> A)
{
	ll n=SZ(U);
	vector<ii>a;
	fore(i,0,n)a.pb({U[i]+A[i],U[i]});
	ll e=0;
	ii mx={-1,-1};
	vector<int>res;
	fore(i,0,n){
		if(a[i].snd<=e)mx=max(mx,a[i]);
		else {
			//cout<<i<<": "<<e<<" "<<a[i].snd<<","<<a[i].fst<<"\n";
			if(mx.fst==-1)return {};
			e=mx.fst;
			if(mx.snd)res.pb(mx.snd);
			mx={-1,-1};
			i--;
		}
	}
	//if(res.back()==a.back().snd)return res;
	if(mx.fst==-1)return {};
	res.pb(a.back().snd);
	return res;
}
