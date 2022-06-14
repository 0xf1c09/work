#include <stdio.h>
#include <cJSON.h>

void profile(){
	printf("/*\n");
	printf("* 文本处理库	: cjson库\n");
	printf("* 过程		： 会将字符串封装JSON结构，并保存到文件cjson_test_json.json中\n");
	printf("* 结果		： 生成一个json文件\n");
	printf("* 测试点	： 字符串封装JSON结构、JSON文件保存\n");
	printf("*\n");
	printf("*/\n");
}

int main(void)
{
	profile();

	cJSON* cjson_test = NULL;
	cJSON* cjson_sonItem = NULL;
	cJSON* cjson_list = NULL;
	char* str = NULL;

	cjson_test = cJSON_CreateObject();

	cJSON_AddStringToObject(cjson_test, "name", "testCJSON");

	cJSON_AddStringToObject(cjson_test, "case", "cJSON_CreateObject()");

	cJSON_AddNumberToObject(cjson_test, "number", 1);

	cjson_sonItem = cJSON_CreateObject();
	cJSON_AddStringToObject(cjson_sonItem, "name", "testSonItest");
	cJSON_AddStringToObject(cjson_sonItem, "case", "cJSON_AddItemToObject()");
	cJSON_AddItemToObject(cjson_test, "sonItem", cjson_sonItem);

	cjson_list = cJSON_CreateArray();
	cJSON_AddItemToArray(cjson_list, cJSON_CreateString( "name" ));
	cJSON_AddItemToArray(cjson_list, cJSON_CreateString( "testJsonList" ));
	cJSON_AddItemToArray(cjson_list, cJSON_CreateString( "cJSON_AddItemToArray()" ));
	cJSON_AddItemToObject(cjson_test, "list", cjson_list);

	cJSON_AddFalseToObject(cjson_test, "boolean");

	str = cJSON_Print(cjson_test);
	printf("%s\n", str);
	FILE *fp = fopen("cjson_test.json", "w");
	fwrite(str, strlen(str), 1, fp);

	fclose(fp);
	free(str);
	cJSON_Delete(cjson_test);

	return 0;
}


