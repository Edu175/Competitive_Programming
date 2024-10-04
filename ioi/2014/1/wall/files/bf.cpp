#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kjfg:v)cout<<kjfg<<" ";cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

void buildWall(int n, int q, int op[], int l[], int r[], int h[], int ret[]){
	vector<ll>a(n);
	fore(i,0,q)r[i]++;
	fore(i,0,q){
		fore(j,l[i],r[i]){
			if(op[i]==1)a[j]=max(a[j],h[i]);
			else a[j]=min(a[j],h[i]);
		}
	}
	fore(i,0,n)ret[i]=a[i];
}
