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
const ll INF=1e6+5;

long long tejedores(int K, vector<int> &t) {
    ll k=K;
    vector<ll>a;
    for(auto i:t)a.pb(i);
    ll n=SZ(a);
    ll sump[n+1];
    sump[0]=0;
    fore(i,0,n)sump[i+1]=a[i]+sump[i];
    ll v=(sump[n]+k-1)/k;
    ll r=0;
    //ll ran[K];
    fore(i,0,n){
    	if(a[i]+r<=v){
    		r+=a[i];
    	}
    	else {
    		k--;
    		if(k<=0)break;
    		ll tec=(sump[n]-sump[i]+k-1)/k;
    		if(r+a[i]<tec)v=r+a[i],r=0;
    		else v=tec,r=a[i];
    	}
    }
    //for(auto i:ran)cout<<i<<" ";
    //cout<<"\n";
    return v;//*max_element(ran,ran+K);
}
