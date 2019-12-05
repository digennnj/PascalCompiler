#include "pascal.h"
void read_id (char id_name[])
{
    Variable *var = lookup(id_name);
    if (var==NULL) {
            error("SYMBOL NOT DEFINED: "+std::string(id_name));
    }
    else {outFile << "read " << id_name << ", " << type_str(var->type) << std::endl;}
}
