 
#include "../headers/object.h"

namespace Ctriplus
{   
    object object::operator()(object argument){return func(argument); };    

    string object::toString(string padding){
        string ret=padding;

        if (obj.type==OBJECT_TYPE::CHAR) {ret=to_string(obj.value_char);}
        else if (obj.type==OBJECT_TYPE::INT){ret=to_string(obj.value_int);}
        else if (obj.type==OBJECT_TYPE::LONG_LONG){ret=to_string(obj.value_ll);}
        else if (obj.type==OBJECT_TYPE::DOUBLE){ret=to_string(obj.value_double);}
        else if (obj.type==OBJECT_TYPE::LONG_DOUBLE){ret=to_string(obj.value_long_double);}
        else if (obj.type==OBJECT_TYPE::STRING){ret=(obj.value_str);}
        else if (obj.type==OBJECT_TYPE::ARRAY){
            for(auto const& item:*obj.vec_ptr){
                ret+= item.toString(padding+"\t")+",";
            }
            ret+="\n";
        }else if (obj.type==OBJECT_TYPE::OBJECT){
            ret+="{\n";
            for(auto& [key, value]: *obj.map_ptr){
                ret+="\t"+ key + ":" + value.toString(padding+"\t")+"\n";
            }
            
            ret"}\n";
        }

        return ret;
    }

    std::ostream& operator<<(std::ostream& stream, const object& obj)
    {
        stream<<obj.toString2();
        return stream;
    }


}