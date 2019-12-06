#include "pascal.h"
std::string type_str(Type typ) {
    switch(typ) {
        case INT: return "integer"; break;
        case REAL: return "real"; break;
        case CHAR: return "character"; break;
        case BOOL: return "boolean"; break;
        case STR: return "string"; break;
        case ARRAY: return "array"; break;
        case FUNC: return "function"; break;
        default: error("invalid type: "+std::to_string(typ)); break;
    }
}
Variable *lookup(const char identifier[]) {
    if (symbolTable.find(identifier)==symbolTable.end()) {
        return NULL;
    }
    else {
        return &symbolTable[identifier];
    }
}
char *full_name(const char *identifier) {
    //std::cout << "full_name" << std::endl;
    for (int i=scopeNames.size(); i>0; i--) {
        char *res = strdup(scope_concat(name_for_scope(i), identifier).c_str());
        //std::cout << res << std::endl;
        if (lookup(res)!=NULL) {return res;}
    }
    printSymbolTable();
    error("symbol not defined: "+std::string(identifier));
}
std::string scope_concat(std::string head, std::string tail) {
    if (head.empty()) {return std::string(tail);}
    if (tail.empty()) {return std::string(head);}
    return head+"."+tail;
}
std::string cur_scope() {
    return name_for_scope(scopeNames.size());
}
std::string name_for_scope(int lvl) {
    int i=0;
    std::string res = "";
    for (auto it = scopeNames.rbegin(); it!=scopeNames.rend() && i<lvl; it++, i++) {
        std::string name = *it;
        res = scope_concat(res, name);
    }
    return res;
}
std::map<std::string,Variable> symbolTable = std::map<std::string,Variable>();
std::list<std::string> scopeNames = {""};
