#include "pascal.h"
void decl_temp(const char identifier[], Type type) {
    if (lookup(identifier)!=NULL) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
        }
        else {
            symbolTable[identifier] = {type, 0, type};
            //outFile << "declare " << identifier << ", " << type_str(type) << std::endl;
            *cur_out() += "declare " + std::string(identifier) + ", " + std::string(type_str(type)) + "\n";
        }
}
void decl_id(const char identifier[], Type type) {
    identifier = strdup(scope_concat(cur_scope(), identifier).c_str());
    if (lookup(identifier)!=NULL) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
        }
        else {
            symbolTable[identifier] = {type, 0, type};
            //outFile << "declare " << identifier << ", " << type_str(type) << std::endl;
            *cur_out() += "declare " + std::string(identifier) + ", " + std::string(type_str(type)) + "\n";
        }
}


void decl_array(char identifier[], Type type, int length) {
    identifier = strdup(scope_concat(cur_scope(), identifier).c_str());
    if (length<=0) {error("ARRAY LENGTH MUST BE POSITIVE");}
    for (int i=0; i<length; i++) {
        std::string elemName = std::string(identifier)+"&"+std::to_string(i);
        decl_id(elemName.c_str(), type);
    }
}

void decl_function(char identifier[], Type type) {
    std::string returnVar = "&#"+std::string(identifier);
    identifier = strdup(scope_concat(cur_scope(), identifier).c_str());
    //outFile << ":" << "#" << identifier << std::endl; // # means function?
    *cur_out() += std::string(":") + "#" + std::string(identifier) + "\n"; 
    if (lookup(identifier)!=NULL) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
    }
    symbolTable[identifier] = {FUNC, 0, type};
    decl_id(strdup(returnVar.c_str()), type);
}
void decl_procedure(char identifier[]) {
    identifier = strdup(scope_concat(cur_scope(), identifier).c_str());
    //outFile << ":" << "#" << identifier << std::endl; // # means function?
    *cur_out() += std::string(":") + "#" + std::string(identifier) + "\n"; 
    if (lookup(identifier)!=NULL) {
            error("SYMBOL ALREADY DEFINED: "+std::string(identifier));
    }
    symbolTable[identifier] = {FUNC, 0, FUNC};
}
