#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vector<ii>h;
		ll q=0,paso=0,fij=0;
		for(auto i:s){
			if(i=='0')q++;
			else {
				if(!paso)h.pb({2*q,0});
				else h.pb({q,1});
				paso=1;
				q=0; fij++;
			}
		}
		h.pb({2*q,0});
		if(!fij){cout<<"0\n";continue;}
		sort(ALL(h));
		auto val=[&](){
			ll res=0,cnt=0;
			fore(i,0,SZ(h)){
				auto [sz,dob]=h[i];
				if(!dob){
					sz/=2;
					if(cnt<sz)res+=cnt;
					else res+=sz;
					cnt++;
				}
				else {
					if(2*cnt<sz){
						ll resi=0;
						resi+=cnt++;
						resi+=cnt++;
						resi=min(resi,sz-1);
						res+=resi;
					}
					else res+=sz;
				}
			}
			return fij+res;
		};
		ll res=n+5;
		do{
			res=min(res,val());
		}while(next_permutation(ALL(h)));
		cout<<res<<"\n";
	}
	return 0;
}