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
	/// Сводка для OnlineShopForm
	/// </summary>
	public ref class OnlineShopForm : public System::Windows::Forms::Form
	{
	public:
		OnlineShopForm(const int x, const int y, const size_t card_now)
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
		~OnlineShopForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btn_close;
	private: System::Windows::Forms::Panel^ background_panel_for_food;
	private: System::Windows::Forms::Panel^ panel_move_form;
	private: System::Windows::Forms::Panel^ panel_back_front;
	private: System::Windows::Forms::Panel^ panel_for_btn_return;
	private: System::Windows::Forms::Button^ btn_return;
	private: System::Windows::Forms::Button^ btn_buy_food;
	private: System::Windows::Forms::Label^ label_name_food;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ image_cloth;
	private: System::Windows::Forms::Button^ btn_buy_cloth;
	private: System::Windows::Forms::Label^ label_name_cloth;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ btn_buy_restaurants;

	private: System::Windows::Forms::Label^ label_name_restaurants;

	private: System::Windows::Forms::Panel^ image_food;
	private: System::Windows::Forms::Panel^ image_restaurants;

	private: System::Windows::Forms::Label^ label_for_food_price;
	private: System::Windows::Forms::Label^ label_for_cloth_price;
	private: System::Windows::Forms::Label^ label_for_restaurants_price;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label_for_cinema_price;
	private: System::Windows::Forms::Panel^ image_cinema;
	private: System::Windows::Forms::Button^ btn_buy_cinema;
	private: System::Windows::Forms::Label^ label_name_cinema;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label_for_entertainme_price;
	private: System::Windows::Forms::Panel^ image_entertainme;
	private: System::Windows::Forms::Button^ btn_buy_entertainme;
	private: System::Windows::Forms::Label^ label_name_enterainme;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label_for_medicine_price;
	private: System::Windows::Forms::Panel^ image_medicine;
	private: System::Windows::Forms::Button^ btn_buy_medicine;
	private: System::Windows::Forms::Label^ label_name_medicine;
	private: System::Windows::Forms::Label^ label_info;


	private: bool dragging = false;
	private: System::Drawing::Point offset;
	private: size_t card_switch;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(OnlineShopForm::typeid));
			this->btn_close = (gcnew System::Windows::Forms::Button());
			this->background_panel_for_food = (gcnew System::Windows::Forms::Panel());
			this->label_for_food_price = (gcnew System::Windows::Forms::Label());
			this->image_food = (gcnew System::Windows::Forms::Panel());
			this->btn_buy_food = (gcnew System::Windows::Forms::Button());
			this->label_name_food = (gcnew System::Windows::Forms::Label());
			this->panel_move_form = (gcnew System::Windows::Forms::Panel());
			this->panel_back_front = (gcnew System::Windows::Forms::Panel());
			this->label_name_form = (gcnew System::Windows::Forms::Label());
			this->image_bank_logo = (gcnew System::Windows::Forms::Panel());
			this->panel_for_btn_return = (gcnew System::Windows::Forms::Panel());
			this->btn_return = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label_for_cloth_price = (gcnew System::Windows::Forms::Label());
			this->image_cloth = (gcnew System::Windows::Forms::Panel());
			this->btn_buy_cloth = (gcnew System::Windows::Forms::Button());
			this->label_name_cloth = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label_for_restaurants_price = (gcnew System::Windows::Forms::Label());
			this->image_restaurants = (gcnew System::Windows::Forms::Panel());
			this->btn_buy_restaurants = (gcnew System::Windows::Forms::Button());
			this->label_name_restaurants = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label_for_cinema_price = (gcnew System::Windows::Forms::Label());
			this->image_cinema = (gcnew System::Windows::Forms::Panel());
			this->btn_buy_cinema = (gcnew System::Windows::Forms::Button());
			this->label_name_cinema = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label_for_entertainme_price = (gcnew System::Windows::Forms::Label());
			this->image_entertainme = (gcnew System::Windows::Forms::Panel());
			this->btn_buy_entertainme = (gcnew System::Windows::Forms::Button());
			this->label_name_enterainme = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label_for_medicine_price = (gcnew System::Windows::Forms::Label());
			this->image_medicine = (gcnew System::Windows::Forms::Panel());
			this->btn_buy_medicine = (gcnew System::Windows::Forms::Button());
			this->label_name_medicine = (gcnew System::Windows::Forms::Label());
			this->label_info = (gcnew System::Windows::Forms::Label());
			this->background_panel_for_food->SuspendLayout();
			this->panel_move_form->SuspendLayout();
			this->panel_back_front->SuspendLayout();
			this->panel_for_btn_return->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel7->SuspendLayout();
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
			this->btn_close->Location = System::Drawing::Point(621, 0);
			this->btn_close->Margin = System::Windows::Forms::Padding(0);
			this->btn_close->Name = L"btn_close";
			this->btn_close->Size = System::Drawing::Size(100, 40);
			this->btn_close->TabIndex = 0;
			this->btn_close->Text = L"⨉";
			this->btn_close->UseVisualStyleBackColor = false;
			this->btn_close->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_close_Click);
			this->btn_close->MouseEnter += gcnew System::EventHandler(this, &OnlineShopForm::btn_close_MouseEnter);
			this->btn_close->MouseLeave += gcnew System::EventHandler(this, &OnlineShopForm::btn_close_MouseLeave);
			// 
			// background_panel_for_food
			// 
			this->background_panel_for_food->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->background_panel_for_food->Controls->Add(this->label_for_food_price);
			this->background_panel_for_food->Controls->Add(this->image_food);
			this->background_panel_for_food->Controls->Add(this->btn_buy_food);
			this->background_panel_for_food->Controls->Add(this->label_name_food);
			this->background_panel_for_food->Location = System::Drawing::Point(10, 60);
			this->background_panel_for_food->Margin = System::Windows::Forms::Padding(0);
			this->background_panel_for_food->Name = L"background_panel_for_food";
			this->background_panel_for_food->Size = System::Drawing::Size(220, 275);
			this->background_panel_for_food->TabIndex = 3;
			// 
			// label_for_food_price
			// 
			this->label_for_food_price->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_for_food_price->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_for_food_price->ForeColor = System::Drawing::Color::Transparent;
			this->label_for_food_price->Location = System::Drawing::Point(0, 165);
			this->label_for_food_price->Margin = System::Windows::Forms::Padding(0);
			this->label_for_food_price->Name = L"label_for_food_price";
			this->label_for_food_price->Size = System::Drawing::Size(220, 59);
			this->label_for_food_price->TabIndex = 10;
			this->label_for_food_price->Text = L"Order a set for 100.00$";
			this->label_for_food_price->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// image_food
			// 
			this->image_food->BackColor = System::Drawing::Color::Transparent;
			this->image_food->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_food.BackgroundImage")));
			this->image_food->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_food->Location = System::Drawing::Point(0, 60);
			this->image_food->Margin = System::Windows::Forms::Padding(0);
			this->image_food->Name = L"image_food";
			this->image_food->Size = System::Drawing::Size(220, 105);
			this->image_food->TabIndex = 9;
			// 
			// btn_buy_food
			// 
			this->btn_buy_food->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_buy_food->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_buy_food->FlatAppearance->BorderSize = 0;
			this->btn_buy_food->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buy_food->Font = (gcnew System::Drawing::Font(L"Arial", 19, System::Drawing::FontStyle::Bold));
			this->btn_buy_food->ForeColor = System::Drawing::Color::Transparent;
			this->btn_buy_food->Location = System::Drawing::Point(-1, 224);
			this->btn_buy_food->Margin = System::Windows::Forms::Padding(0);
			this->btn_buy_food->Name = L"btn_buy_food";
			this->btn_buy_food->Size = System::Drawing::Size(220, 51);
			this->btn_buy_food->TabIndex = 8;
			this->btn_buy_food->Text = L"Buy";
			this->btn_buy_food->UseVisualStyleBackColor = false;
			this->btn_buy_food->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_food_Click);
			this->btn_buy_food->MouseEnter += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_MouseEnter);
			this->btn_buy_food->MouseLeave += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_MouseLeave);
			// 
			// label_name_food
			// 
			this->label_name_food->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_name_food->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_name_food->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_food->Location = System::Drawing::Point(0, 14);
			this->label_name_food->Margin = System::Windows::Forms::Padding(0);
			this->label_name_food->Name = L"label_name_food";
			this->label_name_food->Size = System::Drawing::Size(220, 41);
			this->label_name_food->TabIndex = 7;
			this->label_name_food->Text = L"Food";
			this->label_name_food->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->panel_move_form->Size = System::Drawing::Size(621, 40);
			this->panel_move_form->TabIndex = 8;
			this->panel_move_form->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &OnlineShopForm::panel_move_form_MouseDown);
			this->panel_move_form->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &OnlineShopForm::panel_move_form_MouseMove);
			this->panel_move_form->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &OnlineShopForm::panel_move_form_MouseUp);
			// 
			// panel_back_front
			// 
			this->panel_back_front->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->panel_back_front->Controls->Add(this->label_name_form);
			this->panel_back_front->Controls->Add(this->image_bank_logo);
			this->panel_back_front->Location = System::Drawing::Point(0, 0);
			this->panel_back_front->Margin = System::Windows::Forms::Padding(0);
			this->panel_back_front->Name = L"panel_back_front";
			this->panel_back_front->Size = System::Drawing::Size(621, 40);
			this->panel_back_front->TabIndex = 9;
			this->panel_back_front->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &OnlineShopForm::panel_move_form_MouseDown);
			this->panel_back_front->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &OnlineShopForm::panel_move_form_MouseMove);
			this->panel_back_front->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &OnlineShopForm::panel_move_form_MouseUp);
			// 
			// label_name_form
			// 
			this->label_name_form->BackColor = System::Drawing::Color::Transparent;
			this->label_name_form->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label_name_form->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_name_form->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_form->Location = System::Drawing::Point(60, 1);
			this->label_name_form->Margin = System::Windows::Forms::Padding(0);
			this->label_name_form->Name = L"label_name_form";
			this->label_name_form->Size = System::Drawing::Size(181, 40);
			this->label_name_form->TabIndex = 15;
			this->label_name_form->Text = L"Online bank shop";
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
			this->image_bank_logo->TabIndex = 16;
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
			this->btn_return->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_return_Click);
			this->btn_return->MouseEnter += gcnew System::EventHandler(this, &OnlineShopForm::btn_return_MouseEnter);
			this->btn_return->MouseLeave += gcnew System::EventHandler(this, &OnlineShopForm::btn_return_MouseLeave);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->panel1->Controls->Add(this->label_for_cloth_price);
			this->panel1->Controls->Add(this->image_cloth);
			this->panel1->Controls->Add(this->btn_buy_cloth);
			this->panel1->Controls->Add(this->label_name_cloth);
			this->panel1->Location = System::Drawing::Point(250, 60);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(220, 275);
			this->panel1->TabIndex = 10;
			// 
			// label_for_cloth_price
			// 
			this->label_for_cloth_price->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_for_cloth_price->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_for_cloth_price->ForeColor = System::Drawing::Color::Transparent;
			this->label_for_cloth_price->Location = System::Drawing::Point(0, 165);
			this->label_for_cloth_price->Margin = System::Windows::Forms::Padding(0);
			this->label_for_cloth_price->Name = L"label_for_cloth_price";
			this->label_for_cloth_price->Size = System::Drawing::Size(220, 59);
			this->label_for_cloth_price->TabIndex = 12;
			this->label_for_cloth_price->Text = L"Order a look for 529.90$";
			this->label_for_cloth_price->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// image_cloth
			// 
			this->image_cloth->BackColor = System::Drawing::Color::Transparent;
			this->image_cloth->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_cloth.BackgroundImage")));
			this->image_cloth->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_cloth->Location = System::Drawing::Point(0, 60);
			this->image_cloth->Margin = System::Windows::Forms::Padding(0);
			this->image_cloth->Name = L"image_cloth";
			this->image_cloth->Size = System::Drawing::Size(220, 105);
			this->image_cloth->TabIndex = 9;
			// 
			// btn_buy_cloth
			// 
			this->btn_buy_cloth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_buy_cloth->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_buy_cloth->FlatAppearance->BorderSize = 0;
			this->btn_buy_cloth->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buy_cloth->Font = (gcnew System::Drawing::Font(L"Arial", 19, System::Drawing::FontStyle::Bold));
			this->btn_buy_cloth->ForeColor = System::Drawing::Color::Transparent;
			this->btn_buy_cloth->Location = System::Drawing::Point(0, 224);
			this->btn_buy_cloth->Margin = System::Windows::Forms::Padding(0);
			this->btn_buy_cloth->Name = L"btn_buy_cloth";
			this->btn_buy_cloth->Size = System::Drawing::Size(220, 51);
			this->btn_buy_cloth->TabIndex = 8;
			this->btn_buy_cloth->Text = L"Buy";
			this->btn_buy_cloth->UseVisualStyleBackColor = false;
			this->btn_buy_cloth->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_cloth_Click);
			this->btn_buy_cloth->MouseEnter += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_MouseEnter);
			this->btn_buy_cloth->MouseLeave += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_MouseLeave);
			// 
			// label_name_cloth
			// 
			this->label_name_cloth->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_name_cloth->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_name_cloth->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_cloth->Location = System::Drawing::Point(0, 14);
			this->label_name_cloth->Margin = System::Windows::Forms::Padding(0);
			this->label_name_cloth->Name = L"label_name_cloth";
			this->label_name_cloth->Size = System::Drawing::Size(220, 41);
			this->label_name_cloth->TabIndex = 7;
			this->label_name_cloth->Text = L"Cloth";
			this->label_name_cloth->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->panel3->Controls->Add(this->label_for_restaurants_price);
			this->panel3->Controls->Add(this->image_restaurants);
			this->panel3->Controls->Add(this->btn_buy_restaurants);
			this->panel3->Controls->Add(this->label_name_restaurants);
			this->panel3->Location = System::Drawing::Point(490, 60);
			this->panel3->Margin = System::Windows::Forms::Padding(0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(220, 275);
			this->panel3->TabIndex = 11;
			// 
			// label_for_restaurants_price
			// 
			this->label_for_restaurants_price->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_for_restaurants_price->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_for_restaurants_price->ForeColor = System::Drawing::Color::Transparent;
			this->label_for_restaurants_price->Location = System::Drawing::Point(0, 165);
			this->label_for_restaurants_price->Margin = System::Windows::Forms::Padding(0);
			this->label_for_restaurants_price->Name = L"label_for_restaurants_price";
			this->label_for_restaurants_price->Size = System::Drawing::Size(220, 59);
			this->label_for_restaurants_price->TabIndex = 11;
			this->label_for_restaurants_price->Text = L"Order a menu for 85.00$";
			this->label_for_restaurants_price->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// image_restaurants
			// 
			this->image_restaurants->BackColor = System::Drawing::Color::Transparent;
			this->image_restaurants->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_restaurants.BackgroundImage")));
			this->image_restaurants->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_restaurants->Location = System::Drawing::Point(1, 60);
			this->image_restaurants->Margin = System::Windows::Forms::Padding(0);
			this->image_restaurants->Name = L"image_restaurants";
			this->image_restaurants->Size = System::Drawing::Size(220, 105);
			this->image_restaurants->TabIndex = 10;
			// 
			// btn_buy_restaurants
			// 
			this->btn_buy_restaurants->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_buy_restaurants->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_buy_restaurants->FlatAppearance->BorderSize = 0;
			this->btn_buy_restaurants->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buy_restaurants->Font = (gcnew System::Drawing::Font(L"Arial", 19, System::Drawing::FontStyle::Bold));
			this->btn_buy_restaurants->ForeColor = System::Drawing::Color::Transparent;
			this->btn_buy_restaurants->Location = System::Drawing::Point(0, 224);
			this->btn_buy_restaurants->Margin = System::Windows::Forms::Padding(0);
			this->btn_buy_restaurants->Name = L"btn_buy_restaurants";
			this->btn_buy_restaurants->Size = System::Drawing::Size(220, 51);
			this->btn_buy_restaurants->TabIndex = 8;
			this->btn_buy_restaurants->Text = L"Buy";
			this->btn_buy_restaurants->UseVisualStyleBackColor = false;
			this->btn_buy_restaurants->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_restaurants_Click);
			this->btn_buy_restaurants->MouseEnter += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_MouseEnter);
			this->btn_buy_restaurants->MouseLeave += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_MouseLeave);
			// 
			// label_name_restaurants
			// 
			this->label_name_restaurants->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_name_restaurants->Font = (gcnew System::Drawing::Font(L"SansSerif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(2)));
			this->label_name_restaurants->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_restaurants->Location = System::Drawing::Point(0, 0);
			this->label_name_restaurants->Margin = System::Windows::Forms::Padding(0);
			this->label_name_restaurants->Name = L"label_name_restaurants";
			this->label_name_restaurants->Size = System::Drawing::Size(220, 60);
			this->label_name_restaurants->TabIndex = 7;
			this->label_name_restaurants->Text = L"Restaurant";
			this->label_name_restaurants->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->panel2->Controls->Add(this->label_for_cinema_price);
			this->panel2->Controls->Add(this->image_cinema);
			this->panel2->Controls->Add(this->btn_buy_cinema);
			this->panel2->Controls->Add(this->label_name_cinema);
			this->panel2->Location = System::Drawing::Point(490, 355);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(220, 275);
			this->panel2->TabIndex = 14;
			// 
			// label_for_cinema_price
			// 
			this->label_for_cinema_price->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_for_cinema_price->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_for_cinema_price->ForeColor = System::Drawing::Color::Transparent;
			this->label_for_cinema_price->Location = System::Drawing::Point(0, 165);
			this->label_for_cinema_price->Margin = System::Windows::Forms::Padding(0);
			this->label_for_cinema_price->Name = L"label_for_cinema_price";
			this->label_for_cinema_price->Size = System::Drawing::Size(220, 59);
			this->label_for_cinema_price->TabIndex = 11;
			this->label_for_cinema_price->Text = L"Buy a ticket for 9.50$";
			this->label_for_cinema_price->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// image_cinema
			// 
			this->image_cinema->BackColor = System::Drawing::Color::Transparent;
			this->image_cinema->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_cinema.BackgroundImage")));
			this->image_cinema->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_cinema->Location = System::Drawing::Point(1, 60);
			this->image_cinema->Margin = System::Windows::Forms::Padding(0);
			this->image_cinema->Name = L"image_cinema";
			this->image_cinema->Size = System::Drawing::Size(220, 105);
			this->image_cinema->TabIndex = 10;
			// 
			// btn_buy_cinema
			// 
			this->btn_buy_cinema->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)), static_cast<System::Int32>(static_cast<System::Byte>(113)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_buy_cinema->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_buy_cinema->FlatAppearance->BorderSize = 0;
			this->btn_buy_cinema->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buy_cinema->Font = (gcnew System::Drawing::Font(L"Arial", 19, System::Drawing::FontStyle::Bold));
			this->btn_buy_cinema->ForeColor = System::Drawing::Color::Transparent;
			this->btn_buy_cinema->Location = System::Drawing::Point(0, 224);
			this->btn_buy_cinema->Margin = System::Windows::Forms::Padding(0);
			this->btn_buy_cinema->Name = L"btn_buy_cinema";
			this->btn_buy_cinema->Size = System::Drawing::Size(220, 51);
			this->btn_buy_cinema->TabIndex = 8;
			this->btn_buy_cinema->Text = L"Buy";
			this->btn_buy_cinema->UseVisualStyleBackColor = false;
			this->btn_buy_cinema->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_cinema_Click);
			// 
			// label_name_cinema
			// 
			this->label_name_cinema->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_name_cinema->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_name_cinema->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_cinema->Location = System::Drawing::Point(0, 0);
			this->label_name_cinema->Margin = System::Windows::Forms::Padding(0);
			this->label_name_cinema->Name = L"label_name_cinema";
			this->label_name_cinema->Size = System::Drawing::Size(220, 60);
			this->label_name_cinema->TabIndex = 7;
			this->label_name_cinema->Text = L"Cinema";
			this->label_name_cinema->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->panel5->Controls->Add(this->label_for_entertainme_price);
			this->panel5->Controls->Add(this->image_entertainme);
			this->panel5->Controls->Add(this->btn_buy_entertainme);
			this->panel5->Controls->Add(this->label_name_enterainme);
			this->panel5->Location = System::Drawing::Point(250, 355);
			this->panel5->Margin = System::Windows::Forms::Padding(0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(220, 275);
			this->panel5->TabIndex = 13;
			// 
			// label_for_entertainme_price
			// 
			this->label_for_entertainme_price->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_for_entertainme_price->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_for_entertainme_price->ForeColor = System::Drawing::Color::Transparent;
			this->label_for_entertainme_price->Location = System::Drawing::Point(0, 165);
			this->label_for_entertainme_price->Margin = System::Windows::Forms::Padding(0);
			this->label_for_entertainme_price->Name = L"label_for_entertainme_price";
			this->label_for_entertainme_price->Size = System::Drawing::Size(220, 59);
			this->label_for_entertainme_price->TabIndex = 12;
			this->label_for_entertainme_price->Text = L"Buy game for 49.00$";
			this->label_for_entertainme_price->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// image_entertainme
			// 
			this->image_entertainme->BackColor = System::Drawing::Color::Transparent;
			this->image_entertainme->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_entertainme.BackgroundImage")));
			this->image_entertainme->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_entertainme->Location = System::Drawing::Point(0, 60);
			this->image_entertainme->Margin = System::Windows::Forms::Padding(0);
			this->image_entertainme->Name = L"image_entertainme";
			this->image_entertainme->Size = System::Drawing::Size(220, 105);
			this->image_entertainme->TabIndex = 9;
			// 
			// btn_buy_entertainme
			// 
			this->btn_buy_entertainme->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_buy_entertainme->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_buy_entertainme->FlatAppearance->BorderSize = 0;
			this->btn_buy_entertainme->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buy_entertainme->Font = (gcnew System::Drawing::Font(L"Arial", 19, System::Drawing::FontStyle::Bold));
			this->btn_buy_entertainme->ForeColor = System::Drawing::Color::Transparent;
			this->btn_buy_entertainme->Location = System::Drawing::Point(0, 224);
			this->btn_buy_entertainme->Margin = System::Windows::Forms::Padding(0);
			this->btn_buy_entertainme->Name = L"btn_buy_entertainme";
			this->btn_buy_entertainme->Size = System::Drawing::Size(220, 51);
			this->btn_buy_entertainme->TabIndex = 8;
			this->btn_buy_entertainme->Text = L"Buy";
			this->btn_buy_entertainme->UseVisualStyleBackColor = false;
			this->btn_buy_entertainme->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_entertainme_Click);
			// 
			// label_name_enterainme
			// 
			this->label_name_enterainme->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_name_enterainme->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_name_enterainme->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_enterainme->Location = System::Drawing::Point(0, 14);
			this->label_name_enterainme->Margin = System::Windows::Forms::Padding(0);
			this->label_name_enterainme->Name = L"label_name_enterainme";
			this->label_name_enterainme->Size = System::Drawing::Size(220, 41);
			this->label_name_enterainme->TabIndex = 7;
			this->label_name_enterainme->Text = L"Entertainment";
			this->label_name_enterainme->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(173)),
				static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->panel7->Controls->Add(this->label_for_medicine_price);
			this->panel7->Controls->Add(this->image_medicine);
			this->panel7->Controls->Add(this->btn_buy_medicine);
			this->panel7->Controls->Add(this->label_name_medicine);
			this->panel7->Location = System::Drawing::Point(10, 355);
			this->panel7->Margin = System::Windows::Forms::Padding(0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(220, 275);
			this->panel7->TabIndex = 12;
			// 
			// label_for_medicine_price
			// 
			this->label_for_medicine_price->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_for_medicine_price->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_for_medicine_price->ForeColor = System::Drawing::Color::Transparent;
			this->label_for_medicine_price->Location = System::Drawing::Point(0, 165);
			this->label_for_medicine_price->Margin = System::Windows::Forms::Padding(0);
			this->label_for_medicine_price->Name = L"label_for_medicine_price";
			this->label_for_medicine_price->Size = System::Drawing::Size(220, 59);
			this->label_for_medicine_price->TabIndex = 10;
			this->label_for_medicine_price->Text = L"Order a set for 1200.00$";
			this->label_for_medicine_price->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// image_medicine
			// 
			this->image_medicine->BackColor = System::Drawing::Color::Transparent;
			this->image_medicine->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"image_medicine.BackgroundImage")));
			this->image_medicine->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->image_medicine->Location = System::Drawing::Point(0, 60);
			this->image_medicine->Margin = System::Windows::Forms::Padding(0);
			this->image_medicine->Name = L"image_medicine";
			this->image_medicine->Size = System::Drawing::Size(220, 105);
			this->image_medicine->TabIndex = 9;
			// 
			// btn_buy_medicine
			// 
			this->btn_buy_medicine->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(168)),
				static_cast<System::Int32>(static_cast<System::Byte>(113)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btn_buy_medicine->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_buy_medicine->FlatAppearance->BorderSize = 0;
			this->btn_buy_medicine->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buy_medicine->Font = (gcnew System::Drawing::Font(L"Arial", 19, System::Drawing::FontStyle::Bold));
			this->btn_buy_medicine->ForeColor = System::Drawing::Color::Transparent;
			this->btn_buy_medicine->Location = System::Drawing::Point(-1, 224);
			this->btn_buy_medicine->Margin = System::Windows::Forms::Padding(0);
			this->btn_buy_medicine->Name = L"btn_buy_medicine";
			this->btn_buy_medicine->Size = System::Drawing::Size(220, 51);
			this->btn_buy_medicine->TabIndex = 8;
			this->btn_buy_medicine->Text = L"Buy";
			this->btn_buy_medicine->UseVisualStyleBackColor = false;
			this->btn_buy_medicine->Click += gcnew System::EventHandler(this, &OnlineShopForm::btn_buy_medicine_Click);
			// 
			// label_name_medicine
			// 
			this->label_name_medicine->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_name_medicine->Font = (gcnew System::Drawing::Font(L"SansSerif", 21, System::Drawing::FontStyle::Bold));
			this->label_name_medicine->ForeColor = System::Drawing::Color::Transparent;
			this->label_name_medicine->Location = System::Drawing::Point(0, 14);
			this->label_name_medicine->Margin = System::Windows::Forms::Padding(0);
			this->label_name_medicine->Name = L"label_name_medicine";
			this->label_name_medicine->Size = System::Drawing::Size(220, 41);
			this->label_name_medicine->TabIndex = 7;
			this->label_name_medicine->Text = L"Medicine";
			this->label_name_medicine->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_info
			// 
			this->label_info->BackColor = System::Drawing::Color::Transparent;
			this->label_info->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->label_info->Font = (gcnew System::Drawing::Font(L"Swis721 Blk BT", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_info->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(212)), static_cast<System::Int32>(static_cast<System::Byte>(101)),
				static_cast<System::Int32>(static_cast<System::Byte>(4)));
			this->label_info->Location = System::Drawing::Point(1, 811);
			this->label_info->Margin = System::Windows::Forms::Padding(0);
			this->label_info->Name = L"label_info";
			this->label_info->Size = System::Drawing::Size(720, 81);
			this->label_info->TabIndex = 11;
			this->label_info->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// OnlineShopForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(238)),
				static_cast<System::Int32>(static_cast<System::Byte>(163)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(720, 1000);
			this->Controls->Add(this->label_info);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel_for_btn_return);
			this->Controls->Add(this->panel_move_form);
			this->Controls->Add(this->btn_close);
			this->Controls->Add(this->background_panel_for_food);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(480, 0);
			this->Name = L"OnlineShopForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"OnlineShopForm";
			this->Load += gcnew System::EventHandler(this, &OnlineShopForm::OnlineShopForm_Load);
			this->background_panel_for_food->ResumeLayout(false);
			this->panel_move_form->ResumeLayout(false);
			this->panel_back_front->ResumeLayout(false);
			this->panel_for_btn_return->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void OnlineShopForm_Load(System::Object^ sender, System::EventArgs^ e) {
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

	private: System::Void purchasing_process(const std::string category, const double price) {
		if (price > std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance()))) {
			this->label_info->Text = "Insufficient funds";
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

		double temp_new_balance;
		temp_new_balance = std::stod(decypt(CreditCardList->GetValue(card_switch).GetCardBalance())) - price;
		CostHistoryList->AddToEnd(CostHistory(
			encypt("-" + std::to_string(price).erase(std::to_string(price).length() - 4, 4)),
			encypt(category),
			encypt(temp_day + temp_month + std::to_string(local_time.tm_year - 100))));
		CostHistoryToFile(CostHistoryList->GetValue(CostHistoryList->GetSize() - 1), "private/CostHistoryList.txt");
		CreditCardList->GetValue(card_switch).SetCardBalance(encypt(std::to_string(temp_new_balance).erase(std::to_string(temp_new_balance).length() - 4, 4)));

		this->label_info->Text = "-" + gcnew System::String(std::to_string(price).erase(std::to_string(price).length() - 4, 4).c_str()) + "\nThank you for your purchase!";
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
	private: System::Void btn_buy_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);
		button->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(230)),
			static_cast<System::Int32>(static_cast<System::Byte>(155)),
			static_cast<System::Int32>(static_cast<System::Byte>(5)));
	}
	private: System::Void btn_buy_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Button^ button = safe_cast<Button^>(sender);
		button->BackColor = System::Drawing::Color::FromArgb(
			static_cast<System::Int32>(static_cast<System::Byte>(168)),
			static_cast<System::Int32>(static_cast<System::Byte>(113)),
			static_cast<System::Int32>(static_cast<System::Byte>(0)));
	}


	
	private: System::Void btn_buy_food_Click(System::Object^ sender, System::EventArgs^ e) {
		purchasing_process("Food", 100.00);
	}
	private: System::Void btn_buy_cloth_Click(System::Object^ sender, System::EventArgs^ e) {
		purchasing_process("Cloth", 529.90);
	}
	private: System::Void btn_buy_restaurants_Click(System::Object^ sender, System::EventArgs^ e) {
		purchasing_process("Restaurants", 85.00);
	}
	private: System::Void btn_buy_medicine_Click(System::Object^ sender, System::EventArgs^ e) {
		purchasing_process("Medicine", 1200.00);
	}
	private: System::Void btn_buy_entertainme_Click(System::Object^ sender, System::EventArgs^ e) {
		purchasing_process("Entertainment", 49.00);
	}
	private: System::Void btn_buy_cinema_Click(System::Object^ sender, System::EventArgs^ e) {
		purchasing_process("Cinema", 9.50);
	}
};

}