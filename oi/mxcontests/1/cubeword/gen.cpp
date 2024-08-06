#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,isudgh=b;i<isudgh;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto jhglkdfjg:v)cout<<jhglkdfjg<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
string alphabet="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int main(){FIN;
	ll A,R; cin>>A>>R;
	vector<string>a;
	fore(dfgj,0,2)fore(n,3,3+R)fore(i,0,A)fore(j,0,A){
		string s;
		s.pb(alphabet[i]);
		fore(k,0,n-3)s.pb('a'+dfgj);; s.pb('b'+dfgj);
		s.pb(alphabet[j]);
		a.pb(s);
	}
	cout<<SZ(a)<<"\n";
	for(auto i:a)cout<<i<<"\n";
	return 0;
}