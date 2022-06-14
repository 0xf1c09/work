#include <iostream>
#include <fstream>
#include <json/json.h>

using namespace std;
using namespace Json;

void profile(){
	printf("/*\n");
	printf("* 文本处理库	:  jsoncpp库\n");
	printf("* 过程		： 读取jsoncpp.json文件内容，解析后进行增删改操作\n");
	printf("* 结果		： 输出json文件解析以及处理后的结果\n");
	printf("* 测试点	： JSON文件读取及解析、json内容增删改\n");
	printf("*\n");
	printf("*/\n");
}

Value analysisJson(){
	printf("---------------json文件解析结果--------------------\n");
	ifstream ifs("jsoncpp.json");
	//解析json value
	Reader reader;
	Value root;
	if(reader.parse(ifs,root))
	{
		vector<string> list_strMembers;
		if(!root.isNull() && root.isObject())
			list_strMembers = root.getMemberNames();
		for(auto str:list_strMembers)
		{
			if(!root.isMember(str))
				continue;
			cout<<str<<": ";
			if(!root[str].isNull())
			{
				if(root[str].isInt())
				{
					int tempInt = root[str].asInt();
					cout<<tempInt<<endl;
				}
				else if(root[str].isBool())
				{
					bool tempBool = root[str].asBool();
					cout<<tempBool<<endl;
				}
				else if(root[str].isString())
				{  
					string tempString = root[str].asString();
					cout<<tempString<<endl;
				}
				else if(root[str].isObject())
				{  
					Value tempValue = root[str];
					cout<<tempValue<<endl;
				}
				else if(root[str].isArray())
				{  
					Value tempMember = root[str];
					cout<<"[";
					for(int j = 0;j < tempMember.size();j++)
					{
						if(j!=0) cout<<", ";
						Value tempValue = tempMember[j];
						cout<<"{id: "<<tempValue["id"]<<", "<<"name: "<<tempValue["name"]<<"}";    
					}
					cout<<"]"<<endl;
				}
				else if(root[str].isNumeric() && !root[str].isBool())
				{
					double tempDouble = root[str].asDouble();
					cout<<tempDouble<<endl;
				}
			}
		}
	}
	return root;
}

Value addDataToJson(Value json){
	printf("---------------新增hobby结果--------------------\n");
	Value array_root;
	array_root.append("Basketball");
	array_root.append("Football");
	array_root.append("badminton");
	json["hobby"] = array_root;

	cout<<json.toStyledString()<<endl;
	return json;
}

Value updateDataToJson(Value json){
	printf("---------------更新hobby结果--------------------\n");
	Value array_root;
	array_root.append("Skating");
	array_root.append("Dance");
	json["hobby"] = array_root;

	cout<<json.toStyledString()<<endl;
	return json;
}

void deleteDataToJson(Value json){
	printf("---------------删除hobby结果--------------------\n");
	json.removeMember("hobby");

	cout<<json.toStyledString()<<endl;
}

int main(int argc,char *argv[])
{
	profile();

	Value json_root = analysisJson();

	json_root = addDataToJson(json_root);

	json_root = updateDataToJson(json_root);

	deleteDataToJson(json_root);

	return 0;  
}
