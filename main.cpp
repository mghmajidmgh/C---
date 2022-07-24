#include "headers/C+++.h"

var u;
void f(var a,var b=u){}
void fq(){};
int fp(){ return 0;};

int main(int argc, char const *argv[])
{
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

    return 0;
}


