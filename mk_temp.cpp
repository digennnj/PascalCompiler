#include "pascal.h"
char *temp_int() {
    static int max_int=0;
    static char tempname[30];
    max_int++;
    sprintf(tempname, "&tempi%d" ,max_int);
    decl_temp(tempname, INT);
    return strdup(tempname);
}
char *temp_real() {
    static int max_real=0;
    static char tempname[30];
    max_real++;
    sprintf(tempname, "&tempr%d" ,max_real);
    decl_temp(tempname, REAL);
    return strdup(tempname);
}
char *temp_char() {
    static int max_char=0;
    static char tempname[30];
    max_char++;
    sprintf(tempname, "&tempc%d" ,max_char);
    decl_temp(tempname, CHAR);
    return strdup(tempname);
}
char *temp_bool() {
    static int max_bool=0;
    static char tempname[30];
    max_bool++;
    sprintf(tempname, "&tempb%d" ,max_bool);
    decl_temp(tempname, BOOL);
    return strdup(tempname);
}
char *temp_str() {
    static int max_str=0;
    static char tempname[30];
    max_str++;
    sprintf(tempname, "&temps%d" ,max_str);
    decl_temp(tempname, STR);
    return strdup(tempname);
}
char *temp_label() {
    static int max_lbl=0;
    static char tempname[30];
    max_lbl++;
    sprintf(tempname, "&label%d" ,max_lbl);
    return strdup(tempname);
}
