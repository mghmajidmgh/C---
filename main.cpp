#include "headers/C+++.h"


using namespace std;
using namespace Ctriplus;

var u;
void f(var a,var b=u){}
void fq(){};
#define NAME_OF( v ) #v
int fp(int ii){ std::cout << NAME_OF(ii)<< std::endl; return 0;};
class c{ public: c(){  std::cout << NAME_OF(*this)<< std::endl;};};


int main(int argc, char const *argv[])
{ {
     
        var thislist = {1.234, "banana", "cherry", true, "kiwi", {1,2,3}, "mango"};
        var l=thislist["-4:-2"];
        print(l);
    }
    {
        var obj={
            "name","hasan",
            "family","abbasi",
            "grades",{1,2,7,9},
            "size",{
                    "width",100,
                    "height",200
                }
            
        };

print(obj);
int i=0;

    }
   
    {
        var str="Hrllo";
        char ch=str[-1];
        print(ch);
    }
    {
        var a=340;
        var b=2.1906;
        var c=false;
        var s="Hi";
        print(a,b,c,s);

        var arr={1,false,0.3,"Hello"};
        var obj=R"({firstName:"John", lastName:"Doe"})";
        print(arr);
        print(obj);

    }
    {
        var a{5}, b{1,2,"salam",{4,5,6}}, c{};
        print(a,b,c);
    }

    {
        var a={1,2,3};
        a.foreach([](var& i) { i += 1; } );
        a.foreach([](auto& element) { std::cout << element << " "; }) ;

    }
    {
     map<string, var> fruit_map =  {{"1", "Apple"},
                                  {"2", "Banana"},
                                  {"3", "Mango"},
                                  {"4", "Cocoa"}};
    var map1(fruit_map);
    print("map1:",map1);
    int t=0;
    }
    {
        var arr=R"("hi",1,2,"salam")";
        //for(const auto& item:arr){cout<<endl<<item;}
    }

    var x = R"({firstName:"John", lastName:"Doe"})";
    print(x);
    function f=[](object& self){return self["firstName"]+ var(" ")+ self["lastName"];};
    // var r=f(x);
    // print(r);
    // var of=f;
    x["f"]=f;
    //print(x);
    var result=x["f"]();
    print(result);
    print(x);
    x = R"([1,"salam",2])";
    print(x);
    x="i am strong";
    print(x);

    var pa="salam i am pa";
    print (1,pa);
    console.log("con.log");



     int t=9;
//     cout<<"Hello World"<<endl;   

//     auto pfq=fq;
//     auto pfp=fp;
//     //pfp=pfq;

//     function of=[](var a){cout<<a; return a;};
//     var f2{of};
//     var f3 { [](var a){cout<<a; int t=1+2; return a;} };
//     var ww= f2(100); 

//     f(1,2);

//     var arr;
    

//     arr.push_back(1);
//     arr.push_back(1.222);
//     cout<<arr;
//     arr[1]=string("salam");
// cout<<arr;

//     object a{1};
//     object b=a;
//     if(a==2){}
//     double d=a;
//     a["name"]="Majid";
//     a["family"]="hoseini";
//     a["f"]= var([](var a){cout<<"in a['f']"; int t=1+2; return a;} );
//     a["f"](2);
//     cout<<a;

//       //vector<object> vec{1,2,3};
//       var vt{1,2,false};
//      cout<<vt;

    string j=R"(
    {
    "glossary": {
        "title": "example glossary",
		"GlossDiv": {
            "title": "S",
			"GlossList": {
                "GlossEntry": {
                    "ID": "SGML",
					"SortAs": "SGML",
					"GlossTerm": "Standard Generalized Markup Language",
					"Acronym": "SGML",
					"Abbrev": "ISO 8879:1986",
					"GlossDef": {
                        "para": "A meta-markup language, used to create markup languages such as DocBook.",
						"GlossSeeAlso": ["GML", "XML"]
                    },
					"GlossSee": "markup",
                    "num": 1234,
                    "double_num": 900.145,
                    "bool": true
                }
            }
        }
    }
}
    )";
     string j2=R"([ 1, {"name":"majid"}, 3 ])";


    cout<<endl<<j<<endl;
    var jj=JSON::parse(j);
    cout<<jj<<endl;

    console.log("salam") ;


    return 0;
}

