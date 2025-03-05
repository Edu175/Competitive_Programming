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

ll num(ll k, ll r){
	k++; // )
	ll res=k/4;
	res+=r<k%4;
	return res;
}

ll vac(ll k){
	vv c(4);
	c[k%4]++;
	ll res=0;
	for(ll i=k-1;i>=0;i--){
		ll d2=(i+2)%4;
		ll d3=(i+3)%4;
		res+=c[d2]+c[d3];
		c[i%4]++;
	}
	return res;
}
ll presuf(ll k, ll fg){ // not all , tampoco puede ser 0,0 pq es L
	vv c(4);
	ll res=0;
	for(ll i=k-1;k>=0;k--){
		ll d2=(2-i+4)%4;
		ll d3=(3-i+4)%4;
		
		res+=c[d2];
		res+=c[d3]*fg;
		
		c[((k-(i+1))%4+4)%4]++;
	}
	return res;
}
ll disjoint(ll l, ll r){
	ll res=0;
	fore(i,0,l+1)res+=num(r,(2-i+4)%4);
	return res;
}
int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	ll p=-1;
	fore(i,0,SZ(s))if(s[i]=='1')p=i;
	if(p==-1){
		ll res=vac(n)+presuf(n,0);
		cout<<res<<"\n";
	}
	else if(count(ALL(s),'1')==1){
		ll res=vac(n-1)+presuf(n-1,1);
		res+=(n-1)%4==2||(n-1)%4==3; // all with 1
		cout<<res<<"\n";
	}
	else {
		ll res=0;
		fore(i,0,n)if(s[i]=='1'){
			ll l=-1,r=-1;
			ll p=i;
			do{
				l++; p--;
				if(p<0)p+=n;
			}while(s[p]!='1');
			p=i;
			do{
				r++; p++;
				if(p>=n)p-=n;
			}while(s[p]!='1');
			
			cout<<i<<": "<<l<<" "<<r<<": "<<vac(l)<<" "<<disjoint(l,r)<<"\n";
			
			res+=vac(l);
			res+=disjoint(l,r);
		}
		cout<<res<<"\n";
	}
	return 0;
}
