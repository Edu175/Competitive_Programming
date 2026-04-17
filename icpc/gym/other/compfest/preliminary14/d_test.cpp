#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(v,a) memset((v),(a),sizeof(v))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
	ll n; cin>>n;
	vv a={1},b={1},cs={0};
	fore(i,1,n){
		ll v=a.back(),did=0;
		while(!did){
			fore(c,0,v){
				if(((v-c)<<c)>b.back()){
					b.pb((v-c)<<c);
					a.pb(v);
					cs.pb(c);
					did=1;
					break;
				}
			}
			v++;
		}
	}
	cout<<"a: ";for(auto i:a)cout<<i<<" ";;cout<<"\n";
	cout<<"b: ";for(auto i:b)cout<<i<<" ";;cout<<"\n";
	cout<<"c: ";for(auto i:cs)cout<<i<<" ";;cout<<"\n";
    return 0;
}