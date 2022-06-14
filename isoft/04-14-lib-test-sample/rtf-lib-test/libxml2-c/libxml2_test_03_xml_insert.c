#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xmlmemory.h>

#define PHONE_BOOK_FILE     "phone_book.xml"
#define ID_STR_LEN        16
#define NAME_STR_LEN         32
#define TEL_STR_LEN         16
#define ADDR_STR_LEN         128

typedef struct phone_t {
	int id;
	char name[NAME_STR_LEN];
	char tel[TEL_STR_LEN];
	char address[ADDR_STR_LEN];
}phone;

static void set_phone_item(phone *phone_item)
{
	assert(phone_item);

	phone_item->id = 2;
	snprintf(phone_item->name, NAME_STR_LEN, "%s", "Insert Test");
	snprintf(phone_item->tel, TEL_STR_LEN, "%s", "100 0000 0001");
	snprintf(phone_item->address, ADDR_STR_LEN, "%s", "Shanghai");
}

static xmlNodePtr create_phone_node(const phone *phone_item)
{
	assert(phone_item);

	char id[ID_STR_LEN] = {0};
	xmlNodePtr phone_node = NULL;

	phone_node = xmlNewNode(NULL, BAD_CAST"phone");
	if (phone_node == NULL) {
		fprintf(stderr, "Failed to create new node.\n");
		return NULL;
	}
	snprintf(id, ID_STR_LEN, "%d", phone_item->id);
	xmlNewProp(phone_node, BAD_CAST"id", (xmlChar*)id);

	xmlNewChild(phone_node, NULL, BAD_CAST"name", (xmlChar *)phone_item->name);
	xmlNewChild(phone_node, NULL, BAD_CAST"tel", (xmlChar *)phone_item->tel);
	xmlNewChild(phone_node, NULL, BAD_CAST"address", (xmlChar *)phone_item->address);

	return phone_node;
}

static int add_phone_node_to_root(xmlNodePtr root_node)
{
	xmlNodePtr phone_node = NULL;
	phone *phone_item = NULL;

	phone_item = (phone *)malloc(sizeof(phone));
	if (phone_item == NULL) {
		fprintf(stderr, "Failed to malloc memory.\n");
		return -1;
	}
	set_phone_item(phone_item);

	phone_node = create_phone_node(phone_item); 
	if (phone_node == NULL) {
		fprintf(stderr, "Failed to create phone node.\n");
		goto FAILED;
	}
	xmlAddChild(root_node, phone_node);
	free(phone_item);

	return 0;
FAILED:
	if (phone_item){
		free(phone_item);
	}
	return -1;
}

static int add_phone_node(const char *phone_book_file)
{
	assert(phone_book_file);

	xmlDocPtr doc = NULL;
	xmlNodePtr root_node = NULL;
	xmlNodePtr phone_node = NULL;
	phone *phone_item = NULL;

	doc = xmlParseFile(phone_book_file);
	if (doc == NULL) {
		fprintf(stderr, "Failed to parser xml file:%s\n", phone_book_file);
		return -1;
	}

	root_node = xmlDocGetRootElement(doc);
	if (root_node == NULL) {
		fprintf(stderr, "Failed to get root node.\n");
		goto FAILED;
	}

	if (add_phone_node_to_root(root_node) != 0) {
		fprintf(stderr, "Failed to add a new phone node.\n");
		goto FAILED;
	}
	//将文档保存到文件中，按照utf-8编码格式保存
	xmlSaveFormatFileEnc(phone_book_file, doc, "UTF-8", 1);
	xmlFreeDoc(doc);

	return 0;
FAILED:
	if (doc) {
		xmlFreeDoc(doc);
	}

	return -1;
}

int main(int argc, char *argv[])
{
	char *phone_book_file = PHONE_BOOK_FILE;

	if (argc == 2) {
		phone_book_file = argv[1];
	}

	add_phone_node(phone_book_file);

	return 0;
}
