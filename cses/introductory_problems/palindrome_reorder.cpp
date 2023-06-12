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
	map<char,ll>oc;
	for(auto i:s)oc[i]++;
	char mid='\0';
	string res;
	bool flag=1;
	for(auto i:oc){
		if(i.snd%2){
			if(mid!='\0')flag=0;
			else mid=i.fst;
		}
		fore(j,0,i.snd/2)res+=i.fst;
	}
	if(flag){
		cout<<res;
		if(mid!='\0')cout<<mid;
		reverse(ALL(res));
		cout<<res;
	}
	else cout<<"NO SOLUTION";
	return 0;
}
