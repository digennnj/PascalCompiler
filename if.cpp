#include "pascal.h"
char *gen_if(char *varName) {
    varName = full_name(varName);
    Variable *var = lookup(varName);
    if (var==NULL) {error("SYMBOL NOT DEFINED: "+std::string(varName));}
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
char *gen_else(char *elseLbl) {
	char *endIfLbl = temp_label();
	//outFile << "jmp " << endIfLbl << std::endl;
	*cur_out() += std::string("jmp ") + std::string(endIfLbl) + "\n";
	//outFile << ":" << elseLbl << std::endl;
	*cur_out() += std::string(":") + std::string(elseLbl) + "\n";
	return endIfLbl;
}
void gen_endif(char *endIfLbl) {
	//outFile << ":" << endIfLbl << std::endl;
	*cur_out() += std::string(":") + std::string(endIfLbl) + "\n";
}
