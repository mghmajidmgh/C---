#include "headers/C+++.h"

var u;
void f(var a,var b=u){}
void fq(){};
int fp(){ return 0;};
string getWithoutWhiteSpace(string text);
var JSONparse(string text,int ind=0);

int main(int argc, char const *argv[])
{
    int t=9;
    cout<<"Hello World"<<endl;   

   



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

    // object a{1};
    // object b=a;
    // if(a==2){}
    // double d=a;
    // a["name"]="Majid";
    // a["family"]="hoseini";
    // a["f"]= var([](var a){cout<<"in a['f']"; int t=1+2; return a;} );
    // a["f"](2);
    // cout<<a;

      //vector<object> vec{1,2,3};
      //var vt{1,2,false};
     //cout<<vt;

     
    string j2=R"(
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
     string j=R"([ 1, {"name":"majid"}, 3 ])";

cout<<endl<<j<<endl;
    string s=getWithoutWhiteSpace(j);
    cout<<s<<endl;
    var jj=JSONparse(s);cout<<jj["value"]<<endl;

    return 0;
}

string getWithoutWhiteSpace(string text){
    string ret="";
    for (size_t ind = 0; ind < text.length(); ind++)
    {        
        if (text[ind]=='"')
        {
            ret+=text[ind]; ind++;
             for (; ind < text.length(); ind++)  { ret+=text[ind];  if (text[ind]=='\\')  { ret+=text[ind+1]; ind+=2; } if(text[ind]=='\"')  { ind++; break;}  }         
        }
        char ch=text[ind];
        if (text[ind]!=' ' && text[ind]!='\n'  && text[ind]!='\t'){
            ret+=text[ind];
        }        
    }
    return ret;
}
var JSONparse(string text,int ind)
    {
        var ret;

         for (; ind < text.length(); ind++)    { 
           
            if (text[ind]=='{')
            {
                while(text[ind]!='}' && ind < text.length()){
                    string name="";
                    ind++;
                    while(text[ind]!=':' && ind < text.length() ){name+=text[ind]; ind++;}
                    cout<<" name:"<<name;
                    ind++;//pass :
                    cout<<"ind:"<<ind<<endl;
                    var value=JSONparse( text, ind);
                    ind=value["ind"];
                    ret["value"][name]=value["value"];
                    cout<<"after call JSONparse, ind:"<<ind<<" value:"<<ret[name]<<endl;
                    //ind++;//pass ,
                }
                ind++;//pass }
                ret["ind"]=ind;
                break;
            }else if (text[ind]=='[') {
                do{
                ind++;
                    cout<<"in array,";
                    cout<<"ind:"<<ind<<endl;
                    var value=JSONparse( text, ind);
                    ret["value"].push_back( value["value"]);
                    ind=value["ind"];
                    cout<<"in array after call JSONparse, ind:"<<ind<<" value:"<<value["value"]<<endl;
                    char tc=text[ind];
                    int t=0;
                }while(text[ind]!=']' && ind < text.length());
                ret["ind"]=ind;
                break;
            }else{
                string value="";               
               while(text[ind]!=':' && text[ind]!=',' && text[ind]!=']' && text[ind]!='}' && ind < text.length()){value+=text[ind]; ind++;}
               ret["ind"]=ind;
               ret["value"]=value;
               break;
            }
            
         }

   return ret;
    }