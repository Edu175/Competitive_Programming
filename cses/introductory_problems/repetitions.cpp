#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,v,n) for(ll i=v, edu=n; i<edu; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	string s; cin>>s;
	ll res=0, resi=1;
	fore(i,0,SZ(s)-1){
		if(s[i]==s[i+1])resi++;
		else res=max(res,resi),resi=1;
	}
	res=max(res,resi);
	cout<<res;
	return 0;
}
