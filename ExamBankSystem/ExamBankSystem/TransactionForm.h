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
	/// Сводка для TransactionForm
	/// </summary>
	public ref class TransactionForm : public System::Windows::Forms::Form
	{
	public:
		TransactionForm(const int x, const int y, const size_t card_now)
		{
			InitializeComponent();
			this->Location = System::Drawing::Point(x, y);
			this->card_number->Text = gcnew System::String(decypt(CreditCardList->GetValue(card_now).GetCardNumber()).c_str());
			card_switch = card_now;
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TransactionForm()
		{
			if (components)
			{
				delete components;
			}
		}
	
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::Panel^ card_panel;
	private: System::Windows::Forms::Label^ card_number;
	private: System::Windows::Forms::Panel^ background_card;
	private: System::Windows::Forms::Panel^ background_cost_history;
	private: System::Windows::Forms::Panel^ panel_move_form;
	private: System::Windows::Forms::Panel^ panel_back_front;
	private: System::Windows::Forms::Panel^ panel_for_btn_return;
	private: System::Windows::Forms::Button^ btn_return;
	private: System::Windows::Forms::Panel^ arrow_down_to_card;
	private: System::Windows::Forms::Label^ to_card_number;
	private: System::Windows::Forms::Panel^ arrow_down_to_sum;
	private: System::Windows::Forms::Label^ card_balance;
	private: System::Windows::Forms::Label^ label_to_select_card;
	private: System::Windows::Forms::Label^ label_to_select_another_card;
	private: System::Windows::Forms::Label^ label_to_enter_sum;
	private: System::Windows::Forms::Label^ label_select_card;
	private: System::Windows::Forms::TextBox^ card_textbox;
	private: System::Windows::Forms::TextBox^ sum_textbox;
	private: System::Windows::Forms::Panel^ btn_select_card;
	private: System::Windows::Forms::Button^ btn_send;
	private: System::Windows::Forms::Panel^ panel_card_list;
	private: System::Windows::Forms::Label^ label_error;

	private: bool dragging = false;
	private: System::Drawing::Point offset;
	private: bool panel_card_list_visible = false;
	private: size_t card_switch;
	private: System::Windows::Forms::Label^ max_card_balance;
	private: System::Windows::Forms::Label^ label_name_form;
	private: System::Windows::Forms::Panel^ image_bank_logo;
	private: ref struct TempCardInfo {
		String^ temp_card_number;
		size_t temp_card_switch;
	};

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TransactionForm::typeid));
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->card_panel = (gcnew System::Windows::Forms::Panel());
			this->max_card_balance = (gcnew System::Windows::Forms::Label());
			this->card_balance = (gcnew System::Windows::Forms::Label());
			this->arrow_down_to_card = (gcnew System::Windows::Forms::Panel());
			this->to_card_number = (gcnew System::Windows::Forms::Label());
			this->arrow_down_to_sum = (gcnew System::Windows::Forms::Panel());
			this->card_number = (gcnew System::Windows::Forms::Label());
			this->background_card = (gcnew System::Windows::Forms::Panel());
			this->background_cost_history = (gcnew System::Windows::Forms::Panel());
			this->label_error = (gcnew System::Windows::Forms::Label());
			this->panel_card_list = (gcnew System::Windows::Forms::Panel());
			this->btn_send = (gcnew System::Windows::Forms::Button());
			this->btn_select_card = (gcnew System::Windows::Forms::Panel());
			this->sum_textbox = (gcnew System::Windows::Forms::TextBox());
			this->card_textbox = (gcnew System::Windows::Forms::TextBox());
			this->label_select_card = (gcnew System::Windows::Forms::Label());
			this->label_to_select_another_card = (gcnew System::Windows::Forms::Label());
			this->label_to_enter_sum = (gcnew System::Windows::Forms::Label());
			this->label_to_select_card = (gcnew System::Windows::Forms::Label());
			this->panel_move_form = (gcnew System::Windows::Forms::Panel());
			this->panel_back_front = (gcnew System::Windows::Forms::Panel());
			this->panel_for_btn_return = (gcnew System::Windows::Forms::Panel());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->label_name_form = (gcnew System::Windows::Forms::Label());
			this->image_bank_logo = (gcnew System::Windows::Forms::Panel());
			this->card_panel->SuspendLayout();
			this->background_cost_history->SuspendLayout();
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
			this->btn_close->Click += gcnew System::EventHandler(this, &TransactionForm::btn_close_Click);
			this->btn_close->MouseEnter += gcnew System::EventHandler(this, &TransactionForm::btn_close_MouseEnter);
			this->btn_close->MouseLeave += gcnew System::EventHandler(this, &TransactionForm::btn_close_MouseLeave);
			// 
			// card_panel
			// 
			this->card_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->card_panel->Controls->Add(this->max_card_balance);
			this->card_panel->Controls->Add(this->card_balance);
			this->card_panel->Controls->Add(this->arrow_down_to_card);
			this->card_panel->Controls->Add(this->to_card_number);
			this->card_panel->Controls->Add(this->arrow_down_to_sum);
			this->card_panel->Controls->Add(this->card_number);
			this->card_panel->Cursor = System::Windows::Forms::Cursors::Default;
			this->card_panel->Location = System::Drawing::Point(80, 60);
			this->card_panel->Name = L"card_panel";
			this->card_panel->Size = System::Drawing::Size(560, 300);
			this->card_panel->TabIndex = 1;
			// 
			// max_card_balance
			// 
			this->max_card_balance->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->max_card_balance->Font = (gcnew System::Drawing::Font(L"Verdana", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->max_card_balance->ForeColor = System::Drawing::Color::Gray;
			this->max_card_balance->Location = System::Drawing::Point(0, 154);
			this->max_card_balance->Name = L"max_card_balance";
			this->max_card_balance->Size = System::Drawing::Size(560, 28);
			this->max_card_balance->TabIndex = 6;
			this->max_card_balance->Text = L"0.00";
			this->max_card_balance->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// card_balance
			// 
			this->card_balance->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->card_balance->Font = (gcnew System::Drawing::Font(L"Verdana", 22, System::Drawing::FontStyle::Bold));
			this->card_balance->ForeColor = System::Drawing::Color::Transparent;
			this->card_balance->Location = System::Drawing::Point(0, 109);
			this->card_balance->Name = L"card_balance";
			this->card_balance->Size = System::Drawing::Size(560, 45);
			this->card_balance->TabIndex = 5;
			this->card_balance->Text = L"0.00";
			this->card_balance->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// arrow_down_to_card
			// 
			this->arrow_down_to_card->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->arrow_down_to_card->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"arrow_down_to_card.BackgroundImage")));
			this->arrow_down_to_card->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->arrow_down_to_card->Cursor = System::Windows::Forms::Cursors::Hand;
			this->arrow_down_to_card->Location = System::Drawing::Point(245, 185);
			this->arrow_down_to_card->Name = L"arrow_down_to_card";
			this->arrow_down_to_card->Size = System::Drawing::Size(70, 31);
			this->arrow_down_to_card->TabIndex = 3;
			// 
			// to_card_number
			// 
			this->to_card_number->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->to_card_number->Font = (gcnew System::Drawing::Font(L"Verdana", 22, System::Drawing::FontStyle::Bold));
			this->to_card_number->ForeColor = System::Drawing::Color::Transparent;
			this->to_card_number->Location = System::Drawing::Point(0, 221);
			this->to_card_number->Margin = System::Windows::Forms::Padding(0);
			this->to_card_number->Name = L"to_card_number";
			this->to_card_number->Size = System::Drawing::Size(560, 45);
			this->to_card_number->TabIndex = 4;
			this->to_card_number->Text = L"XXXX XXXX XXXX XXXX";
			this->to_card_number->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// arrow_down_to_sum
			// 
			this->arrow_down_to_sum->AutoSize = true;
			this->arrow_down_to_sum->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->arrow_down_to_sum->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"arrow_down_to_sum.BackgroundImage")));
			this->arrow_down_to_sum->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->arrow_down_to_sum->Cursor = System::Windows::Forms::Cursors::Hand;
			this->arrow_down_to_sum->Location = System::Drawing::Point(245, 75);
			this->arrow_down_to_sum->Name = L"arrow_down_to_sum";
			this->arrow_down_to_sum->Size = System::Drawing::Size(70, 31);
			this->arrow_down_to_sum->TabIndex = 2;
			// 
			// card_number
			// 
			this->card_number->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->card_number->Font = (gcnew System::Drawing::Font(L"Verdana", 22, System::Drawing::FontStyle::Bold));
			this->card_number->ForeColor = System::Drawing::Color::Transparent;
			this->card_number->Location = System::Drawing::Point(0, 17);
			this->card_number->Margin = System::Windows::Forms::Padding(0);
			this->card_number->Name = L"card_number";
			this->card_number->Size = System::Drawing::Size(560, 45);
			this->card_number->TabIndex = 0;
			this->card_number->Text = L"0000 0000 0000 0000";
			this->card_number->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// background_card
			// 
			this->background_card->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)), static_cast<System::Int32>(static_cast<System::Byte>(123)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->background_card->Location = System::Drawing::Point(0, 40);
			this->background_card->Margin = System::Windows::Forms::Padding(0);
			this->background_card->Name = L"background_card";
			this->background_card->Size = System::Drawing::Size(720, 370);
			this->background_card->TabIndex = 3;
			// 
			// background_cost_history
			// 
			this->background_cost_history->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->background_cost_history->Controls->Add(this->label_error);
			this->background_cost_history->Controls->Add(this->panel_card_list);
			this->background_cost_history->Controls->Add(this->btn_send);
			this->background_cost_history->Controls->Add(this->btn_select_card);
			this->background_cost_history->Controls->Add(this->sum_textbox);
			this->background_cost_history->Controls->Add(this->card_textbox);
			this->background_cost_history->Controls->Add(this->label_select_card);
			this->background_cost_history->Controls->Add(this->label_to_select_another_card);
			this->background_cost_history->Controls->Add(this->label_to_enter_sum);
			this->background_cost_history->Controls->Add(this->label_to_select_card);
			this->background_cost_history->Location = System::Drawing::Point(50, 420);
			this->background_cost_history->Margin = System::Windows::Forms::Padding(0);
			this->background_cost_history->Name = L"background_cost_history";
			this->background_cost_history->Size = System::Drawing::Size(620, 500);
			this->background_cost_history->TabIndex = 3;
			// 
			// label_error
			// 
			this->label_error->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_error->Font = (gcnew System::Drawing::Font(L"SansSerif", 16));
			this->label_error->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label_error->Location = System::Drawing::Point(0, 440);
			this->label_error->Margin = System::Windows::Forms::Padding(0);
			this->label_error->Name = L"label_error";
			this->label_error->Size = System::Drawing::Size(620, 41);
			this->label_error->TabIndex = 14;
			this->label_error->Text = L" ";
			this->label_error->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_card_list
			// 
			this->panel_card_list->AutoScroll = true;
			this->panel_card_list->AutoScrollMinSize = System::Drawing::Size(0, 150);
			this->panel_card_list->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->panel_card_list->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel_card_list->Cursor = System::Windows::Forms::Cursors::Default;
			this->panel_card_list->Location = System::Drawing::Point(20, 113);
			this->panel_card_list->Margin = System::Windows::Forms::Padding(0);
			this->panel_card_list->Name = L"panel_card_list";
			this->panel_card_list->Size = System::Drawing::Size(492, 0);
			this->panel_card_list->TabIndex = 7;
			this->panel_card_list->Visible = false;
			// 
			// btn_send
			// 
			this->btn_send->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->btn_send->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_send->FlatAppearance->BorderSize = 0;
			this->btn_send->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_send->Font = (gcnew System::Drawing::Font(L"Candara", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_send->ForeColor = System::Drawing::Color::Transparent;
			this->btn_send->Location = System::Drawing::Point(27, 374);
			this->btn_send->Margin = System::Windows::Forms::Padding(0);
			this->btn_send->Name = L"btn_send";
			this->btn_send->Size = System::Drawing::Size(440, 50);
			this->btn_send->TabIndex = 8;
			this->btn_send->Text = L"Send ->";
			this->btn_send->UseVisualStyleBackColor = false;
			this->btn_send->Click += gcnew System::EventHandler(this, &TransactionForm::btn_send_Click);
			this->btn_send->MouseEnter += gcnew System::EventHandler(this, &TransactionForm::btn_send_MouseEnter);
			this->btn_send->MouseLeave += gcnew System::EventHandler(this, &TransactionForm::btn_send_MouseLeave);
			// 
			// btn_select_card
			// 
			this->btn_select_card->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->btn_select_card->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_select_card.BackgroundImage")));
			this->btn_select_card->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btn_select_card->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_select_card->Location = System::Drawing::Point(455, 71);
			this->btn_select_card->Margin = System::Windows::Forms::Padding(0);
			this->btn_select_card->Name = L"btn_select_card";
			this->btn_select_card->Size = System::Drawing::Size(57, 42);
			this->btn_select_card->TabIndex = 6;
			this->btn_select_card->Click += gcnew System::EventHandler(this, &TransactionForm::btn_select_card_Click);
			// 
			// sum_textbox
			// 
			this->sum_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->sum_textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->sum_textbox->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 21));
			this->sum_textbox->ForeColor = System::Drawing::Color::Transparent;
			this->sum_textbox->Location = System::Drawing::Point(27, 191);
			this->sum_textbox->Margin = System::Windows::Forms::Padding(0);
			this->sum_textbox->MaximumSize = System::Drawing::Size(566, 42);
			this->sum_textbox->MaxLength = 18;
			this->sum_textbox->Name = L"sum_textbox";
			this->sum_textbox->Size = System::Drawing::Size(440, 42);
			this->sum_textbox->TabIndex = 13;
			this->sum_textbox->TextChanged += gcnew System::EventHandler(this, &TransactionForm::sum_textbox_TextChanged);
			// 
			// card_textbox
			// 
			this->card_textbox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->card_textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->card_textbox->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 21));
			this->card_textbox->ForeColor = System::Drawing::Color::Transparent;
			this->card_textbox->Location = System::Drawing::Point(27, 312);
			this->card_textbox->Margin = System::Windows::Forms::Padding(0);
			this->card_textbox->MaximumSize = System::Drawing::Size(566, 42);
			this->card_textbox->MaxLength = 19;
			this->card_textbox->Name = L"card_textbox";
			this->card_textbox->Size = System::Drawing::Size(440, 42);
			this->card_textbox->TabIndex = 12;
			this->card_textbox->TextChanged += gcnew System::EventHandler(this, &TransactionForm::card_textbox_TextChanged);
			// 
			// label_select_card
			// 
			this->label_select_card->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)));
			this->label_select_card->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_select_card->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 21, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_select_card->ForeColor = System::Drawing::Color::Transparent;
			this->label_select_card->Location = System::Drawing::Point(20, 71);
			this->label_select_card->Margin = System::Windows::Forms::Padding(0);
			this->label_select_card->Name = L"label_select_card";
			this->label_select_card->Size = System::Drawing::Size(440, 42);
			this->label_select_card->TabIndex = 9;
			this->label_select_card->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_to_select_another_card
			// 
			this->label_to_select_another_card->AutoSize = true;
			this->label_to_select_another_card->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_to_select_another_card->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_to_select_another_card->ForeColor = System::Drawing::Color::Transparent;
			this->label_to_select_another_card->Location = System::Drawing::Point(20, 261);
			this->label_to_select_another_card->Margin = System::Windows::Forms::Padding(0);
			this->label_to_select_another_card->Name = L"label_to_select_another_card";
			this->label_to_select_another_card->Size = System::Drawing::Size(401, 41);
			this->label_to_select_another_card->TabIndex = 8;
			this->label_to_select_another_card->Text = L"Select the receipt card:";
			this->label_to_select_another_card->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_to_enter_sum
			// 
			this->label_to_enter_sum->AutoSize = true;
			this->label_to_enter_sum->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_to_enter_sum->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_to_enter_sum->ForeColor = System::Drawing::Color::Transparent;
			this->label_to_enter_sum->Location = System::Drawing::Point(20, 138);
			this->label_to_enter_sum->Margin = System::Windows::Forms::Padding(0);
			this->label_to_enter_sum->Name = L"label_to_enter_sum";
			this->label_to_enter_sum->Size = System::Drawing::Size(316, 41);
			this->label_to_enter_sum->TabIndex = 7;
			this->label_to_enter_sum->Text = L"Enter the amount:";
			this->label_to_enter_sum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_to_select_card
			// 
			this->label_to_select_card->AutoSize = true;
			this->label_to_select_card->Cursor = System::Windows::Forms::Cursors::Default;
			this->label_to_select_card->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_to_select_card->ForeColor = System::Drawing::Color::Transparent;
			this->label_to_select_card->Location = System::Drawing::Point(20, 20);
			this->label_to_select_card->Margin = System::Windows::Forms::Padding(0);
			this->label_to_select_card->Name = L"label_to_select_card";
			this->label_to_select_card->Size = System::Drawing::Size(385, 41);
			this->label_to_select_card->TabIndex = 6;
			this->label_to_select_card->Text = L"Select departure card:";
			this->label_to_select_card->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->panel_move_form->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TransactionForm::panel_move_form_MouseDown);
			this->panel_move_form->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TransactionForm::panel_move_form_MouseMove);
			this->panel_move_form->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &TransactionForm::panel_move_form_MouseUp);
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
			this->btn_return->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
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
			this->btn_return->Click += gcnew System::EventHandler(this, &TransactionForm::btn_return_Click);
			this->btn_return->MouseEnter += gcnew System::EventHandler(this, &TransactionForm::btn_return_MouseEnter);
			this->btn_return->MouseLeave += gcnew System::EventHandler(this, &TransactionForm::btn_return_MouseLeave);
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
			this->label_name_form->Size = System::Drawing::Size(134, 40);
			this->label_name_form->TabIndex = 10;
			this->label_name_form->Text = L"Transaction";
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
			this->image_bank_logo->TabIndex = 11;
			// 
			// TransactionForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(720, 1000);
			this->Controls->Add(this->panel_for_btn_return);
			this->Controls->Add(this->panel_move_form);
			this->Controls->Add(this->card_panel);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->background_card);
			this->Controls->Add(this->background_cost_history);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(480, 0);
			this->Name = L"TransactionForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"TransactionForm";
			this->Load += gcnew System::EventHandler(this, &TransactionForm::TransactionForm_Load);
			this->card_panel->ResumeLayout(false);
			this->card_panel->PerformLayout();
			this->background_cost_history->ResumeLayout(false);
			this->background_cost_history->PerformLayout();
			this->panel_move_form->ResumeLayout(false);
			this->panel_back_front->ResumeLayout(false);
			this->panel_for_btn_return->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TransactionForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->panel_card_list->Height += 159;
		this->label_select_card->Text = LocalToString(decypt(CreditCardList->GetValue(card_switch).GetCardNumber()));
		this->max_card_balance->Text = LocalToString(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()));

		for (size_t i = 0; i < CreditCardList->GetSize(); i++)
		{
			Label^ temp_label_card = gcnew Label();
			temp_label_card->Cursor = System::Windows::Forms::Cursors::Hand;
			temp_label_card->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 21));
			temp_label_card->ForeColor = System::Drawing::Color::Transparent;
			temp_label_card->Location = System::Drawing::Point(0, 0);
			temp_label_card->Margin = System::Windows::Forms::Padding(0);
			temp_label_card->Name = L"temp_label_card" + i.ToString();
			temp_label_card->Size = System::Drawing::Size(349, 45);
			temp_label_card->Text = gcnew System::String(decypt(CreditCardList->GetValue(i).GetCardNumber()).c_str());
			temp_label_card->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			TempCardInfo^ temp_card_info = gcnew TempCardInfo();
			temp_card_info->temp_card_number = gcnew String(decypt(CreditCardList->GetValue(i).GetCardNumber()).c_str());
			temp_card_info->temp_card_switch = i;
			temp_label_card->Tag = temp_card_info;
			temp_label_card->Click += gcnew System::EventHandler(this, &TransactionForm::label_select_card_Click);
			this->background_cost_history->Controls->Add(temp_label_card);


			Panel^ temp_panel_card = gcnew Panel();
			temp_panel_card->AutoScroll = true;
			temp_panel_card->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			temp_panel_card->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			temp_panel_card->Controls->Add(temp_label_card);
			temp_panel_card->Cursor = System::Windows::Forms::Cursors::Hand;
			temp_panel_card->Location = System::Drawing::Point(0, 5 + 50 * i);
			temp_panel_card->Margin = System::Windows::Forms::Padding(0);
			temp_panel_card->Name = L"temp_panel_card" + i.ToString();
			temp_panel_card->Size = System::Drawing::Size(349, 45);
			temp_panel_card->Controls->Add(temp_label_card);
			this->background_cost_history->Controls->Add(temp_panel_card);

			this->panel_card_list->Controls->Add(temp_panel_card);
		}
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
	private: System::Void label_select_card_Click(System::Object^ sender, System::EventArgs^ e) {
		TempCardInfo^ temp_card_info = dynamic_cast<TempCardInfo^>(safe_cast<Control^>(sender)->Tag);
		String^ temp_card_number = temp_card_info->temp_card_number;
		size_t temp_card_switch = temp_card_info->temp_card_switch;
		
		this->label_select_card->Text = temp_card_number;
		this->card_number->Text = temp_card_number;
		this->card_switch = temp_card_switch;
		this->max_card_balance->Text = LocalToString(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()));
		
		panel_card_list_visible = false;
		this->panel_card_list->Visible = panel_card_list_visible;
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
	private: System::Void btn_select_card_Click(System::Object^ sender, System::EventArgs^ e) {
		if (panel_card_list_visible) {
			panel_card_list_visible = false;
		}
		else {
			panel_card_list_visible = true;
		}
		this->panel_card_list->Visible = panel_card_list_visible;
	}
	private: System::Void btn_send_Click(System::Object^ sender, System::EventArgs^ e) {
		if (GetStringFromLabel(this->label_error->Text) != "") {
			this->label_error->Text = "Unable to execute";
			return;
		}
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
		CostHistoryList->AddToEnd(CostHistory(encypt("-" + GetStringFromLabel(this->card_balance->Text)), encypt("Transaction"), encypt(temp_day + temp_month + std::to_string(local_time.tm_year - 100))));
		CostHistoryToFile(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1), "private/CostHistoryList.txt");

		double temp_new_balance = std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance())) - std::stod(GetStringFromLabel(this->card_balance->Text));

		CreditCardList->GetValue(card_switch).SetCardBalance(encypt(std::to_string(temp_new_balance).erase(std::to_string(temp_new_balance).length() - 4, 4)));

		
		this->Close();
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
	private: System::Void btn_send_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		this->btn_send->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(185)),
			static_cast<System::Int32>(static_cast<System::Byte>(123)),
			static_cast<System::Int32>(static_cast<System::Byte>(235)));
	}
	private: System::Void btn_send_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->btn_send->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(69)),
			static_cast<System::Int32>(static_cast<System::Byte>(69)),
			static_cast<System::Int32>(static_cast<System::Byte>(69)));
	}

	private: System::Void sum_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		std::string temp_sum = GetStringFromLabel(this->sum_textbox->Text);
		try
		{
			if (temp_sum == "") {
				this->card_balance->Text = "0.00";
			}
			double res = std::stod(temp_sum);
			if ((temp_sum[temp_sum.length() - 1] < '0' || temp_sum[temp_sum.length() - 1] > '9') && temp_sum[temp_sum.length() - 1] != '.') {
				temp_sum.pop_back();
				this->sum_textbox->Text = LocalToString(temp_sum);
			}
			if (res < 0) {
				res *= -1;
			}
			if (res > std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()))) {
				this->sum_textbox->Text = LocalToString(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()));
				this->card_balance->Text = LocalToString(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()));
			}
			else {
				this->card_balance->Text = LocalToString(std::to_string(res).erase(std::to_string(res).length() - 4, 4));
			}
			this->label_error->Text = "";
		}
		catch (...)
		{
			this->label_error->Text = "The amount is incorrect";
		}
	}
	private: System::Void card_textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		std::string temp_card_number = GetStringFromLabel(this->card_textbox->Text);
		try
		{
			std::string res = temp_card_number;
			int findme = temp_card_number.find(" ");
			if (findme == std::string::npos) {
				if (temp_card_number.length() != 16) {
					throw std::runtime_error("error");
				}
			}
			else {
				while (findme != std::string::npos) {
					temp_card_number.erase(findme, 1);
					findme = temp_card_number.find(" ");
				}
				if (temp_card_number.length() != 16) {
					throw std::runtime_error("error");
				}
			}
			for (size_t i = 0; i < temp_card_number.length(); i++)
			{
				if (temp_card_number[i] < '0' || temp_card_number[i] > '9') {
					throw std::runtime_error("error");
				}
			}
			for (size_t i = 4; i < 15; i += 5)
			{
				temp_card_number.insert(i, " ");
			}

			this->card_textbox->Text = LocalToString(temp_card_number);
			this->to_card_number->Text = LocalToString(temp_card_number);
			this->label_error->Text = "";
		}
		catch (...)
		{
			this->label_error->Text = "The credit card is incorrect";
		}
	}
	};

}