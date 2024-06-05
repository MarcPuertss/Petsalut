#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "PassarellaPropietari.h"
#include "TxConsultarMascotes.h"
#include "TxEliminaMascota.h"
#include "PassarellaMascota.h"
#include "CercadoraMascota.h"
#include "CercadoraPropietari.h"
#include "Ordinador.h"
namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Elimina_Mascota_forms
	/// </summary>
	public ref class Elimina_Mascota_forms : public System::Windows::Forms::Form
	{
	public:
		Elimina_Mascota_forms(void)
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
		~Elimina_Mascota_forms()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label8;
	protected:
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panelConfirmacion;
	private: System::Windows::Forms::Label^ labelConfirmacion;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ComboBox^ petsList;


	private: System::Windows::Forms::Button^ buttonCerrarConfirmacion;

	private: System::Void exitbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		this->Close();
	}
	private: System::Void nobutton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		this->panel1->Visible = false;
	}
	private: System::Void exitbuttonconfirmation_Click(System::Object^ sender, System::EventArgs^ e) {
		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		this->Close();
	}
	private: System::Void deletebutton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (petsList->SelectedItem != nullptr) {

			String^ mascotaSeleccionada = petsList->SelectedItem->ToString();
			int indiceParentesisAbierto = mascotaSeleccionada->IndexOf('(');
			int indiceParentesisCerrado = mascotaSeleccionada->IndexOf(')');
			String^ chipString = mascotaSeleccionada->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int chip = Int32::Parse(chipString);
			TxEliminaMascota^ elimMascota = TxEliminaMascota::crear();
			elimMascota->ejecutar(chip);// Ahora pasamos el chip seleccionado como argumento
			panel2->Visible = true;
			// Opcional: Actualizar la GUI si es necesario, por ejemplo, recargar la lista de mascotas
		}
	}
	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {


		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();

		PassarellaPropietari^ propietari = CercadoraPropietari::cercaPropietari(usuari->getUsername());
		TxConsultarMascotes^ consultaMascotas = TxConsultarMascotes::crear(propietari);
		vector<int> mascotas = consultaMascotas->obteResultat();
		// Limpiar el ComboBox
		petsList->Items->Clear();

		// Llenar el ComboBox con los identificadores de mascotas
		CercadoraMascota^ cercadora = gcnew CercadoraMascota();
		// Llenar el ComboBox con los identificadores de mascotas
		for (int i = 0; i < mascotas.size(); ++i) {

			PassarellaMascota^ mascota = cercadora->cercaMascota(mascotas[i]);

			int chip = mascota->Chip;
			String^ nombre = mascota->Nom;

			// Concatenar el chip y el nombre y agregarlos a la lista
			String^ infoMascota = nombre + " (" + chip.ToString() + ")";
			petsList->Items->Add(infoMascota);
		}



	}
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Elimina_Mascota_forms::typeid));
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelConfirmacion = (gcnew System::Windows::Forms::Panel());
			this->labelConfirmacion = (gcnew System::Windows::Forms::Label());
			this->buttonCerrarConfirmacion = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(504, 63);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(142, 33);
			this->label8->TabIndex = 15;
			this->label8->Text = L"MY PETS";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 28));
			this->label6->Location = System::Drawing::Point(443, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(262, 54);
			this->label6->TabIndex = 14;
			this->label6->Text = L"PETSALUT";
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->petsList);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->panel1->Location = System::Drawing::Point(117, 119);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(935, 391);
			this->panel1->TabIndex = 13;
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
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(-1, 77);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(935, 246);
			this->panel2->TabIndex = 16;
			this->panel2->Visible = false;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->button4->Location = System::Drawing::Point(845, 206);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(85, 35);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Tancar";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Elimina_Mascota_forms::exitbuttonconfirmation_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->label2->Location = System::Drawing::Point(331, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(252, 26);
			this->label2->TabIndex = 11;
			this->label2->Text = L"ELIMINAR MASCOTA";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->label3->Location = System::Drawing::Point(202, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(530, 26);
			this->label3->TabIndex = 3;
			this->label3->Text = L"La teva mascota s\'ha eliminat correctament.";
			// 
			// petsList
			// 
			this->petsList->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(298, 142);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(328, 27);
			this->petsList->TabIndex = 14;
			this->petsList->Click += gcnew System::EventHandler(this, &Elimina_Mascota_forms::consultar_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackColor = System::Drawing::Color::Firebrick;
			this->button3->Location = System::Drawing::Point(892, 7);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(38, 31);
			this->button3->TabIndex = 13;
			this->button3->Text = L"X";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Elimina_Mascota_forms::exitbutton_Click);
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->label7->Location = System::Drawing::Point(335, 35);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(252, 26);
			this->label7->TabIndex = 11;
			this->label7->Text = L"ELIMINAR MASCOTA";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->button1->Location = System::Drawing::Point(298, 236);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(328, 73);
			this->button1->TabIndex = 10;
			this->button1->Text = L"ELIMINAR";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Elimina_Mascota_forms::deletebutton_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12.25F));
			this->label1->Location = System::Drawing::Point(293, 114);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(333, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Quina Mascota vols ELIMINAR\?";
			// 
			// panelConfirmacion
			// 
			this->panelConfirmacion->Location = System::Drawing::Point(0, 0);
			this->panelConfirmacion->Name = L"panelConfirmacion";
			this->panelConfirmacion->Size = System::Drawing::Size(200, 100);
			this->panelConfirmacion->TabIndex = 0;
			// 
			// labelConfirmacion
			// 
			this->labelConfirmacion->Location = System::Drawing::Point(0, 0);
			this->labelConfirmacion->Name = L"labelConfirmacion";
			this->labelConfirmacion->Size = System::Drawing::Size(100, 23);
			this->labelConfirmacion->TabIndex = 0;
			// 
			// buttonCerrarConfirmacion
			// 
			this->buttonCerrarConfirmacion->Location = System::Drawing::Point(0, 0);
			this->buttonCerrarConfirmacion->Name = L"buttonCerrarConfirmacion";
			this->buttonCerrarConfirmacion->Size = System::Drawing::Size(75, 23);
			this->buttonCerrarConfirmacion->TabIndex = 0;
			// 
			// Elimina_Mascota_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Elimina_Mascota_forms";
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

};
}
