#include "pascal.h"
char *gen_begin_loop() {
    char *begin_label = temp_label();
    //outFile << ":" << begin_label << std::endl;
    *cur_out() += std::string(":") + std::string(begin_label) + "\n";
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
        //outFile << "jf " << varName << ", " << tempLabel << std::endl;;
        *cur_out() += std::string("jf ") + std::string(varName) + ", " + std::string(tempLabel) + "\n";;
        return tempLabel;
    }
    else {
        error("Expression must evaluate to boolean");
    }
}

char *gen_while_end(char *startLabel, char *endLabel) {
    //outFile << "jmp " << startLabel << std::endl;
    *cur_out() += std::string("jmp ") + std::string(startLabel) + "\n";
	//outFile << ":" << endLabel << std::endl;
	*cur_out() += std::string(":") + std::string(endLabel) + "\n";
}

void gen_repeat(char *varName, char *startLabel) {
    varName = full_name(varName);
    Variable *var = lookup(varName);
    if (var==NULL) {
            error("SYMBOL NOT DEFINED: "+std::string(varName));
    }
    if(var->type == BOOL) {
        //outFile << "jf " << varName << ", " << startLabel << std::endl;
        *cur_out() += std::string("jf ") + std::string(varName) + ", " + std::string(startLabel) + "\n";
    } else {
        error("Expression must evaluate to boolean");
    }
}
