#pragma once
#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <winsqlite/winsqlite3.h>

#include "./table/table.hpp"
#include "./time/time.hpp"
#include "./client/client.hpp"
#include "converter.h"
#include "type_operation.h"
#include "local_save.h"
#include "theme.h"
#include "lang.h"
#include "inputTimeWork.h"
#include "inputPrice.h"
#include "help.h"
#include "logup.h"
#include "login.h"

namespace computerClub {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::SQLite;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			save = new Save("Save\\local_save.txt");
			last_time = new Time(save->TimeStart());
			end_time = new Time(save->TimeEnd());
			price = save->Price();
			type_operation = TypeOperation::CAME;
			set_theme();
			InitializeComponent();
			updateWindow();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			delete last_time;
			delete end_time;
			delete theme;
			delete save;
			delete lang;
			if (components)
			{
				delete components;
			}
			end_time = nullptr;
			last_time = nullptr;
			theme = nullptr;
			save = nullptr;
			lang = nullptr;
		}
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ operationType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ computer;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ToolStripMenuItem^ ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������ToolStripMenuItem;
	private: System::Windows::Forms::Button^ button2;
	private: Time* last_time;
	private: Time* end_time;
	private: TypeOperation type_operation;
	private: Theme* theme;
	private: Lang* lang;
	private: Save* save;
	private: int price;
		   /// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void set_theme()
		{
			theme = new Theme(save->Theme());
			lang = new Lang(save->Lang());
		}
		void updateWindow()
		{
			this->textBox2->Text = Conv::ToSystemString(save->Name());
			this->�������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->����ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->���������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->���ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			
			this->�������������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->��������������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->���������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->�����ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->�����������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->����ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->��������������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->����������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->����������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->�������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->�����������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->�������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->����������ToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->button1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->Border()));
			this->button2->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->Border()));
			
			this->label1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->textBox1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->label2->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->textBox3->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->label3->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->textBox4->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->label4->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->label6->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->comboBox1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->label5->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->textBox2->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			
			this->����ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->���������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->���ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->�������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->menuStrip1->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			
			this->�������������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->��������������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->���������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->�����ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->�����������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->����ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->��������������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->����������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->����������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->�������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->�����������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->�������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->����������ToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));

			this->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			
			this->textBox1->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextBackGround()));
			this->textBox3->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextBackGround()));
			this->textBox4->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextBackGround()));
			this->textBox2->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextBackGround()));
			this->comboBox1->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextBackGround()));
			
			if (save->Lang() != "Save\\rus_Rus.txt")
			{
				this->time->HeaderText = Conv::ToSystemString(lang->data_time);
				this->operationType->HeaderText = Conv::ToSystemString(lang->data_type);
				this->client->HeaderText = Conv::ToSystemString(lang->data_client);
				this->computer->HeaderText = Conv::ToSystemString(lang->data_computer);

				this->����ToolStripMenuItem->Text = Conv::ToSystemString(lang->file);
				this->�������������ToolStripMenuItem->Text = Conv::ToSystemString(lang->imp);
				this->��������������ToolStripMenuItem->Text = Conv::ToSystemString(lang->exp);
				this->���������ToolStripMenuItem->Text = Conv::ToSystemString(lang->save);
				this->�����ToolStripMenuItem->Text = Conv::ToSystemString(lang->report);
				this->���������ToolStripMenuItem->Text = Conv::ToSystemString(lang->settings);
				this->�����������ToolStripMenuItem->Text = Conv::ToSystemString(lang->work_time);
				this->����ToolStripMenuItem->Text = Conv::ToSystemString(lang->price);
				this->��������������ToolStripMenuItem->Text = Conv::ToSystemString(lang->change);
				this->����������ToolStripMenuItem->Text = Conv::ToSystemString(lang->login);
				this->���ToolStripMenuItem->Text = Conv::ToSystemString(lang->view);
				this->����������ToolStripMenuItem->Text = Conv::ToSystemString(lang->theme);
				this->�������ToolStripMenuItem->Text = Conv::ToSystemString(lang->light);
				this->������ToolStripMenuItem->Text = Conv::ToSystemString(lang->dark);
				this->�����������ToolStripMenuItem->Text = Conv::ToSystemString(lang->lang);
				this->�������ToolStripMenuItem->Text = Conv::ToSystemString(lang->rus);
				this->����������ToolStripMenuItem->Text = Conv::ToSystemString(lang->eng);
				this->�������ToolStripMenuItem->Text = Conv::ToSystemString(lang->help);

				this->button1->Text = Conv::ToSystemString(lang->add);
				this->label1->Text = Conv::ToSystemString(lang->time);
				this->label2->Text = Conv::ToSystemString(lang->type);
				this->label3->Text = Conv::ToSystemString(lang->client);
				this->label4->Text = Conv::ToSystemString(lang->computer);
				this->comboBox1->Text = Conv::ToSystemString(lang->CAME);
				this->label5->Text = Conv::ToSystemString(lang->date);
				this->label6->Text = Conv::ToSystemString(lang->user);
				this->button2->Text = Conv::ToSystemString(lang->finish);

				this->comboBox1->Items->Clear();
				this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
					Conv::ToSystemString(lang->CAME),
						Conv::ToSystemString(lang->WAIT),
						Conv::ToSystemString(lang->SIT),
						Conv::ToSystemString(lang->LEAVE)
				});
			}
			else
			{
				SetRus();
			}
		}
		void SetRus()
		{
			this->time->HeaderText = % String("�����");
			this->operationType->HeaderText = % String("���");
			this->client->HeaderText = % String("������");
			this->computer->HeaderText = % String("���������");
			this->����ToolStripMenuItem->Text = % String("����");
			this->�������������ToolStripMenuItem->Text = % String("�������������");
			this->��������������ToolStripMenuItem->Text = % String("��������������");
			this->���������ToolStripMenuItem->Text = % String("���������");
			this->�����ToolStripMenuItem->Text = % String("�����");
			this->���������ToolStripMenuItem->Text = % String("���������");
			this->�����������ToolStripMenuItem->Text = % String("����� ������");
			this->����ToolStripMenuItem->Text = % String("����");
			this->��������������ToolStripMenuItem->Text = % String("������� �������");
			this->����������ToolStripMenuItem->Text = % String("�����������");
			this->���ToolStripMenuItem->Text = % String("���");
			this->����������ToolStripMenuItem->Text = % String("����");
			this->�������ToolStripMenuItem->Text = % String("�������");
			this->������ToolStripMenuItem->Text = % String("������");
			this->�����������ToolStripMenuItem->Text = % String("����");
			this->�������ToolStripMenuItem->Text = % String("�������");
			this->����������ToolStripMenuItem->Text = % String("����������");
			this->�������ToolStripMenuItem->Text = % String("�������");
			this->button1->Text = % String("�������� ������");
			this->label1->Text = % String("�����");
			this->label2->Text = % String("���");
			this->label3->Text = % String("������");
			this->label4->Text = % String("���������");
			this->comboBox1->Text = % String("������");
			this->label5->Text = % String("����");
			this->label6->Text = % String("������������");
			this->button2->Text = % String("��������� ����");
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				% String("������"),
				% String("����� � �������"),
				% String("��� �� ���������"),
				% String("����")
			});
		}
		void saveSetting()
		{
			save->SaveData("Save\\local_save.txt");
		}
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->operationType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->computer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->time, this->operationType,
					this->client, this->computer
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 53);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(374, 158);
			this->dataGridView1->TabIndex = 0;
			// 
			// time
			// 
			this->time->Frozen = true;
			this->time->HeaderText = L"�����";
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			this->time->Width = 50;
			// 
			// operationType
			// 
			this->operationType->Frozen = true;
			this->operationType->HeaderText = L"��� ��������";
			this->operationType->Name = L"operationType";
			this->operationType->ReadOnly = true;
			// 
			// client
			// 
			this->client->Frozen = true;
			this->client->HeaderText = L"������";
			this->client->Name = L"client";
			this->client->ReadOnly = true;
			// 
			// computer
			// 
			this->computer->Frozen = true;
			this->computer->HeaderText = L"���������";
			this->computer->Name = L"computer";
			this->computer->ReadOnly = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->����ToolStripMenuItem,
					this->���������ToolStripMenuItem, this->���ToolStripMenuItem, this->�������ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(597, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->�������������ToolStripMenuItem,
					this->��������������ToolStripMenuItem, this->���������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������������ToolStripMenuItem
			// 
			this->�������������ToolStripMenuItem->Name = L"�������������ToolStripMenuItem";
			this->�������������ToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->�������������ToolStripMenuItem->Text = L"�������������";
			this->�������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������������ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->��������������ToolStripMenuItem->Text = L"��������������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(163, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->�����������ToolStripMenuItem,
					this->����ToolStripMenuItem, this->��������������ToolStripMenuItem, this->����������ToolStripMenuItem
			});
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->���������ToolStripMenuItem->Text = L"���������";
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->�����������ToolStripMenuItem->Text = L"����� ������";
			this->�����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����������ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����ToolStripMenuItem_Click);
			// 
			// ��������������ToolStripMenuItem
			// 
			this->��������������ToolStripMenuItem->Name = L"��������������ToolStripMenuItem";
			this->��������������ToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->��������������ToolStripMenuItem->Text = L"������� �������";
			this->��������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::��������������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->����������ToolStripMenuItem->Text = L"�����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����������ToolStripMenuItem_Click);
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->����������ToolStripMenuItem,
					this->�����������ToolStripMenuItem
			});
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->���ToolStripMenuItem->Text = L"���";
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->������ToolStripMenuItem
			});
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->����������ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// ������ToolStripMenuItem
			// 
			this->������ToolStripMenuItem->Name = L"������ToolStripMenuItem";
			this->������ToolStripMenuItem->Size = System::Drawing::Size(118, 22);
			this->������ToolStripMenuItem->Text = L"������";
			this->������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������ToolStripMenuItem_Click);
			// 
			// �����������ToolStripMenuItem
			// 
			this->�����������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->����������ToolStripMenuItem
			});
			this->�����������ToolStripMenuItem->Name = L"�����������ToolStripMenuItem";
			this->�����������ToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->�����������ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// ����������ToolStripMenuItem
			// 
			this->����������ToolStripMenuItem->Name = L"����������ToolStripMenuItem";
			this->����������ToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->����������ToolStripMenuItem->Text = L"����������";
			this->����������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(392, 187);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"�������� ��������";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(426, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"�����:";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(474, 56);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(111, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(389, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"��� ��������:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(475, 137);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(111, 20);
			this->textBox3->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(423, 111);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(46, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"������:";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::White;
			this->textBox4->Location = System::Drawing::Point(475, 108);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(111, 20);
			this->textBox4->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(401, 137);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"���������:";
			// 
			// comboBox1
			// 
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"������", L"����� � �������", L"��� �� ���������",
					L"����"
			});
			this->comboBox1->Location = System::Drawing::Point(475, 81);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(111, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->Text = L"������";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"����:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(51, 27);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 13;
			this->dateTimePicker1->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker1_ValueChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(343, 27);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(111, 20);
			this->textBox2->TabIndex = 15;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(257, 30);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 13);
			this->label6->TabIndex = 14;
			this->label6->Text = L"������������:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(460, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"�������� ��������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(597, 222);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"����������� ����";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*���������� � �������*/
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Time* tmp_time;
		const std::regex r(R"((\d)(\d):(\d)(\d))");
		if (!std::regex_match(Conv::ToStdString(textBox1->Text), r))
		{
			MessageBox::Show("�������� ������ �������");
			return;
		}
		tmp_time = new Time(Conv::ToStdString(textBox1->Text));
		if (*tmp_time < *last_time || *tmp_time > *end_time)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("����� ����������� �������");
			return;
		}
		if (comboBox1->Text != "������" && 
			comboBox1->Text != "����� � �������" &&
			comboBox1->Text != "��� �� ���������" &&
			comboBox1->Text != "����")
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("�������� ����������� �������");
			return;
		}

		if (textBox4->Text->Length == 0)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("������ ����������� ������");
			return;
		}

		if (textBox3->Text->Length == 0)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("��������� ����������� ������");
			return;
		}

		array<Object^>^ tmp_array = {textBox1->Text, comboBox1->Text, textBox3->Text, textBox4->Text};

		dataGridView1->Rows->Add(tmp_array);
		delete last_time;
		last_time = tmp_time;
	}
	/*�������*/
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		help^ window = gcnew help(theme, save);
		window->ShowDialog();
	}
	/*����� ������� ������*/
	private: System::Void �����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		inputTimeWork^ window = gcnew inputTimeWork(theme, lang, save);
		window->ShowDialog();
		last_time = new Time(save->TimeStart());
		end_time = new Time(save->TimeEnd());
	}
	/*����� ���� ������ �� ���*/
	private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		inputPrice^ window = gcnew inputPrice(theme, lang, save);
		window->ShowDialog();
		price = save->Price();
	}
	private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void �������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	/*����� �� ������� ����*/
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete theme;
		save->Theme("Save\\light.txt");
		theme = new Theme("Save\\light.txt");
		updateWindow();
		saveSetting();
	}
	/*����� �� ������ ����*/
	private: System::Void ������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete theme;
		save->Theme("Save\\dark.txt");
		theme = new Theme("Save\\dark.txt");
		updateWindow();
		saveSetting();
	}
	/*����*/
	private: System::Void ��������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		login^ window = gcnew login(theme, lang, save);
		window->ShowDialog();
		updateWindow();
		saveSetting();
	}
	/*�����������*/
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		logup^ window = gcnew logup(theme, lang, save);
		window->ShowDialog();
		updateWindow();
		saveSetting();
	}
	/*����� ����� �� �������*/
	private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete lang;
		save->Lang("Save\\rus_Rus.txt");
		lang = new Lang("Save\\rus_Rus.txt");
		updateWindow();
		saveSetting();
	}
	/*����� ���� �� ����������*/
	private: System::Void ����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete lang;
		save->Lang("Save\\eng_Eng.txt");
		lang = new Lang("Save\\eng_Eng.txt");
		updateWindow();
		saveSetting();
	}
};
}
