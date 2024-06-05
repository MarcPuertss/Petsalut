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
	/// Resumen de ModProp
	/// </summary>
	public ref class ModProp : public System::Windows::Forms::Form
	{
	public:

		String^ iniUsername;
		String^ iniName;
		String^ iniMail;
		String^ iniPhone;
		String^ iniDate;
		String^ iniPasswd;
	private: System::Windows::Forms::Button^ showPasswd;
	private: System::Windows::Forms::Label^ dateLabel;
	private: System::Windows::Forms::Label^ phoneLabel;

	public:
		String^ iniDesc;

		ModProp(void)
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

				this->dateLabel->Text = res.data;
				iniDate = res.data;

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
		~ModProp()
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
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ mailBox;
	private: System::Windows::Forms::TextBox^ passwdBox;
	private: System::Windows::Forms::TextBox^ descBox;




	private: System::Windows::Forms::MaskedTextBox^ phone;
	private: System::Windows::Forms::MaskedTextBox^ date;


	private: System::Windows::Forms::Label^ usernameLabel;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ AplicarCambis;

	private: System::Windows::Forms::Button^ modTelf;
	private: System::Windows::Forms::Button^ modDate;



	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ModProp::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->mailBox = (gcnew System::Windows::Forms::TextBox());
			this->passwdBox = (gcnew System::Windows::Forms::TextBox());
			this->descBox = (gcnew System::Windows::Forms::TextBox());
			this->phone = (gcnew System::Windows::Forms::MaskedTextBox());
			this->date = (gcnew System::Windows::Forms::MaskedTextBox());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->AplicarCambis = (gcnew System::Windows::Forms::Button());
			this->modTelf = (gcnew System::Windows::Forms::Button());
			this->modDate = (gcnew System::Windows::Forms::Button());
			this->showPasswd = (gcnew System::Windows::Forms::Button());
			this->dateLabel = (gcnew System::Windows::Forms::Label());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 16.2F));
			this->label1->Location = System::Drawing::Point(33, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(305, 31);
			this->label1->TabIndex = 34;
			this->label1->Text = L"Modificar Informacio";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label2->Location = System::Drawing::Point(33, 88);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(123, 19);
			this->label2->TabIndex = 48;
			this->label2->Text = L"Nom Complert";
			// 
			// nameBox
			// 
			this->nameBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nameBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->nameBox->Location = System::Drawing::Point(37, 124);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(273, 24);
			this->nameBox->TabIndex = 49;
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label9->Location = System::Drawing::Point(660, 288);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(93, 19);
			this->label9->TabIndex = 56;
			this->label9->Text = L"Descripcio";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label4->Location = System::Drawing::Point(33, 288);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 19);
			this->label4->TabIndex = 52;
			this->label4->Text = L"Telefon";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label5->Location = System::Drawing::Point(33, 388);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(136, 19);
			this->label5->TabIndex = 53;
			this->label5->Text = L"Data Naixement";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label6->Location = System::Drawing::Point(660, 88);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 19);
			this->label6->TabIndex = 54;
			this->label6->Text = L"Nom d\'usuari";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label7->Location = System::Drawing::Point(660, 188);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(109, 19);
			this->label7->TabIndex = 55;
			this->label7->Text = L"Contrasenya";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label3->Location = System::Drawing::Point(33, 188);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 19);
			this->label3->TabIndex = 51;
			this->label3->Text = L"Correu Electronic";
			// 
			// mailBox
			// 
			this->mailBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mailBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->mailBox->Location = System::Drawing::Point(37, 224);
			this->mailBox->Name = L"mailBox";
			this->mailBox->Size = System::Drawing::Size(273, 24);
			this->mailBox->TabIndex = 57;
			// 
			// passwdBox
			// 
			this->passwdBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwdBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->passwdBox->Location = System::Drawing::Point(664, 224);
			this->passwdBox->Name = L"passwdBox";
			this->passwdBox->Size = System::Drawing::Size(369, 24);
			this->passwdBox->TabIndex = 58;
			this->passwdBox->UseSystemPasswordChar = true;
			// 
			// descBox
			// 
			this->descBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->descBox->Location = System::Drawing::Point(664, 324);
			this->descBox->Multiline = true;
			this->descBox->Name = L"descBox";
			this->descBox->Size = System::Drawing::Size(369, 20);
			this->descBox->TabIndex = 59;
			// 
			// phone
			// 
			this->phone->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phone->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->phone->Location = System::Drawing::Point(37, 324);
			this->phone->Mask = L"+00 000 000 000";
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(273, 24);
			this->phone->TabIndex = 60;
			this->phone->Visible = false;
			// 
			// date
			// 
			this->date->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->date->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->date->Location = System::Drawing::Point(37, 424);
			this->date->Mask = L"00/00/0000";
			this->date->Name = L"date";
			this->date->Size = System::Drawing::Size(273, 24);
			this->date->TabIndex = 61;
			this->date->ValidatingType = System::DateTime::typeid;
			this->date->Visible = false;
			// 
			// usernameLabel
			// 
			this->usernameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->BackColor = System::Drawing::Color::Transparent;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->usernameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->usernameLabel->Location = System::Drawing::Point(660, 127);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(130, 19);
			this->usernameLabel->TabIndex = 62;
			this->usernameLabel->Text = L"username Aqui";
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->button2->Location = System::Drawing::Point(37, 548);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(215, 79);
			this->button2->TabIndex = 65;
			this->button2->Text = L"Tornar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ModProp::button2_Click);
			// 
			// AplicarCambis
			// 
			this->AplicarCambis->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->AplicarCambis->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->AplicarCambis->Location = System::Drawing::Point(664, 548);
			this->AplicarCambis->Margin = System::Windows::Forms::Padding(2);
			this->AplicarCambis->Name = L"AplicarCambis";
			this->AplicarCambis->Size = System::Drawing::Size(369, 79);
			this->AplicarCambis->TabIndex = 66;
			this->AplicarCambis->Text = L"Aplicar Canvis";
			this->AplicarCambis->UseVisualStyleBackColor = true;
			this->AplicarCambis->Click += gcnew System::EventHandler(this, &ModProp::AplicarCambis_Click);
			// 
			// modTelf
			// 
			this->modTelf->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->modTelf->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->modTelf->Location = System::Drawing::Point(315, 323);
			this->modTelf->Margin = System::Windows::Forms::Padding(2);
			this->modTelf->Name = L"modTelf";
			this->modTelf->Size = System::Drawing::Size(121, 25);
			this->modTelf->TabIndex = 67;
			this->modTelf->Text = L"Modificar";
			this->modTelf->UseVisualStyleBackColor = true;
			this->modTelf->Click += gcnew System::EventHandler(this, &ModProp::modTelf_Click);
			// 
			// modDate
			// 
			this->modDate->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->modDate->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->modDate->Location = System::Drawing::Point(315, 422);
			this->modDate->Margin = System::Windows::Forms::Padding(2);
			this->modDate->Name = L"modDate";
			this->modDate->Size = System::Drawing::Size(121, 26);
			this->modDate->TabIndex = 68;
			this->modDate->Text = L"Modificar";
			this->modDate->UseVisualStyleBackColor = true;
			this->modDate->Click += gcnew System::EventHandler(this, &ModProp::modData_Click);
			// 
			// showPasswd
			// 
			this->showPasswd->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->showPasswd->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->showPasswd->Location = System::Drawing::Point(1038, 224);
			this->showPasswd->Margin = System::Windows::Forms::Padding(2);
			this->showPasswd->Name = L"showPasswd";
			this->showPasswd->Size = System::Drawing::Size(121, 25);
			this->showPasswd->TabIndex = 69;
			this->showPasswd->Text = L"Mostrar";
			this->showPasswd->UseVisualStyleBackColor = true;
			this->showPasswd->Click += gcnew System::EventHandler(this, &ModProp::showPasswd_Click);
			// 
			// dateLabel
			// 
			this->dateLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dateLabel->AutoSize = true;
			this->dateLabel->BackColor = System::Drawing::Color::Transparent;
			this->dateLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->dateLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->dateLabel->Location = System::Drawing::Point(36, 427);
			this->dateLabel->Name = L"dateLabel";
			this->dateLabel->Size = System::Drawing::Size(171, 19);
			this->dateLabel->TabIndex = 64;
			this->dateLabel->Text = L"datanaixement Aqui";
			// 
			// phoneLabel
			// 
			this->phoneLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phoneLabel->AutoSize = true;
			this->phoneLabel->BackColor = System::Drawing::Color::Transparent;
			this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->phoneLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->phoneLabel->Location = System::Drawing::Point(36, 327);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Size = System::Drawing::Size(107, 19);
			this->phoneLabel->TabIndex = 63;
			this->phoneLabel->Text = L"telefon Aqui";
			// 
			// ModProp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->showPasswd);
			this->Controls->Add(this->modDate);
			this->Controls->Add(this->modTelf);
			this->Controls->Add(this->AplicarCambis);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dateLabel);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->date);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->descBox);
			this->Controls->Add(this->passwdBox);
			this->Controls->Add(this->mailBox);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ModProp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void modTelf_Click(System::Object^ sender, System::EventArgs^ e) {

		this->phoneLabel->Visible = !this->phoneLabel->Visible;
		this->phone->Visible = !this->phone->Visible;
		

	}
	private: System::Void modData_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->dateLabel->Visible = !this->dateLabel->Visible;
		this->date->Visible = !this->date->Visible;

	}
	private: System::Void AplicarCambis_Click(System::Object^ sender, System::EventArgs^ e) {
		
		try {

			if (iniPasswd != this->passwdBox->Text) iniPasswd = this->passwdBox->Text;
			if (iniName != this->nameBox->Text) iniName = this->nameBox->Text;
			if (iniMail != this->mailBox->Text) iniMail = this->mailBox->Text;
			if (iniDesc != this->descBox->Text) iniDesc = this->descBox->Text;


			if (!this->dateLabel->Visible) iniDate = this->date->Text;
			if (!this->phoneLabel->Visible) iniPhone = this->phone->Text;

			TxModUsu modUsu;
			modUsu.crear(iniUsername, iniPasswd, iniName, iniPhone, iniDate, iniMail, iniDesc, "propietari");
			modUsu.executar();

			Ordinador^ ord = Ordinador::getInstance();
			ord->actualitza(iniUsername, iniName, iniPasswd, "propietari", iniMail, iniDesc, iniPhone);

			// Llamar a la función modificarPropietario con los parámetros necesarios

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

private: System::Void showPasswd_Click(System::Object^ sender, System::EventArgs^ e) {

	this->passwdBox->UseSystemPasswordChar = !this->passwdBox->UseSystemPasswordChar;

}
};
}
