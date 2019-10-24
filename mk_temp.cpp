#include <stdio.h>
#include <iostream>
#include <fstream>
extern std::ofstream outFile;

char *temp_int() {
    static int max_int=0;
    static char tempname[30];
    max_int++;
    sprintf(tempname, "&tempi%d" ,max_int);
    outFile << "declare " << tempname << ", integer" << std::endl;
    return tempname;
}
char *temp_real() {
    static int max_real=0;
    static char tempname[30];
    max_real++;
    sprintf(tempname, "&tempr%d" ,max_real);
    outFile << "declare " << tempname << ", real" << std::endl;
    return tempname;
}
