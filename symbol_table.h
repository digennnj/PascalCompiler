#include <string>
enum Type {INT, REAL, CHAR, BOOL, STR, ARRAY, FUNC};
typedef struct Variable {
    Type type;
    int length;
    Type sub_type;
} Variable;
std::string type_str(Type typ);
Variable *lookup(const char identifier[]);
extern std::map<std::string,Variable> symbolTable;
