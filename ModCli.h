#pragma once
#include "TxConsultaUsu.h"
#include "TxModUsu.h"
#include "Ordinador.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Resumen de ModCli
	/// </summary>
	public ref class ModCli : public System::Windows::Forms::Form
	{
	public:

		String^ iniUsername;
		String^ iniName;
		String^ iniMail;
		String^ iniPhone;
		String^ iniDate;
		String^ iniPasswd;
	private: System::Windows::Forms::Button^ mostrar_contraseña;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ phoneLabel;
	private: System::Windows::Forms::MaskedTextBox^ phone;



	public:

	public:

	public:
		String^ iniDesc;

		ModCli(void)
		{

			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			try {

				TxConsultaUsu conU;
				conU.crear();
				conU.executar();

				TxConsultaUsu::Resultat res = conU.obteResultat();

				this->nameBox->Text = res.nom;
				iniName = res.nom;

				this->mailBox->Text = res.correu;
				iniMail = res.correu;

				this->phoneLabel->Text = res.telefon;
				iniPhone = res.telefon;

				this->usernameLabel->Text = res.username;
				iniUsername = res.username;

				iniPasswd = res.contrasenya;

				this->descBox->Text = res.descripcio;
				iniPasswd = res.descripcio;

			}

			catch (Exception^ ex)
			{
				MessageBox::Show("Error: " + ex->Message);
			}

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ModCli()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ nameBox;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ mailBox;
	private: System::Windows::Forms::TextBox^ passwdBox;
	private: System::Windows::Forms::TextBox^ descBox;









	private: System::Windows::Forms::Label^ usernameLabel;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ AplicarCambis;






	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModCli::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mailBox = (gcnew System::Windows::Forms::TextBox());
			this->passwdBox = (gcnew System::Windows::Forms::TextBox());
			this->descBox = (gcnew System::Windows::Forms::TextBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->AplicarCambis = (gcnew System::Windows::Forms::Button());
			this->mostrar_contraseña = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->phone = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(177, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(325, 42);
			this->label1->TabIndex = 34;
			this->label1->Text = L"Modificar Informacio";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(475, 180);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 25);
			this->label2->TabIndex = 48;
			this->label2->Text = L"Nom Complert";
			// 
			// nameBox
			// 
			this->nameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameBox->Location = System::Drawing::Point(477, 216);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(174, 23);
			this->nameBox->TabIndex = 49;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(682, 180);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(106, 25);
			this->label9->TabIndex = 56;
			this->label9->Text = L"Descripcio";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(180, 353);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(78, 25);
			this->label4->TabIndex = 52;
			this->label4->Text = L"Telefon";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(183, 180);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(128, 25);
			this->label6->TabIndex = 54;
			this->label6->Text = L"Nom d\'usuari";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(474, 272);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(124, 25);
			this->label7->TabIndex = 55;
			this->label7->Text = L"Contrasenya";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(180, 272);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(166, 25);
			this->label3->TabIndex = 51;
			this->label3->Text = L"Correu Electronic";
			// 
			// mailBox
			// 
			this->mailBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mailBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mailBox->Location = System::Drawing::Point(182, 300);
			this->mailBox->Name = L"mailBox";
			this->mailBox->Size = System::Drawing::Size(234, 23);
			this->mailBox->TabIndex = 57;
			// 
			// passwdBox
			// 
			this->passwdBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwdBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwdBox->Location = System::Drawing::Point(477, 300);
			this->passwdBox->Name = L"passwdBox";
			this->passwdBox->Size = System::Drawing::Size(174, 23);
			this->passwdBox->TabIndex = 58;
			this->passwdBox->UseSystemPasswordChar = true;
			// 
			// descBox
			// 
			this->descBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descBox->Location = System::Drawing::Point(686, 216);
			this->descBox->Multiline = true;
			this->descBox->Name = L"descBox";
			this->descBox->Size = System::Drawing::Size(302, 186);
			this->descBox->TabIndex = 59;
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
			this->usernameLabel->Location = System::Drawing::Point(184, 216);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(73, 17);
			this->usernameLabel->TabIndex = 62;
			this->usernameLabel->Text = L"Username";
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(183, 535);
			this->button2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(172, 38);
			this->button2->TabIndex = 65;
			this->button2->Text = L"Tornar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ModCli::button2_Click);
			// 
			// AplicarCambis
			// 
			this->AplicarCambis->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AplicarCambis->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AplicarCambis->Location = System::Drawing::Point(817, 535);
			this->AplicarCambis->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->AplicarCambis->Name = L"AplicarCambis";
			this->AplicarCambis->Size = System::Drawing::Size(171, 38);
			this->AplicarCambis->TabIndex = 66;
			this->AplicarCambis->Text = L"Aplicar Cambis";
			this->AplicarCambis->UseVisualStyleBackColor = true;
			this->AplicarCambis->Click += gcnew System::EventHandler(this, &ModCli::AplicarCambis_Click);
			// 
			// mostrar_contraseña
			// 
			this->mostrar_contraseña->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mostrar_contraseña->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mostrar_contraseña->Location = System::Drawing::Point(477, 333);
			this->mostrar_contraseña->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->mostrar_contraseña->Name = L"mostrar_contraseña";
			this->mostrar_contraseña->Size = System::Drawing::Size(76, 25);
			this->mostrar_contraseña->TabIndex = 70;
			this->mostrar_contraseña->Text = L"Mostrar";
			this->mostrar_contraseña->UseVisualStyleBackColor = true;
			this->mostrar_contraseña->Click += gcnew System::EventHandler(this, &ModCli::button1_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(184, 426);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 25);
			this->button1->TabIndex = 73;
			this->button1->Text = L"Modificar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ModCli::button1_Click_1);
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
			this->phoneLabel->Location = System::Drawing::Point(179, 394);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Size = System::Drawing::Size(56, 17);
			this->phoneLabel->TabIndex = 72;
			this->phoneLabel->Text = L"Telefon";
			// 
			// phone
			// 
			this->phone->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phone->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phone->Location = System::Drawing::Point(187, 392);
			this->phone->Mask = L"+00 000 000 000";
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(229, 23);
			this->phone->TabIndex = 71;
			this->phone->Visible = false;
			// 
			// ModCli
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->mostrar_contraseña);
			this->Controls->Add(this->AplicarCambis);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->descBox);
			this->Controls->Add(this->passwdBox);
			this->Controls->Add(this->mailBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ModCli";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PETSALUT";
			this->Load += gcnew System::EventHandler(this, &ModCli::ModCli_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void AplicarCambis_Click(System::Object^ sender, System::EventArgs^ e) {

		try {

			if (iniPasswd != this->passwdBox->Text) iniPasswd = this->passwdBox->Text;
			if (iniName != this->nameBox->Text) iniName = this->nameBox->Text;
			if (iniMail != this->mailBox->Text) iniMail = this->mailBox->Text;
			if (iniDesc != this->descBox->Text) iniDesc = this->descBox->Text;

			if (!this->phoneLabel->Visible) iniPhone = this->phone->Text;

			TxModUsu modUsu;
			modUsu.crear(iniUsername, iniPasswd, iniName, iniPhone, iniDate, iniMail, iniDesc, "clinica");
			modUsu.executar();

			Ordinador^ ord = Ordinador::getInstance();
			ord->actualitza(iniUsername, iniName, iniPasswd, "clinica", iniMail, iniDesc, iniPhone);

			// Llamar a la función modificarClinica con los parámetros necesarios

			// Si la modificación se realiza correctamente, puedes mostrar un mensaje de éxito
			MessageBox::Show("La modificación se realizó con éxito.");

			this->Close();

		}

		catch (Exception^ ex) {
			// Capturar cualquier excepción lanzada por la función modificarPropietario
			// y mostrar un mensaje de error al usuario
			MessageBox::Show("Error al aplicar els canvis: " + ex->Message);
		}

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();

	}
	private: System::Void ModCli_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	this->passwdBox->UseSystemPasswordChar = !this->passwdBox->UseSystemPasswordChar;

}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->phoneLabel->Visible = !this->phoneLabel->Visible;
	this->phone->Visible = !this->phone->Visible;
}
};
}
