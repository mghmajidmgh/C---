#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <iostream>
#include <vector>
#include <map>
#include <memory>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <string>

using namespace std;
using namespace std::rel_ops;

namespace Ctriplus
{
    class object;        
    using var=object;

    enum OBJECT_TYPE{UNDEFIEND,BOOL,CHAR,INT,LONG_LONG,DOUBLE,LONG_DOUBLE,STRING,ARRAY,OBJECT,FUNCTION};
    using function=object (*)(object &self);
    using function1=object (*)(object &self,object& argument);
    using functionNoReturn=void (*)(object &self,object& argument);

    class JSON{  
        public:      
            static object parseR(string text,int ind=0);
            static string getWithoutWhiteSpace(string text);
        public:
            static object parse(string text);
    };

    class object
    {
        OBJECT_TYPE type{};
        bool value_bool;
        char value_char{};
        int value_int{};
        // long long value_ll{};
        double value_double{};
        // long double value_long_double{};
        string value_str{};
        function func;
        std::shared_ptr<vector<object>> vec_ptr{};
        std::shared_ptr<map<string, object> > map_ptr{};
       
        

        void convertToArray(){
           type=OBJECT_TYPE::ARRAY;  
            vec_ptr= std::make_shared< vector<object>>(); 
            map_ptr=nullptr;
        }
        void convertToObject(){
            type=OBJECT_TYPE::OBJECT; 
            map_ptr= std::make_shared< map<string,object>>(); 
            vec_ptr=nullptr; 
        }

        void checkForObjectString(string value){//cout<<"checkForObjectString";
                if(value[0]=='{' && value.back()=='}' || value[0]=='[' && value.back()==']'){  type= OBJECT_TYPE::OBJECT; *this=JSON::parse(value);}
        }

        public:
            object *parent;
            object(){type=OBJECT_TYPE::UNDEFIEND;  }
            //object(undefined_class value):type{OBJECT_TYPE::UNDEFIEND} {}
            object(bool value):value_bool{value},type{OBJECT_TYPE::BOOL} {}
            object(char value):value_char{value},type{OBJECT_TYPE::CHAR} {}
            object(int value):value_int{value},type{OBJECT_TYPE::INT} {}
            // object(long long value):value_ll{value},type{OBJECT_TYPE::LONG_LONG} {}
            object(double value):value_double{value},type{OBJECT_TYPE::DOUBLE} {}
            // object(long double value):value_long_double{value},type{OBJECT_TYPE::LONG_DOUBLE} {}
            object(string value):value_str{value},type{OBJECT_TYPE::STRING} {checkForObjectString(value);}
            object(const char* value):value_str{string(value)},type{OBJECT_TYPE::STRING} {checkForObjectString(value);}            
            object(function func):func{func},type{OBJECT_TYPE::FUNCTION} {}
            //object(functionNoReturn funcp):type{OBJECT_TYPE::FUNCTION} { func= [funcp](object self,object argument)->object {funcp(self,argument); return object();};  }
            object(vector<object> vec):type{OBJECT_TYPE::ARRAY} {                
                convertToArray();
                for(const auto& item:vec){ push_back(item); cout<<endl<<item;}
            }
            // object(initializer_list<object> vec):type{OBJECT_TYPE::ARRAY} {
            //     convertToArray();
            //     for(const auto& item:vec){ push_back(item);}
            // }
            // object(initializer_list<string,object> map):type{OBJECT_TYPE::OBJECT} {                
            //     convertToObject();
            //     for(const auto& [key, value]: map){
            //          (*map_ptr)[key]=value;
            //     }
            // }
            object(map<string,object> map):type{OBJECT_TYPE::OBJECT} {                
                convertToObject();
                for(const auto& [key, value]: map){
                     (*map_ptr)[key]=value;
                }
            }

            //copy constructor
            // object(const object &obj): type{obj.type},value_int{obj.value_int},vec_ptr{obj.vec_ptr}, map_ptr{obj.map_ptr} { 
            //     cout<<"in copy cons"; 
            // }
            //copy assignment operator
            // object& operator=(const object& right_hand_side){}

            bool isUndefined()const{return (type==OBJECT_TYPE::UNDEFIEND)?true:false;}
            bool isBool()const{return (type==OBJECT_TYPE::BOOL)?true:false;}
            bool isChar()const{return (type==OBJECT_TYPE::CHAR)?true:false;}
            bool isInt()const{return (type==OBJECT_TYPE::INT)?true:false;}
            // bool isLongLong()const{return (type==OBJECT_TYPE::LONG_LONG)?true:false;}
            bool isDouble()const{return (type==OBJECT_TYPE::DOUBLE)?true:false;}
            // bool isLongDouble()const{return (type==OBJECT_TYPE::LONG_DOUBLE)?true:false;}
            bool isString()const{return (type==OBJECT_TYPE::STRING)?true:false;}
            bool isArray()const{return (type==OBJECT_TYPE::ARRAY)?true:false;}
            bool isObject()const{return (type==OBJECT_TYPE::OBJECT)?true:false;}
            bool isFunction()const{return (type==OBJECT_TYPE::FUNCTION)?true:false;}
            string getString()const{ if(type!=OBJECT_TYPE::STRING){throw runtime_error{ "object is not a string"};}else{ return value_str;} }


            bool operator<(const object& obj)const{ return value_int<obj.value_int; }
            bool operator<(int val)const{ return value_int<val; }
            bool operator==(const object& obj)const{ return value_int==obj.value_int; }
            bool operator==(int value)const{ return value_int==value; }

            object operator+(const object& obj)const{
                if(type==OBJECT_TYPE::STRING){
                    return value_str+obj.getString();
                }
                return obj;
            }
            object& operator++(){value_int++; return *this;}
            object& operator[](size_t index){
                if (type!=OBJECT_TYPE::ARRAY){convertToArray();}
                return (*vec_ptr).at(index);
            }
            object& subscriptor(string name){
                if (type!=OBJECT_TYPE::OBJECT){convertToObject(); }
                if((*map_ptr)[name].isFunction()){(*map_ptr)[name].parent=this;}
                return (*map_ptr)[name];
            }
            object& operator[](const char* name){return subscriptor(string(name) );}
            object& operator[](string name){return subscriptor(name); }

            operator int() const { return value_int; }
            operator double() const { return value_double; }

            object operator()() ;
            object operator()(object argument) ;

            vector<object>::iterator begin()
            {
                return (*vec_ptr).begin();
            }
            vector<object>::iterator end()
            {
                return (*vec_ptr).end();
            }

            string toString(const string padding)const;
            friend std::ostream& operator<<(std::ostream& stream, const object& obj);
            friend string type(var obj);
            friend int len(var obj);

            object& push_back(object obj){
                if (type!=OBJECT_TYPE::ARRAY)
                {
                    convertToArray();
                    //throw runtime_error{ "object is not an array"};
                }
                vec_ptr->push_back(obj);
                return *this;
            }
            //void ttt(var a,var b,var c=undefined,var d=undefined){}
    };

    

    class Console{
        public:
            void log(object obj1,object obj2=object(),object obj3=object(),object obj4=object(),object obj5=object(),object obj6=object(),object obj7=object(),object obj8=object(),object obj9=object(),object obj10=object(),object obj11=object(),object obj12=object(),object obj13=object());
            //template <typename... Ts>
            //void log(Ts... args);
    };
    extern Console console;

    
    //inline bool operator<(const object& obj,int val)const{ return obj.value_int<val; }

    /////////   print    //////////
    // Variadic function
    void print();
    template <typename T, typename... Types>
    void print(T var1, Types... var2)
    {
        cout << var1 << " "; 
        print(var2...);
    }
    ////////////////////////////////

    ///////   parseInt    //////////
    object parseBool(string value);
    object parseInt(string value);
    object parseFloat(string value);
    object parseDouble(string value);
    ////////////////////////////////

    
}

#endif