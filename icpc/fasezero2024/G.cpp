#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n+1);
	cin>>a[0].snd;
	fore(i,1,n+1)cin>>a[i].fst;
	fore(i,1,n+1)cin>>a[i].snd,a[i].snd+=a[i].fst;
	n++;
	ll e=a[0].snd,res=0,ei=e;
	fore(i,0,n){
		if(a[i].fst<=e)ei=max(ei,a[i].snd);
		else {
			if(ei<a[i].fst){res=-1;break;}
//			if(i==n-1)break;
//			cout<<i<<" stop\n";
			e=ei;
			res++;
			ei=a[i].snd;
		}
	}
	cout<<res<<"\n";
	return 0;
}
