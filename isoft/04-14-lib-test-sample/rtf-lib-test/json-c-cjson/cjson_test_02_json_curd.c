#include <stdio.h>
#include <cJSON.h>

void profile(){
	printf("/*\n");
	printf("* 文本处理库	:  cjson库\n");
	printf("* 过程		： 读取cjson_test_json.json文件内容，解析后进行增删改操作\n");
	printf("* 结果		： 输出json文件解析以及处理后的结果\n");
	printf("* 测试点	： JSON文件读取及解析、json内容增删改\n");
	printf("*\n");
	printf("*/\n");
}

cJSON * readJson(){

	FILE *fp = fopen("cjson_test.json", "r");
	if(fp == NULL)
	{
		printf("cannot open json file.\n");
		return 0;
	} 
	int fileSize;
	fseek(fp, 0, SEEK_END);
	fileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *buf = (char *)malloc(fileSize * sizeof(char));
	memset(buf, 0, fileSize);
	int ret = fread(buf, fileSize, sizeof(char), fp);
	if(ret == -1)
	{
		fclose(fp);
		return 0;
	}
	fclose(fp);
	return cJSON_Parse(buf);
}

void analysisJsonObj(cJSON *json) {
	printf("---------------json文件解析结果--------------------\n");

	cJSON* cjson_test = NULL;
	cJSON* cjson_name = NULL;
	cJSON* cjson_case = NULL;
	cJSON* cjson_number = NULL;
	cJSON* cjson_sonItem = NULL;
	cJSON* cjson_sonItem_case = NULL;
	cJSON* cjson_sonItem_name = NULL;
	cJSON* cjson_list = NULL;
	cJSON* cjson_boolean = NULL;
	int    list_array_size = 0, i = 0;
	cJSON* cjson_list_item = NULL;

	cjson_test = json;
	if(cjson_test == NULL)
	{
		printf("parse fail.\n");
		return -1;
	}

	cjson_name = cJSON_GetObjectItem(cjson_test, "name");
	cjson_case = cJSON_GetObjectItem(cjson_test, "case");
	cjson_number = cJSON_GetObjectItem(cjson_test, "number");

	printf("name: %s\n", cjson_name->valuestring);
	printf("case:%s\n", cjson_case->valuestring);
	printf("number:%.1f\n", cjson_number->valuedouble);

	cjson_sonItem = cJSON_GetObjectItem(cjson_test, "sonItem");
	cjson_sonItem_name = cJSON_GetObjectItem(cjson_sonItem, "name");
	cjson_sonItem_case = cJSON_GetObjectItem(cjson_sonItem, "case");
	printf("sonItem-name:%s\nsonItem-case:%s\n", cjson_sonItem_name->valuestring, cjson_sonItem_case->valuestring);

	cjson_list = cJSON_GetObjectItem(cjson_test, "list");
	list_array_size = cJSON_GetArraySize(cjson_list);
	printf("list:[");
	for(i = 0; i < list_array_size; i++)
	{
		cjson_list_item = cJSON_GetArrayItem(cjson_list, i);
		printf("%s,", cjson_list_item->valuestring);
	}
	printf("\b]\n");

	cjson_boolean = cJSON_GetObjectItem(cjson_test, "boolean");
	if(cjson_boolean->valueint == 0)
	{
		printf("boolean: false\n");
	}
	else
	{
		printf("boolean:error\n");
	}

}


cJSON * addDataToJson(cJSON *json){
	printf("---------------新增hobby结果--------------------\n");
	if (NULL == json) {
		return;
	}

	cJSON *hobby=cJSON_CreateArray();
	cJSON_AddItemToArray(hobby, cJSON_CreateString("Basketball"));
	cJSON_AddItemToArray(hobby, cJSON_CreateString("Football"));
	cJSON_AddItemToArray(hobby, cJSON_CreateString("badminton"));

	cJSON_AddItemToObject(json, "hobby", hobby);
	printf("%s\n", cJSON_Print(json));
	return json;
}

cJSON * updateDataToJson(cJSON *json){
	printf("---------------更新hobby结果--------------------\n");

	if (NULL == json) {
		return;
	}

	cJSON *hobby=cJSON_CreateArray();
	cJSON_AddItemToArray(hobby, cJSON_CreateString("Skating"));
	cJSON_AddItemToArray(hobby, cJSON_CreateString("dance"));

	/*
	   CJSON_PUBLIC(void) cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newitem);
	   CJSON_PUBLIC(void) cJSON_ReplaceItemInObject(cJSON *object,const char *string,cJSON *newitem);
	 */
	cJSON_ReplaceItemInObject(json, "hobby", hobby);
	printf("%s\n", cJSON_Print(json));
	return json;
}

void deleteDataToJson(cJSON *json){
	printf("---------------删除hobby结果--------------------\n");

	if (NULL == json) {
		return;
	}

	cJSON_DetachItemFromObject(json, "hobby");
	printf("%s\n", cJSON_Print(json));
}

int main(void)
{
	profile();

	cJSON *json_root = readJson();

	analysisJsonObj(json_root);

	json_root = addDataToJson(json_root);

	json_root = updateDataToJson(json_root);

	deleteDataToJson(json_root);

	return 0;
}

