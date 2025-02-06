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
	/// Сводка для CostReportForm
	/// </summary>
	public ref class CostReportForm : public System::Windows::Forms::Form
	{
	public:
		CostReportForm(int x, int y)
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
		~CostReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::Panel^ background_daily_report;
	private: System::Windows::Forms::Panel^ panel_move_form;
	private: System::Windows::Forms::Panel^ panel_back_front;
	private: System::Windows::Forms::Button^ btn_return;
	private: System::Windows::Forms::Panel^ panel_daily_progress;
	private: System::Windows::Forms::Label^ label_daily_reports;
	private: System::Windows::Forms::Panel^ panel_daily_report;
	private: System::Windows::Forms::Label^ label_for_daily_expenses;
	private: System::Windows::Forms::Label^ label_daily_expenses;
	private: System::Windows::Forms::Label^ label_daily_category;
	private: System::Windows::Forms::Label^ label_for_daily_category;
	private: System::Windows::Forms::Label^ label_daily_date;
	private: System::Windows::Forms::Panel^ panel_weekly_report;
	private: System::Windows::Forms::Label^ label_weekly_category;
	private: System::Windows::Forms::Label^ label_for_weekly_category;
	private: System::Windows::Forms::Label^ label_weekly_expenses;
	private: System::Windows::Forms::Label^ label_for_weekly_expenses;
	private: System::Windows::Forms::Panel^ panel_weekly_progress;
	private: System::Windows::Forms::Panel^ background_weekly_report;
	private: System::Windows::Forms::Label^ label_weekly_date;
	private: System::Windows::Forms::Label^ label_weekly_reports;
	private: System::Windows::Forms::Panel^ panel_monthy_report;
	private: System::Windows::Forms::Label^ label_monthly_category;
	private: System::Windows::Forms::Label^ label_for_monthly_category;
	private: System::Windows::Forms::Label^ label_monthly_expenses;
	private: System::Windows::Forms::Label^ label_for_monthly_expenses;
	private: System::Windows::Forms::Panel^ panel_monthly_progress;
	private: System::Windows::Forms::Panel^ background_monthly_report;
	private: System::Windows::Forms::Label^ label_monthly_date;
	private: System::Windows::Forms::Label^ label_monthly_reports;
	private: System::Windows::Forms::Panel^ background_reports;
	private: System::Windows::Forms::Label^ label_name_form;
	private: System::Windows::Forms::Panel^ image_bank_logo;

	private: bool dragging = false;
	private: System::Drawing::Point offset;
	private: size_t card_switch = 0;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CostReportForm::typeid));
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->background_daily_report = (gcnew System::Windows::Forms::Panel());
			this->label_daily_date = (gcnew System::Windows::Forms::Label());
			this->label_daily_reports = (gcnew System::Windows::Forms::Label());
			this->panel_back_front = (gcnew System::Windows::Forms::Panel());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->panel_move_form = (gcnew System::Windows::Forms::Panel());
			this->panel_daily_progress = (gcnew System::Windows::Forms::Panel());
			this->panel_daily_report = (gcnew System::Windows::Forms::Panel());
			this->label_daily_category = (gcnew System::Windows::Forms::Label());
			this->label_for_daily_category = (gcnew System::Windows::Forms::Label());
			this->label_daily_expenses = (gcnew System::Windows::Forms::Label());
			this->label_for_daily_expenses = (gcnew System::Windows::Forms::Label());
			this->panel_weekly_report = (gcnew System::Windows::Forms::Panel());
			this->label_weekly_category = (gcnew System::Windows::Forms::Label());
			this->label_for_weekly_category = (gcnew System::Windows::Forms::Label());
			this->label_weekly_expenses = (gcnew System::Windows::Forms::Label());
			this->label_for_weekly_expenses = (gcnew System::Windows::Forms::Label());
			this->panel_weekly_progress = (gcnew System::Windows::Forms::Panel());
			this->background_weekly_report = (gcnew System::Windows::Forms::Panel());
			this->label_weekly_date = (gcnew System::Windows::Forms::Label());
			this->label_weekly_reports = (gcnew System::Windows::Forms::Label());
			this->panel_monthy_report = (gcnew System::Windows::Forms::Panel());
			this->label_monthly_category = (gcnew System::Windows::Forms::Label());
			this->label_for_monthly_category = (gcnew System::Windows::Forms::Label());
			this->label_monthly_expenses = (gcnew System::Windows::Forms::Label());
			this->label_for_monthly_expenses = (gcnew System::Windows::Forms::Label());
			this->panel_monthly_progress = (gcnew System::Windows::Forms::Panel());
			this->background_monthly_report = (gcnew System::Windows::Forms::Panel());
			this->label_monthly_date = (gcnew System::Windows::Forms::Label());
			this->label_monthly_reports = (gcnew System::Windows::Forms::Label());
			this->background_reports = (gcnew System::Windows::Forms::Panel());
			this->label_name_form = (gcnew System::Windows::Forms::Label());
			this->image_bank_logo = (gcnew System::Windows::Forms::Panel());
			this->background_daily_report->SuspendLayout();
			this->panel_back_front->SuspendLayout();
			this->panel_move_form->SuspendLayout();
			this->panel_daily_report->SuspendLayout();
			this->panel_weekly_report->SuspendLayout();
			this->background_weekly_report->SuspendLayout();
			this->panel_monthy_report->SuspendLayout();
			this->background_monthly_report->SuspendLayout();
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
			this->btn_close->Click += gcnew System::EventHandler(this, &CostReportForm::btn_close_Click);
			this->btn_close->MouseEnter += gcnew System::EventHandler(this, &CostReportForm::btn_close_MouseEnter);
			this->btn_close->MouseLeave += gcnew System::EventHandler(this, &CostReportForm::btn_close_MouseLeave);
			// 
			// background_daily_report
			// 
			this->background_daily_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->background_daily_report->Controls->Add(this->label_daily_date);
			this->background_daily_report->Controls->Add(this->label_daily_reports);
			this->background_daily_report->Location = System::Drawing::Point(0, 81);
			this->background_daily_report->Margin = System::Windows::Forms::Padding(0);
			this->background_daily_report->Name = L"background_daily_report";
			this->background_daily_report->Size = System::Drawing::Size(720, 82);
			this->background_daily_report->TabIndex = 3;
			// 
			// label_daily_date
			// 
			this->label_daily_date->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 17, System::Drawing::FontStyle::Bold));
			this->label_daily_date->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(176)), static_cast<System::Int32>(static_cast<System::Byte>(176)));
			this->label_daily_date->Location = System::Drawing::Point(383, 20);
			this->label_daily_date->Name = L"label_daily_date";
			this->label_daily_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_daily_date->Size = System::Drawing::Size(315, 38);
			this->label_daily_date->TabIndex = 1;
			this->label_daily_date->Text = L"January 31";
			this->label_daily_date->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_daily_reports
			// 
			this->label_daily_reports->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_daily_reports->ForeColor = System::Drawing::Color::Transparent;
			this->label_daily_reports->Location = System::Drawing::Point(20, 0);
			this->label_daily_reports->Name = L"label_daily_reports";
			this->label_daily_reports->Size = System::Drawing::Size(379, 82);
			this->label_daily_reports->TabIndex = 0;
			this->label_daily_reports->Text = L"DAILY REPORT --";
			this->label_daily_reports->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
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
			this->btn_return->Click += gcnew System::EventHandler(this, &CostReportForm::btn_return_Click);
			this->btn_return->MouseEnter += gcnew System::EventHandler(this, &CostReportForm::btn_return_MouseEnter);
			this->btn_return->MouseLeave += gcnew System::EventHandler(this, &CostReportForm::btn_return_MouseLeave);
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
			this->panel_move_form->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &CostReportForm::panel_move_form_MouseDown);
			this->panel_move_form->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &CostReportForm::panel_move_form_MouseMove);
			this->panel_move_form->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &CostReportForm::panel_move_form_MouseUp);
			// 
			// panel_daily_progress
			// 
			this->panel_daily_progress->BackColor = System::Drawing::Color::Lime;
			this->panel_daily_progress->Location = System::Drawing::Point(0, 160);
			this->panel_daily_progress->Margin = System::Windows::Forms::Padding(0);
			this->panel_daily_progress->Name = L"panel_daily_progress";
			this->panel_daily_progress->Size = System::Drawing::Size(720, 3);
			this->panel_daily_progress->TabIndex = 4;
			// 
			// panel_daily_report
			// 
			this->panel_daily_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->panel_daily_report->Controls->Add(this->label_daily_category);
			this->panel_daily_report->Controls->Add(this->label_for_daily_category);
			this->panel_daily_report->Controls->Add(this->label_daily_expenses);
			this->panel_daily_report->Controls->Add(this->label_for_daily_expenses);
			this->panel_daily_report->Location = System::Drawing::Point(0, 163);
			this->panel_daily_report->Margin = System::Windows::Forms::Padding(0);
			this->panel_daily_report->Name = L"panel_daily_report";
			this->panel_daily_report->Size = System::Drawing::Size(720, 96);
			this->panel_daily_report->TabIndex = 4;
			// 
			// label_daily_category
			// 
			this->label_daily_category->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_daily_category->ForeColor = System::Drawing::Color::White;
			this->label_daily_category->Location = System::Drawing::Point(360, 36);
			this->label_daily_category->Margin = System::Windows::Forms::Padding(0);
			this->label_daily_category->Name = L"label_daily_category";
			this->label_daily_category->Size = System::Drawing::Size(310, 36);
			this->label_daily_category->TabIndex = 3;
			this->label_daily_category->Text = L"Food";
			this->label_daily_category->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_for_daily_category
			// 
			this->label_for_daily_category->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_for_daily_category->Font = (gcnew System::Drawing::Font(L"SansSerif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_for_daily_category->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_for_daily_category->Location = System::Drawing::Point(360, 13);
			this->label_for_daily_category->Margin = System::Windows::Forms::Padding(0);
			this->label_for_daily_category->Name = L"label_for_daily_category";
			this->label_for_daily_category->Size = System::Drawing::Size(310, 23);
			this->label_for_daily_category->TabIndex = 2;
			this->label_for_daily_category->Text = L"category";
			this->label_for_daily_category->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_daily_expenses
			// 
			this->label_daily_expenses->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_daily_expenses->ForeColor = System::Drawing::Color::White;
			this->label_daily_expenses->Location = System::Drawing::Point(50, 36);
			this->label_daily_expenses->Margin = System::Windows::Forms::Padding(0);
			this->label_daily_expenses->Name = L"label_daily_expenses";
			this->label_daily_expenses->Size = System::Drawing::Size(310, 36);
			this->label_daily_expenses->TabIndex = 1;
			this->label_daily_expenses->Text = L"0";
			this->label_daily_expenses->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_for_daily_expenses
			// 
			this->label_for_daily_expenses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_for_daily_expenses->Font = (gcnew System::Drawing::Font(L"SansSerif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_for_daily_expenses->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_for_daily_expenses->Location = System::Drawing::Point(50, 13);
			this->label_for_daily_expenses->Margin = System::Windows::Forms::Padding(0);
			this->label_for_daily_expenses->Name = L"label_for_daily_expenses";
			this->label_for_daily_expenses->Size = System::Drawing::Size(310, 23);
			this->label_for_daily_expenses->TabIndex = 0;
			this->label_for_daily_expenses->Text = L"expenses";
			this->label_for_daily_expenses->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_weekly_report
			// 
			this->panel_weekly_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->panel_weekly_report->Controls->Add(this->label_weekly_category);
			this->panel_weekly_report->Controls->Add(this->label_for_weekly_category);
			this->panel_weekly_report->Controls->Add(this->label_weekly_expenses);
			this->panel_weekly_report->Controls->Add(this->label_for_weekly_expenses);
			this->panel_weekly_report->Location = System::Drawing::Point(0, 391);
			this->panel_weekly_report->Margin = System::Windows::Forms::Padding(0);
			this->panel_weekly_report->Name = L"panel_weekly_report";
			this->panel_weekly_report->Size = System::Drawing::Size(720, 96);
			this->panel_weekly_report->TabIndex = 11;
			// 
			// label_weekly_category
			// 
			this->label_weekly_category->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_weekly_category->ForeColor = System::Drawing::Color::White;
			this->label_weekly_category->Location = System::Drawing::Point(360, 36);
			this->label_weekly_category->Margin = System::Windows::Forms::Padding(0);
			this->label_weekly_category->Name = L"label_weekly_category";
			this->label_weekly_category->Size = System::Drawing::Size(310, 36);
			this->label_weekly_category->TabIndex = 3;
			this->label_weekly_category->Text = L"Food";
			this->label_weekly_category->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_for_weekly_category
			// 
			this->label_for_weekly_category->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_for_weekly_category->Font = (gcnew System::Drawing::Font(L"SansSerif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_for_weekly_category->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_for_weekly_category->Location = System::Drawing::Point(360, 13);
			this->label_for_weekly_category->Margin = System::Windows::Forms::Padding(0);
			this->label_for_weekly_category->Name = L"label_for_weekly_category";
			this->label_for_weekly_category->Size = System::Drawing::Size(310, 23);
			this->label_for_weekly_category->TabIndex = 2;
			this->label_for_weekly_category->Text = L"category";
			this->label_for_weekly_category->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_weekly_expenses
			// 
			this->label_weekly_expenses->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_weekly_expenses->ForeColor = System::Drawing::Color::White;
			this->label_weekly_expenses->Location = System::Drawing::Point(50, 36);
			this->label_weekly_expenses->Margin = System::Windows::Forms::Padding(0);
			this->label_weekly_expenses->Name = L"label_weekly_expenses";
			this->label_weekly_expenses->Size = System::Drawing::Size(310, 36);
			this->label_weekly_expenses->TabIndex = 1;
			this->label_weekly_expenses->Text = L"-1000.00";
			this->label_weekly_expenses->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_for_weekly_expenses
			// 
			this->label_for_weekly_expenses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_for_weekly_expenses->Font = (gcnew System::Drawing::Font(L"SansSerif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_for_weekly_expenses->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_for_weekly_expenses->Location = System::Drawing::Point(50, 13);
			this->label_for_weekly_expenses->Margin = System::Windows::Forms::Padding(0);
			this->label_for_weekly_expenses->Name = L"label_for_weekly_expenses";
			this->label_for_weekly_expenses->Size = System::Drawing::Size(310, 23);
			this->label_for_weekly_expenses->TabIndex = 0;
			this->label_for_weekly_expenses->Text = L"expenses";
			this->label_for_weekly_expenses->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_weekly_progress
			// 
			this->panel_weekly_progress->BackColor = System::Drawing::Color::Lime;
			this->panel_weekly_progress->Location = System::Drawing::Point(0, 388);
			this->panel_weekly_progress->Margin = System::Windows::Forms::Padding(0);
			this->panel_weekly_progress->Name = L"panel_weekly_progress";
			this->panel_weekly_progress->Size = System::Drawing::Size(720, 3);
			this->panel_weekly_progress->TabIndex = 10;
			// 
			// background_weekly_report
			// 
			this->background_weekly_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->background_weekly_report->Controls->Add(this->label_weekly_date);
			this->background_weekly_report->Controls->Add(this->label_weekly_reports);
			this->background_weekly_report->Location = System::Drawing::Point(0, 309);
			this->background_weekly_report->Margin = System::Windows::Forms::Padding(0);
			this->background_weekly_report->Name = L"background_weekly_report";
			this->background_weekly_report->Size = System::Drawing::Size(720, 82);
			this->background_weekly_report->TabIndex = 9;
			// 
			// label_weekly_date
			// 
			this->label_weekly_date->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 17, System::Drawing::FontStyle::Bold));
			this->label_weekly_date->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(176)), static_cast<System::Int32>(static_cast<System::Byte>(176)));
			this->label_weekly_date->Location = System::Drawing::Point(381, 21);
			this->label_weekly_date->Name = L"label_weekly_date";
			this->label_weekly_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_weekly_date->Size = System::Drawing::Size(317, 38);
			this->label_weekly_date->TabIndex = 1;
			this->label_weekly_date->Text = L"In 7 days";
			this->label_weekly_date->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_weekly_reports
			// 
			this->label_weekly_reports->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_weekly_reports->ForeColor = System::Drawing::Color::Transparent;
			this->label_weekly_reports->Location = System::Drawing::Point(20, 0);
			this->label_weekly_reports->Name = L"label_weekly_reports";
			this->label_weekly_reports->Size = System::Drawing::Size(377, 82);
			this->label_weekly_reports->TabIndex = 0;
			this->label_weekly_reports->Text = L"WEEKLY REPORT --";
			this->label_weekly_reports->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel_monthy_report
			// 
			this->panel_monthy_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(199)),
				static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(199)));
			this->panel_monthy_report->Controls->Add(this->label_monthly_category);
			this->panel_monthy_report->Controls->Add(this->label_for_monthly_category);
			this->panel_monthy_report->Controls->Add(this->label_monthly_expenses);
			this->panel_monthy_report->Controls->Add(this->label_for_monthly_expenses);
			this->panel_monthy_report->Location = System::Drawing::Point(0, 619);
			this->panel_monthy_report->Margin = System::Windows::Forms::Padding(0);
			this->panel_monthy_report->Name = L"panel_monthy_report";
			this->panel_monthy_report->Size = System::Drawing::Size(720, 96);
			this->panel_monthy_report->TabIndex = 14;
			// 
			// label_monthly_category
			// 
			this->label_monthly_category->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_monthly_category->ForeColor = System::Drawing::Color::White;
			this->label_monthly_category->Location = System::Drawing::Point(360, 36);
			this->label_monthly_category->Margin = System::Windows::Forms::Padding(0);
			this->label_monthly_category->Name = L"label_monthly_category";
			this->label_monthly_category->Size = System::Drawing::Size(310, 36);
			this->label_monthly_category->TabIndex = 3;
			this->label_monthly_category->Text = L"Food";
			this->label_monthly_category->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_for_monthly_category
			// 
			this->label_for_monthly_category->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_for_monthly_category->Font = (gcnew System::Drawing::Font(L"SansSerif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_for_monthly_category->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_for_monthly_category->Location = System::Drawing::Point(360, 13);
			this->label_for_monthly_category->Margin = System::Windows::Forms::Padding(0);
			this->label_for_monthly_category->Name = L"label_for_monthly_category";
			this->label_for_monthly_category->Size = System::Drawing::Size(310, 23);
			this->label_for_monthly_category->TabIndex = 2;
			this->label_for_monthly_category->Text = L"category";
			this->label_for_monthly_category->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_monthly_expenses
			// 
			this->label_monthly_expenses->Font = (gcnew System::Drawing::Font(L"Swis721 BlkEx BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_monthly_expenses->ForeColor = System::Drawing::Color::White;
			this->label_monthly_expenses->Location = System::Drawing::Point(50, 36);
			this->label_monthly_expenses->Margin = System::Windows::Forms::Padding(0);
			this->label_monthly_expenses->Name = L"label_monthly_expenses";
			this->label_monthly_expenses->Size = System::Drawing::Size(310, 36);
			this->label_monthly_expenses->TabIndex = 1;
			this->label_monthly_expenses->Text = L"-1000.00";
			this->label_monthly_expenses->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_for_monthly_expenses
			// 
			this->label_for_monthly_expenses->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label_for_monthly_expenses->Font = (gcnew System::Drawing::Font(L"SansSerif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_for_monthly_expenses->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->label_for_monthly_expenses->Location = System::Drawing::Point(50, 13);
			this->label_for_monthly_expenses->Margin = System::Windows::Forms::Padding(0);
			this->label_for_monthly_expenses->Name = L"label_for_monthly_expenses";
			this->label_for_monthly_expenses->Size = System::Drawing::Size(310, 23);
			this->label_for_monthly_expenses->TabIndex = 0;
			this->label_for_monthly_expenses->Text = L"expenses";
			this->label_for_monthly_expenses->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel_monthly_progress
			// 
			this->panel_monthly_progress->BackColor = System::Drawing::Color::Lime;
			this->panel_monthly_progress->Location = System::Drawing::Point(0, 616);
			this->panel_monthly_progress->Margin = System::Windows::Forms::Padding(0);
			this->panel_monthly_progress->Name = L"panel_monthly_progress";
			this->panel_monthly_progress->Size = System::Drawing::Size(720, 3);
			this->panel_monthly_progress->TabIndex = 13;
			// 
			// background_monthly_report
			// 
			this->background_monthly_report->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->background_monthly_report->Controls->Add(this->label_monthly_date);
			this->background_monthly_report->Controls->Add(this->label_monthly_reports);
			this->background_monthly_report->Location = System::Drawing::Point(0, 537);
			this->background_monthly_report->Margin = System::Windows::Forms::Padding(0);
			this->background_monthly_report->Name = L"background_monthly_report";
			this->background_monthly_report->Size = System::Drawing::Size(720, 82);
			this->background_monthly_report->TabIndex = 12;
			// 
			// label_monthly_date
			// 
			this->label_monthly_date->Font = (gcnew System::Drawing::Font(L"Segoe UI Variable Small", 17, System::Drawing::FontStyle::Bold));
			this->label_monthly_date->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(176)),
				static_cast<System::Int32>(static_cast<System::Byte>(176)), static_cast<System::Int32>(static_cast<System::Byte>(176)));
			this->label_monthly_date->Location = System::Drawing::Point(381, 20);
			this->label_monthly_date->Name = L"label_monthly_date";
			this->label_monthly_date->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label_monthly_date->Size = System::Drawing::Size(317, 38);
			this->label_monthly_date->TabIndex = 1;
			this->label_monthly_date->Text = L"January";
			this->label_monthly_date->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label_monthly_reports
			// 
			this->label_monthly_reports->Font = (gcnew System::Drawing::Font(L"SansSerif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_monthly_reports->ForeColor = System::Drawing::Color::Transparent;
			this->label_monthly_reports->Location = System::Drawing::Point(20, 0);
			this->label_monthly_reports->Name = L"label_monthly_reports";
			this->label_monthly_reports->Size = System::Drawing::Size(377, 82);
			this->label_monthly_reports->TabIndex = 0;
			this->label_monthly_reports->Text = L"MONTHLY REPORT --";
			this->label_monthly_reports->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// background_reports
			// 
			this->background_reports->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(185)),
				static_cast<System::Int32>(static_cast<System::Byte>(123)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->background_reports->Location = System::Drawing::Point(0, 81);
			this->background_reports->Margin = System::Windows::Forms::Padding(0);
			this->background_reports->Name = L"background_reports";
			this->background_reports->Size = System::Drawing::Size(720, 684);
			this->background_reports->TabIndex = 15;
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
			this->label_name_form->Size = System::Drawing::Size(93, 40);
			this->label_name_form->TabIndex = 16;
			this->label_name_form->Text = L"Reports";
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
			this->image_bank_logo->TabIndex = 17;
			// 
			// CostReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(62)),
				static_cast<System::Int32>(static_cast<System::Byte>(66)));
			this->ClientSize = System::Drawing::Size(720, 1000);
			this->Controls->Add(this->panel_monthy_report);
			this->Controls->Add(this->panel_weekly_report);
			this->Controls->Add(this->panel_monthly_progress);
			this->Controls->Add(this->panel_weekly_progress);
			this->Controls->Add(this->background_monthly_report);
			this->Controls->Add(this->background_weekly_report);
			this->Controls->Add(this->panel_daily_report);
			this->Controls->Add(this->panel_daily_progress);
			this->Controls->Add(this->panel_back_front);
			this->Controls->Add(this->panel_move_form);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->background_daily_report);
			this->Controls->Add(this->background_reports);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CostReportForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"CostReportForm";
			this->Load += gcnew System::EventHandler(this, &CostReportForm::CostReportForm_Load);
			this->background_daily_report->ResumeLayout(false);
			this->panel_back_front->ResumeLayout(false);
			this->panel_move_form->ResumeLayout(false);
			this->panel_daily_report->ResumeLayout(false);
			this->panel_weekly_report->ResumeLayout(false);
			this->background_weekly_report->ResumeLayout(false);
			this->panel_monthy_report->ResumeLayout(false);
			this->background_monthly_report->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void CostReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
		std::time_t now = std::time(nullptr);
		std::tm local_time;
		localtime_s(&local_time, &now);

		double daily_insert = 0.0;
		double weekly_insert = 0.0;
		double monthly_insert = 0.0;
		std::string daily_local = std::to_string(local_time.tm_mday);
		int weekly_local_day = local_time.tm_mday;
		int weekly_local_month = local_time.tm_mon + 1;
		std::string monthly_local = std::to_string(local_time.tm_mon + 1);
		std::string daily_category = "";
		std::string weekly_category = "";
		std::string monthly_category = "";
		if (daily_local.length() <= 1) {
			daily_local.insert(0, "0");
		}
		if (monthly_local.length() <= 1) {
			monthly_local.insert(0, "0");
		}

		for (size_t i = 0; i < CostHistoryList->GetSize(); i++)
		{
			std::string temp_getDate = decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).DateGet());

			if (temp_getDate.substr(0, 2) == daily_local) {
				if (std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).TransferSumGet())) < 0) {
					daily_insert += std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).TransferSumGet()));
					daily_category.append(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).CategoryGet()));
					daily_category.append(" ");
				}
			}
			if (temp_getDate.substr(3, 2) == monthly_local) {
				if (std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).TransferSumGet())) < 0) {
					monthly_insert += std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).TransferSumGet()));
					monthly_category.append(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - i).CategoryGet()));
					monthly_category.append(" ");
				}
			}
			else {
				break;
			}
		}

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
				if (temp_date == decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - j).DateGet())
					&& std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - j).TransferSumGet())) < 0) {
					weekly_insert += std::stod(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - j).TransferSumGet()));
					weekly_category.append(decypt(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1 - j).CategoryGet())).append(" ");
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

		std::string max_daily_category = FindMaxFromString(daily_category);
		std::string max_weekly_category = FindMaxFromString(weekly_category);
		std::string max_monthly_category = FindMaxFromString(monthly_category);

		this->label_daily_expenses->Text = LocalToString(std::to_string(daily_insert).erase(std::to_string(daily_insert).length() - 4, 4));
		this->label_daily_category->Text = LocalToString(max_daily_category);

		this->label_weekly_expenses->Text = LocalToString(std::to_string(weekly_insert).erase(std::to_string(weekly_insert).length() - 4, 4));
		this->label_weekly_category->Text = LocalToString(max_weekly_category);

		this->label_monthly_expenses->Text = LocalToString(std::to_string(monthly_insert).erase(std::to_string(monthly_insert).length() - 4, 4));
		this->label_monthly_category->Text = LocalToString(max_monthly_category);

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
		this->label_monthly_date->Text = LocalToString(date_for_label);
		date_for_label.append(" ").append(daily_local);
		this->label_daily_date->Text = LocalToString(date_for_label);

		
		std::ofstream file("reports/cost_reports_" + daily_local + "_"
			+ monthly_local + "_" + std::to_string(local_time.tm_year + 1900) + ".txt");
		if (!file.is_open()) {
			return;
		}

		file << "Daily report\n";
		file << msclr::interop::marshal_as<std::string>(label_daily_expenses->Text) << "\t";
		file << msclr::interop::marshal_as<std::string>(label_daily_category->Text) << "\n";
		file << "\nWeekly report\n";
		file << msclr::interop::marshal_as<std::string>(label_weekly_expenses->Text) << "\t";
		file << msclr::interop::marshal_as<std::string>(label_weekly_category->Text) << "\n";
		file << "\nMonthy report\n";
		file << msclr::interop::marshal_as<std::string>(label_monthly_expenses->Text) << "\t";
		file << msclr::interop::marshal_as<std::string>(label_monthly_category->Text) << "\n";
		file.close();
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
	private: std::string FindMaxFromString(std::string input) {
		std::string max_category = "None";
		int max_count_category = 0;
		while (input != "") {
			int temp_count_category = 0;
			std::string to_delete = input;
			to_delete.erase(input.find(" "), input.length() - 1);
			size_t findme = input.find(to_delete);
			while (findme != std::string::npos)
			{
				input.erase(findme, to_delete.length() + 1);
				findme = input.find(to_delete);
				temp_count_category++;
			}
			if (temp_count_category > max_count_category)
			{
				max_count_category = temp_count_category;
				max_category = to_delete;
			}
			else if (temp_count_category == max_count_category) {
				max_category = "Different";
			}
		}
		return max_category;
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

