#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;

//'A'<'a';

int vial(int K, int C, string &tipo, vector<int> &cuantos, vector<int> &pos, string &queHay) {
	//cout<<"start\n";
    map<ll,ll>kmh;
    map<ll,ll>kmc;
    ll j[30];
    vector<ll> hay[30];
    //cout<<"iniciales\n";
    fore(i,0,SZ(tipo)){
    	while(cuantos[i]--)hay[tipo[i]-'A'].pb(-1);
    }
    vector<pair<ll,ll>>col;
   // cout<<"id\n";
    fore(i,0,SZ(queHay)){
    	if(queHay[i]>='a')kmh[pos[i]]=queHay[i]-'a'+1;
    	else kmc[pos[i]]=queHay[i]-'A'+1;//,cout<<pos[i]<<" "<<queHay[i]-'A'+1<<"\n";
    }
    //cout<<"hay col\nkmh:\n";
    for(auto i:kmh){
    	//cout<<i.fst<<" "<<i.snd<<"\n";
    	if(kmc[i.fst]!=i.snd)hay[i.snd-1].pb(i.fst);
    }
    //cout<<"kmc:\n";
    for(auto i:kmc){
    	//cout<<i.fst<<" "<<i.snd<<"\n";
    	if(i.snd&&kmh[i.fst]!=i.snd)col.pb({i.fst,i.snd-1});
    }
    sort(ALL(col));
    //cout<<"costo fijo\n";
	ll res=1e6*C+SZ(col)*K;
	//cout<<"pongo: "<<SZ(col)<<" saco: ";
	ll sc=0;
	fore(i,0,30){
		sort(ALL(hay[i]));
		j[i]=0;
		for(auto h:hay[i])if(h!=-1)res+=K,sc++;
	}
	//cout<<sc<<"\n";
	//cout<<"ran\n";
	/*fore(i,0,26){
		//cout<<char('a'+i)<<" "<<i<<": ";
		//imp(hay[i]);
	}*/
	vector<pair<ll,ll>>ran;
	for(auto i:col){
		//cout<<i.fst<<" "<<i.snd<<":\n";
		//cout<<j[i.snd]<<": ";
		//imp(hay[i.snd]);
		ll prox=hay[i.snd][j[i.snd]];
		if(prox>i.fst)ran.pb({i.fst,prox});
		j[i.snd]++;
	}
	if(!SZ(ran))return res;
	//cout<<"extra\n";
	ll r=ran[0].snd;
	ll ex=ran[0].snd-ran[0].fst;
	for(auto i:ran){
		//cout<<i.fst<<" "<<i.snd<<"\n";
		if(i==ran[0])continue;
		if(i.fst<r){
			if(i.snd>r)ex+=i.snd-r,r=i.snd;
		}
		else ex+=i.snd-i.fst,r=i.snd;
	}
	res+=ex*2*C;
	return res;
}
