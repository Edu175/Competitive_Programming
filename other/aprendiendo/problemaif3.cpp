#include<bits/stdc++.h>

using namespace std;

int main(){
	int x;
	cin>>x;
	if(x%3==0){
		cout<<"resto cero";
	}else if(x%3==1||x%3==-2){
		cout<<"resto uno";
	}else{
		cout<<"resto dos";
	}
	return 0;
}
