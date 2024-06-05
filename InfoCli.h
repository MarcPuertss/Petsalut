#pragma once
#include "TxConsultaUsu.h"
#include "ModCli.h"
#include "ConsultaCentresForm.h"
namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de InfoCli
	/// </summary>
	public ref class InfoCli : public System::Windows::Forms::Form
	{
	public:
		InfoCli(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c?digo de constructor aqu?
			//

			try {

				TxConsultaUsu conU;
				conU.crear();
				conU.executar();

				TxConsultaUsu::Resultat res = conU.obteResultat();

				this->nameLabel->Text = res.nom;
				this->mailLabel->Text = res.correu;
				this->phoneLabel->Text = res.telefon;
				this->usernameLabel->Text = res.username;
				this->passwordLabel->Text = res.contrasenya;
				this->descripcio->Text = res.descripcio;

			}

			catch (Exception^ ex)
			{
				MessageBox::Show("Error: " + ex->Message);
			}

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est?n usando.
		/// </summary>
		~InfoCli()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label9;
	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::Label^ mailLabel;
	private: System::Windows::Forms::Label^ phoneLabel;

	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::Label^ descripcio;
	private: System::Windows::Forms::Button^ mostraCentresButton;

	private: System::Windows::Forms::Button^ modificarButton;
	private: System::Windows::Forms::Button^ tornaButton;


	private:
		/// <summary>
		/// Variable del dise?ador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M?todo necesario para admitir el Dise?ador. No se puede modificar
		/// el contenido de este m?todo con el editor de c?digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InfoCli::typeid));
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->mailLabel = (gcnew System::Windows::Forms::Label());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->descripcio = (gcnew System::Windows::Forms::Label());
			this->mostraCentresButton = (gcnew System::Windows::Forms::Button());
			this->modificarButton = (gcnew System::Windows::Forms::Button());
			this->tornaButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(739, 168);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(106, 25);
			this->label9->TabIndex = 46;
			this->label9->Text = L"Descripció";
			this->label9->Click += gcnew System::EventHandler(this, &InfoCli::label9_Click);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(104, 267);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(166, 25);
			this->label3->TabIndex = 36;
			this->label3->Text = L"Correu Electronic";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(443, 267);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(124, 25);
			this->label7->TabIndex = 41;
			this->label7->Text = L"Contrasenya";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(106, 168);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(128, 25);
			this->label6->TabIndex = 40;
			this->label6->Text = L"Nom d\'usuari";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(104, 367);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 25);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Telefon";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(443, 168);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 25);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Nom Complert";
			this->label2->Click += gcnew System::EventHandler(this, &InfoCli::label2_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(104, 85);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(285, 42);
			this->label1->TabIndex = 33;
			this->label1->Text = L"Informacio Clinica";
			this->label1->Click += gcnew System::EventHandler(this, &InfoCli::label1_Click);
			// 
			// nameLabel
			// 
			this->nameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nameLabel->AutoSize = true;
			this->nameLabel->BackColor = System::Drawing::Color::Transparent;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->nameLabel->Location = System::Drawing::Point(445, 207);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(37, 17);
			this->nameLabel->TabIndex = 47;
			this->nameLabel->Text = L"Nom";
			// 
			// mailLabel
			// 
			this->mailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mailLabel->AutoSize = true;
			this->mailLabel->BackColor = System::Drawing::Color::Transparent;
			this->mailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mailLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->mailLabel->Location = System::Drawing::Point(104, 300);
			this->mailLabel->Name = L"mailLabel";
			this->mailLabel->Size = System::Drawing::Size(51, 17);
			this->mailLabel->TabIndex = 48;
			this->mailLabel->Text = L"Correu";
			// 
			// phoneLabel
			// 
			this->phoneLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phoneLabel->AutoSize = true;
			this->phoneLabel->BackColor = System::Drawing::Color::Transparent;
			this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->phoneLabel->Location = System::Drawing::Point(104, 400);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Size = System::Drawing::Size(56, 17);
			this->phoneLabel->TabIndex = 49;
			this->phoneLabel->Text = L"Telefon";
			// 
			// usernameLabel
			// 
			this->usernameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->BackColor = System::Drawing::Color::Transparent;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->usernameLabel->Location = System::Drawing::Point(109, 206);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(73, 17);
			this->usernameLabel->TabIndex = 51;
			this->usernameLabel->Text = L"Username";
			// 
			// passwordLabel
			// 
			this->passwordLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->BackColor = System::Drawing::Color::Transparent;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->passwordLabel->Location = System::Drawing::Point(443, 300);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(88, 17);
			this->passwordLabel->TabIndex = 52;
			this->passwordLabel->Text = L"Contrasenya";
			// 
			// descripcio
			// 
			this->descripcio->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descripcio->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->descripcio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->descripcio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->descripcio->Location = System::Drawing::Point(739, 207);
			this->descripcio->Name = L"descripcio";
			this->descripcio->Size = System::Drawing::Size(355, 200);
			this->descripcio->TabIndex = 53;
			this->descripcio->Text = L"Descripcio";
			this->descripcio->Click += gcnew System::EventHandler(this, &InfoCli::descripcio_Click);
			// 
			// mostraCentresButton
			// 
			this->mostraCentresButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mostraCentresButton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mostraCentresButton->Location = System::Drawing::Point(742, 561);
			this->mostraCentresButton->Margin = System::Windows::Forms::Padding(2);
			this->mostraCentresButton->Name = L"mostraCentresButton";
			this->mostraCentresButton->Size = System::Drawing::Size(171, 39);
			this->mostraCentresButton->TabIndex = 54;
			this->mostraCentresButton->Text = L"Mostrar Centres";
			this->mostraCentresButton->UseVisualStyleBackColor = true;
			this->mostraCentresButton->Click += gcnew System::EventHandler(this, &InfoCli::Mostra_Centres_Button);
			// 
			// modificarButton
			// 
			this->modificarButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->modificarButton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->modificarButton->Location = System::Drawing::Point(923, 561);
			this->modificarButton->Margin = System::Windows::Forms::Padding(2);
			this->modificarButton->Name = L"modificarButton";
			this->modificarButton->Size = System::Drawing::Size(171, 39);
			this->modificarButton->TabIndex = 55;
			this->modificarButton->Text = L"Modificar Informacio";
			this->modificarButton->UseVisualStyleBackColor = true;
			this->modificarButton->Click += gcnew System::EventHandler(this, &InfoCli::button1_Click);
			// 
			// tornaButton
			// 
			this->tornaButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tornaButton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tornaButton->Location = System::Drawing::Point(97, 562);
			this->tornaButton->Margin = System::Windows::Forms::Padding(2);
			this->tornaButton->Name = L"tornaButton";
			this->tornaButton->Size = System::Drawing::Size(171, 38);
			this->tornaButton->TabIndex = 56;
			this->tornaButton->Text = L"Tornar";
			this->tornaButton->UseVisualStyleBackColor = true;
			this->tornaButton->Click += gcnew System::EventHandler(this, &InfoCli::button2_Click);
			// 
			// InfoCli
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->tornaButton);
			this->Controls->Add(this->modificarButton);
			this->Controls->Add(this->mostraCentresButton);
			this->Controls->Add(this->descripcio);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->mailLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"InfoCli";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"InfoCli";
			this->Load += gcnew System::EventHandler(this, &InfoCli::InfoCli_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::ModCli^ modCli = gcnew PetSalut::ModCli();

		// Set the size and position of IniUsu to match PantallaPrincipal
		modCli->Size = this->Size;
		modCli->Location = this->Location;

		modCli->ShowDialog();

		this->Close();

	}
	private: System::Void InfoCli_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Mostra_Centres_Button(System::Object^ sender, System::EventArgs^ e) {
		PetSalut::ConsultaCentresForm^ consultaCentres = gcnew PetSalut::ConsultaCentresForm();

		// Set the size and position of IniUsu to match PantallaPrincipal
		consultaCentres->Size = this->Size;
		consultaCentres->Location = this->Location;

		this->Visible = false;

		consultaCentres->ShowDialog();

		this->Visible = true;
	}
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label9_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void descripcio_Click(System::Object^ sender, System::EventArgs^ e) {
}





};
}