#pragma once
#include "TxCrearMascota.h"
#include "Ordinador.h"
#include "CercadoraTipus.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	/// 
	public ref class Crea_Mascota_forms : public System::Windows::Forms::Form
	{
	public:

		Crea_Mascota_forms(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Crea_Mascota_forms()
		{
			if (components)
			{
				delete components;
			}
		}

		void cargarTiposEnComboBox(System::Windows::Forms::ComboBox^ comboBox) {
			// Llamar al método para obtener todos los tipos desde la base de datos
			List<String^>^ tipos = CercadoraTipus::obteTotsTipus();

			// Limpiar el ComboBox antes de agregar los nuevos tipos
			comboBox->Items->Clear();

			// Agregar los tipos obtenidos al ComboBox
			comboBox->Items->AddRange(tipos->ToArray());
		}
	private: System::Windows::Forms::TextBox^ nameBox;
	private: System::Windows::Forms::DateTimePicker^ birthdayBox;
	private: System::Windows::Forms::Label^ nomLabel;

	protected:




	private: System::Windows::Forms::Label^ cumpleLabel;

	private: System::Windows::Forms::Label^ tipusLabel;




	private: System::Windows::Forms::ComboBox^ typeBox;


	private: System::Windows::Forms::Label^ chipLabel;
	private: System::Windows::Forms::Label^ descripcioLabel;






	private: System::Windows::Forms::FontDialog^ fontDialog1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ descriptionBox;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ AdvertName;
	private: System::Windows::Forms::Label^ AdvertType;


	private: System::Windows::Forms::Label^ AdvertBirthay;

	private: System::Windows::Forms::Label^ AdvertChip;
	private: System::Windows::Forms::TextBox^ chipBox;
	private: System::Windows::Forms::Button^ button3;



	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
	private: System::Void chipBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		// Verifica si el carácter no es un dígito ni un control (como retroceso)
		if (!Char::IsDigit(e->KeyChar) && !Char::IsControl(e->KeyChar)) {
			e->Handled = true; // Maneja el evento, efectivamente ignorando la entrada no deseada
		}
	}

	private: System::Void exitbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		this->Close();
	}
	private: System::Void exitbuttonconfirmation_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		this->Close();
	}
	private: System::Void savebutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		if (String::IsNullOrWhiteSpace(this->nameBox->Text)) {
			this->AdvertName->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->chipBox->Text)) {
			this->AdvertChip->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->typeBox->Text)) {
			this->AdvertType->Visible = true;
		}
		else {


			this->panel2->Visible = true;
			this->button1->Visible = false;
			//guardar mascota
			int chipValue = 0;
			Ordinador^ ord = Ordinador::getInstance();
			PassarellaUsuari^ usuari = ord->obteUsuari();
			chipValue = System::Convert::ToInt64(this->chipBox->Text);
			TxCrearMascota^ nuevaMascota = TxCrearMascota::crear(this->nameBox->Text->ToString(), this->birthdayBox->Value, chipValue, this->typeBox->Text->ToString(), usuari->getUsername(), this->descriptionBox->Text->ToString());
			nuevaMascota->ejecutar();

		}
	}
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Crea_Mascota_forms::typeid));
			   this->nameBox = (gcnew System::Windows::Forms::TextBox());
			   this->birthdayBox = (gcnew System::Windows::Forms::DateTimePicker());
			   this->nomLabel = (gcnew System::Windows::Forms::Label());
			   this->cumpleLabel = (gcnew System::Windows::Forms::Label());
			   this->tipusLabel = (gcnew System::Windows::Forms::Label());
			   this->typeBox = (gcnew System::Windows::Forms::ComboBox());
			   this->chipLabel = (gcnew System::Windows::Forms::Label());
			   this->descripcioLabel = (gcnew System::Windows::Forms::Label());
			   this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->chipBox = (gcnew System::Windows::Forms::TextBox());
			   this->AdvertType = (gcnew System::Windows::Forms::Label());
			   this->AdvertBirthay = (gcnew System::Windows::Forms::Label());
			   this->AdvertChip = (gcnew System::Windows::Forms::Label());
			   this->AdvertName = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->descriptionBox = (gcnew System::Windows::Forms::TextBox());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->label9 = (gcnew System::Windows::Forms::Label());
			   this->button2 = (gcnew System::Windows::Forms::Button());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label6 = (gcnew System::Windows::Forms::Label());
			   this->label8 = (gcnew System::Windows::Forms::Label());
			   this->panel1->SuspendLayout();
			   this->panel2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // nameBox
			   // 
			   this->nameBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->nameBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->nameBox->Location = System::Drawing::Point(141, 78);
			   this->nameBox->Name = L"nameBox";
			   this->nameBox->Size = System::Drawing::Size(676, 22);
			   this->nameBox->TabIndex = 1;
			   // 
			   // birthdayBox
			   // 
			   this->birthdayBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->birthdayBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->birthdayBox->Location = System::Drawing::Point(141, 216);
			   this->birthdayBox->Name = L"birthdayBox";
			   this->birthdayBox->Size = System::Drawing::Size(676, 22);
			   this->birthdayBox->TabIndex = 2;
			   // 
			   // nomLabel
			   // 
			   this->nomLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->nomLabel->AutoSize = true;
			   this->nomLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			   this->nomLabel->Location = System::Drawing::Point(72, 80);
			   this->nomLabel->Name = L"nomLabel";
			   this->nomLabel->Size = System::Drawing::Size(55, 20);
			   this->nomLabel->TabIndex = 3;
			   this->nomLabel->Text = L"Nom:";
			   this->nomLabel->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label1_Click);
			   // 
			   // cumpleLabel
			   // 
			   this->cumpleLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->cumpleLabel->AutoSize = true;
			   this->cumpleLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			   this->cumpleLabel->Location = System::Drawing::Point(18, 217);
			   this->cumpleLabel->Name = L"cumpleLabel";
			   this->cumpleLabel->Size = System::Drawing::Size(107, 20);
			   this->cumpleLabel->TabIndex = 4;
			   this->cumpleLabel->Text = L"Aniversari:";
			   this->cumpleLabel->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label2_Click);
			   // 
			   // tipusLabel
			   // 
			   this->tipusLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->tipusLabel->AutoSize = true;
			   this->tipusLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			   this->tipusLabel->Location = System::Drawing::Point(66, 291);
			   this->tipusLabel->Name = L"tipusLabel";
			   this->tipusLabel->Size = System::Drawing::Size(61, 20);
			   this->tipusLabel->TabIndex = 5;
			   this->tipusLabel->Text = L"Tipus:";
			   // 
			   // typeBox
			   // 
			   this->typeBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->typeBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			   this->typeBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->typeBox->FormattingEnabled = true;
			   this->typeBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				   L"canari", L"conill", L"gat", L"gos", L"hamster",
					   L"lloro", L"pony", L"porc"
			   });
			   this->typeBox->Location = System::Drawing::Point(141, 288);
			   this->typeBox->Name = L"typeBox";
			   this->typeBox->Size = System::Drawing::Size(676, 26);
			   this->typeBox->TabIndex = 6;
			   // 
			   // chipLabel
			   // 
			   this->chipLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->chipLabel->AutoSize = true;
			   this->chipLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			   this->chipLabel->Location = System::Drawing::Point(72, 148);
			   this->chipLabel->Name = L"chipLabel";
			   this->chipLabel->Size = System::Drawing::Size(53, 20);
			   this->chipLabel->TabIndex = 7;
			   this->chipLabel->Text = L"Chip:";
			   this->chipLabel->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label4_Click);
			   // 
			   // descripcioLabel
			   // 
			   this->descripcioLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->descripcioLabel->AutoSize = true;
			   this->descripcioLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			   this->descripcioLabel->Location = System::Drawing::Point(23, 364);
			   this->descripcioLabel->Name = L"descripcioLabel";
			   this->descripcioLabel->Size = System::Drawing::Size(104, 20);
			   this->descripcioLabel->TabIndex = 9;
			   this->descripcioLabel->Text = L"Descripció:";
			   // 
			   // fontDialog1
			   // 
			   this->fontDialog1->Apply += gcnew System::EventHandler(this, &Crea_Mascota_forms::fontDialog1_Apply);
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel1->AutoSize = true;
			   this->panel1->BackColor = System::Drawing::SystemColors::Control;
			   this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panel1->Controls->Add(this->button3);
			   this->panel1->Controls->Add(this->chipBox);
			   this->panel1->Controls->Add(this->AdvertType);
			   this->panel1->Controls->Add(this->AdvertBirthay);
			   this->panel1->Controls->Add(this->AdvertChip);
			   this->panel1->Controls->Add(this->AdvertName);
			   this->panel1->Controls->Add(this->label11);
			   this->panel1->Controls->Add(this->descriptionBox);
			   this->panel1->Controls->Add(this->label7);
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Controls->Add(this->descripcioLabel);
			   this->panel1->Controls->Add(this->nameBox);
			   this->panel1->Controls->Add(this->birthdayBox);
			   this->panel1->Controls->Add(this->chipLabel);
			   this->panel1->Controls->Add(this->nomLabel);
			   this->panel1->Controls->Add(this->typeBox);
			   this->panel1->Controls->Add(this->cumpleLabel);
			   this->panel1->Controls->Add(this->tipusLabel);
			   this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			   this->panel1->Location = System::Drawing::Point(80, 85);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1032, 572);
			   this->panel1->TabIndex = 10;
			   this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Crea_Mascota_forms::panel1_Paint);
			   // 
			   // button3
			   // 
			   this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->button3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			   this->button3->Location = System::Drawing::Point(684, 461);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(133, 90);
			   this->button3->TabIndex = 27;
			   this->button3->Text = L"Sortir";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::button3_Click);
			   // 
			   // chipBox
			   // 
			   this->chipBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->chipBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->chipBox->Location = System::Drawing::Point(141, 144);
			   this->chipBox->MaxLength = 9;
			   this->chipBox->Name = L"chipBox";
			   this->chipBox->Size = System::Drawing::Size(676, 22);
			   this->chipBox->TabIndex = 26;
			   this->chipBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Crea_Mascota_forms::chipBox_KeyPress);
			   // 
			   // AdvertType
			   // 
			   this->AdvertType->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->AdvertType->AutoSize = true;
			   this->AdvertType->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->AdvertType->ForeColor = System::Drawing::Color::Brown;
			   this->AdvertType->Location = System::Drawing::Point(823, 291);
			   this->AdvertType->Name = L"AdvertType";
			   this->AdvertType->Size = System::Drawing::Size(131, 18);
			   this->AdvertType->TabIndex = 25;
			   this->AdvertType->Text = L"Required Field *";
			   this->AdvertType->Visible = false;
			   // 
			   // AdvertBirthay
			   // 
			   this->AdvertBirthay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->AdvertBirthay->AutoSize = true;
			   this->AdvertBirthay->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->AdvertBirthay->ForeColor = System::Drawing::Color::Brown;
			   this->AdvertBirthay->Location = System::Drawing::Point(823, 221);
			   this->AdvertBirthay->Name = L"AdvertBirthay";
			   this->AdvertBirthay->Size = System::Drawing::Size(131, 18);
			   this->AdvertBirthay->TabIndex = 24;
			   this->AdvertBirthay->Text = L"Required Field *";
			   this->AdvertBirthay->Visible = false;
			   this->AdvertBirthay->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label14_Click);
			   // 
			   // AdvertChip
			   // 
			   this->AdvertChip->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->AdvertChip->AutoSize = true;
			   this->AdvertChip->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->AdvertChip->ForeColor = System::Drawing::Color::Brown;
			   this->AdvertChip->Location = System::Drawing::Point(823, 149);
			   this->AdvertChip->Name = L"AdvertChip";
			   this->AdvertChip->Size = System::Drawing::Size(131, 18);
			   this->AdvertChip->TabIndex = 23;
			   this->AdvertChip->Text = L"Required Field *";
			   this->AdvertChip->Visible = false;
			   // 
			   // AdvertName
			   // 
			   this->AdvertName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->AdvertName->AutoSize = true;
			   this->AdvertName->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->AdvertName->ForeColor = System::Drawing::Color::Brown;
			   this->AdvertName->Location = System::Drawing::Point(823, 81);
			   this->AdvertName->Name = L"AdvertName";
			   this->AdvertName->Size = System::Drawing::Size(131, 18);
			   this->AdvertName->TabIndex = 22;
			   this->AdvertName->Text = L"Required Field *";
			   this->AdvertName->Visible = false;
			   this->AdvertName->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label12_Click);
			   // 
			   // label11
			   // 
			   this->label11->Location = System::Drawing::Point(0, 0);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(100, 23);
			   this->label11->TabIndex = 21;
			   // 
			   // descriptionBox
			   // 
			   this->descriptionBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->descriptionBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9));
			   this->descriptionBox->Location = System::Drawing::Point(141, 364);
			   this->descriptionBox->Name = L"descriptionBox";
			   this->descriptionBox->Size = System::Drawing::Size(676, 22);
			   this->descriptionBox->TabIndex = 12;
			   this->descriptionBox->TextChanged += gcnew System::EventHandler(this, &Crea_Mascota_forms::textBox2_TextChanged);
			   // 
			   // label7
			   // 
			   this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 16));
			   this->label7->Location = System::Drawing::Point(386, 28);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(234, 31);
			   this->label7->TabIndex = 11;
			   this->label7->Text = L"NOVA MASCOTA";
			   this->label7->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label7_Click);
			   // 
			   // button1
			   // 
			   this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			   this->button1->Location = System::Drawing::Point(853, 461);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(138, 90);
			   this->button1->TabIndex = 10;
			   this->button1->Text = L"Registrar";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::savebutton_Click);
			   // 
			   // panel2
			   // 
			   this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->panel2->AutoScroll = true;
			   this->panel2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			   this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			   this->panel2->Controls->Add(this->button4);
			   this->panel2->Controls->Add(this->label9);
			   this->panel2->Controls->Add(this->button2);
			   this->panel2->Controls->Add(this->label10);
			   this->panel2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			   this->panel2->Location = System::Drawing::Point(27, 164);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(1123, 245);
			   this->panel2->TabIndex = 19;
			   this->panel2->Visible = false;
			   // 
			   // button4
			   // 
			   this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button4->BackColor = System::Drawing::Color::Transparent;
			   this->button4->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			   this->button4->Location = System::Drawing::Point(975, 172);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(127, 64);
			   this->button4->TabIndex = 13;
			   this->button4->Text = L"Sortir";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::exitbuttonconfirmation_Click);
			   // 
			   // label9
			   // 
			   this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label9->AutoSize = true;
			   this->label9->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			   this->label9->Location = System::Drawing::Point(442, 21);
			   this->label9->Name = L"label9";
			   this->label9->Size = System::Drawing::Size(202, 26);
			   this->label9->TabIndex = 11;
			   this->label9->Text = L"NOVA MASCOTA";
			   this->label9->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label9_Click);
			   // 
			   // button2
			   // 
			   this->button2->BackColor = System::Drawing::Color::Firebrick;
			   this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			   this->button2->Location = System::Drawing::Point(1068, 3);
			   this->button2->Name = L"button2";
			   this->button2->Size = System::Drawing::Size(34, 34);
			   this->button2->TabIndex = 13;
			   this->button2->Text = L"X";
			   this->button2->UseVisualStyleBackColor = false;
			   this->button2->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::exitbutton_Click);
			   // 
			   // label10
			   // 
			   this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			   this->label10->Location = System::Drawing::Point(117, 134);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(793, 26);
			   this->label10->TabIndex = 3;
			   this->label10->Text = L"La teva mascota s\'ha afegit a la teva secció \"LES MEVES MASCOTES\".";
			   this->label10->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label10_Click);
			   // 
			   // label6
			   // 
			   this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->label6->AutoSize = true;
			   this->label6->BackColor = System::Drawing::Color::Transparent;
			   this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 24));
			   this->label6->Location = System::Drawing::Point(474, 9);
			   this->label6->MaximumSize = System::Drawing::Size(255, 255);
			   this->label6->Name = L"label6";
			   this->label6->Size = System::Drawing::Size(218, 44);
			   this->label6->TabIndex = 11;
			   this->label6->Text = L"PETSALUT";
			   this->label6->Click += gcnew System::EventHandler(this, &Crea_Mascota_forms::label6_Click);
			   // 
			   // label8
			   // 
			   this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->label8->AutoSize = true;
			   this->label8->BackColor = System::Drawing::Color::Transparent;
			   this->label8->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18));
			   this->label8->Location = System::Drawing::Point(432, 49);
			   this->label8->Name = L"label8";
			   this->label8->Size = System::Drawing::Size(308, 33);
			   this->label8->TabIndex = 12;
			   this->label8->Text = L"Les Meves Mascotes";
			   // 
			   // Crea_Mascota_forms
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(1184, 661);
			   this->Controls->Add(this->panel2);
			   this->Controls->Add(this->label8);
			   this->Controls->Add(this->label6);
			   this->Controls->Add(this->panel1);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Name = L"Crea_Mascota_forms";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			   this->Text = L"PETSALUT";
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void fontDialog1_Apply(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Form1_Resize(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label14_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public:
private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Close();

}
};
}