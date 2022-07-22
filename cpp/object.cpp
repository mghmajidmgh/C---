 
#include "../headers/object.h"

namespace Ctriplus
{   
    object object::operator()(object argument){return func(argument); };    


    std::ostream& operator<<(std::ostream& stream, const object& obj)
    {
        if (obj.type==OBJECT_TYPE::CHAR) {stream<<obj.value_char;}
        else if (obj.type==OBJECT_TYPE::INT){stream<<obj.value_int;}
        else if (obj.type==OBJECT_TYPE::LONG_LONG){stream<<obj.value_ll;}
        else if (obj.type==OBJECT_TYPE::DOUBLE){stream<<obj.value_double;}
        else if (obj.type==OBJECT_TYPE::LONG_DOUBLE){stream<<obj.value_long_double;}
        else if (obj.type==OBJECT_TYPE::STRING){stream<<obj.value_str;}
        else if (obj.type==OBJECT_TYPE::ARRAY){
            for(auto const& item:*obj.vec_ptr){
                stream<<item<<" , ";
            }
            stream<<endl;
        }else if (obj.type==OBJECT_TYPE::OBJECT){
            stream<<"{"<<endl;
            for(auto& [key, value]: *obj.map_ptr){
                stream<< key << ":" << value << std::endl;
            }
            stream<<"}"<<endl;
        }
        

        return stream;
    }

}