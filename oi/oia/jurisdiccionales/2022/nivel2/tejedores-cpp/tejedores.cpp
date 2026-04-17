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
const ll MAXN=1e5+5;
ll a[MAXN];
ll n,k;
bool solve(ll x){
	ll ki=k-1;
	ll sum=0;
	fore(i,0,n){
		sum+=a[i];
		if(sum>x){
			//cout<<i<<"\n";
			ki--;
			sum=a[i];
			if(sum>x)return 0;
		}
	}
	if(ki<0)return 0;
	return 1;
}

ll tejedores(int K, vector<int> &t) {
    k=K;n=SZ(t);
    fore(i,0,n)a[i]=t[i];
    ll l=0,r=1e11;
    //while(1){ll q;cin>>q;cout<<solve(q)<<endl;}
    while(l<=r){
    	ll m=(l+r)/2;
    	if(solve(m))r=m-1;
    	else l=m+1;
    }
    return l;
}
