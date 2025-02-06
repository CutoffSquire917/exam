#pragma once

#include "MyQueue.h"
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <msclr/marshal_cppstd.h> 
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
	/// Сводка для ReceivingForm
	/// </summary>
	public ref class ReceivingForm : public System::Windows::Forms::Form
	{
	public:
		ReceivingForm(const int x, const int y, const size_t card_now)
		{
			InitializeComponent();
			this->Location = System::Drawing::Point(x, y);
			card_switch = card_now;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~ReceivingForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::Panel^ background_panel;
	private: System::Windows::Forms::Panel^ panel_move_form;
	private: System::Windows::Forms::Panel^ panel_back_front;
	private: System::Windows::Forms::Panel^ panel_for_btn_return;
	private: System::Windows::Forms::Button^ btn_return;
	private: System::Windows::Forms::Label^ label_bet;
	private: System::Windows::Forms::Label^ label_to_enter_sum;
	private: System::Windows::Forms::TextBox^ sum_textbox;
	private: System::Windows::Forms::Button^ btn_try;
	private: System::Windows::Forms::Label^ label_error;
	private: System::Windows::Forms::Button^ btn_even;
	private: System::Windows::Forms::Button^ btn_odd;
	private: System::Windows::Forms::Label^ label_rulet2;
	private: System::Windows::Forms::Label^ label_rulet1;
	private: System::Windows::Forms::Label^ label_result;

	private: bool dragging = false;
	private: System::Drawing::Point offset;
	private: size_t card_switch;
	private: bool odd_not_even = true;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ReceivingForm::typeid));
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->label_bet = (gcnew System::Windows::Forms::Label());
			this->background_panel = (gcnew System::Windows::Forms::Panel());
			this->label_rulet2 = (gcnew System::Windows::Forms::Label());
			this->label_rulet1 = (gcnew System::Windows::Forms::Label());
			this->btn_even = (gcnew System::Windows::Forms::Button());
			this->btn_odd = (gcnew System::Windows::Forms::Button());
			this->label_error = (gcnew System::Windows::Forms::Label());
			this->btn_try = (gcnew System::Windows::Forms::Button());
			this->sum_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label_to_enter_sum = (gcnew System::Windows::Forms::Label());
			this->panel_move_form = (gcnew System::Windows::Forms::Panel());
			this->panel_back_front = (gcnew System::Windows::Forms::Panel());
			this->label_name_form = (gcnew System::Windows::Forms::Label());
			this->image_bank_logo = (gcnew System::Windows::Forms::Panel());
			this->panel_for_btn_return = (gcnew System::Windows::Forms::Panel());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->label_result = (gcnew System::Windows::Forms::Label());
			this->background_panel->SuspendLayout();
			this->panel_move_form->SuspendLayout();
			this->panel_back_front->SuspendLayout();
			this->panel_for_btn_return->SuspendLayout();
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
			this->btn_close->Click += gcnew System::EventHandler(this, &ReceivingForm::btn_close_Click);
			this->btn_close->MouseEnter += gcnew System::EventHandler(this, &ReceivingForm::btn_close_MouseEnter);
			this->btn_close->MouseLeave += gcnew System::EventHandler(this, &ReceivingForm::btn_close_MouseLeave);
			// 
			// label_bet
			// 
			this->label_bet->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_bet->Font = (gcnew System::Drawing::Font(L"Vineta BT", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_bet->ForeColor = System::Drawing::Color::Transparent;
			this->label_bet->Location = System::Drawing::Point(140, 22);
			this->label_bet->Name = L"label_bet";
			this->label_bet->Size = System::Drawing::Size(440, 58);
			this->label_bet->TabIndex = 5;
			this->label_bet->Text = L"0.00";
			this->label_bet->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// background_panel
			// 
			this->background_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(31)));
			this->background_panel->Controls->Add(this->label_rulet2);
			this->background_panel->Controls->Add(this->label_rulet1);
			this->background_panel->Controls->Add(this->btn_even);
			this->background_panel->Controls->Add(this->btn_odd);
			this->background_panel->Controls->Add(this->label_error);
			this->background_panel->Controls->Add(this->label_bet);
			this->background_panel->Controls->Add(this->btn_try);
			this->background_panel->Controls->Add(this->sum_textbox);
			this->background_panel->Controls->Add(this->label_to_enter_sum);
			this->background_panel->Location = System::Drawing::Point(0, 351);
			this->background_panel->Margin = System::Windows::Forms::Padding(0);
			this->background_panel->Name = L"background_panel";
			this->background_panel->Size = System::Drawing::Size(720, 353);
			this->background_panel->TabIndex = 3;
			// 
			// label_rulet2
			// 
			this->label_rulet2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_rulet2->Font = (gcnew System::Drawing::Font(L"Vineta BT", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_rulet2->ForeColor = System::Drawing::Color::Gold;
			this->label_rulet2->Location = System::Drawing::Point(583, 0);
			this->label_rulet2->Name = L"label_rulet2";
			this->label_rulet2->Size = System::Drawing::Size(137, 353);
			this->label_rulet2->TabIndex = 18;
			this->label_rulet2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_rulet1
			// 
			this->label_rulet1->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_rulet1->Font = (gcnew System::Drawing::Font(L"Vineta BT", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_rulet1->ForeColor = System::Drawing::Color::Gold;
			this->label_rulet1->Location = System::Drawing::Point(0, 0);
			this->label_rulet1->Name = L"label_rulet1";
			this->label_rulet1->Size = System::Drawing::Size(137, 353);
			this->label_rulet1->TabIndex = 17;
			this->label_rulet1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_even
			// 
			this->btn_even->BackColor = System::Drawing::Color::Black;
			this->btn_even->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_even->FlatAppearance->BorderSize = 0;
			this->btn_even->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_even->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_even->ForeColor = System::Drawing::Color::Transparent;
			this->btn_even->Location = System::Drawing::Point(360, 213);
			this->btn_even->Margin = System::Windows::Forms::Padding(0);
			this->btn_even->Name = L"btn_even";
			this->btn_even->Size = System::Drawing::Size(130, 50);
			this->btn_even->TabIndex = 16;
			this->btn_even->Text = L"Even";
			this->btn_even->UseVisualStyleBackColor = false;
			this->btn_even->Click += gcnew System::EventHandler(this, &ReceivingForm::btn_even_Click);
			// 
			// btn_odd
			// 
			this->btn_odd->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_odd->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_odd->FlatAppearance->BorderSize = 0;
			this->btn_odd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_odd->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_odd->ForeColor = System::Drawing::Color::Transparent;
			this->btn_odd->Location = System::Drawing::Point(230, 213);
			this->btn_odd->Margin = System::Windows::Forms::Padding(0);
			this->btn_odd->Name = L"btn_odd";
			this->btn_odd->Size = System::Drawing::Size(130, 50);
			this->btn_odd->TabIndex = 15;
			this->btn_odd->Text = L"Odd";
			this->btn_odd->UseVisualStyleBackColor = false;
			this->btn_odd->Click += gcnew System::EventHandler(this, &ReceivingForm::btn_odd_Click);
			// 
			// label_error
			// 
			this->label_error->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_error->Font = (gcnew System::Drawing::Font(L"SansSerif", 14));
			this->label_error->ForeColor = System::Drawing::Color::Gold;
			this->label_error->Location = System::Drawing::Point(140, 80);
			this->label_error->Margin = System::Windows::Forms::Padding(0);
			this->label_error->Name = L"label_error";
			this->label_error->Size = System::Drawing::Size(440, 33);
			this->label_error->TabIndex = 14;
			this->label_error->Text = L" ";
			this->label_error->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btn_try
			// 
			this->btn_try->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_try->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_try->FlatAppearance->BorderSize = 0;
			this->btn_try->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_try->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_try->ForeColor = System::Drawing::Color::Transparent;
			this->btn_try->Location = System::Drawing::Point(140, 278);
			this->btn_try->Margin = System::Windows::Forms::Padding(0);
			this->btn_try->Name = L"btn_try";
			this->btn_try->Size = System::Drawing::Size(440, 50);
			this->btn_try->TabIndex = 8;
			this->btn_try->Text = L"TRY!!!";
			this->btn_try->UseVisualStyleBackColor = false;
			this->btn_try->Click += gcnew System::EventHandler(this, &ReceivingForm::btn_try_Click);
			this->btn_try->MouseEnter += gcnew System::EventHandler(this, &ReceivingForm::btn_try_MouseEnter);
			this->btn_try->MouseLeave += gcnew System::EventHandler(this, &ReceivingForm::btn_try_MouseLeave);
			// 
			// sum_textbox
			// 
			this->sum_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->sum_textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->sum_textbox->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 21));
			this->sum_textbox->ForeColor = System::Drawing::Color::Transparent;
			this->sum_textbox->Location = System::Drawing::Point(140, 155);
			this->sum_textbox->Margin = System::Windows::Forms::Padding(0);
			this->sum_textbox->MaximumSize = System::Drawing::Size(566, 42);
			this->sum_textbox->MaxLength = 8;
			this->sum_textbox->Name = L"sum_textbox";
			this->sum_textbox->Size = System::Drawing::Size(440, 42);
			this->sum_textbox->TabIndex = 13;
			this->sum_textbox->TextChanged += gcnew System::EventHandler(this, &ReceivingForm::sum_textbox_TextChanged);
			// 
			// label_to_enter_sum
			// 
			this->label_to_enter_sum->AutoSize = true;
			this->label_to_enter_sum->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_to_enter_sum->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_to_enter_sum->ForeColor = System::Drawing::Color::Transparent;
			this->label_to_enter_sum->Location = System::Drawing::Point(133, 113);
			this->label_to_enter_sum->Margin = System::Windows::Forms::Padding(0);
			this->label_to_enter_sum->Name = L"label_to_enter_sum";
			this->label_to_enter_sum->Size = System::Drawing::Size(316, 41);
			this->label_to_enter_sum->TabIndex = 7;
			this->label_to_enter_sum->Text = L"Enter the amount:";
			this->label_to_enter_sum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_move_form
			// 
			this->panel_move_form->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panel_move_form->Controls->Add(this->panel_back_front);
			this->panel_move_form->Cursor = System::Windows::Forms::Cursors::SizeAll;
			this->panel_move_form->Location = System::Drawing::Point(0, 0);
			this->panel_move_form->Margin = System::Windows::Forms::Padding(0);
			this->panel_move_form->Name = L"panel_move_form";
			this->panel_move_form->Size = System::Drawing::Size(620, 40);
			this->panel_move_form->TabIndex = 8;
			this->panel_move_form->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ReceivingForm::panel_move_form_MouseDown);
			this->panel_move_form->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &ReceivingForm::panel_move_form_MouseMove);
			this->panel_move_form->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ReceivingForm::panel_move_form_MouseUp);
			// 
			// panel_back_front
			// 
			this->panel_back_front->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->panel_back_front->Controls->Add(this->label_name_form);
			this->panel_back_front->Controls->Add(this->image_bank_logo);
			this->panel_back_front->Location = System::Drawing::Point(-50, -20);
			this->panel_back_front->Margin = System::Windows::Forms::Padding(0);
			this->panel_back_front->Name = L"panel_back_front";
			this->panel_back_front->Size = System::Drawing::Size(720, 80);
			this->panel_back_front->TabIndex = 9;
			// 
			// label_name_form
			// 
			this->label_name_form->BackColor = System::Drawing::Color::Transparent;
			this->label_name_form->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label_name_form->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_form->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_form->Location = System::Drawing::Point(110, 20);
			this->label_name_form->Margin = System::Windows::Forms::Padding(0);
			this->label_name_form->Name = L"label_name_form";
			this->label_name_form->Size = System::Drawing::Size(193, 40);
			this->label_name_form->TabIndex = 20;
			this->label_name_form->Text = L"Online bank casino";
			this->label_name_form->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// image_bank_logo
			// 
			this->image_bank_logo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_bank_logo.BackgroundImage")));
			this->image_bank_logo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_bank_logo->Cursor = System::Windows::Forms::Cursors::Default;
			this->image_bank_logo->Location = System::Drawing::Point(50, 20);
			this->image_bank_logo->Margin = System::Windows::Forms::Padding(0);
			this->image_bank_logo->Name = L"image_bank_logo";
			this->image_bank_logo->Size = System::Drawing::Size(60, 40);
			this->image_bank_logo->TabIndex = 21;
			// 
			// panel_for_btn_return
			// 
			this->panel_for_btn_return->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->panel_for_btn_return->Controls->Add(this->btn_return);
			this->panel_for_btn_return->Location = System::Drawing::Point(0, 920);
			this->panel_for_btn_return->Margin = System::Windows::Forms::Padding(0);
			this->panel_for_btn_return->Name = L"panel_for_btn_return";
			this->panel_for_btn_return->Size = System::Drawing::Size(720, 80);
			this->panel_for_btn_return->TabIndex = 9;
			// 
			// btn_return
			// 
			this->btn_return->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(145)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_return->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_return->FlatAppearance->BorderSize = 0;
			this->btn_return->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_return->Font = (gcnew System::Drawing::Font(L"Candara", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_return->ForeColor = System::Drawing::Color::Transparent;
			this->btn_return->Location = System::Drawing::Point(10, 15);
			this->btn_return->Margin = System::Windows::Forms::Padding(0);
			this->btn_return->Name = L"btn_return";
			this->btn_return->Size = System::Drawing::Size(700, 50);
			this->btn_return->TabIndex = 7;
			this->btn_return->Text = L"<- Back";
			this->btn_return->UseVisualStyleBackColor = false;
			this->btn_return->Click += gcnew System::EventHandler(this, &ReceivingForm::btn_return_Click);
			this->btn_return->MouseEnter += gcnew System::EventHandler(this, &ReceivingForm::btn_return_MouseEnter);
			this->btn_return->MouseLeave += gcnew System::EventHandler(this, &ReceivingForm::btn_return_MouseLeave);
			// 
			// label_result
			// 
			this->label_result->BackColor = System::Drawing::Color::Transparent;
			this->label_result->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_result->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 25.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_result->ForeColor = System::Drawing::Color::Gold;
			this->label_result->Location = System::Drawing::Point(102, 140);
			this->label_result->Name = L"label_result";
			this->label_result->Size = System::Drawing::Size(518, 211);
			this->label_result->TabIndex = 19;
			this->label_result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ReceivingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(720, 1000);
			this->Controls->Add(this->label_result);
			this->Controls->Add(this->panel_for_btn_return);
			this->Controls->Add(this->panel_move_form);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->background_panel);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(480, 0);
			this->Name = L"ReceivingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ReceivingForm";
			this->Load += gcnew System::EventHandler(this, &ReceivingForm::ReceivingForm_Load);
			this->background_panel->ResumeLayout(false);
			this->background_panel->PerformLayout();
			this->panel_move_form->ResumeLayout(false);
			this->panel_back_front->ResumeLayout(false);
			this->panel_for_btn_return->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ReceivingForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: std::string encypt(std::string input) {
		const std::string numbers_count = "1234567890";
		const std::string alphabet_count = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
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
	private: std::string GetStringFromLabel(System::String^ toString) {
		return msclr::interop::marshal_as<std::string>(const_cast<System::String^>(toString));
	}
	private: void CostHistoryToFile(const CostHistory obj, const std::string fileWay) {
		try
		{
			std::ofstream file;
			file.open(fileWay, std::ofstream::app);

			if (!file.is_open()) {
				throw std::runtime_error("FILE IS DAMAGED");
			}
			std::string temp_transfer_sum = obj.TransferSumGet();
			std::string temp_date = obj.DateGet();
			if (temp_transfer_sum[0] == '-') {
				temp_transfer_sum.replace(0, 1, "*");
			}
			else if (temp_transfer_sum[0] == '+') {
				temp_transfer_sum.replace(0, 1, "~");
			}
			temp_transfer_sum.replace(temp_transfer_sum.find("."), 1, "#");
			for (size_t i = 0; i < 2; i++)
			{
				temp_date.erase(temp_date.find("."), 1);
			}
			file << temp_transfer_sum << "&" << obj.CategoryGet() << "&" << temp_date << "\n";
			file.close();
		}
		catch (...)
		{
			throw std::runtime_error("FILE IS DAMAGED");
		}
	}

	private: System::Void btn_close_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
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
	private: System::Void btn_return_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btn_try_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GetStringFromLabel(this->label_error->Text) != "") {
			this->label_error->Text = "Unable to execute";
			return;
		}
		int rand_num = rand() % 36 + 1;
		this->label_rulet1->Text = rand_num.ToString();
		this->label_rulet2->Text = rand_num.ToString();
		std::time_t now = std::time(nullptr);
		std::tm local_time;
		localtime_s(&local_time, &now);
		std::string temp_day = std::to_string(local_time.tm_mday);
		if (temp_day.length() <= 1) {
			temp_day.insert(0, "0");
		}
		std::string temp_month = std::to_string(local_time.tm_mon + 1);
		if (temp_month.length() <= 1) {
			temp_month.insert(0, "0");
		}
		double temp_new_balance;
		if ((odd_not_even && rand_num % 2 != 0) || (!odd_not_even && rand_num % 2 == 0)) {
			temp_new_balance = std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance())) + std::stod(GetStringFromLabel(this->label_bet->Text));
			CostHistoryList->AddToEnd(CostHistory(encypt("+" + GetStringFromLabel(this->label_bet->Text)), encypt("Casino"), encypt(temp_day + temp_month + std::to_string(local_time.tm_year - 100))));
			this->label_result->Text = "YOU WON!!!\n+" + LocalToString(GetStringFromLabel((this->label_bet->Text))) + "$";
		}
		else {
			temp_new_balance = std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance())) - std::stod(GetStringFromLabel(this->label_bet->Text));
			std::cout << decypt(CreditCardList->GetValue(card_switch).GetCardBalance()) << " - " << GetStringFromLabel(this->label_bet->Text) << "\n";
			CostHistoryList->AddToEnd(CostHistory(encypt("-" + GetStringFromLabel(this->label_bet->Text)), encypt("Casino"), encypt(temp_day + temp_month + std::to_string(local_time.tm_year - 100))));
			this->label_result->Text = "YOU LOST!!!\nTry again!";
			if (std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance())) < 0) {
				this->label_error->Text = "Insufficient funds";
			}
		}
		CostHistoryToFile(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1), "private/CostHistoryList.txt");
		CreditCardList->GetValue(card_switch).SetCardBalance(encypt(std::to_string(temp_new_balance).erase(std::to_string(temp_new_balance).length() - 4, 4)));

	}
	private: System::Void btn_even_Click(System::Object^ sender, System::EventArgs^ e) {
			odd_not_even = false;
			this->btn_even->BackColor = System::Drawing::Color::FromArgb(
				static_cast<System::Int32>(static_cast<System::Byte>(145)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_odd->BackColor = System::Drawing::Color::FromArgb(
				static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
		}
	private: System::Void btn_odd_Click(System::Object^ sender, System::EventArgs^ e) {
		odd_not_even = true;
		this->btn_odd->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(145)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		this->btn_even->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
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
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
		
	}
	private: System::Void btn_return_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btn_return->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(145)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
	}
	private: System::Void btn_try_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->btn_try->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
	}
	private: System::Void btn_try_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btn_try->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(145)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
	}
	

	private: System::Void sum_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		std::string temp_sum = GetStringFromLabel(this->sum_textbox->Text);
		try
		{
			if (temp_sum == "") {
				this->label_bet->Text = "0.00";
			}
			double res = std::stod(temp_sum);
			if ((temp_sum[temp_sum.length() - 1] < '0' || temp_sum[temp_sum.length() - 1] > '9') && temp_sum[temp_sum.length() - 1] != '.') {
				temp_sum.pop_back();
				this->sum_textbox->Text = LocalToString(temp_sum.c_str());
			}
			if (res < 0) {
				res *= -1;
			}
			if (res > 100000.00) {
				this->sum_textbox->Text = "100000.00";
				this->label_bet->Text = "100000.00";
			}
			else if (res > std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()))) {
				this->sum_textbox->Text = LocalToString(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()).c_str());
				this->label_bet->Text = LocalToString(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()).c_str());
			}
			else {
				this->label_bet->Text = LocalToString(std::to_string(res).erase(std::to_string(res).length() - 4, 4).c_str());
			}
			this->label_error->Text = "";
		}
		catch (...)
		{
			this->label_error->Text = "The amount is incorrect";
			this->label_bet->Text = "0.00";
		}
	}
	
};

}