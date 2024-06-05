#pragma once
#pragma once
#include <string>
#include <iostream>
#include <random>
#include "PassarellaPropietari.h"
#include "TxConsultarMascotes.h"
#include "PassarellaMascota.h"
#include "CercadoraMascota.h"
#include "Ordinador.h"
#include "Elimina_Mascota_forms.h"
#include "Crea_Mascota_forms.h"
#include "CercadoraPropietari.h"
#include "CercadoraCentre.h"
#include "PassarellaCentre.h"
#include "PassarellaEsdeveniments.h"
#include "PassarellaVisites.h"
#include "TxCrearEsdeveniment.h"
#include "TxCrearValoracio.h"
#include "CercadoraAten.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de CreaVisites_forms
	/// </summary>
	public ref class CreaVisites_forms : public System::Windows::Forms::Form
	{
	public:
		CreaVisites_forms(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~CreaVisites_forms()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:

	private: System::Windows::Forms::Panel^ PanelVisita;
	private: System::Windows::Forms::Label^ admasclabel;
	private: System::Windows::Forms::ComboBox^ petsList;



	private: System::Windows::Forms::Label^ adnomlabel;



	private: System::Windows::Forms::Label^ MascotaLabel;
	private: System::Windows::Forms::ComboBox^ HoursBox;

	private: System::Windows::Forms::Label^ adhoralabel;



	private: System::Windows::Forms::Label^ adCentrelabel;

	private: System::Windows::Forms::Label^ adIDdate;


	private: System::Windows::Forms::Label^ titlelabel;


	private: System::Windows::Forms::Label^ CentreLabel;


	private: System::Windows::Forms::DateTimePicker^ DiaBox;




	private: System::Windows::Forms::Label^ nomLabel;
	private: System::Windows::Forms::Label^ dataLabel;
	private: System::Windows::Forms::Label^ HoraLabel;



	private: System::Windows::Forms::ComboBox^ CentresBox;
	private: System::Windows::Forms::Button^ guardarbutton;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::TextBox^ NomBox;

	private: System::Void fillCentres(System::Object^ sender, System::EventArgs^ e) {
		// Limpiar los ítems del ComboBox antes de llenarlo nuevamente
		CentresBox->Items->Clear();

		// Obtener la mascota seleccionada en el ComboBox
		PassarellaMascota^ selectedMascota = dynamic_cast<PassarellaMascota^>(petsList->SelectedItem);

		if (selectedMascota == nullptr) {
			MessageBox::Show("Por favor, seleccione una mascota primero.");
			return;
		}

		// Obtener el tipus de la mascota seleccionada
		String^ tipus = selectedMascota->Tipus;
		List<int>^ centreIds = CercadoraAten::cercaCentreIdsPerTipus(tipus);

		// Llenar el ComboBox con los centre_id obtenidos
		for each (int centreId in centreIds) {
			PassarellaCentre^ centre = CercadoraCentre::cercaCentre(centreId);
			if (centre != nullptr) {
				// Llenar el ComboBox con los objetos PassarellaCentre
				CentresBox->Items->Add(centre);
			}
		}
	}

	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {
		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();
		PassarellaPropietari^ propietari = CercadoraPropietari::cercaPropietari(usuari->getUsername());
		TxConsultarMascotes^ consultaMascotas = TxConsultarMascotes::crear(propietari);
		vector<int> mascotas = consultaMascotas->obteResultat();

		// Limpiar el ComboBox
		petsList->Items->Clear();

		CercadoraMascota^ cercadora = gcnew CercadoraMascota();

		// Llenar el ComboBox con objetos PassarellaMascota^
		for (int i = 0; i < mascotas.size(); ++i) {
			PassarellaMascota^ mascota = cercadora->cercaMascota(mascotas[i]);
			petsList->Items->Add(mascota); // Agregar el objeto mascota al ComboBox
		}
	}


	private: System::Void FillTimeComboBox(System::Object^ sender, System::EventArgs^ e) {

		// Establecer el primer elemento como seleccionado por defecto
		if (HoursBox->Items->Count > 0)
		{
			HoursBox->SelectedIndex = 0;
		}
	}
	private: System::Void guardarbutton_click(System::Object^ sender, System::EventArgs^ e) {

		// Oculta el panel1, lo que tambi�n oculta todos los controles dentro de �l
		if (String::IsNullOrWhiteSpace(this->NomBox->Text)) {
			this->adnomlabel->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->HoursBox->Text)) {
			this->adhoralabel->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->DiaBox->Text)) {
			this->adIDdate->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->petsList->Text)) {
			this->admasclabel->Visible = true;
		}
		else if (String::IsNullOrWhiteSpace(this->CentresBox->Text)) {
			this->adCentrelabel->Visible = true;
		}
		else {

			Ordinador^ ord = Ordinador::getInstance();
			PassarellaUsuari^ usuari = ord->obteUsuari();
			PassarellaMascota^ mascotaSeleccionada = safe_cast<PassarellaMascota^>(petsList->SelectedItem);
			int chipMascota = mascotaSeleccionada->Chip;
			PassarellaCentre^ centroSeleccionado = safe_cast<PassarellaCentre^>(CentresBox->SelectedItem);
			int numeroIDCentro = centroSeleccionado->Numero_ID;

			String^ centroSeleccionadoStr = CentresBox->Text;

			random_device rd;
			mt19937 gen(rd());
			uniform_int_distribution<> distrib(200, 500000);
			int id_mascota = distrib(gen);

			//AQUI NECESITO PASAR EN PETSLIST EL CHIP DEL PET SELECTED
			TxCrearEsdeveniment creaEsde;

			creaEsde.crear(this->NomBox->Text->ToString(), id_mascota, this->DiaBox->Value, this->HoursBox->Text->ToString(), usuari->getUsername(), chipMascota, numeroIDCentro, "Privat", "");
			creaEsde.executar();

			TxCrearValoracio^ novavaloracio = TxCrearValoracio::crear(numeroIDCentro, id_mascota, usuari->getUsername(), 0);
			novavaloracio->ejecutar();
			this->Close();

		}
	}
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreaVisites_forms::typeid));
			this->PanelVisita = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->guardarbutton = (gcnew System::Windows::Forms::Button());
			this->NomBox = (gcnew System::Windows::Forms::TextBox());
			this->CentresBox = (gcnew System::Windows::Forms::ComboBox());
			this->admasclabel = (gcnew System::Windows::Forms::Label());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->adnomlabel = (gcnew System::Windows::Forms::Label());
			this->MascotaLabel = (gcnew System::Windows::Forms::Label());
			this->HoursBox = (gcnew System::Windows::Forms::ComboBox());
			this->adhoralabel = (gcnew System::Windows::Forms::Label());
			this->adCentrelabel = (gcnew System::Windows::Forms::Label());
			this->adIDdate = (gcnew System::Windows::Forms::Label());
			this->titlelabel = (gcnew System::Windows::Forms::Label());
			this->CentreLabel = (gcnew System::Windows::Forms::Label());
			this->DiaBox = (gcnew System::Windows::Forms::DateTimePicker());
			this->nomLabel = (gcnew System::Windows::Forms::Label());
			this->dataLabel = (gcnew System::Windows::Forms::Label());
			this->HoraLabel = (gcnew System::Windows::Forms::Label());
			this->PanelVisita->SuspendLayout();
			this->SuspendLayout();
			// 
			// PanelVisita
			// 
			this->PanelVisita->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PanelVisita->AutoSize = true;
			this->PanelVisita->BackColor = System::Drawing::SystemColors::Control;
			this->PanelVisita->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PanelVisita->Controls->Add(this->button1);
			this->PanelVisita->Controls->Add(this->guardarbutton);
			this->PanelVisita->Controls->Add(this->NomBox);
			this->PanelVisita->Controls->Add(this->CentresBox);
			this->PanelVisita->Controls->Add(this->admasclabel);
			this->PanelVisita->Controls->Add(this->petsList);
			this->PanelVisita->Controls->Add(this->adnomlabel);
			this->PanelVisita->Controls->Add(this->MascotaLabel);
			this->PanelVisita->Controls->Add(this->HoursBox);
			this->PanelVisita->Controls->Add(this->adhoralabel);
			this->PanelVisita->Controls->Add(this->adCentrelabel);
			this->PanelVisita->Controls->Add(this->adIDdate);
			this->PanelVisita->Controls->Add(this->titlelabel);
			this->PanelVisita->Controls->Add(this->CentreLabel);
			this->PanelVisita->Controls->Add(this->DiaBox);
			this->PanelVisita->Controls->Add(this->nomLabel);
			this->PanelVisita->Controls->Add(this->dataLabel);
			this->PanelVisita->Controls->Add(this->HoraLabel);
			this->PanelVisita->Location = System::Drawing::Point(39, 41);
			this->PanelVisita->Name = L"PanelVisita";
			this->PanelVisita->Size = System::Drawing::Size(1109, 585);
			this->PanelVisita->TabIndex = 29;
			this->PanelVisita->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &CreaVisites_forms::PanelVisita_Paint);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->button1->Location = System::Drawing::Point(3, 501);
			this->button1->Name = L"button1";
			this->button1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->button1->Size = System::Drawing::Size(177, 79);
			this->button1->TabIndex = 35;
			this->button1->Text = L"Tornar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreaVisites_forms::button1_Click);
			// 
			// guardarbutton
			// 
			this->guardarbutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->guardarbutton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->guardarbutton->Location = System::Drawing::Point(927, 501);
			this->guardarbutton->Name = L"guardarbutton";
			this->guardarbutton->Size = System::Drawing::Size(177, 79);
			this->guardarbutton->TabIndex = 34;
			this->guardarbutton->Text = L"Guardar";
			this->guardarbutton->UseVisualStyleBackColor = true;
			this->guardarbutton->Click += gcnew System::EventHandler(this, &CreaVisites_forms::guardarbutton_click);
			// 
			// NomBox
			// 
			this->NomBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->NomBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->NomBox->Location = System::Drawing::Point(160, 93);
			this->NomBox->Name = L"NomBox";
			this->NomBox->Size = System::Drawing::Size(640, 24);
			this->NomBox->TabIndex = 33;
			// 
			// CentresBox
			// 
			this->CentresBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CentresBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->CentresBox->FormattingEnabled = true;
			this->CentresBox->Location = System::Drawing::Point(160, 397);
			this->CentresBox->Name = L"CentresBox";
			this->CentresBox->Size = System::Drawing::Size(640, 27);
			this->CentresBox->TabIndex = 32;
			this->CentresBox->Click += gcnew System::EventHandler(this, &CreaVisites_forms::fillCentres);
			// 
			// admasclabel
			// 
			this->admasclabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->admasclabel->AutoSize = true;
			this->admasclabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->admasclabel->ForeColor = System::Drawing::Color::Brown;
			this->admasclabel->Location = System::Drawing::Point(828, 333);
			this->admasclabel->Name = L"admasclabel";
			this->admasclabel->Size = System::Drawing::Size(150, 20);
			this->admasclabel->TabIndex = 31;
			this->admasclabel->Text = L"Required Field *";
			this->admasclabel->Visible = false;
			// 
			// petsList
			// 
			this->petsList->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->petsList->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(160, 326);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(640, 27);
			this->petsList->TabIndex = 30;
			this->petsList->Click += gcnew System::EventHandler(this, &CreaVisites_forms::fillPets);
			// 
			// adnomlabel
			// 
			this->adnomlabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->adnomlabel->AutoSize = true;
			this->adnomlabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->adnomlabel->ForeColor = System::Drawing::Color::Brown;
			this->adnomlabel->Location = System::Drawing::Point(828, 97);
			this->adnomlabel->Name = L"adnomlabel";
			this->adnomlabel->Size = System::Drawing::Size(150, 20);
			this->adnomlabel->TabIndex = 29;
			this->adnomlabel->Text = L"Required Field *";
			this->adnomlabel->Visible = false;
			// 
			// MascotaLabel
			// 
			this->MascotaLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->MascotaLabel->AutoSize = true;
			this->MascotaLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->MascotaLabel->Location = System::Drawing::Point(74, 329);
			this->MascotaLabel->Name = L"MascotaLabel";
			this->MascotaLabel->Size = System::Drawing::Size(80, 20);
			this->MascotaLabel->TabIndex = 28;
			this->MascotaLabel->Text = L"Mascota";
			// 
			// HoursBox
			// 
			this->HoursBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HoursBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->HoursBox->FormattingEnabled = true;
			this->HoursBox->Items->AddRange(gcnew cli::array< System::Object^  >(26) {
				L"9:00", L"9:30", L"10:00", L"10:30", L"11:00",
					L"11:30", L"12:00", L"12:30", L"13:00", L"13:30", L"14:00", L"14:30", L"15:00", L"15:30", L"16:00", L"16:30", L"17:00", L"17:30",
					L"18:00", L"18:30", L"19:00", L"19:30", L"20:00", L"20:30", L"21:00", L"21:30"
			});
			this->HoursBox->Location = System::Drawing::Point(160, 249);
			this->HoursBox->Name = L"HoursBox";
			this->HoursBox->Size = System::Drawing::Size(640, 27);
			this->HoursBox->TabIndex = 27;
			this->HoursBox->SelectedIndexChanged += gcnew System::EventHandler(this, &CreaVisites_forms::HoursBox_SelectedIndexChanged);
			this->HoursBox->Click += gcnew System::EventHandler(this, &CreaVisites_forms::FillTimeComboBox);
			// 
			// adhoralabel
			// 
			this->adhoralabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->adhoralabel->AutoSize = true;
			this->adhoralabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->adhoralabel->ForeColor = System::Drawing::Color::Brown;
			this->adhoralabel->Location = System::Drawing::Point(828, 256);
			this->adhoralabel->Name = L"adhoralabel";
			this->adhoralabel->Size = System::Drawing::Size(150, 20);
			this->adhoralabel->TabIndex = 25;
			this->adhoralabel->Text = L"Required Field *";
			this->adhoralabel->Visible = false;
			this->adhoralabel->Click += gcnew System::EventHandler(this, &CreaVisites_forms::adhoralabel_Click);
			// 
			// adCentrelabel
			// 
			this->adCentrelabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->adCentrelabel->AutoSize = true;
			this->adCentrelabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->adCentrelabel->ForeColor = System::Drawing::Color::Brown;
			this->adCentrelabel->Location = System::Drawing::Point(828, 404);
			this->adCentrelabel->Name = L"adCentrelabel";
			this->adCentrelabel->Size = System::Drawing::Size(150, 20);
			this->adCentrelabel->TabIndex = 24;
			this->adCentrelabel->Text = L"Required Field *";
			this->adCentrelabel->Visible = false;
			// 
			// adIDdate
			// 
			this->adIDdate->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->adIDdate->AutoSize = true;
			this->adIDdate->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->adIDdate->ForeColor = System::Drawing::Color::Brown;
			this->adIDdate->Location = System::Drawing::Point(828, 171);
			this->adIDdate->Name = L"adIDdate";
			this->adIDdate->Size = System::Drawing::Size(150, 20);
			this->adIDdate->TabIndex = 23;
			this->adIDdate->Text = L"Required Field *";
			this->adIDdate->Visible = false;
			// 
			// titlelabel
			// 
			this->titlelabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->titlelabel->AutoSize = true;
			this->titlelabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18.25F));
			this->titlelabel->Location = System::Drawing::Point(449, 28);
			this->titlelabel->Name = L"titlelabel";
			this->titlelabel->Size = System::Drawing::Size(217, 34);
			this->titlelabel->TabIndex = 11;
			this->titlelabel->Text = L"NOVA VISITA";
			// 
			// CentreLabel
			// 
			this->CentreLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->CentreLabel->AutoSize = true;
			this->CentreLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->CentreLabel->Location = System::Drawing::Point(86, 402);
			this->CentreLabel->Name = L"CentreLabel";
			this->CentreLabel->Size = System::Drawing::Size(68, 20);
			this->CentreLabel->TabIndex = 9;
			this->CentreLabel->Text = L"Centre";
			// 
			// DiaBox
			// 
			this->DiaBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->DiaBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->DiaBox->Location = System::Drawing::Point(160, 166);
			this->DiaBox->Name = L"DiaBox";
			this->DiaBox->Size = System::Drawing::Size(640, 24);
			this->DiaBox->TabIndex = 2;
			// 
			// nomLabel
			// 
			this->nomLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nomLabel->AutoSize = true;
			this->nomLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->nomLabel->Location = System::Drawing::Point(96, 96);
			this->nomLabel->Name = L"nomLabel";
			this->nomLabel->Size = System::Drawing::Size(58, 20);
			this->nomLabel->TabIndex = 3;
			this->nomLabel->Text = L"Motiu";
			// 
			// dataLabel
			// 
			this->dataLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dataLabel->AutoSize = true;
			this->dataLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->dataLabel->Location = System::Drawing::Point(105, 166);
			this->dataLabel->Name = L"dataLabel";
			this->dataLabel->Size = System::Drawing::Size(49, 20);
			this->dataLabel->TabIndex = 4;
			this->dataLabel->Text = L"Data";
			// 
			// HoraLabel
			// 
			this->HoraLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->HoraLabel->AutoSize = true;
			this->HoraLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->HoraLabel->Location = System::Drawing::Point(102, 252);
			this->HoraLabel->Name = L"HoraLabel";
			this->HoraLabel->Size = System::Drawing::Size(52, 20);
			this->HoraLabel->TabIndex = 5;
			this->HoraLabel->Text = L"Hora";
			this->HoraLabel->Click += gcnew System::EventHandler(this, &CreaVisites_forms::HoraLabel_Click);
			// 
			// CreaVisites_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->PanelVisita);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"CreaVisites_forms";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->Load += gcnew System::EventHandler(this, &CreaVisites_forms::CreaVisites_forms_Load);
			this->PanelVisita->ResumeLayout(false);
			this->PanelVisita->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void chipLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void cumpleLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tipusLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void descripcioLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void PanelVisita_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void HoraLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void HoursBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void adhoralabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Close();

}
private: System::Void CreaVisites_forms_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
