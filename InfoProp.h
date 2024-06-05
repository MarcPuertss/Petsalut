#pragma once
#include "TxConsultaUsu.h"
#include "ModProp.h"
#include "ConsultaMascota_forms.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de InfoProp
	/// </summary>
	public ref class InfoProp : public System::Windows::Forms::Form
	{
	public:
		InfoProp(void)
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

				this->nameLabel->Text = res.nom;
				this->mailLabel->Text = res.correu;
				this->phoneLabel->Text = res.telefon;
				this->DateLabel->Text = res.data;
				this->usernameLabel->Text = res.username;
				this->descripcio->Text = res.descripcio;

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
		~InfoProp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label9;
	protected:
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ nameLabel;
	private: System::Windows::Forms::Label^ mailLabel;
	private: System::Windows::Forms::Label^ phoneLabel;
	private: System::Windows::Forms::Label^ DateLabel;
	private: System::Windows::Forms::Label^ usernameLabel;

	private: System::Windows::Forms::Label^ descripcio;
	private: System::Windows::Forms::Button^ Accepta_Tanca;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InfoProp::typeid));
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->mailLabel = (gcnew System::Windows::Forms::Label());
			this->phoneLabel = (gcnew System::Windows::Forms::Label());
			this->DateLabel = (gcnew System::Windows::Forms::Label());
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->descripcio = (gcnew System::Windows::Forms::Label());
			this->Accepta_Tanca = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(708, 184);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(172, 33);
			this->label9->TabIndex = 46;
			this->label9->Text = L"Descripcio";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(28, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(279, 33);
			this->label3->TabIndex = 36;
			this->label3->Text = L"Correu Electronic";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(708, 84);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(212, 33);
			this->label6->TabIndex = 40;
			this->label6->Text = L"Nom d\'usuari";
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(28, 384);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(257, 33);
			this->label5->TabIndex = 39;
			this->label5->Text = L"Data Naixement";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(28, 284);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(126, 33);
			this->label4->TabIndex = 38;
			this->label4->Text = L"Telefon";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(28, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(231, 33);
			this->label2->TabIndex = 34;
			this->label2->Text = L"Nom Complert";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(442, 51);
			this->label1->TabIndex = 33;
			this->label1->Text = L"Informacio Usuari";
			// 
			// nameLabel
			// 
			this->nameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nameLabel->AutoSize = true;
			this->nameLabel->BackColor = System::Drawing::Color::Transparent;
			this->nameLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->nameLabel->Location = System::Drawing::Point(29, 117);
			this->nameLabel->Name = L"nameLabel";
			this->nameLabel->Size = System::Drawing::Size(182, 30);
			this->nameLabel->TabIndex = 47;
			this->nameLabel->Text = L"Nombre aqui";
			// 
			// mailLabel
			// 
			this->mailLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mailLabel->AutoSize = true;
			this->mailLabel->BackColor = System::Drawing::Color::Transparent;
			this->mailLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mailLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->mailLabel->Location = System::Drawing::Point(29, 217);
			this->mailLabel->Name = L"mailLabel";
			this->mailLabel->Size = System::Drawing::Size(172, 30);
			this->mailLabel->TabIndex = 48;
			this->mailLabel->Text = L"Correo Aqui";
			// 
			// phoneLabel
			// 
			this->phoneLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->phoneLabel->AutoSize = true;
			this->phoneLabel->BackColor = System::Drawing::Color::Transparent;
			this->phoneLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->phoneLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->phoneLabel->Location = System::Drawing::Point(29, 317);
			this->phoneLabel->Name = L"phoneLabel";
			this->phoneLabel->Size = System::Drawing::Size(164, 30);
			this->phoneLabel->TabIndex = 49;
			this->phoneLabel->Text = L"phone Aqui";
			// 
			// DateLabel
			// 
			this->DateLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DateLabel->AutoSize = true;
			this->DateLabel->BackColor = System::Drawing::Color::Transparent;
			this->DateLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DateLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->DateLabel->Location = System::Drawing::Point(29, 417);
			this->DateLabel->Name = L"DateLabel";
			this->DateLabel->Size = System::Drawing::Size(291, 30);
			this->DateLabel->TabIndex = 50;
			this->DateLabel->Text = L"data naixement Aqui";
			// 
			// usernameLabel
			// 
			this->usernameLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->BackColor = System::Drawing::Color::Transparent;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->usernameLabel->Location = System::Drawing::Point(709, 117);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(214, 30);
			this->usernameLabel->TabIndex = 51;
			this->usernameLabel->Text = L"username Aqui";
			// 
			// descripcio
			// 
			this->descripcio->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descripcio->AutoSize = true;
			this->descripcio->BackColor = System::Drawing::Color::Transparent;
			this->descripcio->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descripcio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->descripcio->Location = System::Drawing::Point(709, 217);
			this->descripcio->Name = L"descripcio";
			this->descripcio->Size = System::Drawing::Size(196, 26);
			this->descripcio->TabIndex = 53;
			this->descripcio->Text = L"descripcio Aqui";
			// 
			// Accepta_Tanca
			// 
			this->Accepta_Tanca->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->Accepta_Tanca->AutoSize = true;
			this->Accepta_Tanca->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Accepta_Tanca->Location = System::Drawing::Point(714, 543);
			this->Accepta_Tanca->Margin = System::Windows::Forms::Padding(2);
			this->Accepta_Tanca->Name = L"Accepta_Tanca";
			this->Accepta_Tanca->Size = System::Drawing::Size(209, 79);
			this->Accepta_Tanca->TabIndex = 54;
			this->Accepta_Tanca->Text = L"Mostrar Mascotes";
			this->Accepta_Tanca->UseVisualStyleBackColor = true;
			this->Accepta_Tanca->Click += gcnew System::EventHandler(this, &InfoProp::Accepta_Tanca_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->AutoSize = true;
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(927, 543);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(209, 79);
			this->button1->TabIndex = 55;
			this->button1->Text = L"Modificar Informacio";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &InfoProp::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->AutoSize = true;
			this->button2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(34, 543);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(215, 79);
			this->button2->TabIndex = 56;
			this->button2->Text = L"Tornar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &InfoProp::button2_Click);
			// 
			// InfoProp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Accepta_Tanca);
			this->Controls->Add(this->descripcio);
			this->Controls->Add(this->usernameLabel);
			this->Controls->Add(this->DateLabel);
			this->Controls->Add(this->phoneLabel);
			this->Controls->Add(this->mailLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"InfoProp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::ModProp^ modProp = gcnew PetSalut::ModProp();
		modProp->Size = this->Size;
		modProp->Location = this->Location;
		this->Visible = false;

		modProp->ShowDialog();

		this->Close();

	}
	private: System::Void Accepta_Tanca_Click(System::Object^ sender, System::EventArgs^ e) {
		PetSalut::ConsultaMascota_forms^ consMasc = gcnew PetSalut::ConsultaMascota_forms();

		// Set the size and position of IniUsu to match PantallaPrincipal
		consMasc->Size = this->Size;
		consMasc->Location = this->Location;

		this->Visible = false;

		consMasc->ShowDialog();

		this->Visible = true;
	}
	};
}