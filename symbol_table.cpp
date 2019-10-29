#include "symbol_table.h"
std::string type_str(Type typ) {
    switch(typ) {
        case INT: return "integer"; break;
        case REAL: return "real"; break;
        case CHAR: return "character"; break;
        case BOOL: return "boolean"; break;
    }
}
