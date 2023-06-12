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
	ll t; cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		string s;cin>>s;
		ll pares=0;
		for(char i='a';i<'z'+1;i++)pares+=count(ALL(s),i)/2;
		ll res=(pares/k)*2;
		if(n/k>=res+1)res++;
		cout<<res<<"\n";
	}
	 return 0;
}

