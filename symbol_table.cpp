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
std::map<std::string,Variable> symbolTable = std::map<std::string,Variable>();
