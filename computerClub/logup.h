#pragma once
#include "lang.h"
#include "theme.h"
#include "converter.h"
#include "local_save.h"
#include <regex>

namespace computerClub {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::Common;
	using namespace System::Data::SQLite;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для logup
	/// </summary>
	public ref class logup : public System::Windows::Forms::Form
	{
	public:
		logup(Theme* theme, Lang* lang, Save* save)
		{
			InitializeComponent();
			this->theme = theme;
			this->lang = lang;
			this->save = save;
			set_theme();
		}

		Theme* theme;
		Lang* lang;
		Save* save;

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~logup()
		{
			if (components)
			{
				delete components;
			}
		}

		void set_theme()
		{
			button1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->Border()));
			label1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));
			textBox1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));

			label1->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			textBox1->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextBackGround()));
			this->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));

			if (save->Lang() != "Save\\rus_Rus.txt")
			{
				this->button1->Text = Conv::ToSystemString(lang->nick);
				this->label1->Text = Conv::ToSystemString(lang->reg);
			}
			else
			{
				SetRus();
			}
		}
		void SetRus()
		{
			this->button1->Text = % String("регистрация");
			this->label1->Text = % String("никнейм");
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"label1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &logup::button1_Click);
			// 
			// logup
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(184, 72);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->MinimumSize = System::Drawing::Size(200, 111);
			this->Name = L"logup";
			this->Text = L"logup";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string baseName = "Save\\database.bytes";

		SQLiteConnection^ connection = gcnew SQLiteConnection();
		connection->ConnectionString = Conv::ToSystemString("Data Source = " + baseName);
		connection->Open();

		SQLiteCommand^ command = gcnew SQLiteCommand(connection);
		command->CommandText = Conv::ToSystemString("SELECT id, username FROM Users");
		command->CommandType = CommandType::Text;
		SQLiteDataReader^ reader = command->ExecuteReader();
		while(reader->Read())
			if (reader->GetString(1) == textBox1->Text)
			{
				if (save->Lang() != "Save\\rus_Rus.txt")
					MessageBox::Show(Conv::ToSystemString(lang->error));
				else
					MessageBox::Show("Никнейм занят");
				return;
			}
		reader->Close();
		command->CommandText = "INSERT INTO Users (username) VALUES('" + textBox1->Text + "')";
		command->ExecuteNonQuery();
		save->Name(Conv::ToStdString(textBox1->Text));
		save->SaveData("Save\\local_save.txt");
		if (save->Lang() != "Save\\rus_Rus.txt")
			MessageBox::Show(Conv::ToSystemString(lang->suck));
		else
			MessageBox::Show("Успешно зарегестрирован");
		this->Close();
	}
};
}
