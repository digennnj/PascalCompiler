#include <fstream>
#include <string.h>
#include "symbol_table.h"
extern char *temp_label();
extern std::ofstream outFile;
extern void decl_function(char*, Type);
extern void decl_procedure(char*);
extern void error(const char []);
extern void error(std::string);
extern Variable *lookup(const char[]);

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

char *call_function(char identifier[]) {
    Variable *func = lookup(identifier);
    if (func==NULL) {
            error("FUNCTION NOT DEFINED: "+std::string(identifier));
    }
    else if (func->type != FUNC || func->sub_type == FUNC) {
        error("NOT A FUNCTION: "+std::string(identifier));
    }
    outFile << "call " << "#" << identifier << std::endl;
    std::string returnVar = "&#"+std::string(identifier);
    return strdup(returnVar.c_str());
}

void call_procedure(char identifier[]) {
    Variable *proc = lookup(identifier);
    if (proc==NULL) {
            error("FUNCTION NOT DEFINED: "+std::string(identifier));
    }
    else if (proc->type != FUNC || proc->sub_type != FUNC) {
        error("NOT A PROCEDURE: "+std::string(identifier));
    }
    outFile << "call " << "#" << identifier << std::endl;
}
