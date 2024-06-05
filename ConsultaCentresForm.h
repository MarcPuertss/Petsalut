#pragma once
#include <string>
#include <iostream>
#include "PassarellaClinica.h"
#include "TxConsultarCentres.h"
#include "PassarellaCentre.h"
#include "CercadoraCentre.h"
#include "Ordinador.h"
#include "EliminaCentresForm.h"
#include "CreaCentreForms.h"
#include "CercadoraClinica.h"
#include "CercadoraAten.h"
#include "ConsultaVisitesCentreForms.h"
#include "CercadoraValoracio.h"
#include "ConsultaVistes_forms.h"

namespace PetSalut {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ConsultaCentresForm
	/// </summary>
	public ref class ConsultaCentresForm : public System::Windows::Forms::Form
	{
	public:

		//Declaració del BindingSource
		List<String^>^ tipusList = gcnew List<String^>();
	private: System::Windows::Forms::ListBox^ tipusListBox;
	private: System::Windows::Forms::Label^ label1;



	public:

		BindingSource^ bs = gcnew BindingSource();
		int centreSeleccionatId = -1;

		ConsultaCentresForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			bs->DataSource = centresList;
		}



	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ConsultaCentresForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ mypetslabel;
	private: System::Windows::Forms::ComboBox^ centresList;

	private: System::Windows::Forms::Button^ consultar;
	private: System::Windows::Forms::Button^ eliminabutton;
	private: System::Windows::Forms::Button^ registrarmascbutton;
	private: System::Windows::Forms::Button^ visitesButton;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Panel^ descriptionPannel;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConsultaCentresForm::typeid));
			this->mypetslabel = (gcnew System::Windows::Forms::Label());
			this->centresList = (gcnew System::Windows::Forms::ComboBox());
			this->consultar = (gcnew System::Windows::Forms::Button());
			this->descriptionPannel = (gcnew System::Windows::Forms::Panel());
			this->eliminabutton = (gcnew System::Windows::Forms::Button());
			this->registrarmascbutton = (gcnew System::Windows::Forms::Button());
			this->visitesButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tipusListBox = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// mypetslabel
			// 
			this->mypetslabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mypetslabel->AutoSize = true;
			this->mypetslabel->BackColor = System::Drawing::Color::Transparent;
			this->mypetslabel->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->mypetslabel->Location = System::Drawing::Point(458, 65);
			this->mypetslabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mypetslabel->Name = L"mypetslabel";
			this->mypetslabel->Size = System::Drawing::Size(278, 42);
			this->mypetslabel->TabIndex = 2;
			this->mypetslabel->Text = L"Els Meus Centres";
			// 
			// centresList
			// 
			this->centresList->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->centresList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11));
			this->centresList->FormattingEnabled = true;
			this->centresList->Location = System::Drawing::Point(229, 157);
			this->centresList->Margin = System::Windows::Forms::Padding(2);
			this->centresList->Name = L"centresList";
			this->centresList->Size = System::Drawing::Size(497, 26);
			this->centresList->TabIndex = 3;
			this->centresList->Click += gcnew System::EventHandler(this, &ConsultaCentresForm::fillPets);
			// 
			// consultar
			// 
			this->consultar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->consultar->BackColor = System::Drawing::Color::White;
			this->consultar->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->consultar->Location = System::Drawing::Point(731, 154);
			this->consultar->Margin = System::Windows::Forms::Padding(2);
			this->consultar->Name = L"consultar";
			this->consultar->Size = System::Drawing::Size(238, 29);
			this->consultar->TabIndex = 4;
			this->consultar->Text = L"Consultar";
			this->consultar->UseVisualStyleBackColor = false;
			this->consultar->Click += gcnew System::EventHandler(this, &ConsultaCentresForm::consultar_Click);
			// 
			// descriptionPannel
			// 
			this->descriptionPannel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descriptionPannel->BackColor = System::Drawing::Color::White;
			this->descriptionPannel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->descriptionPannel->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->descriptionPannel->Location = System::Drawing::Point(229, 191);
			this->descriptionPannel->Margin = System::Windows::Forms::Padding(2);
			this->descriptionPannel->Name = L"descriptionPannel";
			this->descriptionPannel->Size = System::Drawing::Size(497, 336);
			this->descriptionPannel->TabIndex = 5;
			this->descriptionPannel->Visible = false;
			// 
			// eliminabutton
			// 
			this->eliminabutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->eliminabutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->eliminabutton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eliminabutton->Location = System::Drawing::Point(949, 580);
			this->eliminabutton->Name = L"eliminabutton";
			this->eliminabutton->Size = System::Drawing::Size(172, 38);
			this->eliminabutton->TabIndex = 6;
			this->eliminabutton->Text = L"Eliminar centre";
			this->eliminabutton->UseVisualStyleBackColor = false;
			this->eliminabutton->Click += gcnew System::EventHandler(this, &ConsultaCentresForm::eliminabutton_click);
			// 
			// registrarmascbutton
			// 
			this->registrarmascbutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registrarmascbutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->registrarmascbutton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registrarmascbutton->Location = System::Drawing::Point(771, 580);
			this->registrarmascbutton->Name = L"registrarmascbutton";
			this->registrarmascbutton->Size = System::Drawing::Size(172, 38);
			this->registrarmascbutton->TabIndex = 7;
			this->registrarmascbutton->Text = L"Registrar centre";
			this->registrarmascbutton->UseVisualStyleBackColor = false;
			this->registrarmascbutton->Click += gcnew System::EventHandler(this, &ConsultaCentresForm::registrarbutton_Click);
			// 
			// visitesButton
			// 
			this->visitesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->visitesButton->BackColor = System::Drawing::Color::White;
			this->visitesButton->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->visitesButton->Location = System::Drawing::Point(593, 580);
			this->visitesButton->Name = L"visitesButton";
			this->visitesButton->Size = System::Drawing::Size(172, 38);
			this->visitesButton->TabIndex = 8;
			this->visitesButton->Text = L"Visites";
			this->visitesButton->UseVisualStyleBackColor = false;
			this->visitesButton->Click += gcnew System::EventHandler(this, &ConsultaCentresForm::visitesButton_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(51, 580);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 38);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Tornar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ConsultaCentresForm::button1_Click);
			// 
			// tipusListBox
			// 
			this->tipusListBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->tipusListBox->BackColor = System::Drawing::Color::White;
			this->tipusListBox->Enabled = false;
			this->tipusListBox->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tipusListBox->FormattingEnabled = true;
			this->tipusListBox->IntegralHeight = false;
			this->tipusListBox->ItemHeight = 20;
			this->tipusListBox->Location = System::Drawing::Point(731, 208);
			this->tipusListBox->Name = L"tipusListBox";
			this->tipusListBox->ScrollAlwaysVisible = true;
			this->tipusListBox->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->tipusListBox->Size = System::Drawing::Size(238, 319);
			this->tipusListBox->TabIndex = 10;
			this->tipusListBox->TabStop = false;
			this->tipusListBox->UseTabStops = false;
			this->tipusListBox->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(748, 185);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 20);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Tipus d\'animals que s\'atenen";
			this->label1->Visible = false;
			// 
			// ConsultaCentresForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tipusListBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->visitesButton);
			this->Controls->Add(this->registrarmascbutton);
			this->Controls->Add(this->eliminabutton);
			this->Controls->Add(this->descriptionPannel);
			this->Controls->Add(this->consultar);
			this->Controls->Add(this->centresList);
			this->Controls->Add(this->mypetslabel);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ConsultaCentresForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PETSALUT";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verifica si hay al menos un elemento seleccionado en el ComboBox
		if (centresList->SelectedIndex != -1) {
			this->label1->Visible = true;
			tipusListBox->Items->Clear();
			// Si hay un elemento seleccionado, muestra el panel de descripción
			tipusListBox->Visible = true;
			descriptionPannel->Visible = true;
			descriptionPannel->Controls->Clear();
			// Obtén el centro seleccionada del ComboBox
			String^ centreSeleccionat = centresList->SelectedItem->ToString();

			// Extrae el numero_ID de el centro seleccionada (asumiendo que el numero_ID está entre paréntesis)
			int indiceParentesisAbierto = centreSeleccionat->IndexOf('(');
			int indiceParentesisCerrado = centreSeleccionat->IndexOf(')');
			String^ id = centreSeleccionat->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int numero_ID = Int32::Parse(id);
			centreSeleccionatId = numero_ID;
			// Utiliza el numero_ID para buscar y obtener más información de el centro
			CercadoraCentre^ cercadora = gcnew CercadoraCentre();
			PassarellaCentre^ centre = cercadora->cercaCentre(numero_ID);

			// Muestra la información de el centro en el panel de descripción
			// Por ejemplo, podrías mostrar el numero_ID, el nombre, etc.
			// Aquí se muestra el numero_ID, nombre, descripción, clinica y tipo
			Label^ labelNumero_ID = gcnew Label();
			labelNumero_ID->Text = "Id centre: " + centre->Numero_ID;
			labelNumero_ID->Location = Point(10, 10); // Establece la posición del label dentro del panel
			labelNumero_ID->AutoSize = true;
			descriptionPannel->Controls->Add(labelNumero_ID);

			Label^ label_Nom = gcnew Label();
			label_Nom->Text = "Nombre: " + centre->Nom;
			label_Nom->Location = Point(10, labelNumero_ID->Bottom + 25);
			label_Nom->AutoSize = true;
			descriptionPannel->Controls->Add(label_Nom);

			Label^ label_Telefon = gcnew Label();
			label_Telefon->Text = "Telefon: " + centre->Telefon;
			label_Telefon->Location = Point(10, label_Nom->Bottom + 25);
			label_Telefon->AutoSize = true;
			descriptionPannel->Controls->Add(label_Telefon);

			Label^ label_Clinica = gcnew Label();
			label_Clinica->Text = "Clinica: " + centre->Clinica;
			label_Clinica->Location = Point(10, label_Telefon->Bottom + 25);
			label_Clinica->AutoSize = true;
			descriptionPannel->Controls->Add(label_Clinica);

			Label^ label_Ubicacio = gcnew Label();
			label_Ubicacio->Text = "Ubicacio: " + centre->Ubicacio;
			label_Ubicacio->Location = Point(10, label_Clinica->Bottom + 25);
			label_Ubicacio->AutoSize = true;
			descriptionPannel->Controls->Add(label_Ubicacio);

			CercadoraValoracio^ cercadoraValoracio = gcnew CercadoraValoracio();
			int^ val = cercadoraValoracio->cercaValMitja(numero_ID);
			String^ valor= val->ToString();
			if (valor == "0") {
				valor = "No hi ha valoracions";
			}
			
			Label^ label_Valoracio = gcnew Label();
			label_Valoracio->Text = "Valoracio mitja: " + valor;
			label_Valoracio->Location = Point(10, label_Ubicacio->Bottom + 25);
			label_Valoracio->AutoSize = true;
			descriptionPannel->Controls->Add(label_Valoracio);


			// Llista de tipus de mascotes ateses pel centre
			CercadoraAten^ cercadoraAten = gcnew CercadoraAten();
			tipusList = cercadoraAten->cercaTipusAten(numero_ID);
			tipusListBox->Items->AddRange(tipusList->ToArray());
		}
		else {
			// Si no hay elementos seleccionados, muestra un mensaje de error o realiza alguna otra acción según tus necesidades
			MessageBox::Show("Si us plau, selecciona una centre abans de consultar.");
		}
	}
	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {
		//Usar aqui la variable ordenador para obtener el passarela propietari
		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();

		PassarellaClinica^ clinica = CercadoraClinica::cercaClinica(usuari->getUsername());

		TxConsultarCentres^ consultaCentres = TxConsultarCentres::crear(clinica);
		List<int>^ centres = consultaCentres->ObtenirResultat();

		// Limpiar el ComboBox
		centresList->Items->Clear();
		CercadoraCentre^ cercadora = gcnew CercadoraCentre();

		// Llenar el ComboBox con los identificadores de centres
		for each (int centreId in centres) {
			PassarellaCentre^ centre = cercadora->cercaCentre(centreId);

			int numero_ID = centre->Numero_ID;
			String^ nombre = centre->Nom;

			// Concatenar el numero_ID y el nombre y agregarlos a la lista
			String^ infoMascota = nombre + " (" + numero_ID.ToString() + ")";
			centresList->Items->Add(infoMascota);
		}
	}


	private: System::Void eliminabutton_click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::EliminaCentresForm^ eliminaCentre = gcnew PetSalut::EliminaCentresForm();

		// Set the size and position of IniUsu to match PantallaPrincipal
		eliminaCentre->Size = this->Size;
		eliminaCentre->Location = this->Location;

		this->Visible = false;

		eliminaCentre->ShowDialog();

		this->Visible = true;

	}

	private: System::Void registrarbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::CreaCentreForms^ creaMasc = gcnew PetSalut::CreaCentreForms();

		// Set the size and position of IniUsu to match PantallaPrincipal
		creaMasc->Size = this->Size;
		creaMasc->Location = this->Location;

		this->Visible = false;

		creaMasc->ShowDialog();

		this->Visible = true;

	}
	private: System::Void visitesButton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::ConsultaVisitesCentreForms^ consVisites = gcnew PetSalut::ConsultaVisitesCentreForms();
		

		consVisites->CentreId = centreSeleccionatId;


		// Set the size and position of IniUsu to match PantallaPrincipal
		consVisites->Size = this->Size;
		consVisites->Location = this->Location;
		
		this->Visible = false;

		consVisites->ShowDialog();

		this->Visible = true;

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
