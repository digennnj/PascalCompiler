#include "symbol_table.h"
extern void error(std::string);
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
