#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<ll>pos[2];
		string s; cin>>s;
		fore(i,0,n){
			pos[s[i]-'0'].pb(i);
		}
		reverse(ALL(pos[0]));
		auto cont=[&](string &s){
			// cout<<"candidato "<<s<<"\n";
			ll res=0,c=0;
			fore(i,0,SZ(s)){
				if(s[i]=='1')c++;
				else res+=c;
			}
			return res;
		};
		ll res=cont(s);
		fore(q,0,k+1){
			string si=s;
			fore(i,0,min((ll)SZ(pos[0]),q))si[pos[0][i]]='1';
			fore(i,0,min((ll)SZ(pos[1]),k-q))si[pos[1][i]]='0';
			res=min(res,cont(si));
		}
		cout<<res<<"\n";
	}
	return 0;
}
