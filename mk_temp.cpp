#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
extern std::ofstream outFile;
extern void decl_id(char[], std::string);

char *temp_int() {
    static int max_int=0;
    static char tempname[30];
    max_int++;
    sprintf(tempname, "&tempi%d" ,max_int);
    decl_id(tempname, "INTEGER");
    //outFile << "declare " << tempname << ", integer" << std::endl;
    return strdup(tempname);
}
char *temp_real() {
    static int max_real=0;
    static char tempname[30];
    max_real++;
    sprintf(tempname, "&tempr%d" ,max_real);
    decl_id(tempname, "REAL");
    //outFile << "declare " << tempname << ", real" << std::endl;
    return strdup(tempname);
}
