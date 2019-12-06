#include "pascal.h"
char *gen_function(char identifier[], Type type) {
    char *endLbl = temp_label();
    functionsInProgress.push_front(new std::string);
    //outFile << "jmp " << endLbl << std::endl;
    decl_function(identifier, type);
    scopeNames.push_front(std::string(identifier));
    return endLbl;
}
char *gen_procedure(char identifier[]) {
    char *endLbl = temp_label();
    //outFile << "jmp " << endLbl << std::endl;
    functionsInProgress.push_front(new std::string);
    decl_procedure(identifier);
    scopeNames.push_front(std::string(identifier));
    return endLbl;
}
void end_function(char *endLbl) {
    //outFile << "return" << std::endl;
    *cur_out() += std::string("return") + "\n";
    //outFile << ":" << endLbl << std::endl;
    scopeNames.pop_front();
    completedFunctions.push_back(functionsInProgress.front());
    functionsInProgress.pop_front();
}
void end_procedure(char *endLbl) {
    //outFile << "return" << std::endl;
    *cur_out() += std::string("return") + "\n";
    //outFile << ":" << endLbl << std::endl;
    scopeNames.pop_front();
    completedFunctions.push_back(functionsInProgress.front());
    functionsInProgress.pop_front();
}

char *call_function(char identifier[]) {
    char *returnVar = strdup(std::string("&#"+std::string(identifier)).c_str());
    returnVar = full_name(returnVar);
    identifier = full_name(identifier);
    Variable *func = lookup(identifier);
    if (func==NULL) {
            error("FUNCTION NOT DEFINED: "+std::string(identifier));
    }
    else if (func->type != FUNC || func->sub_type == FUNC) {
        error("NOT A FUNCTION: "+std::string(identifier));
    }
    //outFile << "call " << "#" << identifier << std::endl;
    *cur_out() += std::string("call ") + "#" + std::string(identifier) + "\n";
    return strdup(returnVar);
}

void call_procedure(char identifier[]) {
    identifier = full_name(identifier);
    Variable *proc = lookup(identifier);
    if (proc==NULL) {
            error("FUNCTION NOT DEFINED: "+std::string(identifier));
    }
    else if (proc->type != FUNC || proc->sub_type != FUNC) {
        error("NOT A PROCEDURE: "+std::string(identifier));
    }
    //outFile << "call " << "#" << identifier << std::endl;
    *cur_out() += std::string("call ") + "#" + std::string(identifier) + "\n";
}
