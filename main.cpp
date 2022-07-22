#include "headers/C+++.h"

var u;
void f(var a,var b=u){}
void fq(){};
int fp(){ return 0;};

int main(int argc, char const *argv[])
{
    
    cout<<"Hello World"<<endl;

    auto pfq=fq;
    auto pfp=fp;
    //pfp=pfq;

    function of=[](var a){cout<<a; return a;};
    var f2{of};
    var f3 { [](var a){cout<<a; int t=1+2; return a;} };
    var ww= f2(100); 

    f(1,2);

    var arr;
    

    arr.push_back(1);
    arr.push_back(1.222);
    cout<<arr;
    arr[1]=string("salam");
cout<<arr;

    object a{1};
    object b=a;
    if(a==2){}
    double d=a;
    a["name"]="Majid";
    a["family"]="hoseini";
    a["f"]= var([](var a){cout<<"in a['f']"; int t=1+2; return a;} );
    a["f"](2);
    cout<<a;

    return 0;
}


