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
	freopen("concatenation.in","r",stdin);     freopen("concatenation.out","w",stdout);
	#endif
	string a,b; cin>>a>>b;
	ll n=SZ(a),m=SZ(b);
	vector<ll>oc(30);
	// for(auto i:b)oc[i-'a']++;
	fore(i,0,m-1)oc[b[i]-'a']++;
	ll res=0;
	fore(i,0,n)res+=m-(i<n-1?oc[a[i+1]-'a']:0);
	cout<<res<<"\n";
	return 0;
}