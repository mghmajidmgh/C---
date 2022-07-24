 
#include "../headers/object.h"

namespace Ctriplus
{   
    object object::operator()(object argument){return func(argument); };    

    string object::toString(const string padding="")const{
        string ret=padding;
        string tpad="  ";

        if (type==OBJECT_TYPE::CHAR) {ret=to_string(value_char);}
        else if (type==OBJECT_TYPE::INT){ret=to_string(value_int);}
        else if (type==OBJECT_TYPE::LONG_LONG){ret=to_string(value_ll);}
        else if (type==OBJECT_TYPE::DOUBLE){ret=to_string(value_double);}
        else if (type==OBJECT_TYPE::LONG_DOUBLE){ret=to_string(value_long_double);}
        else if (type==OBJECT_TYPE::STRING){ret=(value_str);}
        else if (type==OBJECT_TYPE::ARRAY){
            bool isfirst=true;
            ret+="[";
            for(object const& item:*vec_ptr){
                if(isfirst){isfirst=false;}else{ret+=",";}
                ret+= item.toString();
            }
            ret+="]";
        }else if (type==OBJECT_TYPE::OBJECT){
             bool isfirst=true;
            ret+="\n"+padding+"{\n";
            for(auto& [key, value]: *map_ptr){
                if(isfirst){isfirst=false;}else{ret+=",\n";}
                ret+=padding+tpad+ key + ":" + value.toString(padding+tpad);
            }            
            ret+="\n"+padding+"}";
        }

        return ret;
    }

    std::ostream& operator<<(std::ostream& stream, const object& obj)
    {
        stream<<obj.toString("");
        return stream;
    }


}