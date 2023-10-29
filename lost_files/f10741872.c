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
#define PI 3.141592653589793238462643383279502884197175105820974944592307816
using namespace std;
typedef double ll;

int main(){FIN;
	int a,b,d; cin>>a>>b>>d;
	d%=360;
	ll A,B,H;
	H=sqrt(a*a+b*b);
	if(a||b){
		ll Gi=asin(b/H)*180/PI;
		if((a<0) xor (b<0))Gi=90-Gi;
		d%=360;
		ll G=(d+Gi)-int((d+Gi)/90)*90;
		B=H*sin(G*PI/180);
		A=H*sin((90-G)*PI/180);
		if(a<0&&b<0)d+=180;
		else if(a<0)d+=90;//,swap(A,B);
		else if(b<0)d+=270;//,swap(A,B);
		cout<<fixed<<setprecision(15);//<<Gi<<" "<<G<<" ";
		if((d/90)==0)cout<<A<<" "<<B;//<<"e0\n";
		else if((d/90)==1)cout<<-B<<" "<<A;//<<"e1\n";
		else if((d/90)==2)cout<<-A<<" "<<-B;//<<"e2\n";
		else cout<<A<<" "<<B;//<<"e3\n";
	}
	else cout<<0<<" "<<0<<"\n";
}
