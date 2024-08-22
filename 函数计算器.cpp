#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
bool ispn(unsigned long long n){
	if(n<2) return 0;
	for(unsigned long long i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
bool iscn(unsigned long long n){
	if(n<2) return 0;
	for(unsigned long long i=2;i*i<=n;i++) if(n%i==0) return 1;
	return 0;
}
unsigned long long min(unsigned long long i,unsigned long long n){
	if(i<n) return i;
	else return n;
}
unsigned long long max(unsigned long long i,unsigned long long n){
	if(i<n) return n;
	else return i;
}
void pf(unsigned long long num){
	unsigned long long cn,np=2,ny=0,y[1000];
	if(num<2) cout<<num<<"错误，值<2!"; else{
		cn=num;
		while(iscn(num)){
			for(unsigned long long p=np;p*p<=num;p++){
				if(p>3&&p%2==0) p++;
				np=p;
				if((num%p==0)&&(ispn(p))){
					num/=p;
					y[ny]=p;
					ny++;
					break;
				}
			}
		}
		if(ispn(cn)) cout<<cn<<"是质数。"; else{
			if(num!=1) y[ny]=num;
			cout<<cn<<" = ";
			for(int i=0;i<ny;i++) cout<<y[i]<<"×";
			cout<<y[ny];
		}
		cout<<endl;
	}
}
unsigned long long gcd(unsigned long long n,unsigned long long x){
	if(n>x) swap(n,x);
	if(ispn(n)&&ispn(x)) return 1; else if(x%n==0) return n; else if(n==1) return 1; else{
		while(1){
			x%=n;
			swap(n,x);
			if(ispn(n)&&ispn(x)) return 1; else if(x%n==0) return min(n,x); else if(n==1) return 1;
		}
	}
}
unsigned long long lcm(unsigned long long n,unsigned long long x){
	if(n>x) swap(n,x);
	return x/gcd(n,x)*n;
}
int main(){
	string code;
	cout<<"函数计算器 v1.1.0\n";
	while(1){
		cin>>code;
		if(code=="pf"){
			cout<<"调用成功\n";
			int n;
			cin>>n;
			pf(n); 
		}else if(code=="gcd"){
			cout<<"调用成功\n";
			int n,m;
			cin>>n>>m;
			cout<<gcd(n,m)<<endl;
		}else if(code=="lcm"){
			cout<<"调用成功\n";
			int n,m;
			cin>>n>>m;
			cout<<lcm(n,m)<<endl;
		}else cout<<"无效代码！\n";
	}
	return 0;
}
