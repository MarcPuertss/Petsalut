#pragma once
#include "TxRegistraUsu.h"
#include "CercadoraUsuari.h"
#include "CercadoraClinica.h"
#include "CercadoraPropietari.h"
#include "PassarellaUsuari.h"
#include "MenuProp.h"
#include "PasswordEncrypt.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de RegU
	/// </summary>
	public ref class RegUsu : public System::Windows::Forms::Form
	{
	public:
		RegUsu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
		bool mostra1 = false;
		String^ tipusSelected = "Propietari";
	private: System::Windows::Forms::Label^ PassLong;
	private: System::Windows::Forms::Label^ DiffPasswd;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ descripcio;
	private: System::Windows::Forms::Label^ tipusLabel;
	private: System::Windows::Forms::RadioButton^ radioPropietariButton;
	private: System::Windows::Forms::RadioButton^ radioClinicaButton;
	private: System::Windows::Forms::Label^ nomreq;
	private: System::Windows::Forms::Label^ correureq;
	private: System::Windows::Forms::Label^ telefonreq;
	private: System::Windows::Forms::Label^ datareq;




	private: System::Windows::Forms::Label^ complertreq;

	private: System::Windows::Forms::Label^ contra1req;
	private: System::Windows::Forms::Label^ contra2req;












	public:

	public:
		bool mostra2 = false;


	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~RegUsu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ name;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ mail;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::MaskedTextBox^ phone;
	private: System::Windows::Forms::MaskedTextBox^ date;
	private: System::Windows::Forms::TextBox^ username;
	private: System::Windows::Forms::TextBox^ passwd1;
	private: System::Windows::Forms::TextBox^ passwd2;
	private: System::Windows::Forms::Button^ valid_button;
	private: System::Windows::Forms::Button^ reg_button;
	private: System::Windows::Forms::Button^ show1;
	private: System::Windows::Forms::Button^ show2;

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegUsu::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mail = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->phone = (gcnew System::Windows::Forms::MaskedTextBox());
			this->date = (gcnew System::Windows::Forms::MaskedTextBox());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->passwd1 = (gcnew System::Windows::Forms::TextBox());
			this->passwd2 = (gcnew System::Windows::Forms::TextBox());
			this->valid_button = (gcnew System::Windows::Forms::Button());
			this->reg_button = (gcnew System::Windows::Forms::Button());
			this->show1 = (gcnew System::Windows::Forms::Button());
			this->show2 = (gcnew System::Windows::Forms::Button());
			this->PassLong = (gcnew System::Windows::Forms::Label());
			this->DiffPasswd = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->descripcio = (gcnew System::Windows::Forms::TextBox());
			this->tipusLabel = (gcnew System::Windows::Forms::Label());
			this->radioPropietariButton = (gcnew System::Windows::Forms::RadioButton());
			this->radioClinicaButton = (gcnew System::Windows::Forms::RadioButton());
			this->nomreq = (gcnew System::Windows::Forms::Label());
			this->correureq = (gcnew System::Windows::Forms::Label());
			this->telefonreq = (gcnew System::Windows::Forms::Label());
			this->datareq = (gcnew System::Windows::Forms::Label());
			this->complertreq = (gcnew System::Windows::Forms::Label());
			this->contra1req = (gcnew System::Windows::Forms::Label());
			this->contra2req = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(173, 87);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(327, 42);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Formulari de registre";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(623, 162);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(118, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Nom Complert";
			// 
			// name
			// 
			this->name->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->name->Location = System::Drawing::Point(626, 186);
			this->name->MaxLength = 255;
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(277, 22);
			this->name->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(177, 321);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(138, 21);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Correu Electronic";
			// 
			// mail
			// 
			this->mail->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mail->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->mail->Location = System::Drawing::Point(181, 350);
			this->mail->Name = L"mail";
			this->mail->Size = System::Drawing::Size(278, 22);
			this->mail->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(175, 399);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 21);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Telefon";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(175, 481);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(131, 21);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Data Naixement";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(175, 239);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(108, 21);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Nom d\'usuari";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(622, 241);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(103, 21);
			this->label7->TabIndex = 12;
			this->label7->Text = L"Contrasenya";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(623, 321);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(178, 21);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Verifica la contrasenya";
			// 
			// phone
			// 
			this->phone->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->phone->Location = System::Drawing::Point(179, 423);
			this->phone->Mask = L"+34 000 000 000";
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(277, 22);
			this->phone->TabIndex = 20;
			// 
			// date
			// 
			this->date->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->date->Location = System::Drawing::Point(181, 505);
			this->date->Mask = L"00/00/0000";
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(276, 22);
			this->date->TabIndex = 21;
			this->date->ValidatingType = System::DateTime::typeid;
			// 
			// username
			// 
			this->username->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->username->Location = System::Drawing::Point(178, 272);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(276, 22);
			this->username->TabIndex = 22;
			// 
			// passwd1
			// 
			this->passwd1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwd1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->passwd1->Location = System::Drawing::Point(626, 265);
			this->passwd1->Name = L"passwd1";
			this->passwd1->Size = System::Drawing::Size(276, 22);
			this->passwd1->TabIndex = 23;
			this->passwd1->UseSystemPasswordChar = true;
			// 
			// passwd2
			// 
			this->passwd2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwd2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->passwd2->Location = System::Drawing::Point(627, 345);
			this->passwd2->Name = L"passwd2";
			this->passwd2->Size = System::Drawing::Size(276, 22);
			this->passwd2->TabIndex = 24;
			this->passwd2->UseSystemPasswordChar = true;
			// 
			// valid_button
			// 
			this->valid_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->valid_button->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->valid_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->valid_button->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->valid_button->Location = System::Drawing::Point(627, 493);
			this->valid_button->Name = L"valid_button";
			this->valid_button->Size = System::Drawing::Size(171, 33);
			this->valid_button->TabIndex = 25;
			this->valid_button->Text = L"VALIDAR INFORMACIO";
			this->valid_button->UseVisualStyleBackColor = false;
			this->valid_button->Click += gcnew System::EventHandler(this, &RegUsu::valid_button_Click);
			// 
			// reg_button
			// 
			this->reg_button->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->reg_button->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->reg_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->reg_button->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reg_button->Location = System::Drawing::Point(806, 493);
			this->reg_button->Name = L"reg_button";
			this->reg_button->Size = System::Drawing::Size(172, 33);
			this->reg_button->TabIndex = 26;
			this->reg_button->Text = L"REGISTRAR-SE";
			this->reg_button->UseVisualStyleBackColor = false;
			this->reg_button->Visible = false;
			this->reg_button->Click += gcnew System::EventHandler(this, &RegUsu::reg_button_Click);
			// 
			// show1
			// 
			this->show1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->show1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->show1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->show1->Font = (gcnew System::Drawing::Font(L"Yu Gothic Light", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->show1->Location = System::Drawing::Point(907, 265);
			this->show1->Name = L"show1";
			this->show1->Size = System::Drawing::Size(83, 21);
			this->show1->TabIndex = 27;
			this->show1->Text = L"Mostrar";
			this->show1->UseVisualStyleBackColor = false;
			this->show1->Click += gcnew System::EventHandler(this, &RegUsu::show1_Click);
			// 
			// show2
			// 
			this->show2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->show2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->show2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->show2->Font = (gcnew System::Drawing::Font(L"Yu Gothic Light", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->show2->Location = System::Drawing::Point(907, 345);
			this->show2->Name = L"show2";
			this->show2->Size = System::Drawing::Size(83, 21);
			this->show2->TabIndex = 28;
			this->show2->Text = L"Mostrar";
			this->show2->UseVisualStyleBackColor = false;
			this->show2->Click += gcnew System::EventHandler(this, &RegUsu::show2_Click);
			// 
			// PassLong
			// 
			this->PassLong->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PassLong->AutoSize = true;
			this->PassLong->BackColor = System::Drawing::Color::Transparent;
			this->PassLong->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PassLong->ForeColor = System::Drawing::Color::Red;
			this->PassLong->Location = System::Drawing::Point(625, 289);
			this->PassLong->Name = L"PassLong";
			this->PassLong->Size = System::Drawing::Size(207, 14);
			this->PassLong->TabIndex = 29;
			this->PassLong->Text = L"Password must be 6 characters or more";
			this->PassLong->Visible = false;
			// 
			// DiffPasswd
			// 
			this->DiffPasswd->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DiffPasswd->AutoSize = true;
			this->DiffPasswd->BackColor = System::Drawing::Color::Transparent;
			this->DiffPasswd->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DiffPasswd->ForeColor = System::Drawing::Color::Red;
			this->DiffPasswd->Location = System::Drawing::Point(625, 370);
			this->DiffPasswd->Name = L"DiffPasswd";
			this->DiffPasswd->Size = System::Drawing::Size(125, 14);
			this->DiffPasswd->TabIndex = 30;
			this->DiffPasswd->Text = L"Passwords must match";
			this->DiffPasswd->Visible = false;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(622, 399);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 21);
			this->label9->TabIndex = 31;
			this->label9->Text = L"Descripcio";
			// 
			// descripcio
			// 
			this->descripcio->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descripcio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->descripcio->Location = System::Drawing::Point(627, 423);
			this->descripcio->Name = L"descripcio";
			this->descripcio->Size = System::Drawing::Size(276, 22);
			this->descripcio->TabIndex = 32;
			// 
			// tipusLabel
			// 
			this->tipusLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tipusLabel->AutoSize = true;
			this->tipusLabel->BackColor = System::Drawing::Color::Transparent;
			this->tipusLabel->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tipusLabel->Location = System::Drawing::Point(175, 162);
			this->tipusLabel->Name = L"tipusLabel";
			this->tipusLabel->Size = System::Drawing::Size(116, 21);
			this->tipusLabel->TabIndex = 33;
			this->tipusLabel->Text = L"Tipus d\'Usuari";
			// 
			// radioPropietariButton
			// 
			this->radioPropietariButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->radioPropietariButton->AutoSize = true;
			this->radioPropietariButton->BackColor = System::Drawing::Color::Transparent;
			this->radioPropietariButton->Checked = true;
			this->radioPropietariButton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioPropietariButton->Location = System::Drawing::Point(179, 197);
			this->radioPropietariButton->Name = L"radioPropietariButton";
			this->radioPropietariButton->Size = System::Drawing::Size(90, 22);
			this->radioPropietariButton->TabIndex = 34;
			this->radioPropietariButton->TabStop = true;
			this->radioPropietariButton->Text = L"Propietari";
			this->radioPropietariButton->UseVisualStyleBackColor = false;
			// 
			// radioClinicaButton
			// 
			this->radioClinicaButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->radioClinicaButton->AutoSize = true;
			this->radioClinicaButton->BackColor = System::Drawing::Color::Transparent;
			this->radioClinicaButton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->radioClinicaButton->Location = System::Drawing::Point(295, 197);
			this->radioClinicaButton->Name = L"radioClinicaButton";
			this->radioClinicaButton->Size = System::Drawing::Size(71, 22);
			this->radioClinicaButton->TabIndex = 35;
			this->radioClinicaButton->Text = L"Clinica";
			this->radioClinicaButton->UseVisualStyleBackColor = false;
			this->radioClinicaButton->CheckedChanged += gcnew System::EventHandler(this, &RegUsu::radioClinicaButton_CheckedChanged);
			// 
			// nomreq
			// 
			this->nomreq->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nomreq->AutoSize = true;
			this->nomreq->BackColor = System::Drawing::Color::Transparent;
			this->nomreq->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nomreq->ForeColor = System::Drawing::Color::Red;
			this->nomreq->Location = System::Drawing::Point(281, 245);
			this->nomreq->Name = L"nomreq";
			this->nomreq->Size = System::Drawing::Size(87, 14);
			this->nomreq->TabIndex = 43;
			this->nomreq->Text = L"Required Field *";
			this->nomreq->Visible = false;
			// 
			// correureq
			// 
			this->correureq->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->correureq->AutoSize = true;
			this->correureq->BackColor = System::Drawing::Color::Transparent;
			this->correureq->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->correureq->ForeColor = System::Drawing::Color::Red;
			this->correureq->Location = System::Drawing::Point(310, 327);
			this->correureq->Name = L"correureq";
			this->correureq->Size = System::Drawing::Size(87, 14);
			this->correureq->TabIndex = 44;
			this->correureq->Text = L"Required Field *";
			this->correureq->Visible = false;
			// 
			// telefonreq
			// 
			this->telefonreq->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->telefonreq->AutoSize = true;
			this->telefonreq->BackColor = System::Drawing::Color::Transparent;
			this->telefonreq->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->telefonreq->ForeColor = System::Drawing::Color::Red;
			this->telefonreq->Location = System::Drawing::Point(241, 405);
			this->telefonreq->Name = L"telefonreq";
			this->telefonreq->Size = System::Drawing::Size(87, 14);
			this->telefonreq->TabIndex = 45;
			this->telefonreq->Text = L"Required Field *";
			this->telefonreq->Visible = false;
			// 
			// datareq
			// 
			this->datareq->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->datareq->AutoSize = true;
			this->datareq->BackColor = System::Drawing::Color::Transparent;
			this->datareq->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datareq->ForeColor = System::Drawing::Color::Red;
			this->datareq->Location = System::Drawing::Point(301, 487);
			this->datareq->Name = L"datareq";
			this->datareq->Size = System::Drawing::Size(87, 14);
			this->datareq->TabIndex = 46;
			this->datareq->Text = L"Required Field *";
			this->datareq->Visible = false;
			// 
			// complertreq
			// 
			this->complertreq->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->complertreq->AutoSize = true;
			this->complertreq->BackColor = System::Drawing::Color::Transparent;
			this->complertreq->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->complertreq->ForeColor = System::Drawing::Color::Red;
			this->complertreq->Location = System::Drawing::Point(734, 167);
			this->complertreq->Name = L"complertreq";
			this->complertreq->Size = System::Drawing::Size(87, 14);
			this->complertreq->TabIndex = 47;
			this->complertreq->Text = L"Required Field *";
			this->complertreq->Visible = false;
			// 
			// contra1req
			// 
			this->contra1req->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->contra1req->AutoSize = true;
			this->contra1req->BackColor = System::Drawing::Color::Transparent;
			this->contra1req->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contra1req->ForeColor = System::Drawing::Color::Red;
			this->contra1req->Location = System::Drawing::Point(718, 245);
			this->contra1req->Name = L"contra1req";
			this->contra1req->Size = System::Drawing::Size(87, 14);
			this->contra1req->TabIndex = 48;
			this->contra1req->Text = L"Required Field *";
			this->contra1req->Visible = false;
			// 
			// contra2req
			// 
			this->contra2req->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->contra2req->AutoSize = true;
			this->contra2req->BackColor = System::Drawing::Color::Transparent;
			this->contra2req->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->contra2req->ForeColor = System::Drawing::Color::Red;
			this->contra2req->Location = System::Drawing::Point(787, 327);
			this->contra2req->Name = L"contra2req";
			this->contra2req->Size = System::Drawing::Size(87, 14);
			this->contra2req->TabIndex = 49;
			this->contra2req->Text = L"Required Field *";
			this->contra2req->Visible = false;
			// 
			// RegUsu
			// 
			this->AccessibleName = L"";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->contra2req);
			this->Controls->Add(this->contra1req);
			this->Controls->Add(this->complertreq);
			this->Controls->Add(this->datareq);
			this->Controls->Add(this->telefonreq);
			this->Controls->Add(this->correureq);
			this->Controls->Add(this->nomreq);
			this->Controls->Add(this->radioClinicaButton);
			this->Controls->Add(this->radioPropietariButton);
			this->Controls->Add(this->tipusLabel);
			this->Controls->Add(this->descripcio);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->DiffPasswd);
			this->Controls->Add(this->PassLong);
			this->Controls->Add(this->show2);
			this->Controls->Add(this->show1);
			this->Controls->Add(this->reg_button);
			this->Controls->Add(this->valid_button);
			this->Controls->Add(this->passwd2);
			this->Controls->Add(this->passwd1);
			this->Controls->Add(this->username);
			this->Controls->Add(this->date);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->mail);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->name);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RegUsu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PETSALUT";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void valid_button_Click(System::Object^ sender, System::EventArgs^ e) {
		bool usernamebool = false;
		bool correubool = false;
		bool complertbool = false;
		bool phonebool = false;
		bool contracar = false;
		bool contraeq = false;
		bool databool = false;
		if (String::IsNullOrWhiteSpace(this->username->Text)) {
			this->nomreq->Visible = true;
		}
		else {
			System::String^ usernameText = username->Text;
			if (username->Text)
				System::String^ usernameText = username->Text;
			CercadoraUsuari^ cercadora = gcnew CercadoraUsuari();
			PassarellaUsuari^ usuari = cercadora->cercaUsuari(usernameText);
			if (usuari == nullptr) {
				usernamebool = true;
				this->nomreq->Visible = false;
			}
			else {
				// Si el usuario no es null, muestra un mensaje de error
				MessageBox::Show("El usuario con ese nombre de usuario ya existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		if (String::IsNullOrWhiteSpace(this->mail->Text)) {
			this->correureq->Visible = true;
			correubool = false;
		}
		else {
			this->correureq->Visible = false;
			correubool = true;
		}
		if (phone->MaskFull) {
			this->telefonreq->Visible = false;
			phonebool = true;
		}
		else {
			this->telefonreq->Visible = true;
			phonebool = false;
		}
		if (String::IsNullOrWhiteSpace(this->name->Text)) {
			this->complertreq->Visible = true;
			complertbool = false;
		}
		else {
			this->complertreq->Visible = false;
			complertbool = true;
		}
		if (String::IsNullOrWhiteSpace(this->passwd1->Text)) {
			this->contra1req->Visible = true;
		}
		else {
			this->contra1req->Visible = false;
		}
		if (String::IsNullOrWhiteSpace(this->passwd2->Text)) {
			this->contra2req->Visible = true;
		}
		else {
			this->contra2req->Visible = false;
		}
		if (this->radioClinicaButton->Checked) {
			this->datareq->Visible = false;
		}
		else {
			if (date->MaskFull) {
				this->datareq->Visible = false;
				databool = true;
			}
			else {
				this->datareq->Visible = true;
				databool = false;

			}
		}
		if (passwd1->Text->Length < 6) {

			PassLong->Visible = true;
			contra1req->Visible = true;
			contracar = false;

		}
		else {
			PassLong->Visible = false;
			contra1req->Visible = false;
			contracar = true;

		}
		if (passwd1->Text == passwd2->Text) {

			DiffPasswd->Visible = false;
			if (contracar == true) {
				contraeq = true;
			}
		}
		else {

			DiffPasswd->Visible = true;
			contraeq = false;

		}
		if (this->radioClinicaButton->Checked) {
			if ((usernamebool == true) && (correubool == true) && (complertbool == true) && (phonebool == true) && (contracar == true) && (contraeq == true)) {
				reg_button->Visible = true;
			}
			else {
				reg_button->Visible = false;
			}
		}
		else {
			if ((usernamebool == true) && (correubool == true) && (complertbool == true) && (phonebool == true) && (contracar == true) && (contraeq == true) && (databool = true)) {
				reg_button->Visible = true;
			}
			else {
				reg_button->Visible = false;
			}
		}
	}

	private: System::Void reg_button_Click(System::Object^ sender, System::EventArgs^ e) {

		try {

			String^ usernameS = username->Text;
			String^ nomComplertS = name->Text;
			String^ contrasenyaS = PasswordEncrypt::Encrypt(passwd1->Text);
			String^ telefonS = phone->Text;
			String^ tipusS = tipusSelected;
			String^ correuElectronicS = mail->Text;
			String^ dataNaixementS = date->Text;
			String^ descripcioS = descripcio->Text;



			TxRegistraUsu regUsu;
			regUsu.crear(usernameS, contrasenyaS, nomComplertS, telefonS, tipusS, correuElectronicS, descripcioS, dataNaixementS);
			regUsu.executar();

			PetSalut::MenuProp^ menuProp = gcnew PetSalut::MenuProp();

			this->Visible = false;
			this->Close();
			MessageBox::Show("Usuari creat correctament");
		}
		catch (Exception^ ex)
		{
			MessageBox::Show("Error pantalla usuari: " + ex->Message);
		}

	}
	private: System::Void radioClinicaButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (this->radioClinicaButton->Checked) {
			this->label5->Visible = false;
			this->date->Visible = false;
			this->radioPropietariButton->Checked = false;
			this->tipusSelected = "Clinica";
			this->datareq->Visible = false;
		}
		else {
			this->label5->Visible = true;
			this->date->Visible = true;
			this->radioPropietariButton->Checked = true;
			this->tipusSelected = "Propietari";
		}
	}
private: System::Void show2_Click(System::Object^ sender, System::EventArgs^ e) {

	this->passwd2->UseSystemPasswordChar = !this->passwd2->UseSystemPasswordChar;

}
private: System::Void show1_Click(System::Object^ sender, System::EventArgs^ e) {

	this->passwd1->UseSystemPasswordChar = !this->passwd1->UseSystemPasswordChar;

}


};
}