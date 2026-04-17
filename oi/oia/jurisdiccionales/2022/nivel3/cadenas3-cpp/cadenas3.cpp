#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin,x.end
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
const ll MAXN=2e7+5;

ll cr[MAXN];
void criba(){
	mset(cr,-1);
	fore(i,2,MAXN)if(cr[i]<0){
		cr[i]=i;
		for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=i;
	}
}
map<ll,ll> fact(ll x){
	map<ll,ll>res;
	while(x!=1)res[cr[x]]++,x/=cr[x];
	return res;
}

vector<int> cadenas(vector<int> &a) {
	vector<int>res;
	criba();
    for(auto x:a){
    	ll sum=x;
    	map<ll,ll>div=fact(x);
    	for(auto d:div){
    		//cout<<d.fst<<","<<d.snd<<" ";
    		while(d.snd--){
    			x/=d.fst;
    			sum+=x;
    		}
    	}
    	res.pb(sum);
    	//cout<<"\n";
    }
    return res;
}
