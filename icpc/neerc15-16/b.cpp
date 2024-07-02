#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("black.in","r",stdin);     freopen("black.out","w",stdout);
	#endif
	vector<char> s={'@','.'};
	ll a,b; cin>>a>>b;
	vector<string>r;
	if(a<b)swap(a,b),swap(s[0],s[1]);
	ll c=a-(b-1); c=c*2+1;
	r.resize(c,"..");
	fore(i,0,c){
		if(i&1)r[i][0]=s[0];
		else r[i][0]=s[1];
		r[i][1]=s[1];
	}
	fore(i,0,b-1){
		r.pb(string(2,s[0]));
		r.pb(string(2,s[1]));
	}
	cout<<SZ(r)<<" "<<2<<"\n";
	fore(i,0,SZ(r))cout<<r[i]<<"\n";
	return 0;
}