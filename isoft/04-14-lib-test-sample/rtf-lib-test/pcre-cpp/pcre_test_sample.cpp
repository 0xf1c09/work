#include <pcre.h>                                                     
#include <stdio.h>
#include <string.h>
#define OVECCOUNT 30

void profile(){
	printf("/*\n");
	printf("* 文本处理库	： 正则表达式-pcre库\n");
	printf("* 过程		： 根据正则表达式进行匹配输入文本\n");
	printf("* 结果		： 正确输出匹配的结果\n");
	printf("* 测试点	： 正则表达式匹配正常\n");
	printf("*\n");
	printf("*/\n");
}

int main(int argc, char ** argv)
{
	const char *pcreVersion = pcre_version();
	printf("Pcre version is: %s\n", pcreVersion);
	profile();
	int ovector[OVECCOUNT];
	if (argc != 3)
	{ 
		fprintf(stderr, "Usage: %s <pattern> <text>\n", argv[0]);
		fprintf(stderr, "%s \"http://(\\w+)\\.bplatform\\.demo/([\\s\\S]*)\" \"http://ftp.bplatform.demo/basedeb/pool/main/\"\n", argv[0]);
		return 1;
	}
	const char * pPattern = argv[1];
	const char * pText = argv[2];
	const char * pErrMsg = NULL;
	pcre * pPcre = NULL;
	int nOffset = -1;

	if (NULL == (pPcre = pcre_compile(pPattern, 0, &pErrMsg, &nOffset, NULL)))
	{
		printf("ErrMsg=%s, Offset=%d\n", pErrMsg, nOffset);
		return 1;
	}
	else
	{
		int rc;
		rc = pcre_exec(pPcre, NULL, pText, strlen(pText), 0, 0, ovector, OVECCOUNT);
		if ( rc < 0)
		{
			printf("%s doesn't match %s\n", pText, pPattern);
		}
		else
		{
			for(int i = 0; i < rc; ++i) {
				printf("%s: ",i==0?"原字符串":i==1?"匹配结果1":"匹配结果2");
				const char *str = pText + ovector[2*i];
				int str_len = ovector[2*i+1] - ovector[2*i];
				printf("%.*s\n", str_len, str);
			}
			printf("%s matches %s\n", pText, pPattern);
		}
		printf("Rc : %d\n", rc);
	}
}
