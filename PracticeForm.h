#pragma once

namespace Parser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для PracticeForm
	/// </summary>
	public ref class PracticeForm : public System::Windows::Forms::Form
	{
	public:
		PracticeForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~PracticeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::GroupBox^ groupBox3;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RichTextBox^ richTextBox3;
	private: System::Windows::Forms::GroupBox^ groupBox4;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::RichTextBox^ richTextBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::RichTextBox^ richTextBox5;
	private: System::Windows::Forms::GroupBox^ groupBox6;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::RichTextBox^ richTextBox6;
	private: System::Windows::Forms::HelpProvider^ helpProvider1;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ таблицаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ синтаксисSQLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cREATETABLEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ iNSERTToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ sELECTToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dELETEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aLTERTABLEToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ uPDATEToolStripMenuItem;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->таблицаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->синтаксисSQLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cREATETABLEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->iNSERTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sELECTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dELETEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aLTERTABLEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uPDATEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(1057, 42);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(189, 36);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Проверить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &PracticeForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(165, 42);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(885, 36);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(12, 41);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(1262, 83);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"запрос CREATE TABLE";
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button7->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(0, 42);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(145, 36);
			this->button7->TabIndex = 3;
			this->button7->Text = L"Задание";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &PracticeForm::button7_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->button8);
			this->groupBox2->Controls->Add(this->richTextBox2);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(12, 140);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1262, 82);
			this->groupBox2->TabIndex = 4;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"запрос INSERT";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button2->Location = System::Drawing::Point(1057, 40);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(189, 36);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Проверить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &PracticeForm::button2_Click);
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button8->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button8->Location = System::Drawing::Point(0, 40);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(145, 36);
			this->button8->TabIndex = 9;
			this->button8->Text = L"Задание";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &PracticeForm::button8_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(167, 40);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(885, 36);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->richTextBox3);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->Location = System::Drawing::Point(12, 228);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(1262, 102);
			this->groupBox3->TabIndex = 5;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"запрос SELECT";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button3->Location = System::Drawing::Point(1057, 52);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(189, 36);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Проверить";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &PracticeForm::button3_Click);
			// 
			// richTextBox3
			// 
			this->richTextBox3->Location = System::Drawing::Point(165, 52);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(886, 36);
			this->richTextBox3->TabIndex = 2;
			this->richTextBox3->Text = L"";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Controls->Add(this->richTextBox4);
			this->groupBox4->Controls->Add(this->button10);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox4->Location = System::Drawing::Point(12, 336);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(1262, 102);
			this->groupBox4->TabIndex = 6;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"запрос DELETE";
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button4->Location = System::Drawing::Point(1057, 48);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(189, 39);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Проверить";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &PracticeForm::button4_Click);
			// 
			// richTextBox4
			// 
			this->richTextBox4->Location = System::Drawing::Point(166, 48);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->Size = System::Drawing::Size(886, 36);
			this->richTextBox4->TabIndex = 2;
			this->richTextBox4->Text = L"";
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button10->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button10->Location = System::Drawing::Point(0, 48);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(145, 36);
			this->button10->TabIndex = 11;
			this->button10->Text = L"Задание";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &PracticeForm::button10_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button11);
			this->groupBox5->Controls->Add(this->button5);
			this->groupBox5->Controls->Add(this->richTextBox5);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox5->Location = System::Drawing::Point(12, 444);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(1262, 102);
			this->groupBox5->TabIndex = 7;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"запрос ALTER TABLE";
			// 
			// button11
			// 
			this->button11->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button11->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button11->Location = System::Drawing::Point(0, 40);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(145, 36);
			this->button11->TabIndex = 12;
			this->button11->Text = L"Задание";
			this->button11->UseVisualStyleBackColor = false;
			this->button11->Click += gcnew System::EventHandler(this, &PracticeForm::button11_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button5->Location = System::Drawing::Point(1058, 40);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(189, 36);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Проверить";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &PracticeForm::button5_Click);
			// 
			// richTextBox5
			// 
			this->richTextBox5->Location = System::Drawing::Point(165, 40);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->Size = System::Drawing::Size(885, 36);
			this->richTextBox5->TabIndex = 2;
			this->richTextBox5->Text = L"";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->button12);
			this->groupBox6->Controls->Add(this->button6);
			this->groupBox6->Controls->Add(this->richTextBox6);
			this->groupBox6->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox6->Location = System::Drawing::Point(12, 552);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(1262, 92);
			this->groupBox6->TabIndex = 8;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"запрос UPDATE";
			// 
			// button12
			// 
			this->button12->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button12->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button12->Location = System::Drawing::Point(0, 41);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(145, 36);
			this->button12->TabIndex = 13;
			this->button12->Text = L"Задание";
			this->button12->UseVisualStyleBackColor = false;
			this->button12->Click += gcnew System::EventHandler(this, &PracticeForm::button12_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button6->Location = System::Drawing::Point(1058, 41);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(189, 36);
			this->button6->TabIndex = 0;
			this->button6->Text = L"Проверить";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &PracticeForm::button6_Click);
			// 
			// richTextBox6
			// 
			this->richTextBox6->Location = System::Drawing::Point(165, 41);
			this->richTextBox6->Name = L"richTextBox6";
			this->richTextBox6->Size = System::Drawing::Size(884, 36);
			this->richTextBox6->TabIndex = 2;
			this->richTextBox6->Text = L"";
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button9->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button9->Location = System::Drawing::Point(12, 280);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(145, 36);
			this->button9->TabIndex = 10;
			this->button9->Text = L"Задание";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &PracticeForm::button9_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->таблицаToolStripMenuItem,
					this->синтаксисSQLToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1293, 26);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// таблицаToolStripMenuItem
			// 
			this->таблицаToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->таблицаToolStripMenuItem->Name = L"таблицаToolStripMenuItem";
			this->таблицаToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->таблицаToolStripMenuItem->Text = L"Таблица";
			this->таблицаToolStripMenuItem->Click += gcnew System::EventHandler(this, &PracticeForm::таблицаToolStripMenuItem_Click);
			// 
			// синтаксисSQLToolStripMenuItem
			// 
			this->синтаксисSQLToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->cREATETABLEToolStripMenuItem,
					this->iNSERTToolStripMenuItem, this->sELECTToolStripMenuItem, this->dELETEToolStripMenuItem, this->aLTERTABLEToolStripMenuItem,
					this->uPDATEToolStripMenuItem
			});
			this->синтаксисSQLToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->синтаксисSQLToolStripMenuItem->Name = L"синтаксисSQLToolStripMenuItem";
			this->синтаксисSQLToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->синтаксисSQLToolStripMenuItem->Text = L"Синтаксис SQL ";
			// 
			// cREATETABLEToolStripMenuItem
			// 
			this->cREATETABLEToolStripMenuItem->Name = L"cREATETABLEToolStripMenuItem";
			this->cREATETABLEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
			this->cREATETABLEToolStripMenuItem->Text = L"CREATE TABLE";
			this->cREATETABLEToolStripMenuItem->Click += gcnew System::EventHandler(this, &PracticeForm::cREATETABLEToolStripMenuItem_Click);
			// 
			// iNSERTToolStripMenuItem
			// 
			this->iNSERTToolStripMenuItem->Name = L"iNSERTToolStripMenuItem";
			this->iNSERTToolStripMenuItem->Size = System::Drawing::Size(226, 34);
			this->iNSERTToolStripMenuItem->Text = L"INSERT";
			this->iNSERTToolStripMenuItem->Click += gcnew System::EventHandler(this, &PracticeForm::iNSERTToolStripMenuItem_Click);
			// 
			// sELECTToolStripMenuItem
			// 
			this->sELECTToolStripMenuItem->Name = L"sELECTToolStripMenuItem";
			this->sELECTToolStripMenuItem->Size = System::Drawing::Size(226, 34);
			this->sELECTToolStripMenuItem->Text = L"SELECT";
			this->sELECTToolStripMenuItem->Click += gcnew System::EventHandler(this, &PracticeForm::sELECTToolStripMenuItem_Click);
			// 
			// dELETEToolStripMenuItem
			// 
			this->dELETEToolStripMenuItem->Name = L"dELETEToolStripMenuItem";
			this->dELETEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
			this->dELETEToolStripMenuItem->Text = L"DELETE";
			this->dELETEToolStripMenuItem->Click += gcnew System::EventHandler(this, &PracticeForm::dELETEToolStripMenuItem_Click);
			// 
			// aLTERTABLEToolStripMenuItem
			// 
			this->aLTERTABLEToolStripMenuItem->Name = L"aLTERTABLEToolStripMenuItem";
			this->aLTERTABLEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
			this->aLTERTABLEToolStripMenuItem->Text = L"ALTER TABLE";
			this->aLTERTABLEToolStripMenuItem->Click += gcnew System::EventHandler(this, &PracticeForm::aLTERTABLEToolStripMenuItem_Click);
			// 
			// uPDATEToolStripMenuItem
			// 
			this->uPDATEToolStripMenuItem->Name = L"uPDATEToolStripMenuItem";
			this->uPDATEToolStripMenuItem->Size = System::Drawing::Size(226, 34);
			this->uPDATEToolStripMenuItem->Text = L"UPDATE";
			this->uPDATEToolStripMenuItem->Click += gcnew System::EventHandler(this, &PracticeForm::uPDATEToolStripMenuItem_Click);
			// 
			// PracticeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(1293, 662);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"PracticeForm";
			this->Text = L"Практика";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			this->groupBox6->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void таблицаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void cREATETABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void iNSERTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void sELECTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void dELETEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void aLTERTABLEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void uPDATEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
};
}
