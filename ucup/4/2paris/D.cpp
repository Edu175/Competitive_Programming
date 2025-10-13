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

vv solve(ll k, ll lim){
	vv pot(k+5); pot[0]=1;
	ll ord=1;
	fore(i,1,SZ(pot)){
		pot[i]=pot[i-1]*10%k;
		if(pot[i]==1){
			ord=i;
			break;
		}
	}
	vv res(lim);
	cerr<<"ord "<<ord<<"\n";
	if(k<=100){ // k=1 also works, couls be relaxed up to 180
		ll c=k,p=0;
		while(c>0){
			ll q=min(9ll,c);
			c-=q;
			res[p]=q; p+=ord;
		}
		return res;
	}
	ll w=-1;
	fore(i,1,k+5)if(pot[i-1]*10>=k){w=i;break;}
	assert(w!=-1);
	ll r=0;
	fore(i,0,9){
		fore(j,0,w)res[ord*i+j]=1,r+=pot[j];
	}
	r%=k;
	ll s=k-9*w;
	assert(s>=0);
	fore(j,0,k+5)if(s){
		ll q=min(9ll,s);
		s-=q;
		r+=q*pot[j];
		res[10*ord+j]=q;
	}
	assert(s==0);
	if(r%9!=k%9){
		vv pos(9,-1); // pot[p]=1+r
		fore(i,0,k){
			pos[(pot[i]-1+9)%9]=i;
		}
		ll p=10*ord;
		assert(res[p]==9);
		ll dif=(k%9-r%9+9)%9;
		ll done=0;
		fore(at,0,9)if(pos[at]!=-1){
			fore(j,0,9+1){
				if(at*j==dif){
					done=1;
					r-=j;
					r=(r+pot[j]) // capaz se pasa de k
				}
			}
			if(done)break;
		}
		assert(done);
	}
	ll x=(k-r)%k;
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
	
}
	
	int main(){FIN;
		ll t; cin>>t;
		while(t--){
			ll k; cin>>k;
			ll cnt2=__builtin_ctzll(k),cnt5=0;
			while(k%5==0)cnt5++,k/=5;
			ll mx=max(cnt2,cnt5);
			k>>=cnt2;
			assert(gcd(k,10)==1);
			auto res=solve(k,20*k-mx);
			while(!res.back())res.pop_back();
			reverse(ALL(res));
			fore(_,0,mx)res.pb(0);
			for(auto i:res)cout<<i;
			cout<<"\n";
		}
	return 0;
}
