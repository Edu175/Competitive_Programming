#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
		vector<ll>v;
		v.pb(5);
		v.pb(2);
		v.pb(3);
		fore(i,0,SZ(v))cout<<v[i]<<" ";
		cout<<"\n";
		v.pop_back();
		fore(i,0,SZ(v))cout<<v[i]<<" ";
	 return 0;
}
