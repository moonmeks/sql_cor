#include "PracticeForm.h"
#include "TableForm.h"
#include <Windows.h>
#include <string>
#include <regex>
#include <msclr/marshal_cppstd.h>

System::Void Parser::PracticeForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = richTextBox1->Text;

    std::regex pattern ("CREATE TABLE Class \\(surname varchar\\(20\\), subject varchar\\(20\\), grade int\\);");
    std::string strInput = msclr::interop::marshal_as<std::string>(input);

    bool isValid = std::regex_match(strInput, pattern);

    if(isValid)
    {
        MessageBox::Show("������ ������� ���������");
    }
    else
    {
        MessageBox::Show("������! ������ ������� �����������");
    }
}


System::Void Parser::PracticeForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = richTextBox2->Text;

    std::regex pattern("INSERT INTO Class VALUES \\('������','����������',5\\);");
    std::string strInput = msclr::interop::marshal_as<std::string>(input);

    bool isValid = std::regex_match(strInput, pattern);

    if (isValid)
    {
        MessageBox::Show("������ ������� ���������");
    }
    else
    {
        MessageBox::Show("������! ������ ������� �����������");
    }
}

System::Void Parser::PracticeForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = richTextBox3->Text;

    std::regex pattern("SELECT surname WHERE grade=5;");
    std::string strInput = msclr::interop::marshal_as<std::string>(input);

    bool isValid = std::regex_match(strInput, pattern);

    if (isValid)
    {
        MessageBox::Show("������ ������� ���������");
    }
    else
    {
        MessageBox::Show("������! ������ ������� �����������");
    }
}

System::Void Parser::PracticeForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = richTextBox4->Text;

    std::regex pattern("DELETE FROM CLass WHERE grade=3;");
    std::string strInput = msclr::interop::marshal_as<std::string>(input);

    bool isValid = std::regex_match(strInput, pattern);

    if (isValid)
    {
        MessageBox::Show("������ ������� ���������");
    }
    else
    {
        MessageBox::Show("������! ������ ������� �����������");
    }
}

System::Void Parser::PracticeForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = richTextBox5->Text;

    std::regex pattern("ALTER TABLE");
    std::string strInput = msclr::interop::marshal_as<std::string>(input);

    bool isValid = std::regex_match(strInput, pattern);

    if (isValid)
    {
        MessageBox::Show("������ ������� ���������");
    }
    else
    {
        MessageBox::Show("������! ������ ������� �����������");
    }
}

System::Void Parser::PracticeForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = richTextBox6->Text;

    std::regex pattern("UPDATE");
    std::string strInput = msclr::interop::marshal_as<std::string>(input);

    bool isValid = std::regex_match(strInput, pattern);

    if (isValid)
    {
        MessageBox::Show("������ ������� ���������");
    }
    else
    {
        MessageBox::Show("������! ������ ������� �����������");
    }
}

System::Void Parser::PracticeForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "�������� ������ ��� �������� ������� Class, ������� ������� � ������� �������, ������� � ���������� ����� ������ ������� ������� 20";
    MessageBox::Show(message, L"������� � CREATE TABLE");
}

System::Void Parser::PracticeForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "�������� ������ ��� ���������� ������ ������ ������ �� ������� ������� � ������� Class";
    MessageBox::Show(message, L"������� � INSERT");
}

System::Void Parser::PracticeForm::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "�������� ������ ��� ������� �� ������� CLass ���� ������� ��������, ������� �������� 5";
    MessageBox::Show(message, L"������� � SELECT");
}

System::Void Parser::PracticeForm::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "�������� ������ ��� �������� ������ �� ������� CLass, � ������� ����� ������ 3";
    MessageBox::Show(message, L"������� � DELETE");
}

System::Void Parser::PracticeForm::button11_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "�������� ������ ��� ���������� ������� id � �������";
    MessageBox::Show(message, L"������� � ALTER TABLE");
}

System::Void Parser::PracticeForm::button12_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "�������� ������ ��� ���������� ������ c ����� �������� id � ������� Class";
    MessageBox::Show(message, L"������� � UPDATE");
}

System::Void Parser::PracticeForm::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    TableForm^ TableForm = gcnew Parser::TableForm();
    TableForm->Show();
}

System::Void Parser::PracticeForm::cREATETABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "CREATE TABLE table_name (col1 datatype, col2 datatype, col3 datatype);\n\n������ ������ ������� � ���� ������.\n\n�������� ���� ������:\nINT � ����� �����;\nDATETIME � ����;\nVARCHAR � ������;\nFLOAT � ���������� �����.";
    MessageBox::Show(message, L"��������� CREATE TABLE");
}

System::Void Parser::PracticeForm::iNSERTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "INSERT INTO table_name (col1, col2, col3) VALUES (1, 'word', 5);\n\n������ ��� ���������� ����� ������ � �������";
    MessageBox::Show(message, L"��������� INSERT");
}

System::Void Parser::PracticeForm::sELECTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "SELECT col1 FROM table_name WHERE col2 > 20 GROUP BY col3 HAVING col1 > 1000 ORDER BY col2 DESC;\n\nSELECT � �������� ��������� ������� ��� ��� ������� �������;\nFROM � �� ����� ������� �������� ������\nWHERE � �������, �� �������� SQL �������� ������;\nGROUP BY � �������, �� �������� �� ����� �������������� ������;\nHAVING � �������, �� �������� ��������������� ������ ����� �������������;\nORDER BY � �������, �� �������� ������ ����� �������������;\n\n������������� �������� ������ SELECT � FROM";
    MessageBox::Show(message, L"��������� SELECT");
}

System::Void Parser::PracticeForm::dELETEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "DELETE FROM table_name WHERE col1 = 1;\n\n������ ��� �������� �����";
    MessageBox::Show(message, L"��������� DELETE");
}

System::Void Parser::PracticeForm::aLTERTABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "ALTER TABLE table_name ADD new_col datatype;\n\n������ ��� ���������� ����� �������� � �������";
    MessageBox::Show(message, L"��������� ALTER TABLE");
}

System::Void Parser::PracticeForm::uPDATEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "UPDATE table_name SET col2='new word';\n\n������ ��� ��������� ������ � �������";
    MessageBox::Show(message, L"��������� UPDATE");
}
