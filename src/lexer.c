#include "../include/lexer.h"

static void lex_error(const char *msg) {
	printf("LEXER ERROR: %s\n", msg);
}

void lex(const char *path) {
	FILE *fp = fopen(path, "r");

	// Read each character one at a time
	int ch;
	do {
		ch = fgetc(fp);

		// Ignore whitespace for now
		if (ch == '\n' || ch == '\r' || ch  == '\t')
			continue;

		
		
	} while (ch != EOF);
}

token_t *token_init(ttype_t type) {
	token_t *temp = (token_t *)malloc(sizeof(token_t));

	if (temp == NULL) {
		lex_error("Could not initialize token");
		return NULL;
	}

	temp->type = type;
	temp->data = NULL;

	return temp;
}

tok_element_t *token_list_init() {
	token_t tok;
	tok.type = T_UNDEF;
	tok.data = NULL;
	

	tok_element_t *element = (tok_element_t *)malloc(sizeof(tok_element_t));
	if (element != NULL) {
		element->token = tok;
		element->prev = NULL;
		element->next = NULL;
	} else {
		lex_error("Could not create token element while setting up token list");
		return NULL;
	}

	return element;
}

void token_list_add(tok_element_t *list, token_t tok) {
	
	printf("got here");
	if (list == NULL) {
		lex_error("Cannot append to a NULL list");
		return;
	}
	else {
		printf("here");
		// Get head of the list
		tok_element_t *iter = list;

		// Wrap tok in a tok_element_t
		tok_element_t *new_tok = (tok_element_t *)malloc(sizeof(tok_element_t));
		if (new_tok == NULL) {
			lex_error("Unable to allocate new tok_element_t wrapper");
			return;
		}

		printf("here2");
		new_tok->token = tok;

		// Seek to the end
		while (iter != NULL) {
			iter = iter->next;
		}

		new_tok->prev = iter;
		new_tok->next = NULL;
		iter = new_tok;
	}
}

void print_list(tok_element_t *list) {
	if (list == NULL) {
		lex_error("list is NULL");
		return;
	}

	tok_element_t *iter = list;
	while (iter != NULL) {
		// Extract token
		token_t tok = iter->token;
		printf("token type: %d\n", tok.type);
		printf("token data: %s\n", tok.data);

		iter = iter->next;
	}
}
