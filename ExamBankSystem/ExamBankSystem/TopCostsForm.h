#pragma once

#include "MyQueue.h"
#include <iostream>
#include <string>
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
	/// Сводка для TopCostsForm
	/// </summary>
	public ref class TopCostsForm : public System::Windows::Forms::Form
	{
	public:
		TopCostsForm(int x, int y)
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
		~TopCostsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::Panel^ background_top_costs;
	private: System::Windows::Forms::Panel^ panel_move_form;
	private: System::Windows::Forms::Panel^ panel_back_front;
	private: System::Windows::Forms::Button^ btn_return;
	private: System::Windows::Forms::Panel^ panel_top_costs_progress;
	private: System::Windows::Forms::Label^ label_top_costs;
	private: System::Windows::Forms::Panel^ panel_top_costs_report;
	private: System::Windows::Forms::Label^ label_top1_costs_week;
	private: System::Windows::Forms::Label^ label_top_costs_week;
	private: System::Windows::Forms::Label^ label_top3_costs_month;
	private: System::Windows::Forms::Label^ label_top3_costs_week;
	private: System::Windows::Forms::Label^ label_top2_costs_month;
	private: System::Windows::Forms::Label^ label_top2_costs_week;
	private: System::Windows::Forms::Label^ label_top_costs_month;
	private: System::Windows::Forms::Label^ label_top1_costs_month;
	private: System::Windows::Forms::Panel^ panel_top_categories_report;
	private: System::Windows::Forms::Label^ label_top3_categories_month;
	private: System::Windows::Forms::Label^ label_top3_categories_week;
	private: System::Windows::Forms::Label^ label_top2_categories_month;
	private: System::Windows::Forms::Label^ label_top2_categories_week;
	private: System::Windows::Forms::Label^ label_top_categories_month;
	private: System::Windows::Forms::Label^ label_top1_categories_month;
	private: System::Windows::Forms::Label^ label_top_categories_week;
	private: System::Windows::Forms::Label^ label_top1_categories_week;
	private: System::Windows::Forms::Panel^ panel_top_categories_progress;
	private: System::Windows::Forms::Panel^ background_top_categories;
	private: System::Windows::Forms::Label^ label_top_categories;
	private: System::Windows::Forms::Panel^ background_panel;

	private: bool dragging = false;
	private: System::Drawing::Point offset;
	private: size_t card_switch = 0;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TopCostsForm::typeid));
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->background_top_costs = (gcnew System::Windows::Forms::Panel());
			this->label_top_costs = (gcnew System::Windows::Forms::Label());
			this->label_top_costs_week = (gcnew System::Windows::Forms::Label());
			this->panel_back_front = (gcnew System::Windows::Forms::Panel());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->panel_move_form = (gcnew System::Windows::Forms::Panel());
			this->panel_top_costs_progress = (gcnew System::Windows::Forms::Panel());
			this->panel_top_costs_report = (gcnew System::Windows::Forms::Panel());
			this->label_top3_costs_month = (gcnew System::Windows::Forms::Label());
			this->label_top3_costs_week = (gcnew System::Windows::Forms::Label());
			this->label_top2_costs_month = (gcnew System::Windows::Forms::Label());
			this->label_top2_costs_week = (gcnew System::Windows::Forms::Label());
			this->label_top_costs_month = (gcnew System::Windows::Forms::Label());
			this->label_top1_costs_month = (gcnew System::Windows::Forms::Label());
			this->label_top1_costs_week = (gcnew System::Windows::Forms::Label());
			this->panel_top_categories_report = (gcnew System::Windows::Forms::Panel());
			this->label_top3_categories_month = (gcnew System::Windows::Forms::Label());
			this->label_top3_categories_week = (gcnew System::Windows::Forms::Label());
			this->label_top2_categories_month = (gcnew System::Windows::Forms::Label());
			this->label_top2_categories_week = (gcnew System::Windows::Forms::Label());
			this->label_top_categories_month = (gcnew System::Windows::Forms::Label());
			this->label_top1_categories_month = (gcnew System::Windows::Forms::Label());
			this->label_top_categories_week = (gcnew System::Windows::Forms::Label());
			this->label_top1_categories_week = (gcnew System::Windows::Forms::Label());
			this->panel_top_categories_progress = (gcnew System::Windows::Forms::Panel());
			this->background_top_categories = (gcnew System::Windows::Forms::Panel());
			this->label_top_categories = (gcnew System::Windows::Forms::Label());
			this->background_panel = (gcnew System::Windows::Forms::Panel());
			this->label_name_form = (gcnew System::Windows::Forms::Label());
			this->image_bank_logo = (gcnew System::Windows::Forms::Panel());
			this->background_top_costs->SuspendLayout();
			this->panel_back_front->SuspendLayout();
			this->panel_move_form->SuspendLayout();
			this->panel_top_costs_report->SuspendLayout();
			this->panel_top_categories_report->SuspendLayout();
			this->background_top_categories->SuspendLayout();
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
			this->btn_close->Click += gcnew System::EventHandler(this, &TopCostsForm::btn_close_Click);
			this->btn_close->MouseEnter += gcnew System::EventHandler(this, &TopCostsForm::btn_close_MouseEnter);
			this->btn_close->MouseLeave += gcnew System::EventHandler(this, &TopCostsForm::btn_close_MouseLeave);
			// 
			// background_top_costs
			// 
			this->background_top_costs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->background_top_costs->Controls->Add(this->label_top_costs);
			this->background_top_costs->Location = System::Drawing::Point(0, 81);
			this->background_top_costs->Margin = System::Windows::Forms::Padding(0);
			this->background_top_costs->Name = L"background_top_costs";
			this->background_top_costs->Size = System::Drawing::Size(720, 82);
			this->background_top_costs->TabIndex = 3;
			// 
			// label_top_costs
			// 
			this->label_top_costs->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_top_costs->ForeColor = System::Drawing::Color::Transparent;
			this->label_top_costs->Location = System::Drawing::Point(20, 0);
			this->label_top_costs->Name = L"label_top_costs";
			this->label_top_costs->Size = System::Drawing::Size(673, 82);
			this->label_top_costs->TabIndex = 0;
			this->label_top_costs->Text = L"TOP COSTS --";
			this->label_top_costs->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_top_costs_week
			// 
			this->label_top_costs_week->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 17, System::Drawing::FontStyle::Bold));
			this->label_top_costs_week->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_top_costs_week->Location = System::Drawing::Point(47, 10);
			this->label_top_costs_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top_costs_week->Name = L"label_top_costs_week";
			this->label_top_costs_week->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_top_costs_week->Size = System::Drawing::Size(311, 38);
			this->label_top_costs_week->TabIndex = 1;
			this->label_top_costs_week->Text = L"For week";
			this->label_top_costs_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_back_front
			// 
			this->panel_back_front->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->panel_back_front->Controls->Add(this->btn_return);
			this->panel_back_front->Location = System::Drawing::Point(0, 920);
			this->panel_back_front->Margin = System::Windows::Forms::Padding(0);
			this->panel_back_front->Name = L"panel_back_front";
			this->panel_back_front->Size = System::Drawing::Size(720, 80);
			this->panel_back_front->TabIndex = 8;
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
			this->btn_return->Click += gcnew System::EventHandler(this, &TopCostsForm::btn_return_Click);
			this->btn_return->MouseEnter += gcnew System::EventHandler(this, &TopCostsForm::btn_return_MouseEnter);
			this->btn_return->MouseLeave += gcnew System::EventHandler(this, &TopCostsForm::btn_return_MouseLeave);
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
			this->panel_move_form->TabIndex = 8;
			this->panel_move_form->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &TopCostsForm::panel_move_form_MouseDown);
			this->panel_move_form->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &TopCostsForm::panel_move_form_MouseMove);
			this->panel_move_form->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &TopCostsForm::panel_move_form_MouseUp);
			// 
			// panel_top_costs_progress
			// 
			this->panel_top_costs_progress->BackColor = System::Drawing::Color::Lime;
			this->panel_top_costs_progress->Location = System::Drawing::Point(0, 160);
			this->panel_top_costs_progress->Margin = System::Windows::Forms::Padding(0);
			this->panel_top_costs_progress->Name = L"panel_top_costs_progress";
			this->panel_top_costs_progress->Size = System::Drawing::Size(720, 3);
			this->panel_top_costs_progress->TabIndex = 4;
			// 
			// panel_top_costs_report
			// 
			this->panel_top_costs_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->panel_top_costs_report->Controls->Add(this->label_top3_costs_month);
			this->panel_top_costs_report->Controls->Add(this->label_top3_costs_week);
			this->panel_top_costs_report->Controls->Add(this->label_top2_costs_month);
			this->panel_top_costs_report->Controls->Add(this->label_top2_costs_week);
			this->panel_top_costs_report->Controls->Add(this->label_top_costs_month);
			this->panel_top_costs_report->Controls->Add(this->label_top1_costs_month);
			this->panel_top_costs_report->Controls->Add(this->label_top_costs_week);
			this->panel_top_costs_report->Controls->Add(this->label_top1_costs_week);
			this->panel_top_costs_report->Location = System::Drawing::Point(0, 163);
			this->panel_top_costs_report->Margin = System::Windows::Forms::Padding(0);
			this->panel_top_costs_report->Name = L"panel_top_costs_report";
			this->panel_top_costs_report->Size = System::Drawing::Size(720, 230);
			this->panel_top_costs_report->TabIndex = 4;
			// 
			// label_top3_costs_month
			// 
			this->label_top3_costs_month->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_top3_costs_month->ForeColor = System::Drawing::Color::White;
			this->label_top3_costs_month->Location = System::Drawing::Point(359, 167);
			this->label_top3_costs_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top3_costs_month->Name = L"label_top3_costs_month";
			this->label_top3_costs_month->Size = System::Drawing::Size(310, 36);
			this->label_top3_costs_month->TabIndex = 7;
			this->label_top3_costs_month->Text = L"None";
			this->label_top3_costs_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top3_costs_week
			// 
			this->label_top3_costs_week->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_top3_costs_week->ForeColor = System::Drawing::Color::White;
			this->label_top3_costs_week->Location = System::Drawing::Point(49, 167);
			this->label_top3_costs_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top3_costs_week->Name = L"label_top3_costs_week";
			this->label_top3_costs_week->Size = System::Drawing::Size(310, 36);
			this->label_top3_costs_week->TabIndex = 6;
			this->label_top3_costs_week->Text = L"None";
			this->label_top3_costs_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top2_costs_month
			// 
			this->label_top2_costs_month->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_top2_costs_month->ForeColor = System::Drawing::Color::White;
			this->label_top2_costs_month->Location = System::Drawing::Point(359, 116);
			this->label_top2_costs_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top2_costs_month->Name = L"label_top2_costs_month";
			this->label_top2_costs_month->Size = System::Drawing::Size(310, 36);
			this->label_top2_costs_month->TabIndex = 5;
			this->label_top2_costs_month->Text = L"None";
			this->label_top2_costs_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top2_costs_week
			// 
			this->label_top2_costs_week->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_top2_costs_week->ForeColor = System::Drawing::Color::White;
			this->label_top2_costs_week->Location = System::Drawing::Point(49, 116);
			this->label_top2_costs_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top2_costs_week->Name = L"label_top2_costs_week";
			this->label_top2_costs_week->Size = System::Drawing::Size(310, 36);
			this->label_top2_costs_week->TabIndex = 4;
			this->label_top2_costs_week->Text = L"None";
			this->label_top2_costs_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top_costs_month
			// 
			this->label_top_costs_month->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 17, System::Drawing::FontStyle::Bold));
			this->label_top_costs_month->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_top_costs_month->Location = System::Drawing::Point(358, 10);
			this->label_top_costs_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top_costs_month->Name = L"label_top_costs_month";
			this->label_top_costs_month->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_top_costs_month->Size = System::Drawing::Size(311, 38);
			this->label_top_costs_month->TabIndex = 2;
			this->label_top_costs_month->Text = L"For month";
			this->label_top_costs_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top1_costs_month
			// 
			this->label_top1_costs_month->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_top1_costs_month->ForeColor = System::Drawing::Color::White;
			this->label_top1_costs_month->Location = System::Drawing::Point(359, 65);
			this->label_top1_costs_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top1_costs_month->Name = L"label_top1_costs_month";
			this->label_top1_costs_month->Size = System::Drawing::Size(310, 36);
			this->label_top1_costs_month->TabIndex = 3;
			this->label_top1_costs_month->Text = L"None";
			this->label_top1_costs_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top1_costs_week
			// 
			this->label_top1_costs_week->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_top1_costs_week->ForeColor = System::Drawing::Color::White;
			this->label_top1_costs_week->Location = System::Drawing::Point(49, 65);
			this->label_top1_costs_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top1_costs_week->Name = L"label_top1_costs_week";
			this->label_top1_costs_week->Size = System::Drawing::Size(310, 36);
			this->label_top1_costs_week->TabIndex = 1;
			this->label_top1_costs_week->Text = L"None";
			this->label_top1_costs_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_top_categories_report
			// 
			this->panel_top_categories_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->panel_top_categories_report->Controls->Add(this->label_top3_categories_month);
			this->panel_top_categories_report->Controls->Add(this->label_top3_categories_week);
			this->panel_top_categories_report->Controls->Add(this->label_top2_categories_month);
			this->panel_top_categories_report->Controls->Add(this->label_top2_categories_week);
			this->panel_top_categories_report->Controls->Add(this->label_top_categories_month);
			this->panel_top_categories_report->Controls->Add(this->label_top1_categories_month);
			this->panel_top_categories_report->Controls->Add(this->label_top_categories_week);
			this->panel_top_categories_report->Controls->Add(this->label_top1_categories_week);
			this->panel_top_categories_report->Location = System::Drawing::Point(0, 555);
			this->panel_top_categories_report->Margin = System::Windows::Forms::Padding(0);
			this->panel_top_categories_report->Name = L"panel_top_categories_report";
			this->panel_top_categories_report->Size = System::Drawing::Size(720, 230);
			this->panel_top_categories_report->TabIndex = 11;
			// 
			// label_top3_categories_month
			// 
			this->label_top3_categories_month->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 16.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_top3_categories_month->ForeColor = System::Drawing::Color::White;
			this->label_top3_categories_month->Location = System::Drawing::Point(359, 167);
			this->label_top3_categories_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top3_categories_month->Name = L"label_top3_categories_month";
			this->label_top3_categories_month->Size = System::Drawing::Size(310, 36);
			this->label_top3_categories_month->TabIndex = 7;
			this->label_top3_categories_month->Text = L"None";
			this->label_top3_categories_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top3_categories_week
			// 
			this->label_top3_categories_week->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 16.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_top3_categories_week->ForeColor = System::Drawing::Color::White;
			this->label_top3_categories_week->Location = System::Drawing::Point(49, 167);
			this->label_top3_categories_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top3_categories_week->Name = L"label_top3_categories_week";
			this->label_top3_categories_week->Size = System::Drawing::Size(310, 36);
			this->label_top3_categories_week->TabIndex = 6;
			this->label_top3_categories_week->Text = L"None";
			this->label_top3_categories_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top2_categories_month
			// 
			this->label_top2_categories_month->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 16.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_top2_categories_month->ForeColor = System::Drawing::Color::White;
			this->label_top2_categories_month->Location = System::Drawing::Point(359, 116);
			this->label_top2_categories_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top2_categories_month->Name = L"label_top2_categories_month";
			this->label_top2_categories_month->Size = System::Drawing::Size(310, 36);
			this->label_top2_categories_month->TabIndex = 5;
			this->label_top2_categories_month->Text = L"None";
			this->label_top2_categories_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top2_categories_week
			// 
			this->label_top2_categories_week->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 16.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_top2_categories_week->ForeColor = System::Drawing::Color::White;
			this->label_top2_categories_week->Location = System::Drawing::Point(49, 116);
			this->label_top2_categories_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top2_categories_week->Name = L"label_top2_categories_week";
			this->label_top2_categories_week->Size = System::Drawing::Size(310, 36);
			this->label_top2_categories_week->TabIndex = 4;
			this->label_top2_categories_week->Text = L"None";
			this->label_top2_categories_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top_categories_month
			// 
			this->label_top_categories_month->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 17, System::Drawing::FontStyle::Bold));
			this->label_top_categories_month->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_top_categories_month->Location = System::Drawing::Point(358, 10);
			this->label_top_categories_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top_categories_month->Name = L"label_top_categories_month";
			this->label_top_categories_month->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_top_categories_month->Size = System::Drawing::Size(311, 38);
			this->label_top_categories_month->TabIndex = 2;
			this->label_top_categories_month->Text = L"For month";
			this->label_top_categories_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top1_categories_month
			// 
			this->label_top1_categories_month->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 16.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_top1_categories_month->ForeColor = System::Drawing::Color::White;
			this->label_top1_categories_month->Location = System::Drawing::Point(359, 65);
			this->label_top1_categories_month->Margin = System::Windows::Forms::Padding(0);
			this->label_top1_categories_month->Name = L"label_top1_categories_month";
			this->label_top1_categories_month->Size = System::Drawing::Size(310, 36);
			this->label_top1_categories_month->TabIndex = 3;
			this->label_top1_categories_month->Text = L"None";
			this->label_top1_categories_month->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top_categories_week
			// 
			this->label_top_categories_week->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 17, System::Drawing::FontStyle::Bold));
			this->label_top_categories_week->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_top_categories_week->Location = System::Drawing::Point(47, 10);
			this->label_top_categories_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top_categories_week->Name = L"label_top_categories_week";
			this->label_top_categories_week->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_top_categories_week->Size = System::Drawing::Size(311, 38);
			this->label_top_categories_week->TabIndex = 1;
			this->label_top_categories_week->Text = L"For week";
			this->label_top_categories_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_top1_categories_week
			// 
			this->label_top1_categories_week->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 16.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label_top1_categories_week->ForeColor = System::Drawing::Color::White;
			this->label_top1_categories_week->Location = System::Drawing::Point(49, 65);
			this->label_top1_categories_week->Margin = System::Windows::Forms::Padding(0);
			this->label_top1_categories_week->Name = L"label_top1_categories_week";
			this->label_top1_categories_week->Size = System::Drawing::Size(310, 36);
			this->label_top1_categories_week->TabIndex = 1;
			this->label_top1_categories_week->Text = L"None";
			this->label_top1_categories_week->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_top_categories_progress
			// 
			this->panel_top_categories_progress->BackColor = System::Drawing::Color::Lime;
			this->panel_top_categories_progress->Location = System::Drawing::Point(0, 552);
			this->panel_top_categories_progress->Margin = System::Windows::Forms::Padding(0);
			this->panel_top_categories_progress->Name = L"panel_top_categories_progress";
			this->panel_top_categories_progress->Size = System::Drawing::Size(720, 3);
			this->panel_top_categories_progress->TabIndex = 10;
			// 
			// background_top_categories
			// 
			this->background_top_categories->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->background_top_categories->Controls->Add(this->label_top_categories);
			this->background_top_categories->Location = System::Drawing::Point(0, 473);
			this->background_top_categories->Margin = System::Windows::Forms::Padding(0);
			this->background_top_categories->Name = L"background_top_categories";
			this->background_top_categories->Size = System::Drawing::Size(720, 82);
			this->background_top_categories->TabIndex = 9;
			// 
			// label_top_categories
			// 
			this->label_top_categories->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_top_categories->ForeColor = System::Drawing::Color::Transparent;
			this->label_top_categories->Location = System::Drawing::Point(20, 0);
			this->label_top_categories->Name = L"label_top_categories";
			this->label_top_categories->Size = System::Drawing::Size(673, 82);
			this->label_top_categories->TabIndex = 0;
			this->label_top_categories->Text = L"TOP CATEGORIES --";
			this->label_top_categories->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// background_panel
			// 
			this->background_panel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(123)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->background_panel->Location = System::Drawing::Point(0, 81);
			this->background_panel->Margin = System::Windows::Forms::Padding(0);
			this->background_panel->Name = L"background_panel";
			this->background_panel->Size = System::Drawing::Size(720, 784);
			this->background_panel->TabIndex = 8;
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
			this->label_name_form->Size = System::Drawing::Size(107, 40);
			this->label_name_form->TabIndex = 12;
			this->label_name_form->Text = L"Top costs";
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
			this->image_bank_logo->TabIndex = 13;
			// 
			// TopCostsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(720, 1000);
			this->Controls->Add(this->panel_top_categories_report);
			this->Controls->Add(this->panel_top_categories_progress);
			this->Controls->Add(this->background_top_categories);
			this->Controls->Add(this->panel_top_costs_report);
			this->Controls->Add(this->panel_top_costs_progress);
			this->Controls->Add(this->panel_back_front);
			this->Controls->Add(this->panel_move_form);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->background_top_costs);
			this->Controls->Add(this->background_panel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TopCostsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"TopCostsForm";
			this->Load += gcnew System::EventHandler(this, &TopCostsForm::TopCostsForm_Load);
			this->background_top_costs->ResumeLayout(false);
			this->panel_back_front->ResumeLayout(false);
			this->panel_move_form->ResumeLayout(false);
			this->panel_top_costs_report->ResumeLayout(false);
			this->panel_top_categories_report->ResumeLayout(false);
			this->background_top_categories->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void TopCostsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::time_t now = std::time(nullptr);
		std::tm local_time;
		localtime_s(&local_time, &now);
		std::string daily_local = std::to_string(local_time.tm_mday);
		int weekly_local_day = local_time.tm_mday;
		int weekly_local_month = local_time.tm_mon + 1;
		std::string monthly_local = std::to_string(local_time.tm_mon + 1);
		std::string weekly_category = "";
		std::string monthly_category = "";
		if (daily_local.length() <= 1) {
			daily_local.insert(0, "0");
		}
		if (monthly_local.length() <= 1) {
			monthly_local.insert(0, "0");
		}
		

		double top3 = 0.0, top2 = 0.0, top1 = 0.0;
		for (size_t i = 0; i < 7; i++)
		{
			std::string string_weekly_local_day = std::to_string(weekly_local_day);
			if (string_weekly_local_day.length() <= 1) {
				string_weekly_local_day.insert(0, "0");
			}
			std::string string_weekly_local_month = std::to_string(weekly_local_month);
			if (string_weekly_local_month.length() <= 1) {
				string_weekly_local_month.insert(0, "0");
			}

			std::string temp_date = "";
			temp_date.append(string_weekly_local_day).append(".")
				.append(string_weekly_local_month).append(".")
				.append(std::to_string(local_time.tm_year - 100));
			for (size_t j = 0; j < CostHistoryList->GetSize(); j++) {
				double temp_transfer_sum = std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - j).TransferSumGet()));
				if (temp_date == decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - j).DateGet())) {
					if (temp_transfer_sum < 0) {
						if (temp_transfer_sum <= top3) {
							if (temp_transfer_sum <= top2) {
								if (temp_transfer_sum <= top1) {
									top3 = top2;
									this->label_top3_costs_week->Text = this->label_top2_costs_week->Text;
									top2 = top1;
									this->label_top2_costs_week->Text = this->label_top1_costs_week->Text;
									top1 = temp_transfer_sum;
									this->label_top1_costs_week->Text = LocalToString(std::to_string(temp_transfer_sum).erase(std::to_string(temp_transfer_sum).length() - 4, 4));
								}
								else {
									top3 = top2;
									this->label_top3_costs_week->Text = this->label_top2_costs_week->Text;
									top2 = temp_transfer_sum;
									this->label_top2_costs_week->Text = LocalToString(std::to_string(temp_transfer_sum).erase(std::to_string(temp_transfer_sum).length() - 4, 4));;
								}
							}
							else {
								top3 = temp_transfer_sum;
								this->label_top3_costs_week->Text = LocalToString(std::to_string(temp_transfer_sum).erase(std::to_string(temp_transfer_sum).length() - 4, 4));;
							}
						}
						weekly_category.append(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - j).CategoryGet())).append(" ");
					}
				}
			}

			if (weekly_local_day - 1 <= 0) {
				if (weekly_local_month - 1 <= 0) {
					weekly_local_month = 12;
				}
				else {
					weekly_local_month -= 1;
				}
				if (weekly_local_month == 1 ||
					weekly_local_month == 3 ||
					weekly_local_month == 5 ||
					weekly_local_month == 7 ||
					weekly_local_month == 8 ||
					weekly_local_month == 10 ||
					weekly_local_month == 12) {
					weekly_local_day = 31;
				}
				else if (weekly_local_month == 4 ||
					weekly_local_month == 6 ||
					weekly_local_month == 9 ||
					weekly_local_month == 11) {
					weekly_local_day = 30;
				}
				else {
					if (!((local_time.tm_year + 1900) % 4)) {
						weekly_local_day = 29;
					}
					else {
						weekly_local_day = 28;
					}
				}
			}
			else {
				weekly_local_day--;
			}

		}
		
		top3 = 0.0, top2 = 0.0, top1 = 0.0;
		for (size_t i = 0; i < CostHistoryList->GetSize(); i++)
		{
			std::string temp_getDate = decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).DateGet());
			if (temp_getDate.substr(3, 2) == monthly_local) {
				double temp_transfer_sum = std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).TransferSumGet()));
				if (temp_transfer_sum < 0) {
					if (temp_transfer_sum <= top3) {
						if (temp_transfer_sum <= top2) {
							if (temp_transfer_sum <= top1) {
								top3 = top2;
								this->label_top3_costs_month->Text = this->label_top2_costs_month->Text;
								top2 = top1;
								this->label_top2_costs_month->Text = this->label_top1_costs_month->Text;
								top1 = temp_transfer_sum;
								this->label_top1_costs_month->Text = LocalToString(std::to_string(temp_transfer_sum).erase(std::to_string(temp_transfer_sum).length() - 4, 4));
							}
							else {
								top3 = top2;
								this->label_top3_costs_month->Text = this->label_top2_costs_month->Text;
								top2 = temp_transfer_sum;
								this->label_top2_costs_month->Text = LocalToString(std::to_string(temp_transfer_sum).erase(std::to_string(temp_transfer_sum).length() - 4, 4));;
							}
						}
						else {
							top3 = temp_transfer_sum;
							this->label_top3_costs_month->Text = LocalToString(std::to_string(temp_transfer_sum).erase(std::to_string(temp_transfer_sum).length() - 4, 4));;
						}
					}
					monthly_category.append(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).CategoryGet()));
					monthly_category.append(" ");
				}
			}
			else {
				break;
			}
		}

		
		int top3_category = 0, top2_category = 0, top1_category = 0;
		while (weekly_category != "") {
			int temp_count_category = 0;
			std::string to_delete = weekly_category;
			to_delete.erase(weekly_category.find(" "), weekly_category.length() - 1);
			size_t findme = weekly_category.find(to_delete);
			while (findme != std::string::npos)
			{
				weekly_category.erase(findme, to_delete.length() + 1);
				findme = weekly_category.find(to_delete);
				temp_count_category++;
			}

			if (temp_count_category > top3_category) {

				if (temp_count_category > top2_category) {

					top3_category = top2_category;
					this->label_top3_categories_week->Text = this->label_top2_categories_week->Text;
					if (temp_count_category > top1_category) {
						top2_category = top1_category;
						this->label_top2_categories_week->Text = this->label_top1_categories_week->Text;
						top1_category = temp_count_category;
						this->label_top1_categories_week->Text = LocalToString(to_delete);
					}
					else if (temp_count_category == top1_category) {
						this->label_top1_categories_week->Text = "Diferent";
					}

					else {
						top2_category = temp_count_category;
						this->label_top2_categories_week->Text = LocalToString(to_delete);
					}
				}
				else if (temp_count_category == top2_category) {
					this->label_top2_categories_week->Text = "Diferent";
				}

				else {
					top3_category = temp_count_category;
					this->label_top3_categories_week->Text = LocalToString(to_delete);
				}
			}
			else if (temp_count_category == top3_category) {
				this->label_top3_categories_week->Text = "Diferent";
			}
		}

		top3_category = 0, top2_category = 0, top1_category = 0;
		while (monthly_category != "") {
			int temp_count_category = 0;
			std::string to_delete = monthly_category;
			to_delete.erase(monthly_category.find(" "), monthly_category.length() - 1);
			size_t findme = monthly_category.find(to_delete);
			while (findme != std::string::npos)
			{
				monthly_category.erase(findme, to_delete.length() + 1);
				findme = monthly_category.find(to_delete);
				temp_count_category++;
			}

			if (temp_count_category > top3_category) {

				if (temp_count_category > top2_category) {

					top3_category = top2_category;
					this->label_top3_categories_month->Text = this->label_top2_categories_month->Text;
					if (temp_count_category > top1_category) {
						top2_category = top1_category;
						this->label_top2_categories_month->Text = this->label_top1_categories_month->Text;
						top1_category = temp_count_category;
						this->label_top1_categories_month->Text = LocalToString(to_delete);
					}
					else if (temp_count_category == top1_category) {
						this->label_top1_categories_month->Text = "Diferent";
					}

					else {
						top2_category = temp_count_category;
						this->label_top2_categories_month->Text = LocalToString(to_delete);
					}
				}
				else if (temp_count_category == top2_category) {
					this->label_top2_categories_month->Text = "Diferent";
				}

				else {
					top3_category = temp_count_category;
					this->label_top3_categories_month->Text = LocalToString(to_delete);
				}
			}
			else if (temp_count_category == top3_category) {
				this->label_top3_categories_month->Text = "Diferent";
			}
		}

		std::string date_for_label;
		switch (local_time.tm_mon + 1) {
		case 1: date_for_label = "January"; break;
		case 2: date_for_label = "February"; break;
		case 3: date_for_label = "March"; break;
		case 4: date_for_label = "April"; break;
		case 5: date_for_label = "May"; break;
		case 6: date_for_label = "June"; break;
		case 7: date_for_label = "July"; break;
		case 8: date_for_label = "August"; break;
		case 9: date_for_label = "September"; break;
		case 10: date_for_label = "October"; break;
		case 11: date_for_label = "November"; break;
		case 12: date_for_label = "December"; break;
		}
		this->label_top_costs_month->Text = "For " + LocalToString(date_for_label);
		this->label_top_categories_month->Text = "For " + LocalToString(date_for_label);

		std::ofstream file("reports/top_costs_" + daily_local + "_"
			+ monthly_local + "_" + std::to_string(local_time.tm_year + 1900) + ".txt");
		if (!file.is_open()) {
			return;
		}
		file << "TOP-3 Costs\n";
		file << "For week\n";
		file << msclr::interop::marshal_as<std::string>(label_top1_costs_week->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top2_costs_week->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top3_costs_week->Text) << "\n";
		file << "\nFor month\n";
		file << msclr::interop::marshal_as<std::string>(label_top1_costs_month->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top2_costs_month->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top3_costs_month->Text) << "\n";
		file << "\nTOP-3 Category\n";
		file << "For week\n";
		file << msclr::interop::marshal_as<std::string>(label_top1_categories_week->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top2_categories_week->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top3_categories_week->Text) << "\n";
		file << "\nFor month\n";
		file << msclr::interop::marshal_as<std::string>(label_top1_categories_month->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top2_categories_month->Text) << "\n";
		file << msclr::interop::marshal_as<std::string>(label_top3_categories_month->Text) << "\n";
		file.close();
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

