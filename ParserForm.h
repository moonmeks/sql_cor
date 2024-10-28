#pragma once
#include "Header.h"
//#include <iostream>
//#include <string>
//#include <Windows.h>

#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

ref class ParserForm : public Form
{
public: static System::Windows::Forms::RichTextBox^ richTextBox2;
public: static System::Windows::Forms::DataGridView^ dataGridView1;



private:
    System::Windows::Forms::Label^ label1;
    System::Windows::Forms::Label^ label2;
    System::Windows::Forms::RichTextBox^ richTextBox1;
    System::Windows::Forms::MenuStrip^ menuStrip1;
    System::Windows::Forms::ToolStripMenuItem^ AboutToolStripMenuItem;
    System::Windows::Forms::ToolStripMenuItem^ sQLÑèíòàêñèñToolStripMenuItem;
    System::Windows::Forms::ToolStripMenuItem^ cREATETABLEToolStripMenuItem;
    System::Windows::Forms::ToolStripMenuItem^ sELECTToolStripMenuItem;
    System::Windows::Forms::ToolStripMenuItem^ iNSERTToolStripMenuItem;
    System::Windows::Forms::ToolStripMenuItem^ uPDATEToolStripMenuItem;
    System::Windows::Forms::ToolStripMenuItem^ dELETEToolStripMenuItem;
    System::Windows::Forms::ToolStripMenuItem^ aLTERTABLEToolStripMenuItem;
    System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::ToolStripMenuItem^ òðåíèðîâêàToolStripMenuItem;
       System::Windows::Forms::Button^ button1;

public:
    ParserForm() {
        InitializeComponent();
        AboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::AboutToolStripMenuItem_Click);
        òðåíèðîâêàToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::òðåíèðîâêàToolStripMenuItem_Click);
        //sQLÑèíòàêñèñToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::sQLÑèíòàêñèñToolStripMenuItem_Click);
    }
private: System::Void InitializeComponent() {
    System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ParserForm::typeid));
    this->label1 = (gcnew System::Windows::Forms::Label());
    this->label2 = (gcnew System::Windows::Forms::Label());
    this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
    this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
    this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
    this->AboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->sQLÑèíòàêñèñToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->cREATETABLEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->sELECTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->iNSERTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->uPDATEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->dELETEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->aLTERTABLEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->òðåíèðîâêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
    this->button1 = (gcnew System::Windows::Forms::Button());
    this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
    this->label3 = (gcnew System::Windows::Forms::Label());
    this->menuStrip1->SuspendLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
    this->SuspendLayout();
    // 
    // label1
    // 
    this->label1->AutoSize = true;
    this->label1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label1->Location = System::Drawing::Point(71, 54);
    this->label1->Name = L"label1";
    this->label1->Size = System::Drawing::Size(298, 24);
    this->label1->TabIndex = 1;
    this->label1->Text = L"Ââîä çàïðîñà";
    // 
    // label2
    // 
    this->label2->AutoSize = true;
    this->label2->Font = (gcnew System::Drawing::Font(L"MS Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label2->Location = System::Drawing::Point(71, 263);
    this->label2->Name = L"label2";
    this->label2->Size = System::Drawing::Size(135, 24);
    this->label2->TabIndex = 2;
    this->label2->Text = L"Âûâîä";
    // 
    // richTextBox1
    // 
    this->richTextBox1->BackColor = System::Drawing::SystemColors::Window;
    this->richTextBox1->Location = System::Drawing::Point(75, 77);
    this->richTextBox1->Name = L"richTextBox1";
    this->richTextBox1->Size = System::Drawing::Size(400, 150);
    this->richTextBox1->TabIndex = 3;
    this->richTextBox1->Text = L"";
    // 
    // richTextBox2
    // 
    this->richTextBox2->BackColor = System::Drawing::SystemColors::Window;
    this->richTextBox2->Location = System::Drawing::Point(75, 286);
    this->richTextBox2->Name = L"richTextBox2";
    this->richTextBox2->Size = System::Drawing::Size(400, 150);
    this->richTextBox2->TabIndex = 4;
    this->richTextBox2->Text = L"";
    // 
    // menuStrip1
    // 
    this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlDark;
    this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
    this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
    this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
        this->AboutToolStripMenuItem,
            this->sQLÑèíòàêñèñToolStripMenuItem, this->òðåíèðîâêàToolStripMenuItem
    });
    this->menuStrip1->Location = System::Drawing::Point(0, 0);
    this->menuStrip1->Name = L"menuStrip1";
    this->menuStrip1->Size = System::Drawing::Size(1049, 33);
    this->menuStrip1->TabIndex = 5;
    this->menuStrip1->Text = L"menuStrip1";
    // 
    // AboutToolStripMenuItem
    // 
    this->AboutToolStripMenuItem->Name = L"AboutToolStripMenuItem";
    this->AboutToolStripMenuItem->Size = System::Drawing::Size(141, 29);
    this->AboutToolStripMenuItem->Text = L"Î ïðîãðàììå";
    // 
    // sQLÑèíòàêñèñToolStripMenuItem
    // 
    this->sQLÑèíòàêñèñToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
        this->cREATETABLEToolStripMenuItem,
            this->sELECTToolStripMenuItem, this->iNSERTToolStripMenuItem, this->uPDATEToolStripMenuItem, this->dELETEToolStripMenuItem, this->aLTERTABLEToolStripMenuItem
    });
    this->sQLÑèíòàêñèñToolStripMenuItem->Name = L"sQLÑèíòàêñèñToolStripMenuItem";
    this->sQLÑèíòàêñèñToolStripMenuItem->Size = System::Drawing::Size(144, 29);
    this->sQLÑèíòàêñèñToolStripMenuItem->Text = L"SQL ñèíòàêñèñ";
    // 
    // cREATETABLEToolStripMenuItem
    // 
    this->cREATETABLEToolStripMenuItem->Name = L"cREATETABLEToolStripMenuItem";
    this->cREATETABLEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
    this->cREATETABLEToolStripMenuItem->Text = L"CREATE TABLE";
    this->cREATETABLEToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::cREATETABLEToolStripMenuItem_Click);
    // 
    // sELECTToolStripMenuItem
    // 
    this->sELECTToolStripMenuItem->Name = L"sELECTToolStripMenuItem";
    this->sELECTToolStripMenuItem->Size = System::Drawing::Size(226, 34);
    this->sELECTToolStripMenuItem->Text = L"SELECT";
    this->sELECTToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::sELECTToolStripMenuItem_Click);
    // 
    // iNSERTToolStripMenuItem
    // 
    this->iNSERTToolStripMenuItem->Name = L"iNSERTToolStripMenuItem";
    this->iNSERTToolStripMenuItem->Size = System::Drawing::Size(226, 34);
    this->iNSERTToolStripMenuItem->Text = L"INSERT";
    this->iNSERTToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::iNSERTToolStripMenuItem_Click);
    // 
    // uPDATEToolStripMenuItem
    // 
    this->uPDATEToolStripMenuItem->Name = L"uPDATEToolStripMenuItem";
    this->uPDATEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
    this->uPDATEToolStripMenuItem->Text = L"UPDATE";
    this->uPDATEToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::uPDATEToolStripMenuItem_Click);
    // 
    // dELETEToolStripMenuItem
    // 
    this->dELETEToolStripMenuItem->Name = L"dELETEToolStripMenuItem";
    this->dELETEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
    this->dELETEToolStripMenuItem->Text = L"DELETE";
    this->dELETEToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::dELETEToolStripMenuItem_Click);
    // 
    // aLTERTABLEToolStripMenuItem
    // 
    this->aLTERTABLEToolStripMenuItem->Name = L"aLTERTABLEToolStripMenuItem";
    this->aLTERTABLEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
    this->aLTERTABLEToolStripMenuItem->Text = L"ALTER TABLE";
    this->aLTERTABLEToolStripMenuItem->Click += gcnew System::EventHandler(this, &ParserForm::aLTERTABLEToolStripMenuItem_Click);
    // 
    // òðåíèðîâêàToolStripMenuItem
    // 
    this->òðåíèðîâêàToolStripMenuItem->Name = L"òðåíèðîâêàToolStripMenuItem";
    this->òðåíèðîâêàToolStripMenuItem->Size = System::Drawing::Size(105, 29);
    this->òðåíèðîâêàToolStripMenuItem->Text = L"Ïðàêòèêà";
    // 
    // button1
    // 
    this->button1->BackColor = System::Drawing::SystemColors::ButtonShadow;
    this->button1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
    this->button1->Location = System::Drawing::Point(134, 461);
    this->button1->Name = L"button1";
    this->button1->Size = System::Drawing::Size(268, 40);
    this->button1->TabIndex = 6;
    this->button1->Text = L"Ïðîâåðèòü";
    this->button1->UseVisualStyleBackColor = false;
    this->button1->Click += gcnew System::EventHandler(this, &ParserForm::button1_Click);
    // 
    // dataGridView1
    // 
    this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
    this->dataGridView1->Location = System::Drawing::Point(545, 77);
    this->dataGridView1->Name = L"dataGridView1";
    this->dataGridView1->RowHeadersWidth = 62;
    this->dataGridView1->RowTemplate->Height = 28;
    this->dataGridView1->Size = System::Drawing::Size(438, 210);
    this->dataGridView1->TabIndex = 7;
    // 
    // label3
    // 
    this->label3->AutoSize = true;
    this->label3->Font = (gcnew System::Drawing::Font(L"MS Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
    this->label3->Location = System::Drawing::Point(541, 50);
    this->label3->Name = L"label3";
    this->label3->Size = System::Drawing::Size(185, 24);
    this->label3->TabIndex = 8;
    this->label3->Text = L"Òàáëèöà";
    // 
    // ParserForm
    // 
    this->BackColor = System::Drawing::SystemColors::ControlLight;
    this->ClientSize = System::Drawing::Size(1049, 557);
    this->Controls->Add(this->label3);
    this->Controls->Add(this->dataGridView1);
    this->Controls->Add(this->button1);
    this->Controls->Add(this->richTextBox2);
    this->Controls->Add(this->richTextBox1);
    this->Controls->Add(this->label2);
    this->Controls->Add(this->label1);
    this->Controls->Add(this->menuStrip1);
    this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
    this->MainMenuStrip = this->menuStrip1;
    this->Name = L"ParserForm";
    this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    this->menuStrip1->ResumeLayout(false);
    this->menuStrip1->PerformLayout();
    (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
    this->ResumeLayout(false);
    this->PerformLayout();

}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void AboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void cREATETABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void sELECTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void iNSERTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void uPDATEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void dELETEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void aLTERTABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void òðåíèðîâêàToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void ctor() {
    this->InitializeComponent();
}

};