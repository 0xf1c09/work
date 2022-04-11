#include <iostream>
#include <cstdio>
#include <json/json.h>

using namespace std;

int main()
{
	std::string strValue = "{\"key\":\"value1\",\
				\"array\":[{\"arraykey\":1},{\"arraykey\":2}]}"; 

	Json::Reader reader; 
	Json::Value root; 

	if (reader.parse(strValue, root))   
	{ 
		if (!root["key"].isNull())
		{
			std::string strValue= root["key"].asString(); 
			std::cout << strValue<< std::endl; 
		}
		Json::Value arrayObj = root["array"]; 
		for (int i=0; i<arrayObj.size(); i++) 
		{ 
			int iarrayValue = arrayObj[i]["arraykey"].asInt(); 
			std::cout << iarrayValue << std::endl;  
		} 
	}
	return 0;
}
