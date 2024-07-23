#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;


ll n,t,a,b,c;
ii p,q,s,r;
ll st (ll x){
	return (x)*(x+1)/2;
}

ll dist (ii x, ii y){
	return abs(x.fst-y.fst)+abs(x.snd-y.snd);
}

ll ca(){
	if(c%2==1){
		return (c-1)*2*dist(p,q)+dist(p,q);
	}
	else{
		ii aux=p;
		ii aux1=q;
		aux.snd++;
		aux.fst++;
		aux1.fst++;
		return (c-2)*2*dist(aux,aux1)+dist(aux,aux1)+(c-2)*2+1;
	}
}

ll medio(){
	if(c%2==1){
		return ca();
	}
	else return ca()+2*dist(q,p)+1;
}

void path (){
	fore(i,1,a) cout<<'R';
	fore(i,1,b) cout<<'U';
	if(c%2==0){
		cout<<'R';
		cout<<'U';
	}
	fore(i,0,c-2){
		cout<<'U';
		cout<<'R';
		cout<<'R';
		cout<<'U';
	}
	fore(i,a+c-1,n) cout<<'R';
	fore(i,b+c-1,n) cout<<'U';
	cout<<"\n";
}

int main(){
	JET
	cin>>n>>t>>a>>b>>c;	
	
	p={a,b};
	q={a,b+c-1};
	r={a+c-1,b};
	s={a+c-1,b+c-1};
	ll tot=0;
	if(s.fst>n && s.snd>n){
		tot=st(dist({1,1},s)-1)-st(dist(s,{n,n}));
		if(tot>t) cout<<"Impossible\n";
		else{
			fore(i,1,n){
				cout<<'U';
			}
			fore(i,1,n) cout<<'R';
			cout<<"\n";
		}
	}
	else if (s.fst>n && s.snd<=n){
		ii aux={n,b};
		ii aux1={n,b+c-1};
		ll d1=st(dist({1,1},r)-1)-st(dist(aux,r))+((st(dist(r,aux)+dist(aux,{n,n})-st(dist(aux,r)))));
		ll d2=st(dist({1,1},s)-1)-st(dist(aux1,s))+((st(dist(s,aux1)+dist(aux1,{n,n})-st(dist(aux1,s)))));
		tot=max(d1,d2);
		if(tot>t) cout<<"Impossible\n";
		else{
			fore(i,1,n){
				cout<<'R';
			}
			fore(i,1,n) cout<<'U';
			cout<<"\n";
		}
	}
	else if(s.fst<=n && s.snd>n){
		ii aux={a,n};
		ii aux1={a+c-1,n};
		ll d1=st(dist({1,1},q)-1)-st(dist(aux,q))+(st(dist(q,aux)+dist(aux,{n,n})-st(dist(aux,q))));
		ll d2=st(dist({1,1},s)-1)-st(dist(aux1,s))+(st(dist(s,aux1)+dist(aux1,{n,n})-st(dist(aux1,s))));
		tot=max(d1,d2);
		if(tot>t) cout<<"Impossible\n";
		else{
			fore(i,1,n){
				cout<<'U';
			}
			fore(i,1,n) cout<<'R';
			cout<<"\n";
		}
	}
	else{
		tot+=st(dist(q,{1,1})-1);
		tot-=st(dist(q,p));
		tot+=st(dist(q,{n,n}));
		tot-=st(dist(q,s));
		tot+=medio();
		// cout<<tot;
		if(tot>t) cout<<"Impossible\n";
		else path();
	}
}