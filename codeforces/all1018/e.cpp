#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll node;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		// STree st(n);
		// fore(i,0,n)st.upd(i,1);
		ll fij=0,cp=0;
		fore(i,0,n){
			if(s[i]=='B')fij+=cp;
			else cp++;
		}
		vector<char> b;
		ll q=0;
		fore(i,0,n){
			q++;
			if(i==n-1||s[i]!=s[i+1]){
				if(q&1){
					if(SZ(b)&&b.back()==s[i])b.pop_back();
					else b.pb(s[i]);
				}
				q=0;
			}
		}
		ll sz=SZ(b);
		if(sz)sz+=-(b[0]=='B')-(b.back()=='P');
		assert(sz%2==0);
		ll res=(sz+3)/4;
		fij-=res;
		fij/=2;
		res+=fij;
		cout<<res<<"\n";
	}
	return 0;
}
