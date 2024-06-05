#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "PassarellaPropietari.h"
#include "TxConsultarCentres.h"
#include "TxEliminaCentre.h"
#include "PassarellaMascota.h"
#include "CercadoraCentre.h"
#include "CercadoraClinica.h"
#include "Ordinador.h"
namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for EliminaCentresForm
	/// </summary>
	public ref class EliminaCentresForm : public System::Windows::Forms::Form
	{
	public:
		EliminaCentresForm(void)
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
		~EliminaCentresForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label8;
	protected:








	private: System::Windows::Forms::Panel^ panelConfirmacion;
	private: System::Windows::Forms::Label^ labelConfirmacion;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ centresList;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;


















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
		if (centresList->SelectedItem != nullptr) {
			String^ mascotaSeleccionada = centresList->SelectedItem->ToString();
			int indiceParentesisAbierto = mascotaSeleccionada->IndexOf('(');
			int indiceParentesisCerrado = mascotaSeleccionada->IndexOf(')');
			String^ numero_ID = mascotaSeleccionada->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int chip = Int32::Parse(numero_ID);
			TxEliminaCentre^ elimMascota = TxEliminaCentre::crear();
			elimMascota->ejecutar(chip);// Ahora pasamos el chip seleccionado como argumento
			panel2->Visible = true;
			// Opcional: Actualizar la GUI si es necesario, por ejemplo, recargar la lista de centres
		}
	}
	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();

		PassarellaClinica^ clinica = CercadoraClinica::cercaClinica(usuari->getUsername());
		TxConsultarCentres^ consultaCentres = TxConsultarCentres::crear(clinica);
		List<int>^ centres = consultaCentres->ObtenirResultat();
		// Limpiar el ComboBox
		centresList->Items->Clear();

		// Llenar el ComboBox con los identificadores de centres
		CercadoraCentre^ cercadora = gcnew CercadoraCentre();
		// Llenar el ComboBox con los identificadores de centres
		for each (int centreId in centres) {

			PassarellaCentre^ centre = cercadora->cercaCentre(centreId);

			int numero_ID = centre->Numero_ID;
			String^ nombre = centre->Nom;

			// Concatenar el numero_ID y el nombre y agregarlos a la lista
			String^ infoCentre = nombre + " (" + numero_ID.ToString() + ")";
			centresList->Items->Add(infoCentre);
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EliminaCentresForm::typeid));
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panelConfirmacion = (gcnew System::Windows::Forms::Panel());
			this->labelConfirmacion = (gcnew System::Windows::Forms::Label());
			this->buttonCerrarConfirmacion = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->centresList = (gcnew System::Windows::Forms::ComboBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(446, 51);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(248, 42);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Eliminar Centre";
			this->label8->Click += gcnew System::EventHandler(this, &EliminaCentresForm::label8_Click);
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
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(368, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Quin centre vols eliminar\?";
			this->label1->Click += gcnew System::EventHandler(this, &EliminaCentresForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(690, 464);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(214, 45);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Eliminar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &EliminaCentresForm::deletebutton_Click);
			// 
			// centresList
			// 
			this->centresList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->centresList->FormattingEnabled = true;
			this->centresList->Location = System::Drawing::Point(298, 142);
			this->centresList->Name = L"centresList";
			this->centresList->Size = System::Drawing::Size(328, 24);
			this->centresList->TabIndex = 14;
			this->centresList->Click += gcnew System::EventHandler(this, &EliminaCentresForm::consultar_Click);
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
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(-3, 103);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(941, 246);
			this->panel2->TabIndex = 16;
			this->panel2->Visible = false;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(348, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(247, 25);
			this->label3->TabIndex = 3;
			this->label3->Text = L"El teu centre s\'ha eliminat.\r\n";
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(388, 194);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(170, 35);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Tancar";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &EliminaCentresForm::exitbuttonconfirmation_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->centresList);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F));
			this->panel1->Location = System::Drawing::Point(131, 124);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(935, 1171);
			this->panel1->TabIndex = 13;
			// 
			// EliminaCentresForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->panel1);
			this->Name = L"EliminaCentresForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PETSALUT";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

};
}
