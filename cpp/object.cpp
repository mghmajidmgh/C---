 
#include "../headers/object.h"

namespace Ctriplus
{   
    object&  object::operator[](int index){
        if (type!=OBJECT_TYPE::ARRAY){convertToArray();}
        if(index>=0){ return (*vec_ptr).at(index);}
        else{return ( (*vec_ptr).size()+index>=0 )? (*vec_ptr).at((*vec_ptr).size()+index): object();}       
    }
    object& object::subscriptor(string name){        
        if (type!=OBJECT_TYPE::OBJECT){convertToObject(); }
        if((*map_ptr)[name].isFunction()){(*map_ptr)[name].parent=this;}
        return (*map_ptr)[name];
    }
    
    object object::operator()(){
        return func(*parent);
    } 

    string object::toString(const string padding="")const{
        string ret=padding;
        string tpad="  ";

        if (type==OBJECT_TYPE::UNDEFIEND) {ret="undefined";}
        if (type==OBJECT_TYPE::BOOL) {ret=(value_bool)?"true":"false";}
        else if (type==OBJECT_TYPE::CHAR) {ret=to_string(value_char);}
        else if (type==OBJECT_TYPE::INT){ret=to_string(value_int);}
        // else if (type==OBJECT_TYPE::LONG_LONG){ret=to_string(value_ll);}
        else if (type==OBJECT_TYPE::DOUBLE){ret=to_string(value_double);}
        // else if (type==OBJECT_TYPE::LONG_DOUBLE){ret=to_string(value_long_double);}
        else if (type==OBJECT_TYPE::STRING){ret=(value_str);}
        else if (type==OBJECT_TYPE::ARRAY){
            bool isfirst=true;
            ret+="[";
            for(object const& item:*vec_ptr){
                if(isfirst){isfirst=false;}else{ret+=",";}
                string ch_quote=(item.isString())?"\"":"";
                ret+= ch_quote+item.toString()+ch_quote;
            }
            ret+="]";
        }else if (type==OBJECT_TYPE::OBJECT){
             bool isfirst=true;
            ret+="\n"+padding+"{\n";
            for(auto& [key, value]: *map_ptr){
                if(isfirst){isfirst=false;}else{ret+=",\n";}
                string ch_quote=(value.isString())?"\"":"";
                ret+=padding+tpad+ '\"'+ key +'\"'+ ":" +ch_quote+ value.toString(padding+tpad)+ch_quote;
            }            
            ret+="\n"+padding+"}";
        }else if (type==OBJECT_TYPE::FUNCTION){ret="function";}

        return ret;
    }

    std::ostream& operator<<(std::ostream& stream, const object& obj)
    {
        stream<<obj.toString("");
        return stream;
    }

    var  object::keys(){
        var ret;        
        if (type==OBJECT_TYPE::OBJECT){for(auto& [key, value]: *map_ptr){ret.push_back(key);} }
        return ret;
    }
    var  object::values(){
        var ret;        
        if (type==OBJECT_TYPE::OBJECT){for(auto& [key, value]: *map_ptr){ret.push_back(value);} }
        return ret;
    }
     var  object::items(){
        var ret;        
        if (type==OBJECT_TYPE::OBJECT){for(auto& [key, value]: *map_ptr){var arr; arr.push_back(key); arr.push_back(value);  ret.push_back(arr);} }
        return ret;
    }
    bool in(var value,var obj){
        if (type==OBJECT_TYPE::OBJECT){for(auto& [key, value]: *map_ptr){if(){}} }
    }
    

string JSON::getWithoutWhiteSpace(string text){
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
var JSON::parseR(string text,int ind) {
        var ret;

         for (; ind < text.length(); ind++)    { 
           
            if (text[ind]=='{')
            {
                while(text[ind]!='}' && ind < text.length()){
                    string name="";
                    ind++;
                    while(text[ind]!=':' && ind < text.length() ){name+=text[ind]; ind++;}
                    ind++;//pass :
                    if(name[0]=='\"' && name[name.length()-1]=='\"'){name=name.substr(1,name.length()-2);}//remove "" from name
                    var value=JSON::parseR( text, ind);
                    ind=value["ind"];
                    ret["value"][name]=value["value"];
                }
                ind++;//pass }
                ret["ind"]=ind;
                break;
            }else if (text[ind]=='[') {
                do{
                    ind++;
                    var value=JSON::parseR( text, ind);
                    ret["value"].push_back( value["value"]);
                    ind=value["ind"];
                    char tc=text[ind];
                    int t=0;
                }while(text[ind]!=']' && ind < text.length());
                ret["ind"]=ind+1;
                break;
            }else{
                string value="";      
                bool isString=(text[ind]=='\"');         
               do{value+=text[ind]; ind++;}while( ( isString && text[ind]!='\"' || !isString && text[ind]!=':' && text[ind]!=',' && text[ind]!=']' && text[ind]!='}') && ind < text.length());
               if(isString){value+='\"';ind++;}
               var ovalue;
               if(value[0]=='\"' && value.back()=='\"') {ovalue=value.substr(1,value.length()-2);}//remove "" from value
               else
               {
                   ovalue = parseInt(value);
                   if (ovalue.isUndefined())
                   {
                       ovalue = parseDouble(value);
                       if (ovalue.isUndefined())
                       {
                           ovalue = parseBool(value);
                       }
                   }
               }
               ret["ind"]=ind;
               ret["value"]=ovalue;
               break;
            }
            
         }
        return ret;
    }
    object JSON::parse(string text){ 
        string s=JSON::getWithoutWhiteSpace(text);
        return JSON::parseR(s)["value"];
    }

    void Console::log(object obj1,object obj2,object obj3,object obj4,object obj5,object obj6,object obj7,object obj8,object obj9,object obj10,object obj11,object obj12,object obj13){
        std::cout<<obj1;
        if(!obj2.isUndefined()){std::cout<<obj2;}
    }
    Console console ;

    void print(){};

    
    ///////   parseInt    //////////
    object parseBool(string value)
    {
        object ret;        
        if(value=="true"){ret=true;}else if(value=="false"){ret=false;}else{std::cerr << "string is not bool in parseBool" << '\n';}       
        return ret;
    }
    object parseInt(string value)
    {
        object ret;
        try
        {
            ret = stoi(value);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return ret;
    }
    object parseFloat(string value)
    {
        object ret;
        try
        {
            ret = stof(value);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return ret;
    }
    object parseDouble(string value)
    {
        object ret;
        try
        {
            ret = stod(value);
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        return ret;
    }
    ////////////////////////////////
    string type(object obj){
        string ret="";

        if (obj.type==OBJECT_TYPE::UNDEFIEND) {ret="undefiend";}
        else if (obj.type==OBJECT_TYPE::BOOL) {ret="bool";}
        else if (obj.type==OBJECT_TYPE::CHAR) {ret="char";}
        else if (obj.type==OBJECT_TYPE::INT){ret="int";}
        // else if (obj.type==OBJECT_TYPE::LONG_LONG){ret="long long";}
        else if (obj.type==OBJECT_TYPE::DOUBLE){ret="double";}
        // else if (obj.type==OBJECT_TYPE::LONG_DOUBLE){ret="long double";}
        else if (obj.type==OBJECT_TYPE::STRING){ret="string";}
        else if (obj.type==OBJECT_TYPE::ARRAY){ ret="array";  }
        else if (obj.type==OBJECT_TYPE::OBJECT){ ret="object" ;     }
        else if (obj.type==OBJECT_TYPE::FUNCTION){ret="function";}

        return ret;
    }
    int len(object obj){
        if (obj.type==OBJECT_TYPE::STRING){return obj.value_str.length();}
        else if (obj.type==OBJECT_TYPE::ARRAY){ return (*obj.vec_ptr).size(); }
        else if (obj.type==OBJECT_TYPE::OBJECT){  return (*obj.map_ptr).size(); }
        return 0;
    }



}