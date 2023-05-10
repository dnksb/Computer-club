#pragma once
#include "theme.h"
#include "local_save.h"
#include "converter.h"

namespace computerClub {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ help
	/// </summary>
	public ref class help : public System::Windows::Forms::Form
	{
	public:
		help(Theme* theme, Save* save)
		{
			InitializeComponent();
			this->save = save;
			this->theme = theme;
			set_theme();
		}

		Save* save;
		Theme* theme;
	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~help()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
		void set_theme()
		{
			label1->ForeColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->TextColor()));

			label1->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));
			this->BackColor = System::Drawing::Color::FromName(Conv::ToSystemString(theme->FormBackGround()));

			if (save->Lang() != "Save\\rus_Rus.txt")
			{
				this->label1->Text = "this program is necessary for the manager of a computer club\nto account for the operation of computers and their profitability\nthere are 4 types of commands\nthe person has arrived (the computer should not be specified)\nthe person is waiting (the computer should not be specified)\nthe person has sat down (the computer must be specified)\nthe person has left( computer is not required)";
			}
			else
			{
				this->label1->Text = "эта программа необхоима дл€ менеджера компьютерного клуба\nдл€ учета работы компьютеров и их рентабильности\nесть 4 тип команд\nчеловек пришел(компьютер не надо указывать)\nчеловек ожидает(компьютер не надо указывать)\nчеловек сел(компьютер надо указывать)\nчлеовек ушел(компьютер не надо указывать)";
			}
		}
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->MinimumSize = System::Drawing::Size(350, 330);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(350, 330);
			this->label1->TabIndex = 0;
			this->label1->Text = L"The first file must be such:amount of computers";
			// 
			// help
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 161);
			this->Controls->Add(this->label1);
			this->MaximumSize = System::Drawing::Size(400, 200);
			this->MinimumSize = System::Drawing::Size(400, 200);
			this->Name = L"help";
			this->Text = L"help";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
