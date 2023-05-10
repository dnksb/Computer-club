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
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ inputPrice
	/// </summary>
	public ref class inputPrice : public System::Windows::Forms::Form
	{
	public:
		inputPrice(Theme* theme, Lang* lang, Save* save)
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
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~inputPrice()
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
				this->button1->Text = Conv::ToSystemString(lang->Set);
				this->label1->Text = Conv::ToSystemString(lang->price);
			}
			else
			{
				SetRus();
			}
		}
		void SetRus()
		{
			this->button1->Text = % String("”становить");
			this->label1->Text = % String("цена");
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(15, 39);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &inputPrice::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(72, 13);
			this->textBox1->MinimumSize = System::Drawing::Size(100, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			// 
			// inputPrice
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(184, 72);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->MaximumSize = System::Drawing::Size(200, 111);
			this->MinimumSize = System::Drawing::Size(200, 111);
			this->Name = L"inputPrice";
			this->Text = L"inputPrice";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		const std::regex r(R"((\d)+)");
		if (!std::regex_match(Conv::ToStdString(textBox1->Text), r))
		{
			if (save->Lang() != "Save\\rus_Rus.txt")
				MessageBox::Show(Conv::ToSystemString(lang->error));
			else
				MessageBox::Show("ошибка");
			return;
		}
		save->Price(Convert::ToInt32(textBox1->Text));
		save->SaveData("Save\\local_save.txt");
	}
	};
}
