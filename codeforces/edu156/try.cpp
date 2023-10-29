#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

int main(){FIN;
	ll n; cin>>n;
	ll MK=1;
	fore(i,0,n-1)MK*=3;
	vector<ll>p;
	fore(i,0,n)p.pb(i);
	fore(mk,0,MK){
		vector<ll>a={-1};
		ll mki=mk;
		fore(i,0,n-1)a.pb(mki%3),mki/=3;
		ll cnt=0;
		do{
			ll flag=1;
			ll mn=p[0],mx=p[0];
			fore(i,1,n){
				if(a[i]==0){
					if(!(p[i]<mn))flag=0;
					mn=p[i];
				}
				if(a[i]==2){
					if(!(p[i]>mx))flag=0;
					mx=p[i];
				}
				if(a[i]==1){
					if(!(mn<p[i]&&p[i]<mx))flag=0;
				}
				if(!flag)break;
			}
			cnt+=flag;
		}
		while(next_permutation(ALL(p)));
		if(cnt==0)cout<<a<<" "<<cnt<<"\n";
		//if(cnt>1)cout<<"AAAAAAAAAAAA\n";
	}
	return 0;
}
