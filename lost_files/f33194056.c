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
#define inops 	vector<ll> op=op2(v1.fst,v2.fst);	fore(i,0,6){		llv newv;		newv.fst=op[i];		newv.snd+="(";		if(i!=2&&i!=5)newv.snd+=(v1.snd);		else newv.snd+=(v2.snd);		if(i==0)newv.snd+="+";		if(i==1||i==2)newv.snd+="-";		if(i==3)newv.snd+="*";		if(i==4||i==5)newv.snd+="/";		if(i!=2&&i!=5)newv.snd+=(v2.snd);		else newv.snd+=(v1.snd);		newv.snd+=")";
/*
	vector<ll> op=op2(v1.fst,v2.fst);
	fore(i,0,6){
		llv newv;
		newv.fst=op[i];
		newv.snd+="(";
		if(i!=2&&i!=5)newv.snd+=(v1.snd);
		else newv.snd+=(v2.snd);
		if(i==0)newv.snd+="+";
		if(i==1||i==2)newv.snd+="-";
		if(i==3)newv.snd+="*";
		if(i==4||i==5)newv.snd+="/";
		if(i!=2&&i!=5)newv.snd+=(v2.snd);
		else newv.snd+=(v1.snd);
		newv.snd+=")";
		*/
using namespace std;
typedef float ll;
typedef pair<ll,string> llv;

ll pot10(ll x){
	ll res=1;
	fore(i,0,x)res*=10;
	return res;
}
ll res1;
ll res2;
ll cant1;
ll cant2;
vector<string>solutions1;
vector<string>solutions2;

vector<ll> op2(ll a,ll b){
	vector<ll> res;
	res.pb(a+b);
	res.pb(a-b);
	res.pb(b-a);
	res.pb(a*b);
	res.pb(a/b);
	res.pb(b/a);
	return res;
}

void inop3(llv v1, llv v2, llv v3){
	inops
		vector<ll> opj=op2(newv.fst,v3.fst);
		fore(j,0,6){
			llv newvj;
			newvj.fst=opj[j];
			newvj.snd+="(";
			if(j!=2&&j!=5)newvj.snd+=(newv.snd);
			else newvj.snd+=(v3.snd);
			if(j==0)newvj.snd+="+";
			if(j==1||j==2)newvj.snd+="-";
			if(j==3)newvj.snd+="*";
			if(j==4||j==5)newvj.snd+="/";
			if(j!=2&&j!=5)newvj.snd+=(v3.snd);
			else newvj.snd+=(newv.snd);
			newvj.snd+=")";
			if(newvj.fst==res1){
				cant1++;
				solutions1.pb(newvj.snd);
			}
			else if(newvj.fst==res2){
				cant2++;
				solutions2.pb(newvj.snd);
			}
		}
	}
}

void op3(llv a,llv b,llv c){
	inop3(a,b,c);
	inop3(a,c,b);
	inop3(b,c,a);
}

void inop4(llv v1, llv v2, llv v3, llv v4){
	inops
		op3(newv,v3,v4);
	}
}

void op4(llv a,llv b,llv c,llv d){
	inop4(a,b,c,d);
	inop4(a,c,b,d);
	inop4(a,d,c,b);
	inop4(b,c,d,a);
	inop4(b,d,c,a);
	inop4(c,d,a,b);
}

void inop5(llv v1, llv v2, llv v3, llv v4, llv v5){
	inops
		op4(newv,v3,v4,v5);
	}
}

void op5(llv a,llv b,llv c,llv d,llv e){
	inop5(a,b,c,d,e);
	inop5(a,c,b,d,e);
	inop5(a,d,c,b,e);
	inop5(a,e,c,b,d);
	inop5(b,c,d,a,e);
	inop5(b,d,c,a,e);
	inop5(b,e,c,a,d);
	inop5(c,d,a,b,e);
	inop5(c,e,a,b,d);
	inop5(d,e,a,b,c);
}

void inop6(llv v1, llv v2, llv v3, llv v4, llv v5, llv v6){
	inops
		op5(newv,v3,v4,v5,v6);
	}
}

void op6(llv a,llv b,llv c,llv d,llv e,llv f){
	inop6(a,b,c,d,e,f);
	inop6(a,c,b,d,e,f);
	inop6(a,d,c,b,e,f);
	inop6(a,e,c,b,d,f);
	inop6(a,f,c,b,d,e);
	inop6(b,c,d,a,e,f);
	inop6(b,d,c,a,e,f);
	inop6(b,e,c,a,d,f);
	inop6(b,f,c,a,d,e);
	inop6(c,d,a,b,e,f);
	inop6(c,e,a,b,d,f);
	inop6(c,f,a,b,d,e);
	inop6(d,e,a,b,c,f);
	inop6(d,f,a,b,c,e);
	inop6(e,f,a,b,c,f);
}

int main(){
	ll cart[6];
	ll r,s; 
	cout<<"Introducir 6 cartas: "; fore(i,0,6)cin>>cart[i];
	cout<<"Introducir las 2 cartas de resultado: "; cin>>r>>s;
	res1=r*pot10(((s)?(int(log10(s))+1):1))+s;
	res2=s*pot10(((r)?(int(log10(r))+1):1))+r;
	//cout<<res1<<" "<<res2<<"\n";
	cant1=0; cant2=0;
	pair<ll,string> v[6];
	fore(i,0,6)v[i].fst=cart[i], v[i].snd=to_string(int(cart[i]));
	op6(v[0],v[1],v[2],v[3],v[4],v[5]);
	if(res1==res2){
		cout<<"Existen "<<cant1<<" posibles soluciones con "<<res1<<"\n";
	}
	else{
		cout<<"Existen "<<cant1+cant2<<" posibles soluciones:\n";
		cout<<"Con "<<res1<<": "<<cant1<<"\n";
		cout<<"Con "<<res2<<": "<<cant2<<"\n";
	}
	while(1){
		cout<<"Escribir resultado y cantidad de soluciones si desea rendirse y spoilearse\nEscribir \"terminar\" si desea terminar\n";
		string q; cin>>q;
		if(q=="terminar")break;
		else if(q==to_string(int(res1))){
			long long m; cin>>m;
			fore(i,0,m){
				ll rnd=rand()%SZ(solutions2);
				cout<<solutions1[rnd]<<" = "<<res1<<"\n";
			}
		}
		else if(q==to_string(int(res2))){
			long long m; cin>>m;
			fore(i,0,m){
				ll rnd=rand()%SZ(solutions2);
				cout<<solutions2[rnd]<<" = "<<res2<<"\n";
			}
		}
		else cout<<"Comando invalido\n";
	}
	return 0;
}
