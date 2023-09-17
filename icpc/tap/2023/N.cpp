#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll res=0;
	ll n; cin>>n;
	ll c[5]={};
	//cout<<"scan"<<endl;
	fore(i,0,n){
		ll x; cin>>x;
		c[x%5]++;
	}
	//imp(c);
	//cout<<"reduce"<<endl;
	res+=c[0]; c[0]=0;
	ll x=min(c[1],c[4]);
	res+=x; c[1]-=x,c[4]-=x;
	x=min(c[2],c[3]);
	res+=x; c[2]-=x,c[3]-=x;
	//cout<<"caso"<<endl;
	ll caso=0;
	if(c[1]&&c[2])caso=0;
	else if(c[1]&&c[3])caso=1;
	else if(c[4]&&c[2])caso=1;
	else if(c[4]&&c[3])caso=0;
	else{
		fore(i,1,5)res+=c[i]/5;
		cout<<res<<"\n";
		return 0;
	}
	//cout<<caso<<"\n";
	fore(i,1,5)c[i]=max(c[i],c[5-i]);
	//imp(c);
	//cout<<"it"<<endl;
	//cout<<caso<<endl;
	//imp(c);
	//cout<<endl;
	if(!caso){ //USAR ci addi
		ll add=0;
		fore(q,0,c[2]/2+5){
			//cout<<"q "<<q<<endl;
			ll ci[5];
			fore(j,0,5)ci[j]=c[j];
			if(q*2>ci[2]||q>ci[1])continue;
			ll addi=q; ci[2]-=2*q; ci[1]-=q;
			ll y=min(ci[2],ci[1]/3);
			addi+=y; ci[2]-=y,ci[1]-=3*y;
			addi+=ci[2]/5+ci[1]/5;
			add=max(addi,add);
		}
		res+=add;
	}
	else { //USAR ci addi
		ll add=0;
		fore(q,0,c[2]/3+5){
			ll ci[5];
			fore(j,0,5)ci[j]=c[j];
			if(q*3>ci[2]||q>ci[1])continue;
			ll addi=q; ci[2]-=3*q; ci[1]-=q;
			ll y=min(ci[2],ci[1]/2);
			addi+=y; ci[2]-=y,ci[1]-=2*y;
			addi+=ci[2]/5+ci[1]/5;
			add=max(addi,add);
		}
		res+=add;
	}
	cout<<res<<"\n";
	return 0;
}
