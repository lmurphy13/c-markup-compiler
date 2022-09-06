#include "../include/lexer.h"

void print_help(void);

int main(int argc, char *argv[]) {
	// if (argc < 2) {
	// 	print_help();
	// 	exit(0);
	// }

	tok_element_t *list = token_list_init();

	print_list(list);
	
	token_t token;
	token.type = T_HASH;

	char *s = (char *)malloc(sizeof(char) * 10);
	strncpy(s, "#", 1);
	token.data = s;
	printf("data: %s\n", token.data);
	
	token_list_add(list, token);

	print_list(list);
}

void print_help() {
	printf("Usage:\n");
	printf("./lup [file path]\n");
}
