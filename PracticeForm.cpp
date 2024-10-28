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
        MessageBox::Show("Запрос написан правильно");
    }
    else
    {
        MessageBox::Show("ОШИБКА! Запрос написан неправильно");
    }
}


System::Void Parser::PracticeForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ input = richTextBox2->Text;

    std::regex pattern("INSERT INTO Class VALUES \\('Иванов','Математика',5\\);");
    std::string strInput = msclr::interop::marshal_as<std::string>(input);

    bool isValid = std::regex_match(strInput, pattern);

    if (isValid)
    {
        MessageBox::Show("Запрос написан правильно");
    }
    else
    {
        MessageBox::Show("ОШИБКА! Запрос написан неправильно");
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
        MessageBox::Show("Запрос написан правильно");
    }
    else
    {
        MessageBox::Show("ОШИБКА! Запрос написан неправильно");
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
        MessageBox::Show("Запрос написан правильно");
    }
    else
    {
        MessageBox::Show("ОШИБКА! Запрос написан неправильно");
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
        MessageBox::Show("Запрос написан правильно");
    }
    else
    {
        MessageBox::Show("ОШИБКА! Запрос написан неправильно");
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
        MessageBox::Show("Запрос написан правильно");
    }
    else
    {
        MessageBox::Show("ОШИБКА! Запрос написан неправильно");
    }
}

System::Void Parser::PracticeForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "Напишите запрос для создания таблицы Class, которая указана в разделе Таблица, столбцы с символьным типом данных указать длинной 20";
    MessageBox::Show(message, L"Задание с CREATE TABLE");
}

System::Void Parser::PracticeForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "Напишите запрос для добавления первой строки данных из примера Таблица в таблицу Class";
    MessageBox::Show(message, L"Задание с INSERT");
}

System::Void Parser::PracticeForm::button9_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "Напишите запрос для выборки из таблицы CLass всех фамилий учеников, которые получили 5";
    MessageBox::Show(message, L"Задание с SELECT");
}

System::Void Parser::PracticeForm::button10_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "Напишите запрос для удаления строки из таблицы CLass, в которой стоит оценка 3";
    MessageBox::Show(message, L"Задание с DELETE");
}

System::Void Parser::PracticeForm::button11_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "Напишите запрос для добавления столбца id в таблицу";
    MessageBox::Show(message, L"Задание с ALTER TABLE");
}

System::Void Parser::PracticeForm::button12_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "Напишите запрос для обновления данных c новым столбцом id в таблице Class";
    MessageBox::Show(message, L"Задание с UPDATE");
}

System::Void Parser::PracticeForm::таблицаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    TableForm^ TableForm = gcnew Parser::TableForm();
    TableForm->Show();
}

System::Void Parser::PracticeForm::cREATETABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "CREATE TABLE table_name (col1 datatype, col2 datatype, col3 datatype);\n\nЗапрос создаёт таблицу в базе данных.\n\nОсновные типы данных:\nINT — целое число;\nDATETIME — дата;\nVARCHAR — строка;\nFLOAT — десятичное число.";
    MessageBox::Show(message, L"Синтаксис CREATE TABLE");
}

System::Void Parser::PracticeForm::iNSERTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "INSERT INTO table_name (col1, col2, col3) VALUES (1, 'word', 5);\n\nЗапрос для добавления новой строки в таблицу";
    MessageBox::Show(message, L"Синтаксис INSERT");
}

System::Void Parser::PracticeForm::sELECTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "SELECT col1 FROM table_name WHERE col2 > 20 GROUP BY col3 HAVING col1 > 1000 ORDER BY col2 DESC;\n\nSELECT — выбирает отдельные столбцы или всю таблицу целиком;\nFROM — из какой таблицы получить данные\nWHERE — условие, по которому SQL выбирает данные;\nGROUP BY — столбец, по которому мы будут группироваться данные;\nHAVING — условие, по которому сгруппированные данные будут отфильтрованы;\nORDER BY — столбец, по которому данные будут отсортированы;\n\nОбязательными являются только SELECT и FROM";
    MessageBox::Show(message, L"Синтаксис SELECT");
}

System::Void Parser::PracticeForm::dELETEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "DELETE FROM table_name WHERE col1 = 1;\n\nЗапрос для удаления строк";
    MessageBox::Show(message, L"Синтаксис DELETE");
}

System::Void Parser::PracticeForm::aLTERTABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "ALTER TABLE table_name ADD new_col datatype;\n\nЗапрос для добавления новых столбцов в таблицу";
    MessageBox::Show(message, L"Синтаксис ALTER TABLE");
}

System::Void Parser::PracticeForm::uPDATEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ message = "UPDATE table_name SET col2='new word';\n\nЗапрос для изменения данных в таблице";
    MessageBox::Show(message, L"Синтаксис UPDATE");
}
