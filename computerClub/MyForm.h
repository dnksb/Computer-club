#pragma once
#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
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

	std::vector<TableSpace::Table> tables;
	std::vector<Client*> clients;
	std::queue<Client*> clients_waiting;

	/// <summary>
	/// Сводка для MyForm
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
			clients_waiting = std::queue<Client*>();
			init_tables(save->Tables());
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
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
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ импротироватьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ отчетToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ настройкаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ времяРаботыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ценаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ справкаToolStripMenuItem;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ экспортироватьToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ operationType;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ client;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ computer;
	private: System::Windows::Forms::ToolStripMenuItem^ сменитьПрофильToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ регитрацияToolStripMenuItem;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ToolStripMenuItem^ видToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ темнаяТемаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ светлаяТемаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ светлаяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ темнаяToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ русскийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ английскийToolStripMenuItem;
	private: System::Windows::Forms::Button^ button2;
	private: Time* last_time;
	private: Time* end_time;
	private: TypeOperation type_operation;
	private: Theme* theme;
	private: Lang* lang;
	private: Save* save;
	private: int price;
	private: System::Windows::Forms::ToolStripMenuItem^ патриатичнаяToolStripMenuItem;

		   /// <summary>
		/// Обязательная переменная конструктора.
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
			this->справкаToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->файлToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->настройкаToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->видToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			
			this->импротироватьToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->экспортироватьToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->сохранитьToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->отчетToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->времяРаботыToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->ценаToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->сменитьПрофильToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->регитрацияToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->темнаяТемаToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->светлаяToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->патриатичнаяToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->темнаяToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->светлаяТемаToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->русскийToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			this->английскийToolStripMenuItem->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
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
			
			this->файлToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->настройкаToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->видToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->справкаToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->menuStrip1->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			
			this->импротироватьToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->экспортироватьToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->сохранитьToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->отчетToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->времяРаботыToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->ценаToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->сменитьПрофильToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->регитрацияToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->темнаяТемаToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->светлаяToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->темнаяToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->светлаяТемаToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->патриатичнаяToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->русскийToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));
			this->английскийToolStripMenuItem->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->MenuBackGround()));

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

				this->файлToolStripMenuItem->Text = Conv::ToSystemString(lang->file);
				this->импротироватьToolStripMenuItem->Text = Conv::ToSystemString(lang->imp);
				this->экспортироватьToolStripMenuItem->Text = Conv::ToSystemString(lang->exp);
				this->сохранитьToolStripMenuItem->Text = Conv::ToSystemString(lang->save);
				this->отчетToolStripMenuItem->Text = Conv::ToSystemString(lang->report);
				this->настройкаToolStripMenuItem->Text = Conv::ToSystemString(lang->settings);
				this->времяРаботыToolStripMenuItem->Text = Conv::ToSystemString(lang->work_time);
				this->ценаToolStripMenuItem->Text = Conv::ToSystemString(lang->price);
				this->сменитьПрофильToolStripMenuItem->Text = Conv::ToSystemString(lang->change);
				this->регитрацияToolStripMenuItem->Text = Conv::ToSystemString(lang->login);
				this->видToolStripMenuItem->Text = Conv::ToSystemString(lang->view);
				this->темнаяТемаToolStripMenuItem->Text = Conv::ToSystemString(lang->theme);
				this->светлаяToolStripMenuItem->Text = Conv::ToSystemString(lang->light);
				this->темнаяToolStripMenuItem->Text = Conv::ToSystemString(lang->dark);
				this->патриатичнаяToolStripMenuItem->Text = Conv::ToSystemString(lang->patr);
				this->светлаяТемаToolStripMenuItem->Text = Conv::ToSystemString(lang->lang);
				this->русскийToolStripMenuItem->Text = Conv::ToSystemString(lang->rus);
				this->английскийToolStripMenuItem->Text = Conv::ToSystemString(lang->eng);
				this->справкаToolStripMenuItem->Text = Conv::ToSystemString(lang->help);

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
			this->time->HeaderText = % String("Время");
			this->operationType->HeaderText = % String("Тип");
			this->client->HeaderText = % String("Клиент");
			this->computer->HeaderText = % String("Компьютер");
			this->файлToolStripMenuItem->Text = % String("Файл");
			this->импротироватьToolStripMenuItem->Text = % String("Импортировать");
			this->экспортироватьToolStripMenuItem->Text = % String("Экспортировать");
			this->сохранитьToolStripMenuItem->Text = % String("Сохранить");
			this->отчетToolStripMenuItem->Text = % String("Результаты дня");
			this->настройкаToolStripMenuItem->Text = % String("Настройки");
			this->времяРаботыToolStripMenuItem->Text = % String("Время работы");
			this->ценаToolStripMenuItem->Text = % String("Цена");
			this->сменитьПрофильToolStripMenuItem->Text = % String("Сменить профиль");
			this->регитрацияToolStripMenuItem->Text = % String("Регистрация");
			this->видToolStripMenuItem->Text = % String("Вид");
			this->темнаяТемаToolStripMenuItem->Text = % String("Тема");
			this->светлаяToolStripMenuItem->Text = % String("Светлая");
			this->темнаяToolStripMenuItem->Text = % String("Темная");
			this->светлаяТемаToolStripMenuItem->Text = % String("Язык");
			this->русскийToolStripMenuItem->Text = % String("Русский");
			this->английскийToolStripMenuItem->Text = % String("Английский");
			this->справкаToolStripMenuItem->Text = % String("Справка");
			this->патриатичнаяToolStripMenuItem->Text = % String("Патриатичная");
			this->button1->Text = % String("Добавить запись");
			this->label1->Text = % String("Время");
			this->label2->Text = % String("Тип");
			this->label3->Text = % String("Клиент");
			this->label4->Text = % String("№ Компьютера");
			this->comboBox1->Text = % String("Пришел");
			this->label5->Text = % String("Дата");
			this->label6->Text = % String("Пользователь");
			this->button2->Text = % String("Закончить день");
			this->comboBox1->Items->Clear();
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				% String("Пришел"),
				% String("Встал в очередь"),
				% String("Сел за компьютер"),
				% String("Ушел")
			});
		}
		void saveSetting()
		{
			save->SaveData("Save\\local_save.txt");
		}
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->operationType = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->client = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->computer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->импротироватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->экспортироватьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->отчетToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->настройкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->времяРаботыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ценаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сменитьПрофильToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->регитрацияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->видToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->темнаяТемаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->светлаяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->темнаяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->патриатичнаяToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->светлаяТемаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->русскийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->английскийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->справкаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->time->HeaderText = L"Время";
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			this->time->Width = 50;
			// 
			// operationType
			// 
			this->operationType->Frozen = true;
			this->operationType->HeaderText = L"Тип операции";
			this->operationType->Name = L"operationType";
			this->operationType->ReadOnly = true;
			// 
			// client
			// 
			this->client->Frozen = true;
			this->client->HeaderText = L"Клиент";
			this->client->Name = L"client";
			this->client->ReadOnly = true;
			// 
			// computer
			// 
			this->computer->Frozen = true;
			this->computer->HeaderText = L"Компьютер";
			this->computer->Name = L"computer";
			this->computer->ReadOnly = true;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->файлToolStripMenuItem,
					this->настройкаToolStripMenuItem, this->видToolStripMenuItem, this->справкаToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(597, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->импротироватьToolStripMenuItem,
					this->экспортироватьToolStripMenuItem, this->сохранитьToolStripMenuItem, this->отчетToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"Файл";
			// 
			// импротироватьToolStripMenuItem
			// 
			this->импротироватьToolStripMenuItem->Name = L"импротироватьToolStripMenuItem";
			this->импротироватьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->импротироватьToolStripMenuItem->Text = L"Импортировать";
			this->импротироватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::импротироватьToolStripMenuItem_Click);
			// 
			// экспортироватьToolStripMenuItem
			// 
			this->экспортироватьToolStripMenuItem->Name = L"экспортироватьToolStripMenuItem";
			this->экспортироватьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->экспортироватьToolStripMenuItem->Text = L"Экспортировать";
			this->экспортироватьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::экспортироватьToolStripMenuItem_Click);
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сохранитьToolStripMenuItem_Click);
			// 
			// отчетToolStripMenuItem
			// 
			this->отчетToolStripMenuItem->Name = L"отчетToolStripMenuItem";
			this->отчетToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->отчетToolStripMenuItem->Text = L"Результаты дня";
			this->отчетToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::отчетToolStripMenuItem_Click);
			// 
			// настройкаToolStripMenuItem
			// 
			this->настройкаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->времяРаботыToolStripMenuItem,
					this->ценаToolStripMenuItem, this->сменитьПрофильToolStripMenuItem, this->регитрацияToolStripMenuItem
			});
			this->настройкаToolStripMenuItem->Name = L"настройкаToolStripMenuItem";
			this->настройкаToolStripMenuItem->Size = System::Drawing::Size(79, 20);
			this->настройкаToolStripMenuItem->Text = L"Настройки";
			// 
			// времяРаботыToolStripMenuItem
			// 
			this->времяРаботыToolStripMenuItem->Name = L"времяРаботыToolStripMenuItem";
			this->времяРаботыToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->времяРаботыToolStripMenuItem->Text = L"Время работы";
			this->времяРаботыToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::времяРаботыToolStripMenuItem_Click);
			// 
			// ценаToolStripMenuItem
			// 
			this->ценаToolStripMenuItem->Name = L"ценаToolStripMenuItem";
			this->ценаToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->ценаToolStripMenuItem->Text = L"Цена";
			this->ценаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ценаToolStripMenuItem_Click);
			// 
			// сменитьПрофильToolStripMenuItem
			// 
			this->сменитьПрофильToolStripMenuItem->Name = L"сменитьПрофильToolStripMenuItem";
			this->сменитьПрофильToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->сменитьПрофильToolStripMenuItem->Text = L"Сменить профиль";
			this->сменитьПрофильToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::сменитьПрофильToolStripMenuItem_Click);
			// 
			// регитрацияToolStripMenuItem
			// 
			this->регитрацияToolStripMenuItem->Name = L"регитрацияToolStripMenuItem";
			this->регитрацияToolStripMenuItem->Size = System::Drawing::Size(175, 22);
			this->регитрацияToolStripMenuItem->Text = L"Регистрация";
			this->регитрацияToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::регитрацияToolStripMenuItem_Click);
			// 
			// видToolStripMenuItem
			// 
			this->видToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->темнаяТемаToolStripMenuItem,
					this->светлаяТемаToolStripMenuItem
			});
			this->видToolStripMenuItem->Name = L"видToolStripMenuItem";
			this->видToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->видToolStripMenuItem->Text = L"Вид";
			// 
			// темнаяТемаToolStripMenuItem
			// 
			this->темнаяТемаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->светлаяToolStripMenuItem,
					this->темнаяToolStripMenuItem, this->патриатичнаяToolStripMenuItem
			});
			this->темнаяТемаToolStripMenuItem->Name = L"темнаяТемаToolStripMenuItem";
			this->темнаяТемаToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->темнаяТемаToolStripMenuItem->Text = L"Тема";
			// 
			// светлаяToolStripMenuItem
			// 
			this->светлаяToolStripMenuItem->Name = L"светлаяToolStripMenuItem";
			this->светлаяToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->светлаяToolStripMenuItem->Text = L"Светлая";
			this->светлаяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::светлаяToolStripMenuItem_Click);
			// 
			// темнаяToolStripMenuItem
			// 
			this->темнаяToolStripMenuItem->Name = L"темнаяToolStripMenuItem";
			this->темнаяToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->темнаяToolStripMenuItem->Text = L"Темная";
			this->темнаяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::темнаяToolStripMenuItem_Click);
			// 
			// патриатичнаяToolStripMenuItem
			// 
			this->патриатичнаяToolStripMenuItem->Name = L"патриатичнаяToolStripMenuItem";
			this->патриатичнаяToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->патриатичнаяToolStripMenuItem->Text = L"Патриатичная";
			this->патриатичнаяToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::патриатичнаяToolStripMenuItem_Click);
			// 
			// светлаяТемаToolStripMenuItem
			// 
			this->светлаяТемаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->русскийToolStripMenuItem,
					this->английскийToolStripMenuItem
			});
			this->светлаяТемаToolStripMenuItem->Name = L"светлаяТемаToolStripMenuItem";
			this->светлаяТемаToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->светлаяТемаToolStripMenuItem->Text = L"Язык";
			// 
			// русскийToolStripMenuItem
			// 
			this->русскийToolStripMenuItem->Name = L"русскийToolStripMenuItem";
			this->русскийToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->русскийToolStripMenuItem->Text = L"Русский";
			this->русскийToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::русскийToolStripMenuItem_Click);
			// 
			// английскийToolStripMenuItem
			// 
			this->английскийToolStripMenuItem->Name = L"английскийToolStripMenuItem";
			this->английскийToolStripMenuItem->Size = System::Drawing::Size(141, 22);
			this->английскийToolStripMenuItem->Text = L"Английский";
			this->английскийToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::английскийToolStripMenuItem_Click);
			// 
			// справкаToolStripMenuItem
			// 
			this->справкаToolStripMenuItem->Name = L"справкаToolStripMenuItem";
			this->справкаToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->справкаToolStripMenuItem->Text = L"Справка";
			this->справкаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::справкаToolStripMenuItem_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(392, 187);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Добавить операцию";
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
			this->label1->Text = L"Время:";
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
			this->label2->Text = L"Тип операции:";
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
			this->label3->Text = L"Клиент:";
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
			this->label4->Location = System::Drawing::Point(389, 140);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Компьютер:";
			// 
			// comboBox1
			// 
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Пришел", L"Встал в очередь", L"Сел за компьютер",
					L"Ушел"
			});
			this->comboBox1->Location = System::Drawing::Point(475, 81);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(111, 21);
			this->comboBox1->TabIndex = 11;
			this->comboBox1->Text = L"Пришел";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(12, 30);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(36, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Дата:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(51, 27);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 13;
			this->dateTimePicker1->Value = System::DateTime(2023, 5, 15, 0, 0, 0, 0);
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
			this->label6->Text = L"Пользователь:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(460, 27);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 23);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Добавить операцию";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightCoral;
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
			this->MaximumSize = System::Drawing::Size(613, 261);
			this->MinimumSize = System::Drawing::Size(613, 261);
			this->Name = L"MyForm";
			this->Text = L"Комьютерный клуб";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: bool clear_space = true;
	/*человек вышел из очереди*/
	private: void decrease_queue(String^ time, int num_table)
	{
		Client* client;
		if (clients_waiting.size() != 0)
			client = clients_waiting.front();
		else return;
		if (client != nullptr)
		{
			client_sat(time, Conv::ToSystemString(client->get_name()), num_table);
			clients_waiting.pop();
		}
	}
	/*количество ждущих клиентов*/
	private: int amount_waiting_client()
	{
		int amount = 0;
		for (int i = 0; i < clients.size(); i++)
			if (clients[i]->get_waiting())
				amount++;
		return amount;
	}
	/*есть ли свободный стол*/
	private: bool one_table_free()
	{
		for (int i = 0; i < tables.size(); i++)
			if (tables[i].get_status())
				return true;
		return false;
	}
	/*поиск клиента по имени*/
	private: Client* find_client(String^ client_name)
	{
		for (int i = 0; i < clients.size(); i++)
			if (clients[i]->get_name() == Conv::ToStdString(client_name))
				return clients[i];
		return nullptr;
	}
	/*инициализация пустых столов*/
	private: void init_tables(int amount_table)
	{
		tables.clear();
		tables = std::vector<TableSpace::Table>(amount_table);
		for (int i = 0; i < amount_table; i++)
		{
			tables[i] = TableSpace::Table();
			tables[i].set_num(i);
		}
	}
	/*если клиент Пришел*/
	private: void client_came(String^ time, String^ client_name)
	{
		array<Object^>^ tmp_array = { time, "Пришел", client_name, "" };

		Time* tmp_time;
		
		const std::regex r(R"((\d)(\d):(\d)(\d))");
		if (!std::regex_match(Conv::ToStdString(time), r))
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("неверный формат времени");
			return;
		}
		
		tmp_time = new Time(Conv::ToStdString(time));
		
		if (*tmp_time > *end_time)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("Время неправильно введено");
			return;
		}

		dataGridView1->Rows->Add(tmp_array);
		delete last_time;
		last_time = tmp_time;
		clients.insert(clients.end(), new Client(Time(Conv::ToStdString(time)), Conv::ToStdString(client_name)));
	}
	/*если клиент Сел за компьютер*/
	private: void client_sat(String^ time, String^ client_name, int num_table)
	{
		Client* client = find_client(client_name);
		if (client == nullptr)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("неизвестный клиент");
			return;
		}
		else if (num_table >= save->Tables())
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("такого компьютера нет");
			return;
		}
		else if (!tables[num_table].get_status())
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("место занято");
			return;
		}
		else
		{
			client->set_time(Time(Conv::ToStdString(time)));
			tables[num_table].set_client(client);
			client->set_table_num(num_table);
			
			array<Object^>^ tmp_array = { time, "Сел за компьютер", client_name, Convert::ToString(num_table + 1)};

			Time* tmp_time;

			const std::regex r(R"((\d)(\d):(\d)(\d))");
			if (!std::regex_match(Conv::ToStdString(time), r))
			{
				if (save->Lang() != "Save\\rus_Rus.txt")
					MessageBox::Show(Conv::ToSystemString(lang->error));
				else
					MessageBox::Show("неверный формат времени");
				return;
			}

			tmp_time = new Time(Conv::ToStdString(time));

			if (*tmp_time > *end_time)
			{
				if (save->Lang() != "Save\\rus_Rus.txt")
					MessageBox::Show(Conv::ToSystemString(lang->error));
				else
					MessageBox::Show("Время неправильно введено");
				return;
			}

			dataGridView1->Rows->Add(tmp_array);
			delete last_time;
			last_time = tmp_time;
		}
	}
	/*если клиент Встал в очередь*/
	private: void client_wait(String^ time, String^ client_name)
	{
		if (one_table_free())
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("клиент не может так долго ждать");
			return;
		}
		else if (amount_waiting_client() > save->Tables())
		{
			return;
		}
		else
		{
			array<Object^>^ tmp_array = { time, "Встал в очередь", client_name, ""};

			Time* tmp_time;

			const std::regex r(R"((\d)(\d):(\d)(\d))");
			if (!std::regex_match(Conv::ToStdString(time), r))
			{
				if (save->Lang() != "Save\\rus_Rus.txt")
					MessageBox::Show(Conv::ToSystemString(lang->error));
				else
					MessageBox::Show("неверный формат времени");
				return;
			}

			tmp_time = new Time(Conv::ToStdString(time));

			if (*tmp_time > *end_time)
			{
				if (save->Lang() != "Save\\rus_Rus.txt")
					MessageBox::Show(Conv::ToSystemString(lang->error));
				else
					MessageBox::Show("Время неправильно введено");
				return;
			}

			dataGridView1->Rows->Add(tmp_array);
			delete last_time;
			last_time = tmp_time;

			clients_waiting.push(find_client(client_name));
		}
	}
	/*если клиент Ушел*/
	private: void client_left(String^ time, String^ client_name)
	{
		auto client = find_client(client_name);
		if (client == nullptr)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("неизвестный клиент");
		}
		else
		{
			int num_table = client->get_table_num();
			tables[num_table].left_client(Conv::ToStdString(time), client->get_time());
			
			array<Object^>^ tmp_array = { time, "Ушел", client_name, "" };
			dataGridView1->Rows->Add(tmp_array);
			
			Time* tmp_time;
			tmp_time = new Time(Conv::ToStdString(time));
			delete last_time;
			last_time = tmp_time;
			
			decrease_queue(time, num_table);
		}
	}
	/*интерпретатор полученой из файла строки*/
	private: void interpreter(String^ line)
	{
		auto commands = line->Split(' ');
		if (commands->Length != 3 && commands->Length != 4)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("неверная запись в файле");
			return;
		}

		auto time = commands[0];
		auto num_operation = Convert::ToInt32(commands[1]);
		auto client_name = commands[2];

		if (Time(Conv::ToStdString(time)) < *last_time)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("неверное время операции");
			return;
		}

		switch (num_operation)
		{
		case 1:
			client_came(time, client_name);
			break;
		case 2:
			client_sat(time, client_name, Convert::ToInt32(commands[3]) - 1);
			break;
		case 3:
			client_wait(time, client_name);
			break;
		case 4:
			client_left(time, client_name);
			break;
		default:
			break;
		}

		delete commands;
	}
	/*добавление в таблицу*/
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Time* tmp_time;

		if (clear_space)
		{
			this->dataGridView1->Rows->Clear();
			clear_space = false;
			init_tables(save->Tables());
		}
		
		const std::regex r(R"((\d)(\d):(\d)(\d))");
		if (!std::regex_match(Conv::ToStdString(textBox1->Text), r))
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("неверный формат времени");
			return;
		}
		
		tmp_time = new Time(Conv::ToStdString(textBox1->Text));
		
		if (*tmp_time < *last_time || *tmp_time > *end_time)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("Время неправильно введено");
			return;
		}
		
		if (comboBox1->Text != "Пришел" && 
			comboBox1->Text != "Встал в очередь" &&
			comboBox1->Text != "Сел за компьютер" &&
			comboBox1->Text != "Ушел" &&
			comboBox1->Text != "Gone" &&
			comboBox1->Text != "Waiting" &&
			comboBox1->Text != "Village" &&
			comboBox1->Text != "Came")
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("операция неправильно выбрана");
			return;
		}

		if (textBox4->Text->Length == 0)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("клиент неправильно введен");
			return;
		}


		const std::regex r1(R"((\d)+)");
		if (!std::regex_match(Conv::ToStdString(textBox3->Text), r1))
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("компьютер неправильно введен");
			return;
		}
		if (Convert::ToInt32(textBox3->Text) <= 0)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("компьютер неправильно введен");
			return;
		}

		int tmp_num;
		if (comboBox1->Text == "Пришел" || comboBox1->Text == "Came")
			tmp_num = 1;
		if (comboBox1->Text == "Сел за компьютер" || comboBox1->Text == "Village")
			tmp_num = 2;
		if (comboBox1->Text == "Встал в очередь" || comboBox1->Text == "Waiting")
			tmp_num = 3;
		if (comboBox1->Text == "Ушел" || comboBox1->Text == "Gone")
			tmp_num = 4;
		
		String^ tmp = textBox1->Text + " " + tmp_num + " " + textBox4->Text + " " + Convert::ToString(textBox3->Text);

		interpreter(tmp);
		delete last_time;
		last_time = tmp_time;
	}
	/*вызывается при завершении рабочего дня*/
	private: void time_off()
	{
		for (int i = 0; i < tables.size(); i++)
			if (!tables[i].get_status())
			{
				auto client = tables[i].get_client();
				array<Object^>^ tmp_array = { Conv::ToSystemString(end_time->output()), "Ушел", Conv::ToSystemString(client->get_name()), ""};
				dataGridView1->Rows->Add(tmp_array);
				tables[i].left_client(*end_time);
				delete client;
			}
		while (clients_waiting.size() > 0)
		{
			auto client = clients_waiting.front();
			array<Object^>^ tmp_array = { Conv::ToSystemString(end_time->output()), "Ушел", Conv::ToSystemString(client->get_name()), "" };
			dataGridView1->Rows->Add(tmp_array);
			delete client;
			clients_waiting.pop();
		}
	}
	/*справка*/
	private: System::Void справкаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		help^ window = gcnew help(theme, save);
		window->ShowDialog();
	}
	/*смена времени работы*/
	private: System::Void времяРаботыToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		inputTimeWork^ window = gcnew inputTimeWork(theme, lang, save);
		window->ShowDialog();
		last_time = new Time(save->TimeStart());
		end_time = new Time(save->TimeEnd());
	}
	/*смена цены аренды на час*/
	private: System::Void ценаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		inputPrice^ window = gcnew inputPrice(theme, lang, save);
		window->ShowDialog();
		price = save->Price();
	}
	/*импорт данных из файла*/
	private: System::Void импротироватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		clear_space = true;
		OpenFileDialog^ file = gcnew OpenFileDialog();
		file->Filter = "txt files (*.txt)|*.txt";
		file->ShowDialog();
		array<String^> ^lines;
		try
		{
			lines = IO::File::ReadAllLines(file->FileName);
		}
		catch (...)
		{
			return;
		}
		clients = std::vector<Client*>(0);

		try
		{
			int tmp;
			tmp = Convert::ToInt32(lines[0]);
			save->Tables(tmp);
			std::string time = "";
			
			time = Conv::ToStdString(lines[1]->Split()[0]);
			save->TimeStart(time);
			last_time->set_time(time);
			
			time = Conv::ToStdString(lines[1]->Split()[1]);
			save->TimeEnd(time);
			end_time->set_time(time);
			
			tmp = Convert::ToInt32(lines[2]);
			save->Price(tmp);
			price = tmp;
		}
		catch (std::exception ex)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("неверный формат файла");
			return;
		}

		init_tables(save->Tables());

		this->dataGridView1->Rows->Clear();

		try
		{
			std::string line = "";
			for(int i = 3; i < lines->Length; i++)
			{
				interpreter(lines[i]);
			}
		}
		catch (std::exception ex)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("ошибка");
			return;
		}

		time_off();
		clients.clear();
	}
	/*сохранение в бд*/
	private: System::Void сохранитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string baseName = "Save\\database.bytes";

		SQLiteConnection^ connection = gcnew SQLiteConnection();
		connection->ConnectionString = Conv::ToSystemString("Data Source = " + baseName);
		connection->Open();

		SQLiteCommand^ command = gcnew SQLiteCommand(connection);
		command->CommandText = Conv::ToSystemString("SELECT id FROM Users WHERE username = '" + save->Name() + "'");
		command->CommandType = CommandType::Text;
		SQLiteDataReader^ reader = command->ExecuteReader();
		
		int user_id = 0;

		while(reader->Read())
			user_id = reader->GetInt32(0);
		reader->Close();
		
		command->CommandText = "SELECT id FROM Date_to_users WHERE user_if = " + 
			Convert::ToString(user_id) +" AND date = " + 
			Convert::ToString(dateTimePicker1->Value.DayOfYear);
		reader = command->ExecuteReader();
		
		if (!reader->Read())
		{
			reader->Close();
			command->CommandText = "INSERT INTO Date_to_users (user_if, date) VALUES(" + 
				Convert::ToString(user_id) +", " + 
				Convert::ToString(dateTimePicker1->Value.DayOfYear) + ")";
			command->ExecuteNonQuery();
		}

		reader->Close();
		command->CommandText = "SELECT id FROM Date_to_users WHERE user_if = " +
			Convert::ToString(user_id) + " AND date = " +
			Convert::ToString(dateTimePicker1->Value.DayOfYear);
		reader = command->ExecuteReader();
		int date_id = 0;
		while (reader->Read())
			date_id = reader->GetInt32(0);
		
		reader->Close();
		

		for (int i = 0; i < dataGridView1->Rows->Count; i++)
		{
			String^ tmp_str = "";
			tmp_str += this->dataGridView1->Rows[i]->Cells[0]->Value + " ";
			int tmp_num = 0;
			if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Пришел" ||
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Came")
				tmp_num = 1;
			else if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Сел за компьютер" ||
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Village")
				tmp_num = 2;
			else if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Встал в очередь" ||
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Waiting")
				tmp_num = 3;
			else if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Ушел" ||
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Gone")
				tmp_num = 4;
			tmp_str += Convert::ToString(tmp_num) + " ";
			tmp_str += this->dataGridView1->Rows[i]->Cells[2]->Value + " ";
			tmp_str += this->dataGridView1->Rows[i]->Cells[3]->Value + "\n";
			command->CommandText = "INSERT INTO Date_to_operations (date_id, operation) VALUES(" +
				Convert::ToString(date_id) + ", '" +
				tmp_str + "' )";
			command->ExecuteNonQuery();
		}
	}
	/*функция сотрировки компьютеров по рентабильности*/
	private: void sort()
	{
		for (int d = tables.size() / 2; d > 0; d /= 2)
		{
			for (int i = d; i < tables.size(); ++i)
			{
				for (int j = i - d; j >= 0 && tables[j].get_time() > tables[j + d].get_time(); j -= d)
				{
					std::swap(tables[j], tables[j + d]);
				}
			}
		}

		for (int d = tables.size() / 2; d > 0; d /= 2)
		{
			for (int i = d; i < tables.size(); ++i)
			{
				for (int j = i - d; j >= 0 && tables[j].get_cof() > tables[j + d].get_cof(); j -= d)
				{
					std::swap(tables[j], tables[j + d]);
				}
			}
		}
	}
	/*вывод результатов за день*/
	private: System::Void отчетToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ tmp_str = "";

		sort();

		for each (auto table in tables)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				tmp_str += Conv::ToSystemString(lang->computer) + " №";
			else
				tmp_str += "Компьютер №";
			tmp_str += Convert::ToString(table.get_num() + 1) + ": " +
				Convert::ToString(table.get_cof() * save->Price()) + "; " +
				Conv::ToSystemString(table.get_time().output()) + "\n";
		}
		
		MessageBox::Show(tmp_str);
	}
	/*функция по экспорту списка в файл txt*/
	private: System::Void экспортироватьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ tmp_str = "";

		tmp_str += Convert::ToInt32(save->Tables()) + "\n";
		tmp_str += Conv::ToSystemString(save->TimeStart()) + " " + Conv::ToSystemString(save->TimeEnd()) + "\n";
		tmp_str += Convert::ToInt32(save->Price()) + "\n";

		for (int i = 0; i < dataGridView1->Rows->Count; i++)
		{
			tmp_str += this->dataGridView1->Rows[i]->Cells[0]->Value + " ";
			int tmp_num = 0;
			if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Пришел" || 
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Came")
				tmp_num = 1;
			else if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Сел за компьютер" || 
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Village")
				tmp_num = 2;
			else if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Встал в очередь" || 
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Waiting")
				tmp_num = 3;
			else if (this->dataGridView1->Rows[i]->Cells[1]->Value == "Ушел" ||
				this->dataGridView1->Rows[i]->Cells[1]->Value == "Gone")
				tmp_num = 4;
			tmp_str += Convert::ToString(tmp_num) + " ";
			tmp_str += this->dataGridView1->Rows[i]->Cells[2]->Value + " ";
			tmp_str += this->dataGridView1->Rows[i]->Cells[3]->Value + "\n";
		}

		SaveFileDialog^ file = gcnew SaveFileDialog();
		file->Filter = "txt files (*.txt)| *.txt";
		file->ShowDialog();
		try
		{
			IO::File::WriteAllText(file->FileName, tmp_str);
		}
		catch (...)
		{
			
		}
	}
	/*функция по завершению дня работы*/
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		clear_space = true;
		time_off();
		clients.clear();
		String^ tmp_str = "";

		sort();

		for each (auto table in tables)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				tmp_str += Conv::ToSystemString(lang->computer) + " №";
			else
				tmp_str += "Компьютер №";
			tmp_str += Convert::ToString(table.get_num() + 1) + ": " +
				Convert::ToString(table.get_cof() * save->Price()) + "; " +
				Conv::ToSystemString(table.get_time().output()) + "\n";
		}

		MessageBox::Show(tmp_str);
	}
	/*смена на светлую тему*/
	private: System::Void светлаяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete theme;
		save->Theme("Save\\light.txt");
		theme = new Theme("Save\\light.txt");
		updateWindow();
		saveSetting();
	}
	/*смена на темную тему*/
	private: System::Void темнаяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete theme;
		save->Theme("Save\\dark.txt");
		theme = new Theme("Save\\dark.txt");
		updateWindow();
		saveSetting();
	}
	/*вход*/
	private: System::Void сменитьПрофильToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		login^ window = gcnew login(theme, lang, save);
		window->ShowDialog();
		updateWindow();
		saveSetting();
	}
	/*регистрация*/
	private: System::Void регитрацияToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		logup^ window = gcnew logup(theme, lang, save);
		window->ShowDialog();
		updateWindow();
		saveSetting();
	}
	/*смена языка на русский*/
	private: System::Void русскийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete lang;
		save->Lang("Save\\rus_Rus.txt");
		lang = new Lang("Save\\rus_Rus.txt");
		updateWindow();
		saveSetting();
	}
	/*смена язык на английский*/
	private: System::Void английскийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete lang;
		save->Lang("Save\\eng_Eng.txt");
		lang = new Lang("Save\\eng_Eng.txt");
		updateWindow();
		saveSetting();
	}
	/*смена на патриатичную тему*/
	private: System::Void патриатичнаяToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		delete theme;
		save->Theme("Save\\patriotic.txt");
		theme = new Theme("Save\\patriotic.txt");
		updateWindow();
		saveSetting();
	}
	private: System::Void dateTimePicker1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		clear_space = true;

		std::string baseName = "Save\\database.bytes";

		SQLiteConnection^ connection = gcnew SQLiteConnection();
		connection->ConnectionString = Conv::ToSystemString("Data Source = " + baseName);
		connection->Open();

		SQLiteCommand^ command = gcnew SQLiteCommand(connection);
		command->CommandText = Conv::ToSystemString("SELECT id FROM Users WHERE username = '" + save->Name() + "'");
		command->CommandType = CommandType::Text;
		SQLiteDataReader^ reader = command->ExecuteReader();

		int user_id = 0;

		while (reader->Read())
			user_id = reader->GetInt32(0);
		reader->Close();

		command->CommandText = "SELECT id FROM Date_to_users WHERE user_if = " +
			Convert::ToString(user_id) + " AND date = " +
			Convert::ToString(dateTimePicker1->Value.DayOfYear);
		reader = command->ExecuteReader();

		if (!reader->Read())
		{
			reader->Close();
			command->CommandText = "INSERT INTO Date_to_users (user_if, date) VALUES(" +
				Convert::ToString(user_id) + ", " +
				Convert::ToString(dateTimePicker1->Value.DayOfYear) + ")";
			command->ExecuteNonQuery();
		}

		reader->Close();
		command->CommandText = "SELECT id FROM Date_to_users WHERE user_if = " +
			Convert::ToString(user_id) + " AND date = " +
			Convert::ToString(dateTimePicker1->Value.DayOfYear);
		reader = command->ExecuteReader();
		int date_id = 0;
		while (reader->Read())
			date_id = reader->GetInt32(0);
		reader->Close();

		clients = std::vector<Client*>(0);

		init_tables(save->Tables());

		this->dataGridView1->Rows->Clear();

		command->CommandText = "SELECT operation FROM Date_to_operations WHERE date_id = " +
			Convert::ToString(date_id);

		reader = command->ExecuteReader();

		try
		{
			while (reader->Read())
			{
				interpreter(reader->GetString(0));
			}
		}
		catch (std::exception ex)
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("ошибка");
			return;
		}

		time_off();
		clients.clear();
	}
};
}
