#pragma once

#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <msclr/marshal_cppstd.h>
#include "Header.h"
#include "ParserForm.h"

struct lexer_t {
    const char* input;
    const char* token_start;
};

struct table_t {
    std::string table_name;
    std::vector<std::string> column_name;
    std::vector<std::string> data_type;
    std::vector<std::vector<std::string>> values;
};

struct parser_t {
    lexer_t* lexer;
    token_t current; 
    token_t previous;
    table_t* table;

    bool had_error;
};

lexer_t* lexer_create(const char* string)
{
    lexer_t* lexer = static_cast<lexer_t*>(calloc(1, sizeof(lexer_t)));
    if (!lexer)
        return nullptr;
    //assert(lexer);

    lexer->input = string;

    return lexer;
}

void lexer_destroy(lexer_t* lexer)
{
    if (lexer)
        free(lexer);
}

static bool char_is_alpha(char c)
{
    return (c >= 'a' && c <= 'z')
        || (c >= 'A' && c <= 'Z')
        || c == '_'|| (c >= 'а' && c <= 'я')
        || (c >= 'А' && c <= 'Я');
}

static bool char_is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

/*Если указатель на конце строки, то возвращается true*/
static bool lexer_at_eos(lexer_t* lexer)
{
    return *lexer->input == '\0';
}

/*Эта функция принимает указатель на scanner_t структуру в качестве аргумента.
Он возвращает версию символа в нижнем регистре, на который указывает lexer->input.
Результат будет приведен к char с помощью static_cast<char>.*/
static char lexer_peek(lexer_t* lexer) {
    return static_cast<char>(std::tolower(*lexer->input));
}

static char lexer_peek_start(lexer_t* lexer) {
    return static_cast<char>(std::tolower(*lexer->token_start));
}

/*Функция scanner_advance перемещает указатель input на один символ вперед и возвращает этот символ.*/
static char lexer_advance(lexer_t* lexer) {
    return *lexer->input++;
}

static void lexer_skip_space(lexer_t* lexer) {
    while (true) {
        char c = lexer_peek(lexer);
        switch (c) {
        case ' ':
        case '\r':
        case '\n':
        case '\t':
            lexer_advance(lexer);
            break;
        default:
            return;
        }
    }
}

static token_t lexer_token_create(lexer_t* lexer, token_type type)
{
    token_t token = {
        type,
        lexer->token_start,
        lexer->input - lexer->token_start };
    return token;
}

static token_t lexer_token_error_create(const char* error_msg)
{
    token_t token = { 
        token_type::TOKEN_ERROR, 
        error_msg, 
        static_cast<int>(strlen(error_msg)) };
    return token;
}

/*TOKEN_IDENT - токен не идентифицирован как оператор
Внутри функции происходит проверка, равна ли разница между указателями token_start и input сумме start и length. 

Затем происходит цикл, в котором сравниваются символы из строки token_start с символами из суффикса*/

static token_type scan_keyword(lexer_t* lexer, int start, int length, const char* suffix, token_type type)
{
    // Проверяем, что длина токена соответствует указанной длине
    if (lexer->input - lexer->token_start != start + length)
        return token_type::TOKEN_IDENT;

    // Проверяем, что каждый символ токена соответствует указанному суффиксу
    for (int i = start; i < start + length; i++) {
        if (tolower(lexer->token_start[i]) != suffix[i - start])
            return token_type::TOKEN_IDENT;
    }
    return type;
}

static token_type scan_ident_type(lexer_t* lexer)
{
    switch (lexer_peek_start(lexer)) {
    case 's': {
        token_type t = scan_keyword(lexer, 1, 5, "elect", token_type::TOKEN_SELECT);
        if (t != token_type::TOKEN_IDENT)
            return t;
        return scan_keyword(lexer, 1, 2, "et", token_type::TOKEN_SET);
    }
    case 'f': return scan_keyword(lexer, 1, 3, "rom", token_type::TOKEN_FROM);
    case 'w': return scan_keyword(lexer, 1, 4, "here", token_type::TOKEN_WHERE);
    case 'a': {
        token_type t = scan_keyword(lexer, 1, 2, "nd", token_type::TOKEN_AND);
        if (t != token_type::TOKEN_IDENT)
            return t;
        token_type t1 = scan_keyword(lexer, 1, 4, "lter", token_type::TOKEN_ALTER);
        if (t1 != token_type::TOKEN_IDENT)
            return t1;
        token_type t2 = scan_keyword(lexer, 1, 2, "dd", token_type::TOKEN_ADD);
        if (t2 != token_type::TOKEN_IDENT)
            return t2;
        return scan_keyword(lexer, 1, 2, "sc", token_type::TOKEN_ASC);
    }
    case 'g': return scan_keyword(lexer, 1, 4, "roup", token_type::TOKEN_GROUP);
    case 'h': return scan_keyword(lexer, 1, 5, "aving", token_type::TOKEN_HAVING);
    case 'o': return scan_keyword(lexer, 1, 4, "rder", token_type::TOKEN_ORDER);
    case 'b': return scan_keyword(lexer, 1, 1, "y", token_type::TOKEN_BY);
    case 'd': {
        token_type t = scan_keyword(lexer, 1, 3, "esc", token_type::TOKEN_DESC);
        if (t != token_type::TOKEN_IDENT)
            return t; 
        return scan_keyword(lexer, 1, 5, "elete", token_type::TOKEN_DELETE);
    }
    case 'c': return scan_keyword(lexer, 1, 5, "reate", token_type::TOKEN_CREATE);
    case 't': return scan_keyword(lexer, 1, 4, "able", token_type::TOKEN_TABLE);
    case 'i': {
        token_type t = scan_keyword(lexer, 1, 5, "nsert", token_type::TOKEN_INSERT);
        if (t != token_type::TOKEN_IDENT)
            return t;
        return scan_keyword(lexer, 1, 3, "nto", token_type::TOKEN_INTO);
    }
    case 'v': return scan_keyword(lexer, 1, 5, "alues", token_type::TOKEN_VALUES);
    case 'u': return scan_keyword(lexer, 1, 5, "pdate", token_type::TOKEN_UPDATE);
    }
    return token_type::TOKEN_IDENT;
}

/*Пока встречаются цифры или буквы, проходим до конца, идентифицируем символы и создаем токен*/
static token_t lexer_ident(lexer_t* lexer)
{
    while (char_is_digit(lexer_peek(lexer)) || char_is_alpha(lexer_peek(lexer)))
        lexer_advance(lexer);

    return lexer_token_create(lexer, scan_ident_type(lexer));
}

static token_t lexer_number(lexer_t* lexer)
{
    while (char_is_digit(lexer_peek(lexer)))
        lexer_advance(lexer);

    return lexer_token_create(lexer, token_type::TOKEN_NUMBER);
}

/*Разбор на токены всей строки*/
token_t lexer_next(lexer_t* lexer)
{
    lexer_skip_space(lexer);

    lexer->token_start = lexer->input;

    if (lexer_at_eos(lexer))
        return lexer_token_create(lexer, token_type::TOKEN_EOS);

    char c = lexer_advance(lexer);

    if (char_is_alpha(c))
        return lexer_ident(lexer);

    if (char_is_digit(c))
        return lexer_number(lexer);

    switch (c) {
    case ';': return lexer_token_create(lexer, token_type::TOKEN_SEMICOLON);
    case ',': return lexer_token_create(lexer, token_type::TOKEN_COMMA);
    case '*': return lexer_token_create(lexer, token_type::TOKEN_STAR);
    case '=': return lexer_token_create(lexer, token_type::TOKEN_EQUAL);
    case '<': return lexer_token_create(lexer, token_type::TOKEN_LESS);
    case '>': return lexer_token_create(lexer, token_type::TOKEN_GREATER);
    case '(': return lexer_token_create(lexer, token_type::TOKEN_LPAREN);
    case ')': return lexer_token_create(lexer, token_type::TOKEN_RPAREN);
    case '\'': return lexer_token_create(lexer, token_type::TOKEN_QUOT);
    }
    return lexer_token_error_create("Unknown character");
}

parser_t* parser_create() {
    parser_t* parser = static_cast<parser_t*>(calloc(1, sizeof(parser_t)));
    if (!parser)
        return nullptr;
    return parser;
}

void parser_destroy(parser_t* parser)
{
    if (parser)
        free(parser);
}

static void parser_error_at(parser_t* parser, token_t token, const char* msg)
{
    if (parser->had_error)
        return;

    ParserForm::richTextBox2->AppendText("Error");

    if (token.type == token_type::TOKEN_EOS) {
        ParserForm::richTextBox2->AppendText(" at end");
    }
    else if (token.type == token_type::TOKEN_ERROR) {
    }

    else {
        ParserForm::richTextBox2->AppendText(" parsing '" + gcnew String(token.start, 0, token.length) + "'");
    }
    ParserForm::richTextBox2->AppendText(": " + gcnew String(msg) + "\n");
    parser->had_error = true;
}

static void parser_error(parser_t* parser, const char* msg) {
    
    parser_error_at(parser, parser->previous, msg);
}

static void parser_error_at_current(parser_t* parser, const char* msg)
{
    parser_error_at(parser, parser->current, msg);
}

//функция, которая продвигает указатель текущего токена на следующий токен, игнорируя 
//ошибочные токены и вызывая parser_error_at_current для каждого ошибочного токена
static void parser_advance(parser_t* parser)
{
    parser->previous = parser->current;
    for (;;) {
        parser->current = lexer_next(parser->lexer);
        if (parser->current.type != token_type::TOKEN_ERROR)
            break;

        parser_error_at_current(parser, parser->current.start);
    }
}

//функция, которая проверяет, соответствует ли текущий токен заданному типу, и если да, 
//то продвигает указатель текущего токена.
static void parser_consume(parser_t* parser, token_type type, const char* msg)
{
    if (parser->current.type == type) {
        parser_advance(parser);
        return;
    }
    parser_error_at_current(parser, msg);
}

static bool parser_check(parser_t* parser, token_type type) {
    return parser->current.type == type;
}

//функция, которая проверяет, соответствует ли текущий токен заданному типу, и если да, то 
//продвигает указатель текущего токена и возвращает true.
static bool parser_match(parser_t* parser, token_type type)
{
    if (!parser_check(parser, type))
        return false;
    parser_advance(parser);
    return true;
}

void DisplayTableInDataGridView(const table_t& table) {

    DataGridView^ dataGridView = ParserForm::dataGridView1;

    // Очистка существующих данных
    dataGridView->Columns->Clear();
    dataGridView->Rows->Clear();

    // Создание столбцов
    for (const auto& col_name : table.column_name) {
        dataGridView->Columns->Add(gcnew String(col_name.c_str()), gcnew String(col_name.c_str()));
    }
    // Добавление строк
    for (const auto& row_values : table.values) {
        array<String^>^ row = gcnew array<String^>(row_values.size());
        for (size_t i = 0; i < row_values.size(); ++i) {
            row[i] = gcnew String(row_values[i].c_str());
        }
        dataGridView->Rows->Add(row);
    }
    // Обновление DataGridView
    dataGridView->Refresh();
}

static bool check_column_exists(parser_t* parser)
{
    std::string column_name(parser->previous.start, parser->previous.length);
    bool column_exists = false;
    for (const auto& col : parser->table->column_name) {
        if (column_name == col) {
            column_exists = true;
            break;
        }
    }
    return column_exists;
};

/*
std::string parse_predicate(parser_t* parser)
{
    parser_consume(parser, token_type::TOKEN_IDENT, "Left predicate identifier expected");

    std::string column_name(parser->previous.start, parser->previous.length);

    if (parser->table != nullptr && !check_column_exists(parser))
    {
        parser_error(parser, "Column does not exist");
    }

    if (!parser_match(parser, token_type::TOKEN_EQUAL) &&
        !parser_match(parser, token_type::TOKEN_LESS) &&
        !parser_match(parser, token_type::TOKEN_GREATER)) {
        parser_error(parser, "Predicate operator expected");
        return "";
    }

    if (!parser_match(parser, token_type::TOKEN_IDENT) &&
        !parser_match(parser, token_type::TOKEN_NUMBER)) {
        parser_error(parser, "Right predicate identifier or number expected");
        return "";
    }
    // Возвращаем имя столбца для дальнейшего использования
    return column_name;
}
*/

static void parse_predicate(parser_t* parser)
{
    parser_consume(parser, token_type::TOKEN_IDENT, "Left predicate identifier expected");

    if (parser->table != nullptr && !check_column_exists(parser))
    {
        parser_error(parser, "Column does not exist");
    }

    if (!parser_match(parser, token_type::TOKEN_EQUAL) &&
        !parser_match(parser, token_type::TOKEN_LESS) &&
        !parser_match(parser, token_type::TOKEN_GREATER)) {
        parser_error(parser, "Predicate operator expected");
        return;
    }

    if (!parser_match(parser, token_type::TOKEN_IDENT) &&
        !parser_match(parser, token_type::TOKEN_NUMBER)) {
        parser_error(parser, "Right predicate identifier or number expected");
        return;
    }
}

static void parse_order(parser_t* parser)
{
    parser_consume(parser, token_type::TOKEN_BY, "ORDER should always be followed by BY");
    parser_consume(parser, token_type::TOKEN_IDENT, "Column name expected");
    if (parser->table != nullptr && !check_column_exists(parser))
    {
        parser_error(parser, "Column does not exist");
    }

    if (parser_match(parser, token_type::TOKEN_ASC))
        return;
    parser_match(parser, token_type::TOKEN_DESC);
};
 
static void parser_destroy_table(table_t* table)
{
    delete table;
};

static void parser_create_table(parser_t* parser)
{
    parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");

    std::string tab_name(parser->previous.start, parser->previous.length);
    table_t* table = new table_t;
    table->table_name = tab_name;

    parser_consume(parser, token_type::TOKEN_LPAREN, "LPAREN expected");
    do {
        parser_consume(parser, token_type::TOKEN_IDENT, "Column name expected");
        std::string col_name(parser->previous.start, parser->previous.length);
        table->column_name.push_back(col_name);

        parser_consume(parser, token_type::TOKEN_IDENT, "Datatype of attribute expected");

        std::string data_type(parser->previous.start, parser->previous.length);
        if (data_type == "varchar") {
            parser_consume(parser, token_type::TOKEN_LPAREN, "LPAREN expected");
            parser_consume(parser, token_type::TOKEN_NUMBER, "Length of varchar expected");
            int length = std::stoi(std::string(parser->previous.start, parser->previous.length));
            parser_consume(parser, token_type::TOKEN_RPAREN, "RPAREN expected");
            data_type = "varchar(" + std::to_string(length) + ")";
        }
        table->data_type.push_back(data_type);

    } while (parser_match(parser, token_type::TOKEN_COMMA));
    parser->table = table;
    parser_consume(parser, token_type::TOKEN_RPAREN, "RPAREN expected");
    DisplayTableInDataGridView(*(parser->table));
};

bool evaluate_predicate(const std::string& column_value, const std::string& op, const double number) {
    double value;
    try {
        value = std::stod(column_value);
    }
    catch (const std::invalid_argument&) {
        // Если значение не является числом, пропускаем его
        return false;
    }
    catch (const std::out_of_range&) {
        // Если число слишком большое или слишком маленькое для double
        return false;
    }

    // Сравнение значения столбца с числом
    if (op == ">" && value > number) return true;
    if (op == "<" && value < number) return true;
    if (op == "=" && value == number) return true;

    // Если значение не соответствует условию, возвращаем false
    return false;
}

void parser_select(parser_t* parser)
{
    if (parser->table == nullptr)
    {
        if (parser_check(parser, token_type::TOKEN_IDENT)) {
            do {
                parser_consume(parser, (token_type::TOKEN_IDENT), "Column name after , expected");
            } while (parser_match(parser, token_type::TOKEN_COMMA));
        }
        else {
            parser_consume(parser, token_type::TOKEN_STAR, "Column name or * expected");
        }

        parser_consume(parser, token_type::TOKEN_FROM, "FROM expected");
        parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");

        if (parser_match(parser, token_type::TOKEN_WHERE)) {
            do {
                parse_predicate(parser);
            } while (parser_match(parser, token_type::TOKEN_AND));
        }

        if (parser_match(parser, token_type::TOKEN_GROUP))
        {
            parser_consume(parser, token_type::TOKEN_BY, "GROUP should always be followed by BY");
            parser_consume(parser, token_type::TOKEN_IDENT, "Column name expected");
        }

        if (parser_match(parser, token_type::TOKEN_HAVING))
            parse_predicate(parser);

        if (parser_match(parser, token_type::TOKEN_ORDER))
            parse_order(parser);

        //ParserForm::richTextBox2->Text = "SQL query is correct\n";
        return;
    }
    
    std::vector<std::string> selected_columns;
    if (parser_check(parser, token_type::TOKEN_IDENT)) {
        do {
            std::string column_name(parser->current.start, parser->current.length);
            selected_columns.push_back(column_name);
            parser_consume(parser, token_type::TOKEN_IDENT, "Column name expected");

            if (!check_column_exists(parser))
            {
                parser_error(parser, "Column does not exist");
                return;
            }
            
        } while (parser_match(parser, token_type::TOKEN_COMMA));
    }
    else {
        parser_consume(parser, token_type::TOKEN_STAR, "Column name or * expected");
        selected_columns = parser->table->column_name;
    }

    parser_consume(parser, token_type::TOKEN_FROM, "FROM expected");
    parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
    std::string tab_name(parser->previous.start, parser->previous.length);

    if (tab_name != parser->table->table_name) {
        parser_error(parser, "Table does not exist");
        return;
    }

    std::vector<std::vector<std::string>> filtered_values;
    if (parser_match(parser, token_type::TOKEN_WHERE)) {
        std::string left, op;
        double right;

        // Считываем левый идентификатор условия
        parser_consume(parser, token_type::TOKEN_IDENT, "Left predicate identifier expected");
        left = std::string(parser->previous.start, parser->previous.length);

        if (parser_match(parser, token_type::TOKEN_EQUAL)) {
            op = "=";
        }
        else if (parser_match(parser, token_type::TOKEN_LESS)) {
            op = "<";
        }
        else if (parser_match(parser, token_type::TOKEN_GREATER)) {
            op = ">";
        }
        else {
            parser_error(parser, "Predicate operator expected");
            return;
        }
        // Считываем правое число
        parser_consume(parser, token_type::TOKEN_NUMBER, "Right predicate number expected");
        right = std::stod(std::string(parser->previous.start, parser->previous.length));

        // Получаем индекс столбца left
        int left_index = -1;
        for (size_t i = 0; i < parser->table->column_name.size(); ++i) {
            if (parser->table->column_name[i] == left) {
                left_index = int(i);
                break;
            }
        }
        if (left_index == -1) {
            parser_error(parser, "Column does not exist");
            return;
        }
        for (const auto& row : parser->table->values) {
            if (evaluate_predicate(row[left_index], op, right)) {
                filtered_values.push_back(row);
            }
        }
    }
    else {

        filtered_values = parser->table->values;
    }
    std::stringstream result_stream;
    for (const auto& col : selected_columns) {
        result_stream << col << " | ";
    }
    result_stream << "\n" << std::string(5 * selected_columns.size(), '-') << "\n";

    for (const auto& row : filtered_values) {
        for (const auto& col_name : selected_columns) {
            size_t col_index = std::distance(parser->table->column_name.begin(), std::find(parser->table->column_name.begin(), parser->table->column_name.end(), col_name));
            result_stream << row[col_index] << " | ";
        }
        result_stream << "\n";
    }
    ParserForm::richTextBox2->Text = gcnew System::String(result_stream.str().c_str());
}

void parser_insert(parser_t* parser)
{
    if (parser->table == nullptr)
    {
        parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
        parser_consume(parser, token_type::TOKEN_VALUES, "VALUES expected");
        parser_consume(parser, token_type::TOKEN_LPAREN, "LPAREN expected");
        do {
            if (parser_check(parser, token_type::TOKEN_NUMBER))
                parser_consume(parser, token_type::TOKEN_NUMBER, "An integer value expected");
            else if (parser_match(parser, token_type::TOKEN_QUOT)) {
                parser_consume(parser, token_type::TOKEN_IDENT, "A char value expected");
                parser_consume(parser, token_type::TOKEN_QUOT, " ' expected");
            }
            else if (parser_check(parser, token_type::TOKEN_IDENT))
                parser_error(parser, " ' expected");
        } while (parser_match(parser, token_type::TOKEN_COMMA));

        parser_consume(parser, token_type::TOKEN_RPAREN, "RPAREN expected");
        return;
    }

    parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
    std::string tab_name(parser->previous.start, parser->previous.length);
    
    if (tab_name != parser->table->table_name) {
        parser_error(parser, "Table does not exist");
       
        return;
    }
    
        parser_consume(parser, token_type::TOKEN_VALUES, "VALUES expected");
        parser_consume(parser, token_type::TOKEN_LPAREN, "LPAREN expected");

        std::vector<std::string> current_values;
        do {
            if (parser_check(parser, token_type::TOKEN_NUMBER))
            {
                parser_consume(parser, token_type::TOKEN_NUMBER, "An integer value expected");
                current_values.push_back(std::string(parser->previous.start, parser->previous.length));
            }
            else if (parser_match(parser, token_type::TOKEN_QUOT)) {
                parser_consume(parser, token_type::TOKEN_IDENT, "A char value expected");
                current_values.push_back(std::string(parser->previous.start, parser->previous.length));
                parser_consume(parser, token_type::TOKEN_QUOT, " ' expected");
            }
            else if (parser_check(parser, token_type::TOKEN_IDENT))
                parser_error(parser, " ' expected");
        } while (parser_match(parser, token_type::TOKEN_COMMA));

        parser_consume(parser, token_type::TOKEN_RPAREN, "RPAREN expected");

        if (current_values.size() != parser->table->column_name.size()) {
            parser_error(parser, "Number of values does not match number of columns");
            return;
        }
        parser->table->values.push_back(current_values);
        DisplayTableInDataGridView(*(parser->table));
    
};

void parser_delete(parser_t* parser) {

    if (parser->table == nullptr)
    {
        parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
        if (parser_match(parser, token_type::TOKEN_WHERE)) {
            do {
                parse_predicate(parser);
            } while (parser_match(parser, token_type::TOKEN_AND));
        }
        return;
    }

    parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
    std::string tab_name(parser->previous.start, parser->previous.length);

    if (tab_name != parser->table->table_name) {
        parser_error(parser, "Table does not exist");
        return;
    }
     // Получение индекса столбца для условия
        parser_consume(parser, token_type::TOKEN_WHERE, "WHERE expected");
        parser_consume(parser, token_type::TOKEN_IDENT, "Column name expected");
        std::string col_name(parser->previous.start, parser->previous.length);
        auto col_it = std::find(parser->table->column_name.begin(), parser->table->column_name.end(), col_name);

        // Проверка существования столбца
        if (col_it == parser->table->column_name.end()) {
            parser_error(parser, "Column does not exist");
            return; // Возвращаемся из функции, если столбец не существует
        }
        size_t col_index = std::distance(parser->table->column_name.begin(), col_it);

        token_type operator_type;
        if (parser_match(parser, token_type::TOKEN_EQUAL)) {
            operator_type = token_type::TOKEN_EQUAL;
        }
        else if (parser_match(parser, token_type::TOKEN_LESS)) {
            operator_type = token_type::TOKEN_LESS;
        }
        else if (parser_match(parser, token_type::TOKEN_GREATER)) {
            operator_type = token_type::TOKEN_GREATER;
        }
        else {
            parser_error(parser, "Unsupported operator. Only =, <, and > are supported for DELETE");
            return;
        }
        std::string value_to_delete;
        int value_to_delete_int = 0;
        bool is_number = false;

        // Определение типа значения для удаления
        if (parser_check(parser, token_type::TOKEN_NUMBER)) {
            parser_consume(parser, token_type::TOKEN_NUMBER, "Numeric value expected");
            value_to_delete_int = std::stoi(parser->previous.start);
            is_number = true;
        }
        else if (parser_check(parser, token_type::TOKEN_IDENT)) {
            parser_consume(parser, token_type::TOKEN_IDENT, "String value expected");
            value_to_delete = std::string(parser->previous.start, parser->previous.length);
        }
        else {
            parser_error(parser, "Value expected");
            return; // Возвращаемся из функции, если значение не предоставлено
        }
        // Удаление строк, соответствующих условию
        auto& rows = parser->table->values;
        rows.erase(std::remove_if(rows.begin(), rows.end(),
            [&](const std::vector<std::string>& row) {
                if (is_number) {
                    int row_value_int = std::stoi(row[col_index]);
                    switch (operator_type) {
                    case token_type::TOKEN_EQUAL:
                        return row_value_int == value_to_delete_int;
                    case token_type::TOKEN_LESS:
                        return row_value_int < value_to_delete_int;
                    case token_type::TOKEN_GREATER:
                        return row_value_int > value_to_delete_int;
                    default:
                        return false;
                    }
                }
                else {
                    // Сравнение строковых значений
                    return row[col_index] == value_to_delete;
                }
            }), rows.end());
        DisplayTableInDataGridView(*(parser->table));
}


static void parser_alter(parser_t* parser)
{
    if (parser->table == nullptr)
    {
        parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
        parser_consume(parser, token_type::TOKEN_ADD, "ADD expected");
        parser_consume(parser, token_type::TOKEN_IDENT, "Column name expected");
        parser_consume(parser, token_type::TOKEN_IDENT, "Datatype of column expected");
        std::string data_type(parser->previous.start, parser->previous.length);
        if (data_type == "varchar") {
            parser_consume(parser, token_type::TOKEN_LPAREN, "LPAREN expected");
            parser_consume(parser, token_type::TOKEN_NUMBER, "Length of varchar expected");
            parser_consume(parser, token_type::TOKEN_RPAREN, "RPAREN expected");
        }
        return;
    }

    parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
    std::string tab_name(parser->previous.start, parser->previous.length);

    if (tab_name != parser->table->table_name)
    {
        parser_error(parser, "Table does not exist");
        return;
    }

    parser_consume(parser, token_type::TOKEN_ADD, "ADD expected");

    do {
        parser_consume(parser, token_type::TOKEN_IDENT, "Column name expected");
        if (check_column_exists(parser))
        {
            parser_error(parser, "Column was exist");
            return;
        }
        std::string col_name(parser->previous.start, parser->previous.length);
        parser->table->column_name.push_back(col_name);

        parser_consume(parser, token_type::TOKEN_IDENT, "Datatype of attribute expected");

        std::string data_type(parser->previous.start, parser->previous.length);
        if (data_type == "varchar") {
            parser_consume(parser, token_type::TOKEN_LPAREN, "LPAREN expected");
            parser_consume(parser, token_type::TOKEN_NUMBER, "Length of varchar expected");
            int length = std::stoi(std::string(parser->previous.start, parser->previous.length));
            parser_consume(parser, token_type::TOKEN_RPAREN, "RPAREN expected");
            data_type = "varchar(" + std::to_string(length) + ")";
        }
        parser->table->data_type.push_back(data_type);

    } while (parser_match(parser, token_type::TOKEN_COMMA));
    DisplayTableInDataGridView(*(parser->table));
};

static void parser_update(parser_t* parser)
{
    if (parser->table == nullptr) {
        parser_consume(parser, token_type::TOKEN_IDENT, "Table name expected");
        //std::string tab_name(parser->previous.start, parser->previous.length);

        //if (parser->table != nullptr && tab_name != parser->table->table_name)
            //parser_error(parser, "Table does not exist");

        if (parser_match(parser, token_type::TOKEN_SET))
            parse_predicate(parser);

        if (parser_match(parser, token_type::TOKEN_WHERE)) {
            do {
                parse_predicate(parser);
            } while (parser_match(parser, token_type::TOKEN_AND));
        }
    }

 
};

static void parse_query(parser_t* parser)
{
    while (!parser_match(parser, token_type::TOKEN_EOS))
    {
        if (parser_match(parser, token_type::TOKEN_SELECT)) {
            
            parser_select(parser);
            if (parser->had_error) break;
        }
        else if (parser_match(parser, token_type::TOKEN_CREATE)) {
            parser_consume(parser, token_type::TOKEN_TABLE, "TABLE expected");
            parser_create_table(parser);
            if (parser->had_error) break;
        }
        else if (parser_match(parser, token_type::TOKEN_INSERT)) {
            parser_consume(parser, token_type::TOKEN_INTO, "INTO expected");
            parser_insert(parser);
            if (parser->had_error) break;
        }
        else if (parser_match(parser, token_type::TOKEN_DELETE)) {
            parser_consume(parser, token_type::TOKEN_FROM, "FROM expected");
            parser_delete(parser);
            if (parser->had_error) break;
        }
        else if (parser_match(parser, token_type::TOKEN_ALTER)) {
            parser_consume(parser, token_type::TOKEN_TABLE, "TABLE expected");
            parser_alter(parser);
            if (parser->had_error) break;
        }
        else if (parser_match(parser, token_type::TOKEN_UPDATE)) {
            parser_update(parser);
            if (parser->had_error) break;
        }
        else
            parser_error(parser, "Operator type unsupported");
            if (parser->had_error) break;

        parser_consume(parser, token_type::TOKEN_SEMICOLON, "Queries should end with a semicolon");
    }
    if (!parser->had_error) 
        ParserForm::richTextBox2->AppendText("SQL query is correct\n");
    if (parser->table != nullptr)
        parser_destroy_table(parser->table);
}

bool parser_parse(parser_t* parser, lexer_t* lexer)
{
    parser->lexer = lexer;
    parser->had_error = false;

    parser_advance(parser);
    while (!parser_match(parser, token_type::TOKEN_EOS)) {
        parse_query(parser);
        if (parser->had_error)
            break;
    }
    return !parser->had_error;
}