#include<bits/stdc++.h>
using namespace std;
const long double rtd=57.295779513082320876798154814105;
unsigned short stp;
typedef unsigned long long ull;
bool ispn(ull n){
	if(n<2) return 0;
	for(ull i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}
bool iscn(ull n){
	if(n<2) return 0;
	for(ull i=2;i*i<=n;i++) if(n%i==0) return 1;
	return 0;
}
ull min(ull i,ull n){
	if(i<n) return i;
	else return n;
}
ull max(ull i,ull n){
	if(i<n) return n;
	else return i;
}
void pf(ull num){
	ull cn,np=2,ny=0,y[1000];
	if(num<2) cout<<num<<"����ֵ<2��"; else{
		cn=num;
		while(iscn(num)){
			for(ull p=np;p*p<=num;p++){
				if(p>3&&p%2==0) p++;
				if((num%p==0)&&(ispn(p))){
					np=p;
					num/=p;
					y[ny]=p;
					ny++;
					break;
				}
			}
		}
		if(ispn(cn)) cout<<cn<<"��������"; else{
			if(num!=1) y[ny]=num;
			cout<<cn<<" = ";
			for(int i=0;i<ny;i++) cout<<y[i]<<"��";
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
ull lcm(ull n,ull x){
	if(n>x) swap(n,x);
	return x/gcd(n,x)*n;
}
long double mod(long double n,long double m){
	while(n<0||n>=m) if(n<0) n+=m; else n-=m;
	return n;
}
void cb(){
	long double n,num=0;
	ull lb,b;
	cin>>n>>lb>>b;
	b=max(min(b,36),2);
	lb=max(min(lb,10),2);
	int zn=n;
	long double xn=n-zn;
	char zdig[100]={0},xdig[1000]={0};
	for(int i=0;i<100;i++){
		num+=(zn%10)*pow(lb,i);
		zn/=10;
		if(zn==0) break;
	}for(int i=1;i<100;i++){
		xn*=10;
		xn=mod(xn,10);
		num+=int(xn)/pow(lb,i)*1.0;
		if(xn==0) break;
	}
	int di,znum=num;
	long double xnum=num-znum;
	for(int i=0;i<100;i++){
		zdig[i]=znum%b+'0';
		if(zdig[i]>'9') zdig[i]+=7;
		znum/=b;
		di=i;
		if(znum==0) break;
	}for(int i=di;i>-1;i--) cout<<zdig[i];
	if(xnum!=0){
		cout<<'.';
		for(int i=0;i<1000;i++){
			if(i>stp) break;
			xnum*=b;
			xdig[i]=int(xnum)+'0';
			if(xdig[i]>'9') xdig[i]+=7;
			xnum-=int(xnum);
			di=i;
			if(xnum==0) break;
		}for(int i=0;i<=di;i++) cout<<xdig[i];
	}
}
int main(){
	string code;
	cout<<"���������� v1.5.1\n1991537 Bytes\n"<<setprecision(10);
	while(1){
		cin>>code;
		if(code=="pf"){
			cout<<"���óɹ�\n";
			ull n;
			cin>>n;
			pf(n); 
		}else if(code=="gcd"){
			cout<<"���óɹ�\n";
			ull n,m;
			cin>>n>>m;
			cout<<gcd(n,m)<<endl;
		}else if(code=="lcm"){
			cout<<"���óɹ�\n";
			ull n,m;
			cin>>n>>m;
			cout<<lcm(n,m)<<endl;
		}else if(code=="+"){
			cout<<"���óɹ�\n";
			long double n,m;
			cin>>n>>m;
			cout<<n<<'+'<<m<<'='<<n+m<<endl;
		}else if(code=="-"){
			cout<<"���óɹ�\n";
			long double n,m;
			cin>>n>>m;
			cout<<n<<'-'<<m<<'='<<n-m<<endl;
		}else if(code=="*"){
			cout<<"���óɹ�\n";
			long double n,m;
			cin>>n>>m;
			cout<<n<<"��"<<m<<'='<<n*m<<endl;
		}else if(code=="/"){
			cout<<"���óɹ�\n";
			long double n,m;
			cin>>n>>m;
			cout<<n<<"��"<<m<<'='<<n/m<<endl;
		}else if(code=="^"){
			cout<<"���óɹ�\n";
			long double n,m;
			cin>>n>>m;
			cout<<n<<'^'<<m<<'='<<pow(n,m)<<endl;
		}else if(code=="ispn"){
			cout<<"���óɹ�\n";
			ull n;
			cin>>n;
			if(ispn(n)) cout<<"true\n"; else cout<<"false\n";
		}else if(code=="cb"){
			cout<<"���óɹ�\n";
			cb();
			cout<<endl;
		}else if(code=="stp"){
			cout<<"���óɹ�\n";
			cin>>stp;
			stp=min(500,stp);
			cout<<setprecision(stp);
		}else if(code=="dis"){
			cout<<"���óɹ�\n";
			long double x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			cout<<pow(pow((x2-x1),2)+pow((y2-y1),2),0.5);
		}else if(code=="dsin"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"sin "<<d<<"��="<<sin(d/rtd)<<endl;
		}else if(code=="dcos"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"cos "<<d<<"��="<<cos(d/rtd)<<endl;
		}else if(code=="dtan"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"tan "<<d<<"��="<<tan(d/rtd)<<endl;
		}else if(code=="dcot"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"cot "<<d<<"��="<<1.0/tan(d/rtd)<<endl;
		}else if(code=="dsec"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"sec "<<d<<"��="<<1.0/cos(d/rtd)<<endl;
		}else if(code=="dcsc"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"csc "<<d<<"��="<<1.0/sin(d/rtd)<<endl;
		}else if(code=="rsin"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"sin "<<d<<"="<<sin(d)<<endl;
		}else if(code=="rcos"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"cos "<<d<<"="<<cos(d)<<endl;
		}else if(code=="rtan"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"tan "<<d<<"="<<tan(d)<<endl;
		}else if(code=="rcot"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"cot "<<d<<"="<<1.0/tan(d)<<endl;
		}else if(code=="rsec"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"sec "<<d<<"="<<1.0/cos(d)<<endl;
		}else if(code=="rcsc"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"csc "<<d<<"="<<1.0/sin(d)<<endl;
		}else if(code=="dasin"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arcsin "<<d<<"="<<asin(d)*rtd<<"��\n";
		}else if(code=="dacos"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arccos "<<d<<"="<<acos(d)*rtd<<"��\n";
		}else if(code=="datan"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arctan "<<d<<"��="<<atan(d)*rtd<<"��\n";
		}else if(code=="dacot"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arccot "<<d<<"="<<1.0/atan(d)*rtd<<"��\n";
		}else if(code=="dasec"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arcsec "<<d<<"="<<1.0/acos(d)*rtd<<"��\n";
		}else if(code=="dacsc"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arccsc "<<d<<"="<<1.0/asin(d)*rtd<<"��\n";
		}else if(code=="rasin"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arcsin "<<d<<"="<<asin(d)<<endl;
		}else if(code=="racos"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arccos "<<d<<"="<<acos(d)<<endl;
		}else if(code=="ratan"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arctan "<<d<<"="<<atan(d)<<endl;
		}else if(code=="racot"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arccot "<<d<<"="<<1.0/atan(d)<<endl;
		}else if(code=="rasec"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arcsec "<<d<<"="<<1.0/acos(d)<<endl;
		}else if(code=="racsc"){
			cout<<"���óɹ�\n";
			long double d;
			cin>>d;
			cout<<"arccsc "<<d<<"="<<1.0/asin(d)<<endl;
		}else cout<<"��Ч���룡\n";
	}return 0;
}
