#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
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
	ll n, m; cin>>n>>m;
	ll rta=0;
	ll res=1;
	fore(k,2,m+1){
		vv st(k+10);
		ll a=0;
		ll sum=0;
		ll c=0;
		ll cnt=0;
		while(a<=n){
			if(st[c]) break;
			st[c]=1;
			st[k]=1;
			ll comidas=(n-c)/k+1;
			ll mas = c*comidas+k*(comidas)*(comidas-1)/2;
			ll q=0;
			if(c<=a) q = (a-c)/(k-1)+1;
			
			ll menos = c * q + k * q * (q-1) / 2;
			sum+=(mas -  menos);
			
			c=(c+comidas*k)%n;
			a+=comidas;
			// cout<<"a:"<<a<<" c:"<<c<<" sum:"<<sum<<" k:"<<k<<" comidas:"<<comidas<<" saltos:"<<saltos<<" n:"<<n<<endl;
			// if(k==11) cout<<"a:"<<a<<" c:"<<c<<" sum:"<<sum<<" k:"<<k<<" comidas:"<<comidas<<" q:"<<q<<endl;
			assert(comidas>=(n-c)/k-2);
			assert(c<=k+1);
			// if(k==1126) cnt++;
			// assert(cnt<=3);
			
		}
		// if(k==563) cout<<sum<<endl;
		// if(k==322) cout<<sum<<endl;
		if(sum>rta) res=k;
		rta = max(rta,sum);
	}
	cout<<res<<"\n";
	cerr<<rta<<"\n";
	return 0;
}