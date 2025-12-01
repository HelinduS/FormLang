%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
void yyerror(const char *s);
%}

%option noyywrap

%%
"meta"          { return META; }
"form"          { return FORM; }
"section"       { return SECTION; }
"field"         { return FIELD; }
"required"      { return REQUIRED; }
"min"           { return MIN; }
"max"           { return MAX; }
"default"       { return DEFAULT; }
"rows"          { return ROWS; }
"cols"          { return COLS; }
"pattern"       { return PATTERN; }
"options"       { return OPTIONS; }
"accept"        { return ACCEPT; }
"text"          { yylval.str = strdup(yytext); return TEXT; }
"textarea"      { yylval.str = strdup(yytext); return TEXTAREA; }
"number"        { yylval.str = strdup(yytext); return NUMBER; }
"email"         { yylval.str = strdup(yytext); return EMAIL; }
"checkbox"      { yylval.str = strdup(yytext); return CHECKBOX; }
"radio"         { yylval.str = strdup(yytext); return RADIO; }
"date"          { yylval.str = strdup(yytext); return DATE; }
"dropdown"      { yylval.str = strdup(yytext); return DROPDOWN; }
"password"      { yylval.str = strdup(yytext); return PASSWORD; }
"file"          { yylval.str = strdup(yytext); return FILETYPE; }
"true"          { yylval.str = strdup("true"); return BOOLEAN; }
"false"         { yylval.str = strdup("false"); return BOOLEAN; }
"validate"      { return VALIDATE; }
"if"            { return IF; }
"error"         { return ERROR; }

[0-9]+          { yylval.num = atoi(yytext); return NUM; }
\"[^\"]*\"      { yylval.str = strdup(yytext); return STRING; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
";"             { return SEMICOLON; }
":"             { return COLON; }
"="             { return EQUALS; }
","             { return COMMA; }
"<"             { return '<'; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFIER; }
[ \t\n\r]+      { /* skip whitespace */ }
.               { yyerror("Invalid token"); return ERROR_TOKEN; }

%%

