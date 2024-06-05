#pragma once
#include <string>
#include <iostream>
#include "PassarellaPropietari.h"
#include "TxConsultarMascotes.h"
#include "PassarellaMascota.h"
#include "CercadoraMascota.h"
#include "Ordinador.h"
#include "Elimina_Mascota_forms.h"
#include "Crea_Mascota_forms.h"
#include "CercadoraPropietari.h"
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
	/// Resumen de ConsultaMascota_forms
	/// </summary>
	public ref class ConsultaMascota_forms : public System::Windows::Forms::Form
	{
	public:
		ConsultaMascota_forms(void)
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
		~ConsultaMascota_forms()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	protected:

	protected:

	private: System::Windows::Forms::Label^ petsaludlabel;
	private: System::Windows::Forms::Label^ mypetslabel;
	private: System::Windows::Forms::ComboBox^ petsList;

	private: System::Windows::Forms::Button^ consultar;
	private: System::Windows::Forms::Button^ eliminabutton;
	private: System::Windows::Forms::Button^ registrarmascbutton;
	private: System::Windows::Forms::Button^ visitesButton;
	private: System::Windows::Forms::Button^ button1;






	private: System::Windows::Forms::Panel^ descriptionPannel;

	
	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verifica si hay al menos un elemento seleccionado en el ComboBox
		if (petsList->SelectedIndex != -1) {
			// Si hay un elemento seleccionado, muestra el panel de descripción
			descriptionPannel->Visible = true;
			descriptionPannel->Controls->Clear();
			// Obtén la mascota seleccionada del ComboBox
			String^ mascotaSeleccionada = petsList->SelectedItem->ToString();

			// Extrae el chip de la mascota seleccionada (asumiendo que el chip está entre paréntesis)
			int indiceParentesisAbierto = mascotaSeleccionada->IndexOf('(');
			int indiceParentesisCerrado = mascotaSeleccionada->IndexOf(')');
			String^ chipString = mascotaSeleccionada->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int chip = Int32::Parse(chipString);

			// Utiliza el chip para buscar y obtener más información de la mascota
			CercadoraMascota^ cercadora = gcnew CercadoraMascota();
			PassarellaMascota^ mascota = cercadora->cercaMascota(chip);

			// Muestra la información de la mascota en el panel de descripción
			// Por ejemplo, podrías mostrar el chip, el nombre, la fecha de nacimiento, etc.
			// Aquí se muestra el chip, nombre, fecha de nacimiento, descripción, propietario y tipo
			Label^ labelChip = gcnew Label();
			labelChip->Text = "Chip: \n" + mascota->Chip;
			labelChip->Location = Point(10, 10); // Establece la posición del label dentro del panel
			labelChip->AutoSize = true;
			descriptionPannel->Controls->Add(labelChip);

			Label^ labelNombre = gcnew Label();
			labelNombre->Text = "Nombre: \n" + mascota->Nom;
			labelNombre->Location = Point(10, labelChip->Bottom + 25);
			labelNombre->AutoSize = true;
			descriptionPannel->Controls->Add(labelNombre);

			Label^ labelFechaNacimiento = gcnew Label();
			labelFechaNacimiento->Text = "Fecha de Nacimiento: \n" + mascota->DataNaixament.ToString();
			labelFechaNacimiento->Location = Point(10, labelNombre->Bottom + 25); // Establece la posición del label debajo del anterior
			labelFechaNacimiento->AutoSize = true; // Ajusta automáticamente el tamaño del label al texto
			descriptionPannel->Controls->Add(labelFechaNacimiento);

			Label^ labelDescripcion = gcnew Label();
			labelDescripcion->Text = "Descripción: \n" + mascota->Descripcio;
			labelDescripcion->MaximumSize = System::Drawing::Size(descriptionPannel->Width - 10, 0);
			labelDescripcion->Location = Point(10, labelFechaNacimiento->Bottom + 25); // Establece la posición del label debajo del anterior
			labelDescripcion->AutoSize = true; // Ajusta automáticamente el tamaño del label al texto
			descriptionPannel->Controls->Add(labelDescripcion);

			Label^ labelPropietario = gcnew Label();
			labelPropietario->Text = "Propietario: \n" + mascota->Propietari;
			labelPropietario->Location = Point(10, labelDescripcion->Bottom + 25); // Establece la posición del label debajo del anterior
			labelPropietario->AutoSize = true; // Ajusta automáticamente el tamaño del label al texto
			descriptionPannel->Controls->Add(labelPropietario);

			Label^ labelTipo = gcnew Label();
			labelTipo->Text = "Tipo: \n" + mascota->Tipus;
			labelTipo->Location = Point(10, labelPropietario->Bottom + 25);
			labelTipo->AutoSize = true; // Ajusta automáticamente el tamaño del label al texto// Establece la posición del label debajo del anterior
			descriptionPannel->Controls->Add(labelTipo);

			// Añade más labels con la información que quieras mostrar
		}
		else {
			// Si no hay elementos seleccionados, muestra un mensaje de error o realiza alguna otra acción según tus necesidades
			MessageBox::Show("Por favor, selecciona una mascota antes de consultar.");
		}
	}
	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {
	

		//Usar aqui la variable ordenador para obtener el passarela propietari

		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();
	
		PassarellaPropietari^ propietari = CercadoraPropietari::cercaPropietari(usuari->getUsername());
		
		TxConsultarMascotes^ consultaMascotas = TxConsultarMascotes::crear(propietari);
		vector<int> mascotas = consultaMascotas->obteResultat();
		// Limpiar el ComboBox
		petsList->Items->Clear();
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


	private: System::Void eliminabutton_click(System::Object^ sender, System::EventArgs^ e) {
		
		PetSalut::Elimina_Mascota_forms^ elimMasc = gcnew PetSalut::Elimina_Mascota_forms();
		// Set the size and position of IniUsu to match PantallaPrincipal
		elimMasc->Size = this->Size;
		elimMasc->Location = this->Location;

		this->Visible = false;

		elimMasc -> ShowDialog();

		this->Visible = true;

	}

	private: System::Void registrarbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::Crea_Mascota_forms^ creaMasc = gcnew PetSalut::Crea_Mascota_forms();

		// Set the size and position of IniUsu to match PantallaPrincipal
		creaMasc->Size = this->Size;
		creaMasc->Location = this->Location;

		this->Visible = false;

		creaMasc->ShowDialog();

		this->Visible = true;

	}
	private: System::Void visitesButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		PetSalut::ConsultaVistes_forms^ consVisites = gcnew PetSalut::ConsultaVistes_forms();

		// Set the size and position of IniUsu to match PantallaPrincipal
		consVisites->Size = this->Size;
		consVisites->Location = this->Location;
		
		this->Visible = false;

		consVisites->ShowDialog();

		this->Visible = true;
		

	}
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConsultaMascota_forms::typeid));
			this->petsaludlabel = (gcnew System::Windows::Forms::Label());
			this->mypetslabel = (gcnew System::Windows::Forms::Label());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->consultar = (gcnew System::Windows::Forms::Button());
			this->descriptionPannel = (gcnew System::Windows::Forms::Panel());
			this->eliminabutton = (gcnew System::Windows::Forms::Button());
			this->registrarmascbutton = (gcnew System::Windows::Forms::Button());
			this->visitesButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// petsaludlabel
			// 
			this->petsaludlabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->petsaludlabel->AutoSize = true;
			this->petsaludlabel->BackColor = System::Drawing::Color::Transparent;
			this->petsaludlabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 28));
			this->petsaludlabel->Location = System::Drawing::Point(471, 9);
			this->petsaludlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->petsaludlabel->Name = L"petsaludlabel";
			this->petsaludlabel->Size = System::Drawing::Size(262, 54);
			this->petsaludlabel->TabIndex = 1;
			this->petsaludlabel->Text = L"PETSALUT";
			this->petsaludlabel->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::label1_Click);
			// 
			// mypetslabel
			// 
			this->mypetslabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->mypetslabel->AutoSize = true;
			this->mypetslabel->BackColor = System::Drawing::Color::Transparent;
			this->mypetslabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 20));
			this->mypetslabel->Location = System::Drawing::Point(410, 63);
			this->mypetslabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mypetslabel->Name = L"mypetslabel";
			this->mypetslabel->Size = System::Drawing::Size(379, 39);
			this->mypetslabel->TabIndex = 2;
			this->mypetslabel->Text = L"LES MEVES MASCOTES";
			// 
			// petsList
			// 
			this->petsList->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->petsList->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(199, 136);
			this->petsList->Margin = System::Windows::Forms::Padding(2);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(590, 27);
			this->petsList->TabIndex = 3;
			this->petsList->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::fillPets);
			// 
			// consultar
			// 
			this->consultar->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->consultar->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->consultar->Location = System::Drawing::Point(793, 135);
			this->consultar->Margin = System::Windows::Forms::Padding(2);
			this->consultar->Name = L"consultar";
			this->consultar->Size = System::Drawing::Size(179, 29);
			this->consultar->TabIndex = 4;
			this->consultar->Text = L"CONSULTAR";
			this->consultar->UseVisualStyleBackColor = true;
			this->consultar->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::consultar_Click);
			// 
			// descriptionPannel
			// 
			this->descriptionPannel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->descriptionPannel->BackColor = System::Drawing::SystemColors::Control;
			this->descriptionPannel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->descriptionPannel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->descriptionPannel->Location = System::Drawing::Point(199, 169);
			this->descriptionPannel->Margin = System::Windows::Forms::Padding(2);
			this->descriptionPannel->Name = L"descriptionPannel";
			this->descriptionPannel->Size = System::Drawing::Size(773, 480);
			this->descriptionPannel->TabIndex = 5;
			this->descriptionPannel->Visible = false;
			this->descriptionPannel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ConsultaMascota_forms::panel1_Paint);
			// 
			// eliminabutton
			// 
			this->eliminabutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->eliminabutton->BackColor = System::Drawing::Color::IndianRed;
			this->eliminabutton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->eliminabutton->Location = System::Drawing::Point(990, 561);
			this->eliminabutton->Name = L"eliminabutton";
			this->eliminabutton->Size = System::Drawing::Size(182, 88);
			this->eliminabutton->TabIndex = 6;
			this->eliminabutton->Text = L"ELIMINAR MASCOTA";
			this->eliminabutton->UseVisualStyleBackColor = false;
			this->eliminabutton->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::eliminabutton_click);
			// 
			// registrarmascbutton
			// 
			this->registrarmascbutton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->registrarmascbutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->registrarmascbutton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->registrarmascbutton->Location = System::Drawing::Point(990, 467);
			this->registrarmascbutton->Name = L"registrarmascbutton";
			this->registrarmascbutton->Size = System::Drawing::Size(182, 88);
			this->registrarmascbutton->TabIndex = 7;
			this->registrarmascbutton->Text = L"REGISTRAR MASCOTA";
			this->registrarmascbutton->UseVisualStyleBackColor = false;
			this->registrarmascbutton->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::registrarbutton_Click);
			// 
			// visitesButton
			// 
			this->visitesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->visitesButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->visitesButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->visitesButton->Location = System::Drawing::Point(990, 373);
			this->visitesButton->Name = L"visitesButton";
			this->visitesButton->Size = System::Drawing::Size(182, 88);
			this->visitesButton->TabIndex = 8;
			this->visitesButton->Text = L"VISITES";
			this->visitesButton->UseVisualStyleBackColor = false;
			this->visitesButton->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::visitesButton_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->button1->Location = System::Drawing::Point(12, 561);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(182, 88);
			this->button1->TabIndex = 9;
			this->button1->Text = L"TORNAR";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ConsultaMascota_forms::button1_Click);
			// 
			// ConsultaMascota_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->visitesButton);
			this->Controls->Add(this->registrarmascbutton);
			this->Controls->Add(this->eliminabutton);
			this->Controls->Add(this->descriptionPannel);
			this->Controls->Add(this->consultar);
			this->Controls->Add(this->petsList);
			this->Controls->Add(this->mypetslabel);
			this->Controls->Add(this->petsaludlabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"ConsultaMascota_forms";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Close();

}
};
}
