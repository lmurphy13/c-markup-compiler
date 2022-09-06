/*
 * Lexer
 */

#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum ttype_e {
	T_UNDEF = 0,
	T_STRING,
	T_INTEGER,
	T_HASH,
	T_DOT,
	T_DASH
} ttype_t;

typedef struct {
	ttype_t type;
	char *data;
} token_t;


// Wrapper around token_t
typedef struct tok_element_s {
	token_t token;
	void *prev;
	void *next;
} tok_element_t;

void lex(const char *path);

// Token functions
token_t *token_init(ttype_t type);

// Token linked list
tok_element_t *token_list_init(void);
void token_list_add(tok_element_t *list, token_t tok);

void print_list(tok_element_t *list);


#endif
