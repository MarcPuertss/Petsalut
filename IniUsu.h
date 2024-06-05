#pragma once
#include "TxIniciSessio.h"
#include "MenuProp.h"
#include "MenuCli.h"
#include "PasswordEncrypt.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de IniUsu
	/// </summary>
	public ref class IniUsu : public System::Windows::Forms::Form
	{
	public:
		IniUsu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~IniUsu()
		{
			if (components)
			{
				delete components;
			}
		}

		void loginFunction() {
			try {
				String^ username = userTextBox->Text;
				String^ contrasenya = passwordTextBox->Text;

				TxIniciSessio iniS;

				iniS.crear(username, contrasenya);
				iniS.executar();

				PassarellaUsuari^ usu = CercadoraUsuari::cercaUsuari(username);
				String^ tip = usu->getTipus();

				if (tip == "propietari") {

					PetSalut::MenuProp^ menuProp = gcnew PetSalut::MenuProp();

					// Set the size and position of IniUsu to match PantallaPrincipal
					menuProp->Size = this->Size;
					menuProp->Location = this->Location;

					this->Visible = false;

					menuProp->ShowDialog();

					this->Visible = true;
				}
				else {
					PetSalut::MenuCli^ menuCli = gcnew PetSalut::MenuCli();

					// Set the size and position of IniUsu to match PantallaPrincipal
					menuCli->Size = this->Size;
					menuCli->Location = this->Location;

					this->Visible = false;

					menuCli->ShowDialog();

					this->Visible = true;
				}

				this->Close();

			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error: " + ex->Message);
			}
		}



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ userTextBox;
	private: System::Windows::Forms::TextBox^ passwordTextBox;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ showPasswordTextBox;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(IniUsu::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->userTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->showPasswordTextBox = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(500, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(214, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Iniciar Sessio";
			this->label1->Click += gcnew System::EventHandler(this, &IniUsu::label1_Click);
			// 
			// userTextBox
			// 
			this->userTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->userTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->userTextBox->Location = System::Drawing::Point(446, 254);
			this->userTextBox->Margin = System::Windows::Forms::Padding(2);
			this->userTextBox->Name = L"userTextBox";
			this->userTextBox->Size = System::Drawing::Size(307, 24);
			this->userTextBox->TabIndex = 1;
			this->userTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &IniUsu::userTextBox_KeyDown);
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->passwordTextBox->Location = System::Drawing::Point(446, 367);
			this->passwordTextBox->Margin = System::Windows::Forms::Padding(2);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(307, 24);
			this->passwordTextBox->TabIndex = 2;
			this->passwordTextBox->UseSystemPasswordChar = true;
			this->passwordTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &IniUsu::paswordTextBox_KeyDown);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(541, 324);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Contrasenya";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(541, 214);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 25);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Nom d\'usuari";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(475, 444);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(248, 34);
			this->button1->TabIndex = 5;
			this->button1->Text = L"INICIAR ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &IniUsu::button1_Click);
			// 
			// showPasswordTextBox
			// 
			this->showPasswordTextBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->showPasswordTextBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->showPasswordTextBox->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->showPasswordTextBox->Location = System::Drawing::Point(757, 367);
			this->showPasswordTextBox->Margin = System::Windows::Forms::Padding(2);
			this->showPasswordTextBox->Name = L"showPasswordTextBox";
			this->showPasswordTextBox->Size = System::Drawing::Size(82, 23);
			this->showPasswordTextBox->TabIndex = 6;
			this->showPasswordTextBox->Text = L"Mostrar";
			this->showPasswordTextBox->UseVisualStyleBackColor = true;
			this->showPasswordTextBox->Click += gcnew System::EventHandler(this, &IniUsu::showPasswordTextBox_Click);
			// 
			// IniUsu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->showPasswordTextBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->userTextBox);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"IniUsu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->Load += gcnew System::EventHandler(this, &IniUsu::IniUsu_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->loginFunction();
	}
	private: System::Void IniUsu_Load(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void showPasswordTextBox_Click(System::Object^ sender, System::EventArgs^ e) {

		this->passwordTextBox->UseSystemPasswordChar = !this->passwordTextBox->UseSystemPasswordChar;


	}
	private: System::Void userTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			this->loginFunction();
		}
	}
	private: System::Void paswordTextBox_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Enter) {
			this->loginFunction();
		}
	}




};
}
