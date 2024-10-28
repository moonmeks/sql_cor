#pragma once

#include "ParserForm.h"

#include "AboutForm.h"
#include "PracticeForm.h"
#include "Header.h"

using namespace Parser;

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;

[STAThread]

int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
  
    ParserForm^ form = gcnew ParserForm();
    Application::Run(form);

    return 0;
}

System::Void ParserForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

    String^ input = richTextBox1->Text;

    const char* strInput = (const char*)(Marshal::StringToHGlobalAnsi(input)).ToPointer();
    ParserForm::richTextBox2 = richTextBox2;
    ParserForm::dataGridView1 = dataGridView1;
    lexer_t* lexer = lexer_create(strInput);
    parser_t* parser = parser_create();

    bool result = parser_parse(parser, lexer);

    lexer_destroy(lexer);
    parser_destroy(parser);
}

System::Void ParserForm::AboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{   
    AboutForm^ AboutForm = gcnew Parser::AboutForm();
    AboutForm->Show();
}

System::Void ParserForm::cREATETABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "CREATE TABLE table_name (col1 datatype, col2 datatype, col3 datatype);\n\n«апрос создаЄт таблицу в базе данных.\n\nќсновные типы данных:\nINT Ч целое число;\nDATETIME Ч дата;\nVARCHAR Ч строка;\nFLOAT Ч дес€тичное число.";
    MessageBox::Show(message, L"—интаксис CREATE TABLE");
}

System::Void ParserForm::sELECTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "SELECT col1 FROM table_name WHERE col2 > 20 GROUP BY col3 HAVING col1 > 1000 ORDER BY col2 DESC;\n\nSELECT Ч выбирает отдельные столбцы или всю таблицу целиком;\nFROM Ч из какой таблицы получить данные\nWHERE Ч условие, по которому SQL выбирает данные;\nGROUP BY Ч столбец, по которому мы будут группироватьс€ данные;\nHAVING Ч условие, по которому сгруппированные данные будут отфильтрованы;\nORDER BY Ч столбец, по которому данные будут отсортированы;\n\nќб€зательными €вл€ютс€ только SELECT и FROM";
    MessageBox::Show(message, L"—интаксис SELECT");
}

System::Void ParserForm::iNSERTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "INSERT INTO table_name (col1, col2, col3) VALUES (1, 'word', 5);\n\n«апрос дл€ добавлени€ новой строки в таблицу";
    MessageBox::Show(message, L"—интаксис INSERT");
}

System::Void ParserForm::uPDATEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "UPDATE table_name SET col2='new word';\n\n«апрос дл€ изменени€ данных в таблице";
    MessageBox::Show(message, L"—интаксис UPDATE");
}

System::Void ParserForm::dELETEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "DELETE FROM table_name WHERE col1 = 1;\n\n«апрос дл€ удалени€ строк";
    MessageBox::Show(message, L"—интаксис DELETE");
}

System::Void ParserForm::aLTERTABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "ALTER TABLE table_name ADD new_col datatype;\n\n«апрос дл€ добавлени€ новых столбцов в таблицу";
    MessageBox::Show(message, L"—интаксис ALTER TABLE");
}

System::Void ParserForm::тренировкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    PracticeForm^ PracticeForm = gcnew Parser::PracticeForm();
    PracticeForm->Show();
}
