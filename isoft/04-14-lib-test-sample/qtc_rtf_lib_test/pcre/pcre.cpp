#include <stdio.h>
#include <string.h>
#include <pcre.h>

int pcre_test() {
    const char *pcreVersion = pcre_version();
    printf("Pcre version is: %s\n", pcreVersion);
    const char *err;
    int erroffset;
    const char *s = "<title>Hello World</title>";
    const char *p = "<title>(.*)</title>";
    int infosize;
    int ovector[30]= {0};
    pcre *re = pcre_compile(p, 0, &err, &erroffset, NULL);
    if (re == NULL) {
        printf("compile err: %s %d\n", err, erroffset);
        return 1;
    }
    int n = pcre_fullinfo(re, NULL, PCRE_INFO_SIZE, &infosize);
    if (n < 0) {
        printf("fullinfo err: %d\n", n);
        pcre_free(re);
        return 1;
    }
    printf("fullinfo res: %d\n", infosize);

    int rc = pcre_exec(re, NULL, s, strlen(s), 0, 0, ovector, 30);
    if (rc < 0) {
        pcre_free(re);
        printf("pcre_exec %d\n", rc);
        return 1;
    }
    for (int i=0; i<rc; i++) {
        const char *substring_start = s + ovector[2*i];
        int substring_length = ovector[2*i+1] - ovector[2*i];
        printf("$%2d: %.*s\n", i, substring_length, substring_start);
    }
    return 0;
}
