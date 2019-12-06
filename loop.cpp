#include "pascal.h"
char *gen_begin_loop() {
    char *begin_label = temp_label();
    outFile << ":" << begin_label << std::endl;
    return begin_label;
}

char *gen_while_loop(char *varName) {
    varName = full_name(varName);
    Variable *var = lookup(varName);
    if (var==NULL) {
            error("SYMBOL NOT DEFINED: "+std::string(varName));
    }
    if(var->type == BOOL) {
        char *tempLabel = temp_label();
        outFile << "jf " << varName << ", " << tempLabel << std::endl;;
        return tempLabel;
    }
    else {
        error("Expression must evaluate to boolean");
    }
}

char *gen_while_end(char *startLabel, char *endLabel) {
    outFile << "jmp " << startLabel << std::endl;
	outFile << ":" << endLabel << std::endl;
}

void gen_repeat(char *varName, char *startLabel) {
    varName = full_name(varName);
    Variable *var = lookup(varName);
    if (var==NULL) {
            error("SYMBOL NOT DEFINED: "+std::string(varName));
    }
    if(var->type == BOOL) {
        outFile << "jf " << varName << ", " << startLabel << std::endl;
    } else {
        error("Expression must evaluate to boolean");
    }
}
