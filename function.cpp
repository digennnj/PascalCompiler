#include <fstream>
#include "symbol_table.h"
extern char *temp_label();
extern std::ofstream outFile;
extern void decl_function(char*, Type);
extern void decl_procedure(char*);

char *gen_function(char identifier[], Type type) {
    char *endLbl = temp_label();
    outFile << "jmp " << endLbl << std::endl;
    outFile << ":" << "#" << identifier << std::endl; // # means function?
    decl_function(identifier, type);
    return endLbl;
}
char *gen_procedure(char identifier[]) {
    char *endLbl = temp_label();
    outFile << "jmp " << endLbl << std::endl;
    outFile << ":" << "#" << identifier << std::endl; // # means function?
    decl_procedure(identifier);
    return endLbl;
}
void end_function(char *endLbl) {
    outFile << "return" << std::endl;
    outFile << ":" << endLbl << std::endl;
}
void end_procedure(char *endLbl) {
    outFile << "return" << std::endl;
    outFile << ":" << endLbl << std::endl;
}
