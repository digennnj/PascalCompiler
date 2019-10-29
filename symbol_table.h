#pragma once
#include <string>
#include <map>
enum Type {INT, REAL, CHAR, BOOL, STR};
typedef struct Variable {
    Type type;
} Variable;
std::string type_str(Type typ);
