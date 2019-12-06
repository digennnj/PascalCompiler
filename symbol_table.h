#pragma once
#include <string>
#include <map>
enum Type {INT, REAL, CHAR, BOOL, STR, ARRAY, FUNC};
typedef struct Variable {
    Type type;
    int length;
    Type sub_type;
} Variable;
std::string type_str(Type typ);
