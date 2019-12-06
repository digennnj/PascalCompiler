#include <string>
#include <list>
enum Type {INT, REAL, CHAR, BOOL, STR, ARRAY, FUNC};
typedef struct Variable {
    Type type;
    int length;
    Type sub_type;
} Variable;
std::string type_str(Type typ);
Variable *lookup(const char identifier[]);
extern std::map<std::string,Variable> symbolTable;
extern std::list<std::string> scopeNames;
char *full_name(const char *identifier);
std::string scope_concat(std::string head, std::string tail);
std::string cur_scope();
std::string name_for_scope(int lvl);
