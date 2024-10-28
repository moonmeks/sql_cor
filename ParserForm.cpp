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
    String^ message = "CREATE TABLE table_name (col1 datatype, col2 datatype, col3 datatype);\n\n������ ������ ������� � ���� ������.\n\n�������� ���� ������:\nINT � ����� �����;\nDATETIME � ����;\nVARCHAR � ������;\nFLOAT � ���������� �����.";
    MessageBox::Show(message, L"��������� CREATE TABLE");
}

System::Void ParserForm::sELECTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "SELECT col1 FROM table_name WHERE col2 > 20 GROUP BY col3 HAVING col1 > 1000 ORDER BY col2 DESC;\n\nSELECT � �������� ��������� ������� ��� ��� ������� �������;\nFROM � �� ����� ������� �������� ������\nWHERE � �������, �� �������� SQL �������� ������;\nGROUP BY � �������, �� �������� �� ����� �������������� ������;\nHAVING � �������, �� �������� ��������������� ������ ����� �������������;\nORDER BY � �������, �� �������� ������ ����� �������������;\n\n������������� �������� ������ SELECT � FROM";
    MessageBox::Show(message, L"��������� SELECT");
}

System::Void ParserForm::iNSERTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "INSERT INTO table_name (col1, col2, col3) VALUES (1, 'word', 5);\n\n������ ��� ���������� ����� ������ � �������";
    MessageBox::Show(message, L"��������� INSERT");
}

System::Void ParserForm::uPDATEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "UPDATE table_name SET col2='new word';\n\n������ ��� ��������� ������ � �������";
    MessageBox::Show(message, L"��������� UPDATE");
}

System::Void ParserForm::dELETEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "DELETE FROM table_name WHERE col1 = 1;\n\n������ ��� �������� �����";
    MessageBox::Show(message, L"��������� DELETE");
}

System::Void ParserForm::aLTERTABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "ALTER TABLE table_name ADD new_col datatype;\n\n������ ��� ���������� ����� �������� � �������";
    MessageBox::Show(message, L"��������� ALTER TABLE");
}

System::Void ParserForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    PracticeForm^ PracticeForm = gcnew Parser::PracticeForm();
    PracticeForm->Show();
}
