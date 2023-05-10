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
	/// ������ ��� help
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
		/// ���������� ��� ������������ �������.
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
				this->label1->Text = "��� ��������� ��������� ��� ��������� ������������� �����\n��� ����� ������ ����������� � �� ��������������\n���� 4 ��� ������\n������� ������(��������� �� ���� ���������)\n������� �������(��������� �� ���� ���������)\n������� ���(��������� ���� ���������)\n������� ����(��������� �� ���� ���������)";
			}
		}
	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
