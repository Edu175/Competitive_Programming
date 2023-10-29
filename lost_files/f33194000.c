#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){
	vector<ll>p(2,1);
	p.pb(2),p.pb(3);
	do{
		fore(i,0,4)cout<<"0 "<<p[i]<<" ";
		cout<<"\n";
		string s; cin>>s;
	}
	while(next_permutation(ALL(p)));
	return 0;
}
