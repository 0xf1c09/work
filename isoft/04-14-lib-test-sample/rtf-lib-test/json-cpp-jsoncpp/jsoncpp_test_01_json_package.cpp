#include <iostream>
#include <fstream>
#include <json/json.h>

using namespace std;
using namespace Json;

void profile(){
	printf("/*\n");
	printf("* 文本处理库	： jsoncpp库\n");
	printf("* 过程		： 会将数据封装为JSON结构，并保存到文件jsoncpp.json中\n");
	printf("* 结果		： 生成一个json文件\n");
	printf("* 测试点	： 将数据构建封装JSON结构、JSON文件保存\n");
	printf("*\n");
	printf("*/\n");
}


int main(int argc,char *argv[])
{

	profile();
	//构建json对象
	Value family;
	Value members;
	family["family_id"] = 1314;
	family["single_parent"] = false;
	family["age"] = 20;
	family["money"] = 13.14;
	for(int i = 0 ;i < 4; ++i)
	{
		Value member;
		member["id"] = i + 1;
		member["name"] = "name";
		members.append(member);
	}
	family["members"] = members;

	//打印json value
	string strJson = family.toStyledString();
	cout<<strJson<<endl;

	StyledWriter sw;
	ofstream os;
	os.open("./jsoncpp.json");
	os << sw.write(family);
	os.close();

	return 0;  
}
