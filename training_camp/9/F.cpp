#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

long double dist(pair<ll,ll>p1, pair<ll,ll> p2){
	ll cx=abs(p1.fst-p2.fst);
	ll cy=abs(p1.snd-p2.snd);
	return hypot(cx,cy);
}

bool colineales(vector<pair<ll,ll>>abc){
	sort(ALL(abc));
	reverse(ALL(abc));
	pair<ll,ll> a=abc[0],b=abc[1],c=abc[2];
	ll cx1=a.fst-b.fst;
	ll cy1=a.snd-b.snd;
	ll cx2=b.fst-c.fst;
	ll cy2=b.snd-c.snd;
	ll g1=gcd(cx1,cy1);
	ll g2=gcd(cx2,cy2);
	cx1/=g1, cy1/=g1;
	cx2/=g2, cy2/=g2;
	//cout<<cx1<<","<<cy1<<" "<<cx2<<","<<cy2<<"\n";
	if(cx1==cx2&&cy1==cy2)return 1;
	else return 0;
}

int main(){FIN;
	ll n; cin>>n;
	pair<ll,ll> a[n];
	map<pair<ll,ll>,ll>pos;
	fore(i,0,n){
		cin>>a[i].fst>>a[i].snd;
		a[i].fst*=2;
		a[i].snd*=2;
		pos[a[i]]=i;
	}
	pair<ll,ll> p[3];
	p[0]=a[0];
	p[1]=a[1];
	long double d=dist(p[0],a[1]);
	fore(i,2,n){
		ll di=dist(p[0],a[i]);
		if(di<d)d=di,p[1]=a[i];
	}
	pair<ll,ll> mid={(p[0].fst+p[1].fst)/2,(p[0].snd+p[1].snd)/2};
	pair<ll,ll> mini;
	ll uno=1;
	fore(i,1,n){
		if(a[i]!=p[0]&&a[i]!=p[1]){
			//cout<<p[0].fst<<" "<<p[0].snd<<" "<<p[1].fst<<" "<<p[1].snd<<" "<<a[i].fst<<" "<<a[i].snd<<"? "<<colineales({p[0],p[1],a[i]})<<"\n";
			if(!colineales({p[0],p[1],a[i]})){
				long double di=dist(mid,a[i]);
				if(uno--==1)d=di,p[2]=a[i];//,cout<<"did1"<<"\n";
				else if(di<=d){
					d=di,p[2]=a[i];
					//cout<<"did"<<"\n";
				}
			}
		}
	}
	/*fore(i,0,3){
		cout<<p[i].fst<<","<<p[i].snd<<" ";
	}*/
	fore(i,0,3){
		cout<<pos[p[i]]+1<<" ";
	}
	return 0;
}
