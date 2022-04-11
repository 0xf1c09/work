#include <string>
#include <json/json.h>
#include <iostream>
#include <fstream>

using namespace std;

void writeFileJson()
{
	Json::Value root;
	
	root["name"] = Json::Value("Mike Jiang");
	root["age"] = Json::Value(23);
	root["sex_is_male"] = Json::Value(true);
	
	Json::Value partner;
	
	partner["partner_name"] = Json::Value("Galatea");
	partner["partner_age"] = Json::Value(21);
	partner["partner_sex_is_male"] = Json::Value(false);
	
	root["partner"] = Json::Value(partner);
	
	root["achievement"].append("ach1");
	root["achievement"].append("ach2");
	root["achievement"].append("ach3");

	cout << "toStyledString():" << endl;
	cout << root.toStyledString() << endl;

	cout << "FastWriter:" << endl;
	Json::FastWriter fw;
	cout << fw.write(root) << endl << endl;
	
	cout << "StyledWriter:" << endl;
	Json::StyledWriter sw;
	cout << sw.write(root) << endl << endl;
	
	ofstream os;
	os.open("./libcfg/jsoncpp/NewJsonData.json");
	os << sw.write(root);
	os.close();
}
 
int main(int argc, char *argv[]) 
{
	writeFileJson();
	return 0;
}
