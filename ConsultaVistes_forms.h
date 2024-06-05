#pragma once
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
#include "CreaVisites_forms.h"
#include "EliminaVisita_forms.h"
#include "TxModificarValoracio.h"


namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ConsultaVistes_forms
	/// </summary>
	public ref class ConsultaVistes_forms : public System::Windows::Forms::Form
	{
	public:
		ConsultaVistes_forms(void)
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
		~ConsultaVistes_forms()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ registrarbutton;
	private: System::Windows::Forms::Button^ eliminabutton;
	private: System::Windows::Forms::Label^ visitesLabel;

	private: System::Windows::Forms::Label^ petsaludlabel;
	private: System::Windows::Forms::Label^ mascotalabel;
	private: System::Windows::Forms::ComboBox^ visitaList;
	private: System::Windows::Forms::Label^ visitaLabel;

	private: System::Windows::Forms::Button^ consultar;
	private: System::Windows::Forms::Button^ valorarButton;
	private: System::Windows::Forms::ComboBox^ petsList;
	private: System::Windows::Forms::Panel^ hiddenPanel; // Panel oculto
	private: System::Windows::Forms::Button^ showHideButton; // Botón para mostrar/ocultar el panel
	private: System::Windows::Forms::Label^ trackBarLabel;
	private: System::Windows::Forms::Label^ valorartext;
	private: System::Windows::Forms::Button^ notaguardarButton;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ descriptionPannel;
	private: System::Windows::Forms::Button^ button1;


	private: System::Windows::Forms::TrackBar^ trackBar;

	//	private: System::Windows::Forms::Button^ consultar;
	protected:

	private: System::Void fillPets(System::Object^ sender, System::EventArgs^ e) {


		//Usar aqui la variable ordenador para obtener el passarela propietari
		petsList->Items->Clear();
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
	private: System::Void visitalist_click(System::Object^ sender, System::EventArgs^ e) {
		visitaList->Items->Clear();
		if (petsList->SelectedIndex == -1) return;

		// Obtener el identificador de la mascota seleccionada
		String^ selectedPet = petsList->SelectedItem->ToString();
		int chipMascota = Int32::Parse(selectedPet->Split('(')[1]->Replace(")", "")->Trim());

		// Buscar la mascota por su chip usando la CercadoraMascota
		CercadoraMascota^ cercadora = gcnew CercadoraMascota();
		PassarellaMascota^ mascota = cercadora->cercaMascota(chipMascota);

		if (mascota == nullptr) {
			MessageBox::Show("No se pudo encontrar la mascota seleccionada.");
			return;
		}

		// Consultar las visitas de la mascota seleccionada
		TxConsultarVisites^ consultaVisites = TxConsultarVisites::crear(mascota);
		vector<int> visitesIDs = consultaVisites->obteResultat();
		// Limpiar el ComboBox de visitas
		visitaList->Items->Clear();

		CercadoraEsdeveniments^ cercadorEsdeveniments = gcnew CercadoraEsdeveniments();

		// Llenar el ComboBox de visitas y buscar nombre de eventos
		for (int i = 0; i < visitesIDs.size(); ++i) {
			PassarellaEsdeveniments^ esdeveniment = cercadorEsdeveniments->cercaEsdeveniment(visitesIDs[i]);

			int id = esdeveniment->Numeroid;
			String^ nomEsdeveniment = esdeveniment->Nom;
			String^ infoVisita = nomEsdeveniment + " (" + id.ToString() + ")";
			visitaList->Items->Add(infoVisita);

		}
	}

	private: System::Void eliminabutton_click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::EliminaVisita_forms^ elimVisita = gcnew PetSalut::EliminaVisita_forms();
		elimVisita->Size = this->Size; 
		elimVisita->Location = this->Location; 
		this->Visible = false;

		elimVisita->ShowDialog();

		this->Visible = true;

		if (visitaList->SelectedIndex != -1)
			this->Close();

	}

	private: System::Void registrarbutton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::CreaVisites_forms^ creaVisita = gcnew PetSalut::CreaVisites_forms();
		
		// Set the size and position of IniUsu to match PantallaPrincipal
		creaVisita->Size = this->Size;
		creaVisita->Location = this->Location;

		this->Visible = false;

		creaVisita->ShowDialog();

		this->Visible = true;

	}
	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (visitaList->SelectedIndex != -1) {
			// Si hay un elemento seleccionado, muestra el panel de descripción
			descriptionPannel->Visible = true;
			descriptionPannel->Controls->Clear();

			// Obtén el evento seleccionado del ComboBox
			String^ esdevenimentSeleccionado = visitaList->SelectedItem->ToString();

			// Extrae el numero_id del evento seleccionado (asumiendo que el ID está entre paréntesis)
			int indiceParentesisAbierto = esdevenimentSeleccionado->IndexOf('(');
			int indiceParentesisCerrado = esdevenimentSeleccionado->IndexOf(')');
			String^ idString = esdevenimentSeleccionado->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int numeroid = Int32::Parse(idString);

			// Utiliza el numeroid para buscar y obtener más información del evento y visita
			CercadoraEsdeveniments^ cercadora = gcnew CercadoraEsdeveniments();
			PassarellaEsdeveniments^ esdeveniment = cercadora->cercaEsdeveniment(numeroid);
			CercadoraVisita^ cercadorav = gcnew CercadoraVisita();
			PassarellaVisites^ visita = cercadorav->cercaVisita(numeroid);
			CercadoraMascota^ buscadorMascotas = gcnew CercadoraMascota();
			PassarellaMascota^ mascota = buscadorMascotas->cercaMascota(visita->Mascota);

			CercadoraCentre^ buscadorCentros = gcnew CercadoraCentre();
			PassarellaCentre^ centre = buscadorCentros->cercaCentre(visita->Centre);

			// Muestra la información del evento en el panel de descripción
			Label^ labelNumeroID = gcnew Label();
			labelNumeroID->Text = "Número de Visita: \n" + esdeveniment->Numeroid.ToString();
			labelNumeroID->Location = Point(10, 10);
			labelNumeroID->AutoSize = true;
			descriptionPannel->Controls->Add(labelNumeroID);

			Label^ labelNombre = gcnew Label();
			labelNombre->Text = "Motiu: \n" + esdeveniment->Nom;
			labelNombre->Location = Point(10, labelNumeroID->Bottom + 8);
			labelNombre->AutoSize = true;
			descriptionPannel->Controls->Add(labelNombre);

			Label^ labelFecha = gcnew Label();
			labelFecha->Text = "Data: \n" + esdeveniment->Data.ToString("dd/MM/yyyy");
			labelFecha->Location = Point(10, labelNombre->Bottom + 8);
			labelFecha->AutoSize = true;
			descriptionPannel->Controls->Add(labelFecha);

			Label^ labelHora = gcnew Label();
			labelHora->Text = "Hora: \n" + esdeveniment->Hora;
			labelHora->Location = Point(10, labelFecha->Bottom + 8);
			labelHora->AutoSize = true;
			descriptionPannel->Controls->Add(labelHora);

			Label^ labelMascota = gcnew Label();
			labelMascota->Text = "Mascota: \n" + mascota->Nom;
			labelMascota->Location = Point(10, labelHora->Bottom + 8);
			labelMascota->AutoSize = true;
			descriptionPannel->Controls->Add(labelMascota);

			Label^ labelCentre = gcnew Label();
			labelCentre->Text = "Centre: \n" + centre->Nom;
			labelCentre->Location = Point(10, labelMascota->Bottom + 8);
			labelCentre->AutoSize = true;
			descriptionPannel->Controls->Add(labelCentre);

			Label^ labelUbicacio = gcnew Label();
			labelUbicacio->Text = "Ubicació: \n" + centre->Ubicacio;
			labelUbicacio->Location = Point(10, labelCentre->Bottom + 8);
			labelUbicacio->AutoSize = true;
			descriptionPannel->Controls->Add(labelUbicacio);

			    this->valorarButton->Visible = true;

		}
		else {
			// Si no hay elementos seleccionados, muestra un mensaje de error
			MessageBox::Show("Por favor, selecciona un evento antes de consultar.");
		}
	}
	private: System::Void trackBar_Scroll(System::Object^ sender, System::EventArgs^ e) {
			   // Obtiene el valor actual del TrackBar
			   int valorSeleccionado = trackBar->Value;

			   // Actualiza el texto de la Label con el valor seleccionado
			   trackBarLabel->Text = "Nota: " + valorSeleccionado.ToString();
	}
		
	private: System::Void exitbutton_click(System::Object^ sender, System::EventArgs^ e) {
		this->hiddenPanel->Visible = false;

	}
	private: System::Void valorarButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if(this->valorartext->Text != "")
			this->hiddenPanel->Visible = true;

	}
	private: System::Void notaguardarButton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		String^ esdevenimentSeleccionado = visitaList->SelectedItem->ToString();

		// Extrae el numero_id del evento seleccionado (asumiendo que el ID está entre paréntesis)
		int indiceParentesisAbierto = esdevenimentSeleccionado->IndexOf('(');
		int indiceParentesisCerrado = esdevenimentSeleccionado->IndexOf(')');
		String^ idString = esdevenimentSeleccionado->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
		int numeroid = Int32::Parse(idString);
		CercadoraVisita^ cercadorav = gcnew CercadoraVisita();
		PassarellaVisites^ visita = cercadorav->cercaVisita(numeroid);
		int numeroidcentre = visita->Centre;
		Ordinador^ ord = Ordinador::getInstance();
		PassarellaUsuari^ usuari = ord->obteUsuari();
		TxModificarValoracio^ valoracioModificada = TxModificarValoracio::prepara(numeroidcentre, numeroid, usuari->getUsername(), trackBar->Value);
		try {
			valoracioModificada->executa();
		}
		catch (Exception^ ex) {
			throw gcnew Exception("No s'ha pogut modificar l'item");

		}
		this->hiddenPanel->Visible = false;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConsultaVistes_forms::typeid));
			this->registrarbutton = (gcnew System::Windows::Forms::Button());
			this->eliminabutton = (gcnew System::Windows::Forms::Button());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->visitesLabel = (gcnew System::Windows::Forms::Label());
			this->petsaludlabel = (gcnew System::Windows::Forms::Label());
			this->mascotalabel = (gcnew System::Windows::Forms::Label());
			this->visitaList = (gcnew System::Windows::Forms::ComboBox());
			this->visitaLabel = (gcnew System::Windows::Forms::Label());
			this->hiddenPanel = (gcnew System::Windows::Forms::Panel());
			this->notaguardarButton = (gcnew System::Windows::Forms::Button());
			this->valorartext = (gcnew System::Windows::Forms::Label());
			this->trackBarLabel = (gcnew System::Windows::Forms::Label());
			this->showHideButton = (gcnew System::Windows::Forms::Button());
			this->trackBar = (gcnew System::Windows::Forms::TrackBar());
			this->consultar = (gcnew System::Windows::Forms::Button());
			this->valorarButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->descriptionPannel = (gcnew System::Windows::Forms::Panel());
			this->hiddenPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// registrarbutton
			// 
			this->registrarbutton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->registrarbutton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->registrarbutton->Location = System::Drawing::Point(925, 353);
			this->registrarbutton->Name = L"registrarbutton";
			this->registrarbutton->Size = System::Drawing::Size(194, 86);
			this->registrarbutton->TabIndex = 8;
			this->registrarbutton->Text = L"REGISTRAR VISITA";
			this->registrarbutton->UseVisualStyleBackColor = false;
			this->registrarbutton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::registrarbutton_Click);
			// 
			// eliminabutton
			// 
			this->eliminabutton->BackColor = System::Drawing::Color::IndianRed;
			this->eliminabutton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->eliminabutton->Location = System::Drawing::Point(925, 445);
			this->eliminabutton->Name = L"eliminabutton";
			this->eliminabutton->Size = System::Drawing::Size(194, 86);
			this->eliminabutton->TabIndex = 9;
			this->eliminabutton->Text = L"ELIMINAR VISITA";
			this->eliminabutton->UseVisualStyleBackColor = false;
			this->eliminabutton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::eliminabutton_click);
			// 
			// petsList
			// 
			this->petsList->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(368, 51);
			this->petsList->Margin = System::Windows::Forms::Padding(2);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(344, 31);
			this->petsList->TabIndex = 3;
			this->petsList->TextChanged += gcnew System::EventHandler(this, &ConsultaVistes_forms::petsList_TextChanged);
			this->petsList->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::fillPets);
			// 
			// visitesLabel
			// 
			this->visitesLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->visitesLabel->AutoSize = true;
			this->visitesLabel->BackColor = System::Drawing::Color::Transparent;
			this->visitesLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18));
			this->visitesLabel->Location = System::Drawing::Point(513, 61);
			this->visitesLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->visitesLabel->Name = L"visitesLabel";
			this->visitesLabel->Size = System::Drawing::Size(129, 33);
			this->visitesLabel->TabIndex = 11;
			this->visitesLabel->Text = L"VISITES";
			this->visitesLabel->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::visitesLabel_Click);
			// 
			// petsaludlabel
			// 
			this->petsaludlabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->petsaludlabel->AutoSize = true;
			this->petsaludlabel->BackColor = System::Drawing::Color::Transparent;
			this->petsaludlabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 24));
			this->petsaludlabel->Location = System::Drawing::Point(468, 17);
			this->petsaludlabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->petsaludlabel->Name = L"petsaludlabel";
			this->petsaludlabel->Size = System::Drawing::Size(218, 44);
			this->petsaludlabel->TabIndex = 10;
			this->petsaludlabel->Text = L"PETSALUT";
			// 
			// mascotalabel
			// 
			this->mascotalabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mascotalabel->AutoSize = true;
			this->mascotalabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->mascotalabel->Location = System::Drawing::Point(265, 55);
			this->mascotalabel->Name = L"mascotalabel";
			this->mascotalabel->Size = System::Drawing::Size(98, 23);
			this->mascotalabel->TabIndex = 17;
			this->mascotalabel->Text = L"Mascota:";
			// 
			// visitaList
			// 
			this->visitaList->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->visitaList->FormattingEnabled = true;
			this->visitaList->Location = System::Drawing::Point(368, 102);
			this->visitaList->Name = L"visitaList";
			this->visitaList->Size = System::Drawing::Size(344, 31);
			this->visitaList->TabIndex = 18;
			this->visitaList->TextChanged += gcnew System::EventHandler(this, &ConsultaVistes_forms::visitaList_TextChanged);
			this->visitaList->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::visitalist_click);
			// 
			// visitaLabel
			// 
			this->visitaLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->visitaLabel->AutoSize = true;
			this->visitaLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->visitaLabel->Location = System::Drawing::Point(289, 106);
			this->visitaLabel->Name = L"visitaLabel";
			this->visitaLabel->Size = System::Drawing::Size(73, 23);
			this->visitaLabel->TabIndex = 19;
			this->visitaLabel->Text = L"Visita:";
			// 
			// hiddenPanel
			// 
			this->hiddenPanel->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->hiddenPanel->Controls->Add(this->notaguardarButton);
			this->hiddenPanel->Controls->Add(this->valorartext);
			this->hiddenPanel->Controls->Add(this->trackBarLabel);
			this->hiddenPanel->Controls->Add(this->showHideButton);
			this->hiddenPanel->Controls->Add(this->trackBar);
			this->hiddenPanel->Location = System::Drawing::Point(280, 177);
			this->hiddenPanel->Name = L"hiddenPanel";
			this->hiddenPanel->Size = System::Drawing::Size(560, 343);
			this->hiddenPanel->TabIndex = 21;
			this->hiddenPanel->Visible = false;
			// 
			// notaguardarButton
			// 
			this->notaguardarButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->notaguardarButton->Location = System::Drawing::Point(212, 268);
			this->notaguardarButton->Name = L"notaguardarButton";
			this->notaguardarButton->Size = System::Drawing::Size(145, 35);
			this->notaguardarButton->TabIndex = 22;
			this->notaguardarButton->Text = L"VALORAR";
			this->notaguardarButton->UseVisualStyleBackColor = true;
			this->notaguardarButton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::notaguardarButton_Click);
			// 
			// valorartext
			// 
			this->valorartext->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->valorartext->AutoSize = true;
			this->valorartext->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->valorartext->Location = System::Drawing::Point(164, 17);
			this->valorartext->Name = L"valorartext";
			this->valorartext->Size = System::Drawing::Size(265, 26);
			this->valorartext->TabIndex = 21;
			this->valorartext->Text = L"Com valores la visita\?";
			this->valorartext->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::valorartext_Click);
			// 
			// trackBarLabel
			// 
			this->trackBarLabel->AutoSize = true;
			this->trackBarLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->trackBarLabel->Location = System::Drawing::Point(207, 56);
			this->trackBarLabel->Name = L"trackBarLabel";
			this->trackBarLabel->Size = System::Drawing::Size(135, 26);
			this->trackBarLabel->TabIndex = 0;
			this->trackBarLabel->Text = L"No valorat";
			// 
			// showHideButton
			// 
			this->showHideButton->BackColor = System::Drawing::Color::Firebrick;
			this->showHideButton->Location = System::Drawing::Point(511, 9);
			this->showHideButton->Name = L"showHideButton";
			this->showHideButton->Size = System::Drawing::Size(33, 33);
			this->showHideButton->TabIndex = 22;
			this->showHideButton->Text = L"X";
			this->showHideButton->UseVisualStyleBackColor = false;
			this->showHideButton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::exitbutton_click);
			// 
			// trackBar
			// 
			this->trackBar->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->trackBar->Location = System::Drawing::Point(149, 156);
			this->trackBar->Minimum = 1;
			this->trackBar->Name = L"trackBar";
			this->trackBar->Size = System::Drawing::Size(260, 45);
			this->trackBar->TabIndex = 1;
			this->trackBar->Maximum = 10;
			this->trackBar->Scroll += gcnew System::EventHandler(this, &ConsultaVistes_forms::trackBar_Scroll);
			// 
			// consultar
			// 
			this->consultar->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->consultar->Location = System::Drawing::Point(718, 51);
			this->consultar->Margin = System::Windows::Forms::Padding(2);
			this->consultar->Name = L"consultar";
			this->consultar->Size = System::Drawing::Size(166, 31);
			this->consultar->TabIndex = 5;
			this->consultar->Text = L"CONSULTAR";
			this->consultar->UseVisualStyleBackColor = true;
			this->consultar->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::consultar_Click);
			// 
			// valorarButton
			// 
			this->valorarButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->valorarButton->Location = System::Drawing::Point(718, 102);
			this->valorarButton->Name = L"valorarButton";
			this->valorarButton->Size = System::Drawing::Size(166, 31);
			this->valorarButton->TabIndex = 20;
			this->valorarButton->Text = L"VALORAR VISITA";
			this->valorarButton->UseVisualStyleBackColor = true;
			this->valorarButton->Visible = false;
			this->valorarButton->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::valorarButton_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->AutoSize = true;
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Controls->Add(this->hiddenPanel);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->petsList);
			this->panel1->Controls->Add(this->descriptionPannel);
			this->panel1->Controls->Add(this->registrarbutton);
			this->panel1->Controls->Add(this->valorarButton);
			this->panel1->Controls->Add(this->eliminabutton);
			this->panel1->Controls->Add(this->consultar);
			this->panel1->Controls->Add(this->mascotalabel);
			this->panel1->Controls->Add(this->visitaList);
			this->panel1->Controls->Add(this->visitaLabel);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->panel1->Location = System::Drawing::Point(27, 105);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1122, 534);
			this->panel1->TabIndex = 22;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->button1->Location = System::Drawing::Point(3, 445);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(167, 86);
			this->button1->TabIndex = 22;
			this->button1->Text = L"Tornar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ConsultaVistes_forms::button1_Click);
			// 
			// descriptionPannel
			// 
			this->descriptionPannel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->descriptionPannel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->descriptionPannel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 8));
			this->descriptionPannel->Location = System::Drawing::Point(280, 177);
			this->descriptionPannel->Margin = System::Windows::Forms::Padding(2);
			this->descriptionPannel->Name = L"descriptionPannel";
			this->descriptionPannel->Size = System::Drawing::Size(560, 343);
			this->descriptionPannel->TabIndex = 5;
			this->descriptionPannel->Visible = false;
			this->descriptionPannel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ConsultaVistes_forms::descriptionPannel_Paint);
			// 
			// ConsultaVistes_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->visitesLabel);
			this->Controls->Add(this->petsaludlabel);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ConsultaVistes_forms";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->hiddenPanel->ResumeLayout(false);
			this->hiddenPanel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void visitesLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void descriptionPannel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void valorartext_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Close();
}
private: System::Void petsList_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	this->visitaList->Text = "";
	this->valorarButton->Visible = false;

}
private: System::Void visitaList_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (this->valorartext->Text != "")
		this->valorarButton->Visible = true;
		this->hiddenPanel->Visible = false;

}
};
}
