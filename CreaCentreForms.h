#pragma once
#include "TxCrearCentre.h"
#include "TxCrearAten.h"
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
	public ref class CreaCentreForms : public System::Windows::Forms::Form
	{
	public:

		CreaCentreForms(void)
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
		~CreaCentreForms()
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

	private: System::Windows::Forms::Label^ nomLabel;
	private: System::Windows::Forms::Label^ ubicacioLabel;

	protected:
	private: System::Windows::Forms::FontDialog^ fontDialog1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::TextBox^ ubicacioBox;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button4;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ AdvertName;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ advertTelefon;
	private: System::Windows::Forms::MaskedTextBox^ telefonBox;
	private: System::Windows::Forms::Label^ telefonLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::CheckedListBox^ tipuscentre;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	protected:

	protected:
	private: System::ComponentModel::IContainer^ components;

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary
#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreaCentreForms::typeid));
			   this->nameBox = (gcnew System::Windows::Forms::TextBox());
			   this->nomLabel = (gcnew System::Windows::Forms::Label());
			   this->ubicacioLabel = (gcnew System::Windows::Forms::Label());
			   this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->button4 = (gcnew System::Windows::Forms::Button());
			   this->label10 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->tipuscentre = (gcnew System::Windows::Forms::CheckedListBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->advertTelefon = (gcnew System::Windows::Forms::Label());
			   this->telefonBox = (gcnew System::Windows::Forms::MaskedTextBox());
			   this->telefonLabel = (gcnew System::Windows::Forms::Label());
			   this->button3 = (gcnew System::Windows::Forms::Button());
			   this->AdvertName = (gcnew System::Windows::Forms::Label());
			   this->label11 = (gcnew System::Windows::Forms::Label());
			   this->ubicacioBox = (gcnew System::Windows::Forms::TextBox());
			   this->label7 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			   this->panel1->SuspendLayout();
			   this->panel2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // nameBox
			   // 
			   this->nameBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->nameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->nameBox->Location = System::Drawing::Point(145, 143);
			   this->nameBox->Name = L"nameBox";
			   this->nameBox->Size = System::Drawing::Size(698, 24);
			   this->nameBox->TabIndex = 1;
			   // 
			   // nomLabel
			   // 
			   this->nomLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->nomLabel->AutoSize = true;
			   this->nomLabel->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->nomLabel->Location = System::Drawing::Point(86, 147);
			   this->nomLabel->Name = L"nomLabel";
			   this->nomLabel->Size = System::Drawing::Size(45, 20);
			   this->nomLabel->TabIndex = 3;
			   this->nomLabel->Text = L"Nom:";
			   // 
			   // ubicacioLabel
			   // 
			   this->ubicacioLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->ubicacioLabel->AutoSize = true;
			   this->ubicacioLabel->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ubicacioLabel->Location = System::Drawing::Point(58, 265);
			   this->ubicacioLabel->Name = L"ubicacioLabel";
			   this->ubicacioLabel->Size = System::Drawing::Size(73, 20);
			   this->ubicacioLabel->TabIndex = 9;
			   this->ubicacioLabel->Text = L"Ubicació:";
			   // 
			   // panel1
			   // 
			   this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			   this->panel1->AutoSize = true;
			   this->panel1->BackColor = System::Drawing::Color::Transparent;
			   this->panel1->Controls->Add(this->panel2);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->tipuscentre);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->advertTelefon);
			   this->panel1->Controls->Add(this->telefonBox);
			   this->panel1->Controls->Add(this->telefonLabel);
			   this->panel1->Controls->Add(this->button3);
			   this->panel1->Controls->Add(this->AdvertName);
			   this->panel1->Controls->Add(this->label11);
			   this->panel1->Controls->Add(this->ubicacioBox);
			   this->panel1->Controls->Add(this->label7);
			   this->panel1->Controls->Add(this->button1);
			   this->panel1->Controls->Add(this->ubicacioLabel);
			   this->panel1->Controls->Add(this->nameBox);
			   this->panel1->Controls->Add(this->nomLabel);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->panel1->Location = System::Drawing::Point(59, 12);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(3596, 1337);
			   this->panel1->TabIndex = 10;
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
			   this->panel2->Controls->Add(this->label10);
			   this->panel2->Location = System::Drawing::Point(169, 188);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(723, 264);
			   this->panel2->TabIndex = 19;
			   this->panel2->Visible = false;
			   // 
			   // button4
			   // 
			   this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			   this->button4->BackColor = System::Drawing::Color::Transparent;
			   this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button4->Location = System::Drawing::Point(262, 195);
			   this->button4->Name = L"button4";
			   this->button4->Size = System::Drawing::Size(170, 35);
			   this->button4->TabIndex = 13;
			   this->button4->Text = L"Sortir";
			   this->button4->UseVisualStyleBackColor = false;
			   this->button4->Click += gcnew System::EventHandler(this, &CreaCentreForms::exitbuttonconfirmation_Click);
			   // 
			   // label10
			   // 
			   this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label10->AutoSize = true;
			   this->label10->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label10->Location = System::Drawing::Point(232, 99);
			   this->label10->Name = L"label10";
			   this->label10->Size = System::Drawing::Size(227, 75);
			   this->label10->TabIndex = 3;
			   this->label10->Text = L"El teu centre s\'ha afegit.\r\n\r\n\r\n";
			   this->label10->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			   // 
			   // label3
			   // 
			   this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label3->AutoSize = true;
			   this->label3->ForeColor = System::Drawing::Color::Red;
			   this->label3->Location = System::Drawing::Point(865, 320);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(120, 20);
			   this->label3->TabIndex = 34;
			   this->label3->Text = L"Required Field *";
			   this->label3->Visible = false;
			   // 
			   // tipuscentre
			   // 
			   this->tipuscentre->FormattingEnabled = true;
			   this->tipuscentre->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				   L"gat", L"canari", L"conill", L"gos", L"hamster",
					   L"lloro", L"pony", L"porc"
			   });
			   this->tipuscentre->Location = System::Drawing::Point(145, 313);
			   this->tipuscentre->Margin = System::Windows::Forms::Padding(2);
			   this->tipuscentre->Name = L"tipuscentre";
			   this->tipuscentre->Size = System::Drawing::Size(699, 139);
			   this->tipuscentre->TabIndex = 32;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(81, 313);
			   this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(52, 20);
			   this->label1->TabIndex = 31;
			   this->label1->Text = L"Tipus:";
			   // 
			   // advertTelefon
			   // 
			   this->advertTelefon->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->advertTelefon->AutoSize = true;
			   this->advertTelefon->ForeColor = System::Drawing::Color::Red;
			   this->advertTelefon->Location = System::Drawing::Point(864, 197);
			   this->advertTelefon->Name = L"advertTelefon";
			   this->advertTelefon->Size = System::Drawing::Size(120, 20);
			   this->advertTelefon->TabIndex = 30;
			   this->advertTelefon->Text = L"Required Field *";
			   this->advertTelefon->Visible = false;
			   // 
			   // telefonBox
			   // 
			   this->telefonBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->telefonBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->telefonBox->Location = System::Drawing::Point(145, 203);
			   this->telefonBox->Mask = L"+34 000 000 000";
			   this->telefonBox->Name = L"telefonBox";
			   this->telefonBox->Size = System::Drawing::Size(698, 24);
			   this->telefonBox->TabIndex = 28;
			   // 
			   // telefonLabel
			   // 
			   this->telefonLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->telefonLabel->AutoSize = true;
			   this->telefonLabel->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->telefonLabel->Location = System::Drawing::Point(66, 203);
			   this->telefonLabel->Name = L"telefonLabel";
			   this->telefonLabel->Size = System::Drawing::Size(62, 20);
			   this->telefonLabel->TabIndex = 29;
			   this->telefonLabel->Text = L"Telefon:";
			   // 
			   // button3
			   // 
			   this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->button3->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button3->Location = System::Drawing::Point(29, 541);
			   this->button3->Name = L"button3";
			   this->button3->Size = System::Drawing::Size(164, 40);
			   this->button3->TabIndex = 27;
			   this->button3->Text = L"Sortir";
			   this->button3->UseVisualStyleBackColor = true;
			   this->button3->Click += gcnew System::EventHandler(this, &CreaCentreForms::button3_Click);
			   // 
			   // AdvertName
			   // 
			   this->AdvertName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->AdvertName->AutoSize = true;
			   this->AdvertName->ForeColor = System::Drawing::Color::Red;
			   this->AdvertName->Location = System::Drawing::Point(864, 138);
			   this->AdvertName->Name = L"AdvertName";
			   this->AdvertName->Size = System::Drawing::Size(120, 20);
			   this->AdvertName->TabIndex = 22;
			   this->AdvertName->Text = L"Required Field *";
			   this->AdvertName->Visible = false;
			   // 
			   // label11
			   // 
			   this->label11->Location = System::Drawing::Point(0, 0);
			   this->label11->Name = L"label11";
			   this->label11->Size = System::Drawing::Size(100, 23);
			   this->label11->TabIndex = 21;
			   // 
			   // ubicacioBox
			   // 
			   this->ubicacioBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->ubicacioBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ubicacioBox->Location = System::Drawing::Point(144, 261);
			   this->ubicacioBox->Name = L"ubicacioBox";
			   this->ubicacioBox->Size = System::Drawing::Size(698, 24);
			   this->ubicacioBox->TabIndex = 12;
			   // 
			   // label7
			   // 
			   this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label7->AutoSize = true;
			   this->label7->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label7->Location = System::Drawing::Point(412, 29);
			   this->label7->Name = L"label7";
			   this->label7->Size = System::Drawing::Size(261, 42);
			   this->label7->TabIndex = 11;
			   this->label7->Text = L"Registrar Centre";
			   // 
			   // button1
			   // 
			   this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->button1->Location = System::Drawing::Point(858, 541);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(164, 40);
			   this->button1->TabIndex = 10;
			   this->button1->Text = L"Registrar";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &CreaCentreForms::savebutton_Click);
			   // 
			   // label2
			   // 
			   this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->label2->AutoSize = true;
			   this->label2->ForeColor = System::Drawing::Color::Red;
			   this->label2->Location = System::Drawing::Point(864, 253);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(120, 20);
			   this->label2->TabIndex = 33;
			   this->label2->Text = L"Required Field *";
			   this->label2->Visible = false;
			   // 
			   // errorProvider1
			   // 
			   this->errorProvider1->ContainerControl = this;
			   // 
			   // CreaCentreForms
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			   this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->ClientSize = System::Drawing::Size(1184, 661);
			   this->Controls->Add(this->panel1);
			   this->Name = L"CreaCentreForms";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"PETSALUT";
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion


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
		bool name = false;
		bool telefon = false;
		bool ubicacio = false;
		bool tipus = false;
		if (String::IsNullOrWhiteSpace(this->nameBox->Text)) {
			this->AdvertName->Visible = true;
		}
		else {
			name = true;
			this->AdvertName->Visible = false;
		}
		if (telefonBox->MaskFull) {
			this->advertTelefon->Visible = false;
			telefon = true;
		}
		else {
			telefon = false;
			this->advertTelefon->Visible = true;
		}
		if (String::IsNullOrWhiteSpace(this->ubicacioBox->Text)) {
			this->label2->Visible = true;
		}
		else {
			ubicacio = true;
			this->label2->Visible = false;
		}
		for (int i = 0; i < this->tipuscentre->Items->Count; i++)
		{
			System::String^ item = this->tipuscentre->Items[i]->ToString();
			bool isChecked = this->tipuscentre->GetItemChecked(i);
			if (isChecked) {
				tipus = true;
				i = this->tipuscentre->Items->Count;
				this->label3->Visible = false;
			}
		}
		if (tipus == false) {
			this->label3->Visible = true;
		}
		if ((name == true) && (telefon == true) && (ubicacio == true) && (tipus == true)) {
			this->panel2->Visible = true;
			//guardar centre
			Ordinador^ ord = Ordinador::getInstance();
			PassarellaUsuari^ usuari = ord->obteUsuari();
			TxCrearCentre^ nouCentre = TxCrearCentre::crear(this->nameBox->Text, this->telefonBox->Text, usuari->getUsername(), this->ubicacioBox->Text);
			nouCentre->ejecutar();
			int id = nouCentre->Numero_ID;
			for (int i = 0; i < this->tipuscentre->Items->Count; i++)
			{
				System::String^ item = this->tipuscentre->Items[i]->ToString();
				bool isChecked = this->tipuscentre->GetItemChecked(i);
				if (isChecked) {
					TxCrearAten^ nouAten = TxCrearAten::crear(item, id);
					nouAten->ejecutar();
				}
			}
		}
	}



private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
}
};
}