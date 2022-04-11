#include <stdio.h>
#include <cJSON.h>

int main(void)
{
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

    return 0;
}


