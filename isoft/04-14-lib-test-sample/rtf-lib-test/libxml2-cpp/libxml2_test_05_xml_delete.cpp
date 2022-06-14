#include <stdio.h>
#include "libxml/parser.h"
#include "libxml/tree.h"

#define DEFAULT_XML_FILE "phone_book.xml"

int main(int argc, char* argv[]){
	xmlDocPtr doc;				//定义解析文档指针
	xmlNodePtr cur, pre;			//定义节点指针（在各个节点之间移动）
	char *szDocName = DEFAULT_XML_FILE;

	if (argc == 2) {
		szDocName = argv[1];
	}

	doc = xmlReadFile(szDocName, "utf-8", XML_PARSE_RECOVER); 	//解析文档
	if (NULL == doc){
		fprintf(stderr, "Document not parsed successfully.\n");
		return -1;
	}

	//获取根节点
	cur = xmlDocGetRootElement(doc);
	if (cur == NULL) {
		fprintf(stderr, "Root is empty.\n");
		return -1;
	}

	if ((xmlStrcmp(cur->name, (const xmlChar *)"phone_books"))) {
		fprintf(stderr, "The root is not phone_books.\n");
		xmlFreeDoc(doc);
		return -1;
	}
	//遍历处理根节点的每一个子节点
	cur = cur->xmlChildrenNode;
	while (cur != NULL) {
		if ((!xmlStrcmp(cur->name, (const xmlChar *)"phone"))) {
			if((!xmlStrcmp(xmlGetProp(cur, (const xmlChar *)"id"), (const xmlChar *)"2"))){	
				pre->next=cur->next;
				xmlFreeNode(cur);
			}
		}
		pre = cur;
		cur = cur->next;
	}
	//保存文档到原文档中
	xmlSaveFile(szDocName, doc);
	xmlFreeDoc(doc);

	return 0;
}
