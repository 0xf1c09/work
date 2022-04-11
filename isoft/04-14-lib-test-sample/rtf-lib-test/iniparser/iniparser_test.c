#include <stdio.h>
#include <iniparser/iniparser.h>
#include "dictionary.h"


#define PATH "./config.ini"
#define PATH_DST "./config_dst.ini"

int main (int argc, char **argv)
{
    FILE  *fp = NULL  ;
    dictionary *ini= NULL;

    ini = iniparser_load(PATH);

    if( ini ==NULL)
    {
        printf("inipar  failure\n");
        return -1;
    }

    //设置ipaddrpool
    iniparser_set(ini, "ipaddrpool:start", "192.168.10.0");
    iniparser_set(ini, "ipaddrpool:end", "192.168.10.100");
    iniparser_set(ini, "ipaddrpool:flag", "true");
    iniparser_unset(ini, "opt:dns2");

    printf("%s\n", iniparser_getstring(ini, "ipaddrpool:start", "null"));
    printf("%s\n", iniparser_getstring(ini, "ipaddrpool:end", "null"));
    printf("%s\n", iniparser_getstring(ini, "filepath:leasefile", "null"));
    printf("%s\n", iniparser_getstring(ini, "network:interface", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:dns1", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:dns2", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:subnet", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:router", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:domain", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:lease", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:t1", "null"));
    printf("%s\n", iniparser_getstring(ini, "opt:t2", "null"));


    fp = fopen(PATH_DST, "w");
    if( fp == NULL ) {
        printf("stone:fopen error!\n");
        exit(-1);
    }

    iniparser_dumpsection_ini(ini, "ipaddrpool", fp);
    iniparser_dumpsection_ini(ini, "filepath", fp);
    iniparser_dumpsection_ini(ini, "network", fp);
    iniparser_dumpsection_ini(ini, "opt", fp);
    fclose(fp);

    iniparser_freedict(ini);



    return 0;
}
