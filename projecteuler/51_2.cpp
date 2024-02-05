#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

bool isPrime(ll x){
	if(x<2)return 0;
	for(ll i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}
ll dig(ll x){
	ll res=0;
	while(x>0)res++,x/=10;
	return res;
}
int main(){FIN;
	ll fam,D; cin>>fam>>D;
	ll p10[D+1];
	p10[0]=1;
	fore(d,1,D+1)p10[d]=p10[d-1]*10;
	vector<vector<ll>>mask;
	fore(mk,1,1ll<<D){
		ll c=__builtin_popcountll(mk);
		if((mk&1)==0&&c%3==0){
			ll x=0;
			fore(d,0,D){
				if((1ll<<d)&mk)x+=p10[d];
			}
			mask.pb({mk,x,c});
		}
	}
	//for(auto v:mask)cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
	vector<ii>res;
	for(auto v:mask){
		//cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<":"<<endl;
		fore(num,0,p10[D-v[2]]){
			ll x=0,n=num;
			fore(i,0,D)if(!((1ll<<i)&v[0])){
				x+=(n%10)*p10[i];
				n/=10;
			}
			//cout<<num<<" "<<x<<"\n";
			ll cnt=0,s=0;
			if(dig(x)!=dig(x+v[1]))s=1;
			fore(t,s,10)cnt+=isPrime(x+v[1]*t);
			if(cnt>=fam){
				fore(t,s,10)if(isPrime(x+v[1]*t)){
					res.pb({x+v[1]*t,v[1]});
					break;
				}
			}
		}
	}
	sort(ALL(res));
	if(!SZ(res))cout<<"ninguno\n";
	else {
		auto [x,v]=res[0];
		while(fam){
			if(isPrime(x))cout<<x<<"\n",fam--;
			x+=v;
		}
	}
	return 0;
}

