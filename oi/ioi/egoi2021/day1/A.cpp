#include <bits/stdc++.h>
#define pb push__back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
// (2) 62   (5) 27
int main(){FIN;
	ll a,b; cin>>a>>b;
	ll p2=1,p5=1,res2=0,res5=0;
	fore(i,0,63){
		if((a+p2-1)/p2*p2<=b)res2=i;
		p2*=2;
	}
	fore(i,0,28){
		if((a+p5-1)/p5*p5<=b)res5=i;
		p5*=5;
	}
	cout<<min(res2,res5)<<"\n";
	return 0;
}
