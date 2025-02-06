#pragma once

#include "MyQueue.h"
#include <iostream>
#include <string>
extern MyQueue<CreditCard>* CreditCardList;
extern MyQueue<CostHistory>* CostHistoryList;

namespace ExamBankSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для CostAllForm
	/// </summary>
	public ref class CostAllForm : public System::Windows::Forms::Form
	{
	public:
		CostAllForm(int x, int y)
		{
			InitializeComponent();
			this->Location = System::Drawing::Point(x, y);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~CostAllForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_close;

	private: System::Windows::Forms::Panel^ background_cost_history;
	private: System::Windows::Forms::Panel^ panel_back_front;



	private: System::Windows::Forms::Button^ btn_return;



	private: bool dragging = false;
	private: System::Drawing::Point offset;
	private: size_t card_switch = 0;
	private: System::Drawing::Color white_card_color = System::Drawing::Color::FromArgb(
		static_cast<System::Int32>(static_cast<System::Byte>(255)),
		static_cast<System::Int32>(static_cast<System::Byte>(250)),
		static_cast<System::Int32>(static_cast<System::Byte>(250)));
	private: System::Drawing::Color black_card_color = System::Drawing::Color::FromArgb(
		static_cast<System::Int32>(static_cast<System::Byte>(23)),
		static_cast<System::Int32>(static_cast<System::Byte>(23)),
		static_cast<System::Int32>(static_cast<System::Byte>(23)));

	private: System::Windows::Forms::Panel^ panel_move_form;
	private: System::Windows::Forms::Label^ label_name_form;
	private: System::Windows::Forms::Panel^ image_bank_logo;








	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CostAllForm::typeid));
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->background_cost_history = (gcnew System::Windows::Forms::Panel());
			this->panel_back_front = (gcnew System::Windows::Forms::Panel());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->panel_move_form = (gcnew System::Windows::Forms::Panel());
			this->label_name_form = (gcnew System::Windows::Forms::Label());
			this->image_bank_logo = (gcnew System::Windows::Forms::Panel());
			this->panel_back_front->SuspendLayout();
			this->panel_move_form->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_close
			// 
			this->btn_close->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->btn_close->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->btn_close->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_close->FlatAppearance->BorderSize = 0;
			this->btn_close->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_close->Font = (gcnew System::Drawing::Font(L"Candara", 14, System::Drawing::FontStyle::Bold));
			this->btn_close->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btn_close->Location = System::Drawing::Point(620, 0);
			this->btn_close->Margin = System::Windows::Forms::Padding(0);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(100, 40);
			this->btn_close->TabIndex = 0;
			this->btn_close->Text = L"⨉";
			this->btn_close->UseVisualStyleBackColor = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &CostAllForm::btn_close_Click);
			this->btn_close->MouseEnter += gcnew System::EventHandler(this, &CostAllForm::btn_close_MouseEnter);
			this->btn_close->MouseLeave += gcnew System::EventHandler(this, &CostAllForm::btn_close_MouseLeave);
			// 
			// background_cost_history
			// 
			this->background_cost_history->AutoScroll = true;
			this->background_cost_history->AutoScrollMinSize = System::Drawing::Size(0, 695);
			this->background_cost_history->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->background_cost_history->Location = System::Drawing::Point(50, 37);
			this->background_cost_history->Name = L"background_cost_history";
			this->background_cost_history->Size = System::Drawing::Size(640, 963);
			this->background_cost_history->TabIndex = 3;
			// 
			// panel_back_front
			// 
			this->panel_back_front->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->panel_back_front->Controls->Add(this->btn_return);
			this->panel_back_front->Location = System::Drawing::Point(50, 940);
			this->panel_back_front->Name = L"panel_back_front";
			this->panel_back_front->Size = System::Drawing::Size(640, 60);
			this->panel_back_front->TabIndex = 7;
			// 
			// btn_return
			// 
			this->btn_return->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->btn_return->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_return->FlatAppearance->BorderSize = 0;
			this->btn_return->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_return->Font = (gcnew System::Drawing::Font(L"Candara", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_return->ForeColor = System::Drawing::Color::Transparent;
			this->btn_return->Location = System::Drawing::Point(158, 10);
			this->btn_return->Margin = System::Windows::Forms::Padding(0);
			this->btn_return->Name = L"btn_return";
			this->btn_return->Size = System::Drawing::Size(324, 40);
			this->btn_return->TabIndex = 7;
			this->btn_return->Text = L"<- Back";
			this->btn_return->UseVisualStyleBackColor = false;
			this->btn_return->Click += gcnew System::EventHandler(this, &CostAllForm::btn_return_Click);
			this->btn_return->MouseEnter += gcnew System::EventHandler(this, &CostAllForm::btn_return_MouseEnter);
			this->btn_return->MouseLeave += gcnew System::EventHandler(this, &CostAllForm::btn_return_MouseLeave);
			// 
			// panel_move_form
			// 
			this->panel_move_form->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panel_move_form->Controls->Add(this->label_name_form);
			this->panel_move_form->Controls->Add(this->image_bank_logo);
			this->panel_move_form->Cursor = System::Windows::Forms::Cursors::SizeAll;
			this->panel_move_form->Location = System::Drawing::Point(0, 0);
			this->panel_move_form->Margin = System::Windows::Forms::Padding(0);
			this->panel_move_form->Name = L"panel_move_form";
			this->panel_move_form->Size = System::Drawing::Size(620, 40);
			this->panel_move_form->TabIndex = 9;
			this->panel_move_form->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CostAllForm::panel_move_form_MouseDown);
			this->panel_move_form->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &CostAllForm::panel_move_form_MouseMove);
			this->panel_move_form->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CostAllForm::panel_move_form_MouseUp);
			// 
			// label_name_form
			// 
			this->label_name_form->BackColor = System::Drawing::Color::Transparent;
			this->label_name_form->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label_name_form->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_form->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_form->Location = System::Drawing::Point(60, 0);
			this->label_name_form->Margin = System::Windows::Forms::Padding(0);
			this->label_name_form->Name = L"label_name_form";
			this->label_name_form->Size = System::Drawing::Size(98, 40);
			this->label_name_form->TabIndex = 10;
			this->label_name_form->Text = L"History";
			this->label_name_form->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// image_bank_logo
			// 
			this->image_bank_logo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_bank_logo.BackgroundImage")));
			this->image_bank_logo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_bank_logo->Cursor = System::Windows::Forms::Cursors::Default;
			this->image_bank_logo->Location = System::Drawing::Point(0, 0);
			this->image_bank_logo->Margin = System::Windows::Forms::Padding(0);
			this->image_bank_logo->Name = L"image_bank_logo";
			this->image_bank_logo->Size = System::Drawing::Size(60, 40);
			this->image_bank_logo->TabIndex = 11;
			// 
			// CostAllForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(720, 1000);
			this->Controls->Add(this->panel_back_front);
			this->Controls->Add(this->panel_move_form);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->background_cost_history);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CostAllForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"CostAllForm";
			this->Load += gcnew System::EventHandler(this, &CostAllForm::CostAllForm_Load);
			this->panel_back_front->ResumeLayout(false);
			this->panel_move_form->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CostAllForm_Load(System::Object^ sender, System::EventArgs^ e) {		
		for (size_t i = 0; i < CostHistoryList->GetSize(); i++) // 20 / max 9
		{
			Label^ temp_sum = gcnew Label();
			temp_sum->AutoSize = true;
			temp_sum->Font = (gcnew System::Drawing::Font(L"AIGDT", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			try
			{
				if (std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).TransferSumGet())) < 0) {
					temp_sum->ForeColor = System::Drawing::Color::Red;
				}
				else {
					temp_sum->ForeColor = System::Drawing::Color::Transparent;
				}
			}
			catch (...)
			{
				temp_sum->ForeColor = System::Drawing::Color::Transparent;
			}
			temp_sum->Location = System::Drawing::Point(10, 19);
			temp_sum->Name = L"temp_sum";
			temp_sum->Size = System::Drawing::Size(117, 39);
			temp_sum->Text = LocalToString(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).TransferSumGet()));
			temp_sum->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			background_cost_history->Controls->Add(temp_sum);

			Label^ temp_category = gcnew Label();
			temp_category->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			temp_category->Font = (gcnew System::Drawing::Font(L"Ebrima", 14.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			temp_category->ForeColor = System::Drawing::Color::Transparent;
			temp_category->Name = L"temp_category";
			temp_category->Text = LocalToString(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).CategoryGet()));
			temp_category->Size = System::Drawing::Size(300, 31);
			temp_category->Location = System::Drawing::Point(140, 5);
			temp_category->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			temp_category->RightToLeft = System::Windows::Forms::RightToLeft::No;
			background_cost_history->Controls->Add(temp_category);

			Label^ temp_date = gcnew Label();
			temp_date->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			temp_date->Font = (gcnew System::Drawing::Font(L"Ebrima", 14.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			temp_date->ForeColor = System::Drawing::Color::Transparent;
			temp_date->Name = L"temp_date";
			temp_date->Text = LocalToString(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).DateGet()));
			temp_date->Size = System::Drawing::Size(300, 31);
			temp_date->Location = System::Drawing::Point(140, 30);
			temp_date->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			temp_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
			background_cost_history->Controls->Add(temp_date);

			Panel^ cost_temp_panel = gcnew Panel();
			cost_temp_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			cost_temp_panel->Location = System::Drawing::Point(15, 10 + 75 * i);
			cost_temp_panel->Margin = System::Windows::Forms::Padding(0, 10, 0, 0);
			cost_temp_panel->Name = L"cost_temp_panel" + i.ToString();
			cost_temp_panel->Size = System::Drawing::Size(450, 65);
			cost_temp_panel->Controls->Add(temp_sum);
			cost_temp_panel->Controls->Add(temp_category);
			cost_temp_panel->Controls->Add(temp_date);
			background_cost_history->Controls->Add(cost_temp_panel);
		}
		Panel^ cost_temp_panel = gcnew Panel();
		cost_temp_panel->Location = System::Drawing::Point(15, 10 + 75 * CostHistoryList->GetSize());
		cost_temp_panel->Margin = System::Windows::Forms::Padding(0, 10, 0, 0);
		cost_temp_panel->Name = L"cost_temp_panel" + CostHistoryList->GetSize().ToString();
		cost_temp_panel->Size = System::Drawing::Size(450, 65);
		background_cost_history->Controls->Add(cost_temp_panel);
	}

	
	private: std::string encypt(std::string input) {
		const std::string numbers_count = "1234567890";
		const std::string alphabet_count = "abcdefghijklmnopCreditCardListrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (size_t i = 0; i < input.length(); i++)
		{
			if (input[i] >= 48 && input[i] <= 57) {
				for (size_t j = 0; j < numbers_count.length(); j++)
				{
					if (input[i] == numbers_count[j]) {
						input[i] = numbers_count[(j + 7) % 10];
						break;
					}
				}
			}
			else if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) {
				for (size_t j = 0; j < alphabet_count.length(); j++)
				{
					if (input[i] == alphabet_count[j]) {
						input[i] = alphabet_count[(j + 11) % 52];
						break;
					}
				}
			}
		}
		return input;
	}
	private: std::string decypt(std::string input) {
		const std::string numbers_count = "0123456789";
		const std::string alphabet_count = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		for (size_t i = 0; i < input.length(); i++)
		{
			if (input[i] >= 48 && input[i] <= 57) {
				for (size_t j = 0; j < numbers_count.length(); j++)
				{
					if (input[i] == numbers_count[j]) {
						if (int(j) - 7 <= 0) {
							input[i] = numbers_count[(3 + int(j)) % 10];
						}
						else {
							input[i] = numbers_count[(j - 7) % 10];
						}
						break;
					}
				}
			}
			else if ((input[i] >= 65 && input[i] <= 90) || (input[i] >= 97 && input[i] <= 122)) {
				for (size_t j = 0; j < alphabet_count.length(); j++)
				{
					if (input[i] == alphabet_count[j]) {
						if (int(j) - 11 <= 0) {
							input[i] = alphabet_count[(41 + j) % 52];
						}
						else {
							input[i] = alphabet_count[(j - 11) % 52];
						}
						break;
					}
				}
			}
		}
		return input;
	}
	private: System::String^ LocalToString(const std::string toString) {
		return gcnew System::String(toString.c_str());
	}


	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btn_return_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void panel_move_form_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			dragging = true;
			offset = System::Drawing::Point(e->X, e->Y);
		}
	}
	private: System::Void panel_move_form_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (dragging) {
		this->Left = Cursor->Position.X - offset.X;
		this->Top = Cursor->Position.Y - offset.Y;
	}
}
	private: System::Void panel_move_form_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	dragging = false;
}
	private: System::Void btn_close_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			this->btn_close->BackColor = System::Drawing::Color::FromArgb(
				static_cast<System::Int32>(static_cast<System::Byte>(133)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)));
		}
	private: System::Void btn_close_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btn_close->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)),
			static_cast<System::Int32>(static_cast<System::Byte>(20)));
	}
	private: System::Void btn_return_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->btn_return->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(185)),
			static_cast<System::Int32>(static_cast<System::Byte>(123)),
			static_cast<System::Int32>(static_cast<System::Byte>(235)));
	}
	private: System::Void btn_return_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btn_return->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(69)),
			static_cast<System::Int32>(static_cast<System::Byte>(69)),
			static_cast<System::Int32>(static_cast<System::Byte>(69)));
	}
};

}

