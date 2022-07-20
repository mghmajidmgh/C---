#include "h/C+++.h"

int main(int argc, char const *argv[])
{
    
    cout<<"Hello World"<<endl;

    object arr;
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
    cout<<a;

    return 0;
}
