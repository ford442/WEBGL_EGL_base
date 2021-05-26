
#include <emscripten.h>
#include "func.h"

void printjs(std::string& str)
{
    char timeBuffer[80];
        struct tm *timeinfo;

        char dest[99999];
        sprintf(dest, " %s\n",  str.c_str());
        EM_ASM({
            console.log(Module.UTF8ToString($0))
        }, dest);
}

void printjs(const char* str)
{
     char timeBuffer[80];
        struct tm *timeinfo;

        char dest[99999];
        sprintf(dest, " %s\n",  str);
        EM_ASM({
            console.log(Module.UTF8ToString($0))
        }, dest);
}

void printjs(int entier)
{
     char timeBuffer[80];
        struct tm *timeinfo;

        char dest[99999];
        sprintf(dest, " int: %d\n",  entier);
        EM_ASM({
            console.log(Module.UTF8ToString($0))
        }, dest);
}