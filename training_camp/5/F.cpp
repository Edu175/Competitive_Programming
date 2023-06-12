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
typedef int ll;

int main(){FIN;
	string h; cin>>h;
	//cout<<h<<"\n";
	int m=SZ(h);
	ll flag=0,res;
	fore(i,0,m){
		if(flag)break;
		string ri;
		ri+=h[i];
		int numi=stoi(ri);
		//cout<<numi<<" ";
		if(numi%8==0)res=numi,flag=1;
		fore(j,i+1,m){
			if(flag)break;
			string r;
			r+=h[i];
			r+=h[j];
			int numj=stoi(r);
			//cout<<numj<<" ";
			if(numj%8==0)res=numj,flag=1;
			fore(k,j+1,m){
				if(flag)break;
				string s;
				s+=h[i];
				s+=h[j];
				s+=h[k];
				int num=stoi(s);
				//cout<<num<<" ";
				if(num%8==0)res=num,flag=1;
			}
		}
	}
	if (flag){
		cout<<"YES\n",pres;
	}
	else cout<<"NO\n";
	return 0;
}
