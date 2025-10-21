#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

// x%9==0 => r%9 == k%9

vv solve(ll d, ll k, ll lim){ // desired sum, modulo, limit of dig
	// cerr<<"solve "<<d<<" "<<k<<" "<<lim<<":\n";
	vv pot(k+5); pot[0]=1;
	ll ord=1;
	fore(i,1,SZ(pot)){
		pot[i]=pot[i-1]*10%k;
		if(pot[i]==1){
			ord=i;
			// cerr<<"found\n";
			break;
		}
	}
	vv res(lim);
	// cerr<<"ord "<<ord<<"\n";
	if(d<=100){ // k=1 also works, couls be relaxed up to 180
		ll c=d,p=0;
		while(c>0){
			ll q=min(9ll,c);
			c-=q;
			res[p]=q; p+=ord;
		}
		return res;
	}
	ll w=-1;
	fore(i,1,k+5)if(pot[i-1]*10>=k){w=i;break;}
	// cerr<<"w "<<w<<"\n";
	assert(w!=-1);
	ll r=0;
	fore(i,0,9){
		fore(j,0,w)res[ord*i+j]=1,r+=pot[j];
	}
	r%=k;
	ll s=d-9*w; // digit sum
	assert(s>=0);
	fore(j,0,d+5)if(s){
		ll q=min(9ll,s);
		s-=q;
		r+=q*pot[j%ord];
		res[10*ord+j]=q;
	}
	r%=k;
	assert(s==0);
	
	assert(r%gcd(k,9)==0);
	ll u=-1;
	fore(c,1,10){
		ll cur=c*k;
		if(r%9==cur%9){u=cur;break;}
	}
	assert(u!=-1);
	
	ll x=u-r;
	// cout<<r<<": "<<u<<": "<<x<<"\n";
	assert(x%9==0); // asegurar
	for(ll j=w-1;j>=0;j--){
		ll am=9*pot[j];
		ll q=x/am;
		assert(q<=9);
		x-=q*am;
		fore(i,0,q){
			ll p=ord*i+j;
			res[p]--;
			res[p+1]++;
		}
	}
	assert(x==0); // deberias hacer que x%9==0 al principio
	return res;
}
	
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll k; cin>>k;
		ll _k=k;
		ll cnt2=__builtin_ctzll(k),cnt5=0;
		while(k%5==0)cnt5++,k/=5;
		ll mx=max(cnt2,cnt5);
		k>>=cnt2;
		assert(gcd(k,10)==1);
		auto res=solve(_k,k,20*_k-mx);
		ll sum=0;
		for(auto i:res)sum+=i;
		assert(sum==_k);
		while(!res.back())res.pop_back();
		reverse(ALL(res));
		fore(_,0,mx)res.pb(0);
		for(auto i:res)cout<<i;
		cout<<"\n";
	}
	return 0;
}
