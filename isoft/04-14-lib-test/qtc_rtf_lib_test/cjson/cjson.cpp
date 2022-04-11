#include <stdio.h>
#include <cJSON.h>

char *message =
"{                                               \
    \"name\":	\"testCJSON\",                   \
    \"case\":	\"cJSON_CreateObject()\",        \
    \"number\":	1.0,                             \
    \"sonItem\":	{                                \
        \"name\":	\"testSonItest\",            \
        \"case\":	\"cJSON_AddItemToObject()\"  \
    },                                            \
    \"list\":	[\"name\", \"testJsonList\", \"cJSON_AddItemToArray()\"],\
    \"boolean\":	false\
}";


int cjson_test_01_json_package()
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

int cjson_test_02_json_analysis()
{
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

    cjson_test = cJSON_Parse(message);
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

    return 0;
}


