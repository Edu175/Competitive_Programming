#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	int n,q; 
	cin>>n>>q;
	string s,s1;
	cin>>s>>s1;
	fore(i,0,q){
		char c; cin>>c;
		if(c=='S'){
			int x; cin>>x;
			ll rta=stoll(s)+stoll(s1);
			cout<<to_string(rta)[n-1-x]<<"\n";
		}
		else{
			int x,y; cin>>x>>y;
			(c=='W') ? s[x]='0'+y:s1[x]='0'+y;
		}
	}
}