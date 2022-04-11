#include <iostream>
#include <string>
#include <json/json.h>

using namespace std;
int main()
{
	Json::Value root; 
	Json::Value arrayObj;
	Json::Value item; 

	root["key"] = "value1"; 
	for (int i=0; i<10; i++)
	{ 
		item["arraykey"] = i; 
		arrayObj.append(item);
	} 
	root["array"] = arrayObj; 
	std::string out = root.toStyledString();
	std::cout << out << std::endl;
	return 0;
}
