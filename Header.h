#pragma once
#ifndef  HEADER_H
#define HEADER_H

//#include <stdbool.h>

enum class token_type {
    TOKEN_IDENT,
    TOKEN_NUMBER,

    TOKEN_STAR,
    TOKEN_COMMA,
    TOKEN_SEMICOLON,

    TOKEN_LPAREN,
    TOKEN_RPAREN,

    TOKEN_EQUAL,
    TOKEN_LESS,
    TOKEN_GREATER,

    TOKEN_SELECT,
    TOKEN_CREATE,
    TOKEN_TABLE,
    TOKEN_INSERT,
    TOKEN_DELETE,
    TOKEN_ALTER,
    TOKEN_UPDATE,

    TOKEN_FROM,
    TOKEN_WHERE,
    TOKEN_AND,
    TOKEN_ADD,

    TOKEN_ORDER,
    TOKEN_BY,
    TOKEN_ASC,
    TOKEN_DESC,
    TOKEN_SET,

    TOKEN_GROUP,
    TOKEN_HAVING,

    TOKEN_INTO,
    TOKEN_VALUES,
    TOKEN_QUOT,

    TOKEN_ERROR,                
    TOKEN_EOS  
};

typedef struct token_t {
    token_type type;            
    const char* start;          
    int length;             
} token_t;

typedef struct parser_t parser_t;

typedef struct lexer_t lexer_t;

lexer_t* lexer_create(const char* string);

void lexer_destroy(lexer_t* lexer);

token_t lexer_next(lexer_t* lexer);

parser_t* parser_create(void);

void parser_destroy(parser_t* parser);

bool parser_parse(parser_t* parser, lexer_t* lexer);

 
#endif //HEADER_H