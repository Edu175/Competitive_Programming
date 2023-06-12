#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;

int main(){
	ll n,d,f; cin>>n>>d>>f;
	ll a[n];
	ll c[d];
	fore(i,0,d)c[i]=1;
	fore(i,0,n)cin>>a[i],c[a[i]-1]=0;
	ll res=0;
	ll sum=0;
	ll l=0,r;
	fore(i,0,d){
		sum+=c[i];
		r=i;
		while(sum>f){
			sum-=c[l];
			l++;
		}
		res=max(res,r-l+1);
	}
	/*fore(i,0,d)cout<<c[i];
	cout<<"\n";*/
	cout<<res<<"\n";
	return 0;
}
