%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Remove quotes from strings
char *strip_quotes(char *str) {
    int len = strlen(str);
    if (len >= 2 && str[0] == '"' && str[len-1] == '"') {
        char *new_str = malloc(len-1);
        strncpy(new_str, str+1, len-2);
        new_str[len-2] = '\0';
        free(str);
        return new_str;
    }
    return str;
}

// Field and attribute state variables
int textarea_rows = 0, textarea_cols = 0;
char *textarea_default = NULL, *field_pattern = NULL;
FILE *output;
void yyerror(const char *s);
int yylex(void);

#define MAX_OPTIONS 10
char *radio_options[MAX_OPTIONS]; int option_count = 0;
char *dropdown_default = NULL;
int dropdown_required = 0;
char *dropdown_options[MAX_OPTIONS];
int dropdown_option_count = 0;
int min_value = 0, max_value = 0;
int has_min = 0, has_max = 0;
char *date_min = NULL, *date_max = NULL;
int is_required = 0, is_checked = 0, has_options = 0;
char *password_pattern = NULL;
char *file_accept = NULL;
%}

%union {
    char *str;
    int num;
}

%token FORM SECTION FIELD REQUIRED MIN MAX DEFAULT ROWS COLS PATTERN OPTIONS ACCEPT VALIDATE IF ERROR
%token <str> TEXT TEXTAREA NUMBER EMAIL CHECKBOX RADIO DATE DROPDOWN PASSWORD FILETYPE
%token META
%token <str> IDENTIFIER STRING BOOLEAN
%token <num> NUM
%token LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COLON EQUALS COMMA
%token ERROR_TOKEN
%type <str> field_type field_name validate_condition

%%

form: FORM IDENTIFIER LBRACE{
    fprintf(output, "<form name=\"%s\">\n", $2);
    }
    meta_list section_list {
        fprintf(output, "<button type=\"submit\">Submit</button>\n</form>\n"); 
        free($2);
    }
    validate_block_opt RBRACE{

    }
;

meta_list:
      /* empty */
    | meta_list meta_line
    ;

meta_line: META IDENTIFIER EQUALS STRING SEMICOLON
    {
        // Output meta as HTML comment
        char *unquoted = strip_quotes($4);
        fprintf(output, "<!-- Meta: %s = %s -->\n", $2, unquoted);
        free($2); free(unquoted);
    }
;

section_list: /* empty */
    | section_list section
    ;

section: SECTION IDENTIFIER LBRACE field_list RBRACE
    { free($2); }
    ;

field_list: /* empty */
    | field_list field
    ;

field:
    FIELD field_name COLON field_type attribute_list SEMICOLON
    {
        if (strcmp($4, "text") == 0) {
            fprintf(output, "<label>%s: <input type=\"text\" name=\"%s\"%s", $2, $2, is_required ? " required" : "");
            if (field_pattern) fprintf(output, " pattern=\"%s\"", field_pattern);
            fprintf(output, "></label><br>\n");
        } else if (strcmp($4, "number") == 0) {
            fprintf(output, "<label>%s: <input type=\"number\" name=\"%s\"", $2, $2);
            if (is_required) fprintf(output, " required");
            if (has_min) fprintf(output, " min=\"%d\"", min_value);
            if (has_max) fprintf(output, " max=\"%d\"", max_value);
            fprintf(output, "></label><br>\n");
        } else if (strcmp($4, "email") == 0) {
            fprintf(output, "<label>%s: <input type=\"email\" name=\"%s\"%s", $2, $2, is_required ? " required" : "");
            if (field_pattern) fprintf(output, " pattern=\"%s\"", field_pattern);
            fprintf(output, "></label><br>\n");
        } else if (strcmp($4, "checkbox") == 0) {
            fprintf(output, "<label><input type=\"checkbox\" name=\"%s\"%s> %s</label><br>\n",
                    $2, is_checked ? " checked" : "", $2);
        } else if (strcmp($4, "radio") == 0) {
            fprintf(output, "<label>%s:</label><br>\n", $2);
            for (int i = 0; i < option_count; i++) {
                fprintf(output, "<input type=\"radio\" name=\"%s\" value=\"%s\"> %s<br>\n",
                        $2, radio_options[i], radio_options[i]);
                free(radio_options[i]);
            }
            option_count = 0;
        } else if (strcmp($4, "textarea") == 0) {
            fprintf(output, "<label>%s:<br><textarea name=\"%s\"", $2, $2);
            if (textarea_rows) fprintf(output, " rows=\"%d\"", textarea_rows);
            if (textarea_cols) fprintf(output, " cols=\"%d\"", textarea_cols);
            fprintf(output, ">");
            if (textarea_default) fprintf(output, "%s", textarea_default);
            fprintf(output, "</textarea></label><br>\n");
        } else if (strcmp($4, "date") == 0) {
            fprintf(output, "<label>%s: <input type=\"date\" name=\"%s\"", $2, $2);
            if (is_required) fprintf(output, " required");
            if (date_min) fprintf(output, " min=\"%s\"", date_min);
            if (date_max) fprintf(output, " max=\"%s\"", date_max);
            fprintf(output, "></label><br>\n");
        } else if (strcmp($4, "dropdown") == 0) {
            fprintf(output, "<label>%s: <select name=\"%s\"%s>\n", $2, $2, dropdown_required ? " required" : "");
            for (int i = 0; i < dropdown_option_count; i++) {
                if (dropdown_default && strcmp(dropdown_default, dropdown_options[i]) == 0)
                    fprintf(output, "<option value=\"%s\" selected>%s</option>\n", dropdown_options[i], dropdown_options[i]);
                else
                    fprintf(output, "<option value=\"%s\">%s</option>\n", dropdown_options[i], dropdown_options[i]);
                free(dropdown_options[i]);
            }
            fprintf(output, "</select></label><br>\n");
        } else if (strcmp($4, "password") == 0) {
            fprintf(output, "<label>%s: <input type=\"password\" name=\"%s\"%s", $2, $2, is_required ? " required" : "");
            if (password_pattern) fprintf(output, " pattern=\"%s\"", password_pattern);
            fprintf(output, "></label><br>\n");
        } else if (strcmp($4, "file") == 0) {
            fprintf(output, "<label>%s: <input type=\"file\" name=\"%s\"%s", $2, $2, is_required ? " required" : "");
            if (file_accept) fprintf(output, " accept=\"%s\"", file_accept);
            fprintf(output, "></label><br>\n");
        } else {
            fprintf(stderr, "Error: Unknown field type '%s' in field '%s'.\n", $4, $2);
        }
        // Reset all attribute variables after each field
        is_required = 0; has_min = 0; has_max = 0;
        min_value = 0; max_value = 0; is_checked = 0;
        has_options = 0;
        textarea_rows = 0; textarea_cols = 0;
        if (textarea_default) { free(textarea_default); textarea_default = NULL; }
        if (field_pattern) { free(field_pattern); field_pattern = NULL; }
        if (dropdown_default) { free(dropdown_default); dropdown_default = NULL; }
        dropdown_required = 0; dropdown_option_count = 0;
        if (date_min) { free(date_min); date_min = NULL; }
        if (date_max) { free(date_max); date_max = NULL; }
        if (password_pattern) { free(password_pattern); password_pattern = NULL; }
        if (file_accept) { free(file_accept); file_accept = NULL; }
        free($2); free($4);
    }
  | FIELD field_name COLON field_type error
    {
        yyerror("Invalid field declaration or missing semicolon");
        // Reset as above for error recovery
        is_required = 0; has_min = 0; has_max = 0;
        min_value = 0; max_value = 0; is_checked = 0;
        option_count = 0; textarea_rows = 0; textarea_cols = 0;
        if (textarea_default) { free(textarea_default); textarea_default = NULL; }
        if (field_pattern) { free(field_pattern); field_pattern = NULL; }
        if (dropdown_default) { free(dropdown_default); dropdown_default = NULL; }
        dropdown_required = 0; dropdown_option_count = 0;
        if (date_min) { free(date_min); date_min = NULL; }
        if (date_max) { free(date_max); date_max = NULL; }
        if (password_pattern) { free(password_pattern); password_pattern = NULL; }
        if (file_accept) { free(file_accept); file_accept = NULL; }
        free($2); free($4);
    
    }
;

field_name:
    IDENTIFIER   { $$ = $1; }
  | TEXT         { $$ = $1; }
  | TEXTAREA     { $$ = $1; }
  | NUMBER       { $$ = $1; }
  | EMAIL        { $$ = $1; }
  | CHECKBOX     { $$ = $1; }
  | RADIO        { $$ = $1; }
  | DATE         { $$ = $1; }
  | DROPDOWN     { $$ = $1; }
  | PASSWORD     { $$ = $1; }
  | FILETYPE     { $$ = $1; }
  ;

field_type:
    TEXT         { $$ = $1; }
    | TEXTAREA   { $$ = $1; }
    | NUMBER     { $$ = $1; }
    | EMAIL      { $$ = $1; }
    | CHECKBOX   { $$ = $1; }
    | RADIO      { $$ = $1; }
    | DATE       { $$ = $1; }
    | DROPDOWN   { $$ = $1; }
    | PASSWORD   { $$ = $1; }
    | FILETYPE   { $$ = $1; }
    | IDENTIFIER { fprintf(stderr, "Error: Unknown field type '%s'.\n", $1); $$ = $1;}
    ;

attribute_list: /* empty */ { }
    | attribute_list attribute
    ;

attribute:
      REQUIRED { is_required = 1; dropdown_required = 1; }
    | MIN EQUALS NUM { has_min = 1; min_value = $3; }
    | MAX EQUALS NUM { has_max = 1; max_value = $3; }
    | DEFAULT EQUALS BOOLEAN { is_checked = (strcmp($3, "true") == 0 ? 1 : 0); free($3); }
    | LBRACKET string_list RBRACKET { has_options = 1; }
    | ROWS EQUALS NUM { textarea_rows = $3; }
    | COLS EQUALS NUM { textarea_cols = $3; }
    | DEFAULT EQUALS STRING {
            if (textarea_default) free(textarea_default);
            if (dropdown_default) free(dropdown_default);
            textarea_default = strip_quotes($3);
            dropdown_default = strdup(textarea_default);
      }
    | PATTERN EQUALS STRING {
            if (field_pattern) free(field_pattern);
            if (password_pattern) free(password_pattern);
            field_pattern = strip_quotes($3);
            password_pattern = strdup(field_pattern);
      }
    | MIN EQUALS STRING { date_min = strip_quotes($3); }
    | MAX EQUALS STRING { date_max = strip_quotes($3); }
    | OPTIONS EQUALS LBRACKET dropdown_option_list RBRACKET { }
    | ACCEPT EQUALS STRING { if (file_accept) free(file_accept); file_accept = strip_quotes($3); }
    | IDENTIFIER { fprintf(stderr, "Warning: Unknown attribute '%s' ignored.\n", $1); free($1); }
    ;

dropdown_option_list:
    STRING
        { if (dropdown_option_count < MAX_OPTIONS) dropdown_options[dropdown_option_count++] = strip_quotes($1); else free($1); }
 | dropdown_option_list COMMA STRING
        { if (dropdown_option_count < MAX_OPTIONS) dropdown_options[dropdown_option_count++] = strip_quotes($3); else free($3); }
  ;

string_list: STRING
    {
        if (option_count < MAX_OPTIONS) radio_options[option_count++] = strip_quotes($1);
        else free($1);
    }
    | string_list COMMA STRING
    {
        if (option_count < MAX_OPTIONS) radio_options[option_count++] = strip_quotes($3);
        else free($3);
    }
    ;

validate_block_opt:
      /* empty */
    | validate_block
    ;

validate_block:
    VALIDATE LBRACE validate_content_list RBRACE
    ;

validate_content_list:
      /* empty */
    | validate_content_list validate_statement
    ;

validate_statement:
    IF validate_condition LBRACE ERROR STRING SEMICOLON RBRACE
    {
        char *msg = strip_quotes($5);
        // JS validation for age < N
        // Only works for `if age < N` format!
        int number = 0;
        char field[64] = "";
        // Parse $2 (which is like "age < 18")
        sscanf($2, "%s < %d", field, &number);

        fprintf(output,
            "<script>\n"
            "document.addEventListener('DOMContentLoaded', function() {\n"
            "  var form = document.querySelector('form');\n"
            "  if(form) {\n"
            "    form.addEventListener('submit', function(e) {\n"
            "      var age = document.getElementsByName('%s')[0]?.value;\n"
            "      if (age !== undefined && age < %d) {\n"
            "        alert('%s');\n"
            "        e.preventDefault();\n"
            "      }\n"
            "    });\n"
            "  }\n"
            "});\n"
            "</script>\n",
            field, number, msg
        );

        free($2); free(msg);
    }
;


validate_condition:
      IDENTIFIER '<' NUM
        {
            char buf[128];
            snprintf(buf, sizeof(buf), "%s < %d", $1, $3);
            $$ = strdup(buf);
            free($1);
        }
;
%%

void yyerror(const char *s) {
    extern int yylineno;
    fprintf(stderr, "Syntax error: %s at line %d\n", s, yylineno);
}

int main() {
    output = fopen("output.html", "w");
    if (!output) {
        fprintf(stderr, "Cannot open output.html\n");
        return 1;
    }
    yyparse();
    fclose(output);
    return 0;
}