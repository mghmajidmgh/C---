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
{
    print(1, 124);
    console.log("con.log");
    var ttt={0};
    //var arr1({1,2,3});
    //fp(ttt);
    c c1;
    ttt=1;
   
//     int t=9;
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
					"GlossSee": "markup"
                }
            }
        }
    }
}
    )";
     string j2=R"([ 1, {"name":"majid"}, 3 ])";


    cout<<endl<<j<<endl;
    var jj=JSON::parse(j);
    cout<<jj["value"]<<endl;

    console.log("salam") ;


    return 0;
}

