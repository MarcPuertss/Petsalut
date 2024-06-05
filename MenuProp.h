#pragma once
#include "InfoProp.h"
#include "ModProp.h"
#include "TxEsborraUsu.h"
#include "CreaVisites_forms.h"
#include "ConsultaVistes_forms.h"
#include "ConsultaMascota_forms.h"
#include "CrearPublic.h"
#include "ConsultarEvents.h"
#include "CercadoraPublic.h"
#include "PassarellaPublic.h"
#include "CercadoraEsdeveniments.h"
#include "Ordinador.h"
#include "PassarellaParticipa.h"
#include "CercadoraParticipa.h"
#include "TxEsborraParticipa.h"
#include "TxCrearParticipa.h"
namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MenuProp
	/// </summary>
	public ref class MenuProp : public System::Windows::Forms::Form
	{
	public:
		MenuProp(void)
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
		~MenuProp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ConsultaButton;
	private: System::Windows::Forms::Button^ ModificarButton;
	private: System::Windows::Forms::Button^ TancarButton;
	protected:

	protected:
	private: System::Windows::Forms::Button^ EliminarButton;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ ConsultarMascotesButton;

	private: System::Windows::Forms::Button^ ConsultaVisitesButton;
	private: System::Windows::Forms::Button^ ProgramarVisitesButton;
	private: System::Windows::Forms::Button^ PublicarEventButton;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ tituloLabel;
	private: System::Windows::Forms::Label^ nombreLabel;



	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ apuntarseButton;

	private: System::Windows::Forms::Label^ dataLabel;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ ubicacionLabel;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ descripcionLabel;
	private: System::Windows::Forms::Button^ anteriorButton;
	private: System::Windows::Forms::Button^ seguentButton;
	private: System::Windows::Forms::Button^ eliminar_compte_acceptar;
	private: System::Windows::Forms::Button^ cancelar_eliminar_compte;
	private: System::Windows::Forms::TextBox^ contrasenyaelimina;
	private: System::Windows::Forms::Label^ labelelimina;
	private: System::Windows::Forms::PictureBox^ boxeliminar;
	private: System::Windows::Forms::Button^ Accepta_Tanca;
	private: System::Windows::Forms::Button^ Cancela_Tanca;
	private: System::Windows::Forms::Label^ LabelTancaSessio;
	private: System::Windows::Forms::PictureBox^ TancaSessioBox;
	private: System::Windows::Forms::Label^ tipusLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ paginasLabel;
	private: System::Windows::Forms::Label^ participantsLabel;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ apuntatButton;










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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuProp::typeid));
			this->ConsultaButton = (gcnew System::Windows::Forms::Button());
			this->ModificarButton = (gcnew System::Windows::Forms::Button());
			this->TancarButton = (gcnew System::Windows::Forms::Button());
			this->EliminarButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ConsultarMascotesButton = (gcnew System::Windows::Forms::Button());
			this->ConsultaVisitesButton = (gcnew System::Windows::Forms::Button());
			this->ProgramarVisitesButton = (gcnew System::Windows::Forms::Button());
			this->PublicarEventButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->apuntatButton = (gcnew System::Windows::Forms::Button());
			this->participantsLabel = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->paginasLabel = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->eliminar_compte_acceptar = (gcnew System::Windows::Forms::Button());
			this->Accepta_Tanca = (gcnew System::Windows::Forms::Button());
			this->cancelar_eliminar_compte = (gcnew System::Windows::Forms::Button());
			this->anteriorButton = (gcnew System::Windows::Forms::Button());
			this->contrasenyaelimina = (gcnew System::Windows::Forms::TextBox());
			this->Cancela_Tanca = (gcnew System::Windows::Forms::Button());
			this->labelelimina = (gcnew System::Windows::Forms::Label());
			this->seguentButton = (gcnew System::Windows::Forms::Button());
			this->boxeliminar = (gcnew System::Windows::Forms::PictureBox());
			this->LabelTancaSessio = (gcnew System::Windows::Forms::Label());
			this->apuntarseButton = (gcnew System::Windows::Forms::Button());
			this->TancaSessioBox = (gcnew System::Windows::Forms::PictureBox());
			this->tipusLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->ubicacionLabel = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->descripcionLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tituloLabel = (gcnew System::Windows::Forms::Label());
			this->nombreLabel = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxeliminar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TancaSessioBox))->BeginInit();
			this->SuspendLayout();
			// 
			// ConsultaButton
			// 
			this->ConsultaButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ConsultaButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ConsultaButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->ConsultaButton->Location = System::Drawing::Point(10, 129);
			this->ConsultaButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ConsultaButton->Name = L"ConsultaButton";
			this->ConsultaButton->Size = System::Drawing::Size(253, 48);
			this->ConsultaButton->TabIndex = 0;
			this->ConsultaButton->Text = L"Consultar Informacio";
			this->ConsultaButton->UseVisualStyleBackColor = true;
			this->ConsultaButton->Click += gcnew System::EventHandler(this, &MenuProp::Consulta_Click);
			// 
			// ModificarButton
			// 
			this->ModificarButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ModificarButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ModificarButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->ModificarButton->Location = System::Drawing::Point(10, 181);
			this->ModificarButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ModificarButton->Name = L"ModificarButton";
			this->ModificarButton->Size = System::Drawing::Size(253, 48);
			this->ModificarButton->TabIndex = 1;
			this->ModificarButton->Text = L"Modificar Informacio";
			this->ModificarButton->UseVisualStyleBackColor = true;
			this->ModificarButton->Click += gcnew System::EventHandler(this, &MenuProp::Modifica_Click);
			// 
			// TancarButton
			// 
			this->TancarButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TancarButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->TancarButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->TancarButton->Location = System::Drawing::Point(10, 446);
			this->TancarButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->TancarButton->Name = L"TancarButton";
			this->TancarButton->Size = System::Drawing::Size(253, 48);
			this->TancarButton->TabIndex = 2;
			this->TancarButton->Text = L"Tancar Sessio";
			this->TancarButton->UseVisualStyleBackColor = true;
			this->TancarButton->Click += gcnew System::EventHandler(this, &MenuProp::Tanca_Click);
			// 
			// EliminarButton
			// 
			this->EliminarButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EliminarButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->EliminarButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->EliminarButton->Location = System::Drawing::Point(10, 506);
			this->EliminarButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->EliminarButton->Name = L"EliminarButton";
			this->EliminarButton->Size = System::Drawing::Size(253, 42);
			this->EliminarButton->TabIndex = 3;
			this->EliminarButton->Text = L"Elimina el teu Perfil";
			this->EliminarButton->UseVisualStyleBackColor = true;
			this->EliminarButton->Click += gcnew System::EventHandler(this, &MenuProp::Elimina_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 47);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(269, 49);
			this->label1->TabIndex = 4;
			this->label1->Text = L"MENU PROPIETARI";
			// 
			// ConsultarMascotesButton
			// 
			this->ConsultarMascotesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ConsultarMascotesButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ConsultarMascotesButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->ConsultarMascotesButton->Location = System::Drawing::Point(10, 286);
			this->ConsultarMascotesButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ConsultarMascotesButton->Name = L"ConsultarMascotesButton";
			this->ConsultarMascotesButton->Size = System::Drawing::Size(253, 48);
			this->ConsultarMascotesButton->TabIndex = 14;
			this->ConsultarMascotesButton->Text = L"Les  meves Mascotes";
			this->ConsultarMascotesButton->UseVisualStyleBackColor = true;
			this->ConsultarMascotesButton->Click += gcnew System::EventHandler(this, &MenuProp::ConsultarMascotesButton_Click);
			// 
			// ConsultaVisitesButton
			// 
			this->ConsultaVisitesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ConsultaVisitesButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ConsultaVisitesButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->ConsultaVisitesButton->Location = System::Drawing::Point(10, 390);
			this->ConsultaVisitesButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ConsultaVisitesButton->Name = L"ConsultaVisitesButton";
			this->ConsultaVisitesButton->Size = System::Drawing::Size(253, 48);
			this->ConsultaVisitesButton->TabIndex = 15;
			this->ConsultaVisitesButton->Text = L"Historial Visites";
			this->ConsultaVisitesButton->UseVisualStyleBackColor = true;
			this->ConsultaVisitesButton->Click += gcnew System::EventHandler(this, &MenuProp::ConsultaVisitesButton_Click);
			// 
			// ProgramarVisitesButton
			// 
			this->ProgramarVisitesButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ProgramarVisitesButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ProgramarVisitesButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->ProgramarVisitesButton->Location = System::Drawing::Point(10, 338);
			this->ProgramarVisitesButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ProgramarVisitesButton->Name = L"ProgramarVisitesButton";
			this->ProgramarVisitesButton->Size = System::Drawing::Size(253, 48);
			this->ProgramarVisitesButton->TabIndex = 16;
			this->ProgramarVisitesButton->Text = L"Programar Visita";
			this->ProgramarVisitesButton->UseVisualStyleBackColor = true;
			this->ProgramarVisitesButton->Click += gcnew System::EventHandler(this, &MenuProp::ProgramarVisitesButton_Click);
			// 
			// PublicarEventButton
			// 
			this->PublicarEventButton->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->PublicarEventButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->PublicarEventButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->PublicarEventButton->Location = System::Drawing::Point(10, 233);
			this->PublicarEventButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PublicarEventButton->Name = L"PublicarEventButton";
			this->PublicarEventButton->Size = System::Drawing::Size(253, 48);
			this->PublicarEventButton->TabIndex = 17;
			this->PublicarEventButton->Text = L"Publicar Event";
			this->PublicarEventButton->UseVisualStyleBackColor = true;
			this->PublicarEventButton->Click += gcnew System::EventHandler(this, &MenuProp::PublicarEventButton_Click);
			// 
			// panel1
			// 
			this->panel1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(276, -76);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(10, 745);
			this->panel1->TabIndex = 18;
			// 
			// panel2
			// 
			this->panel2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel2->BackColor = System::Drawing::SystemColors::Control;
			this->panel2->Controls->Add(this->apuntatButton);
			this->panel2->Controls->Add(this->participantsLabel);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->paginasLabel);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->eliminar_compte_acceptar);
			this->panel2->Controls->Add(this->Accepta_Tanca);
			this->panel2->Controls->Add(this->cancelar_eliminar_compte);
			this->panel2->Controls->Add(this->anteriorButton);
			this->panel2->Controls->Add(this->contrasenyaelimina);
			this->panel2->Controls->Add(this->Cancela_Tanca);
			this->panel2->Controls->Add(this->labelelimina);
			this->panel2->Controls->Add(this->seguentButton);
			this->panel2->Controls->Add(this->boxeliminar);
			this->panel2->Controls->Add(this->LabelTancaSessio);
			this->panel2->Controls->Add(this->apuntarseButton);
			this->panel2->Controls->Add(this->TancaSessioBox);
			this->panel2->Controls->Add(this->tipusLabel);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->dataLabel);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->ubicacionLabel);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->descripcionLabel);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->tituloLabel);
			this->panel2->Controls->Add(this->nombreLabel);
			this->panel2->Location = System::Drawing::Point(316, 75);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(856, 523);
			this->panel2->TabIndex = 19;
			// 
			// apuntatButton
			// 
			this->apuntatButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->apuntatButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->apuntatButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->apuntatButton->Location = System::Drawing::Point(344, 452);
			this->apuntatButton->Margin = System::Windows::Forms::Padding(2);
			this->apuntatButton->Name = L"apuntatButton";
			this->apuntatButton->Size = System::Drawing::Size(202, 61);
			this->apuntatButton->TabIndex = 35;
			this->apuntatButton->Text = L"DESAPUNTAT";
			this->apuntatButton->UseVisualStyleBackColor = false;
			this->apuntatButton->Click += gcnew System::EventHandler(this, &MenuProp::apuntatButton_Click);
			// 
			// participantsLabel
			// 
			this->participantsLabel->AutoSize = true;
			this->participantsLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->participantsLabel->ForeColor = System::Drawing::SystemColors::GrayText;
			this->participantsLabel->Location = System::Drawing::Point(703, 32);
			this->participantsLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->participantsLabel->Name = L"participantsLabel";
			this->participantsLabel->Size = System::Drawing::Size(29, 26);
			this->participantsLabel->TabIndex = 34;
			this->participantsLabel->Text = L"N";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label8->Location = System::Drawing::Point(539, 32);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(166, 26);
			this->label8->TabIndex = 33;
			this->label8->Text = L"Participants:";
			// 
			// paginasLabel
			// 
			this->paginasLabel->AutoSize = true;
			this->paginasLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->paginasLabel->Location = System::Drawing::Point(753, 453);
			this->paginasLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->paginasLabel->Name = L"paginasLabel";
			this->paginasLabel->Size = System::Drawing::Size(78, 18);
			this->paginasLabel->TabIndex = 32;
			this->paginasLabel->Text = L"PAGINAS";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 16));
			this->label7->Location = System::Drawing::Point(18, 23);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(135, 31);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Creador:";
			this->label7->Click += gcnew System::EventHandler(this, &MenuProp::label7_Click);
			// 
			// eliminar_compte_acceptar
			// 
			this->eliminar_compte_acceptar->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->eliminar_compte_acceptar->Location = System::Drawing::Point(428, 252);
			this->eliminar_compte_acceptar->Margin = System::Windows::Forms::Padding(2);
			this->eliminar_compte_acceptar->Name = L"eliminar_compte_acceptar";
			this->eliminar_compte_acceptar->Size = System::Drawing::Size(280, 68);
			this->eliminar_compte_acceptar->TabIndex = 24;
			this->eliminar_compte_acceptar->Text = L"Acceptar";
			this->eliminar_compte_acceptar->UseVisualStyleBackColor = true;
			this->eliminar_compte_acceptar->Visible = false;
			this->eliminar_compte_acceptar->Click += gcnew System::EventHandler(this, &MenuProp::eliminar_compte_acceptar_Click);
			// 
			// Accepta_Tanca
			// 
			this->Accepta_Tanca->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Accepta_Tanca->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Accepta_Tanca->Location = System::Drawing::Point(428, 261);
			this->Accepta_Tanca->Margin = System::Windows::Forms::Padding(2);
			this->Accepta_Tanca->Name = L"Accepta_Tanca";
			this->Accepta_Tanca->Size = System::Drawing::Size(280, 53);
			this->Accepta_Tanca->TabIndex = 29;
			this->Accepta_Tanca->Text = L"Acceptar";
			this->Accepta_Tanca->UseVisualStyleBackColor = true;
			this->Accepta_Tanca->Visible = false;
			this->Accepta_Tanca->Click += gcnew System::EventHandler(this, &MenuProp::Accepta_Tanca_Click);
			// 
			// cancelar_eliminar_compte
			// 
			this->cancelar_eliminar_compte->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cancelar_eliminar_compte->Location = System::Drawing::Point(151, 252);
			this->cancelar_eliminar_compte->Margin = System::Windows::Forms::Padding(2);
			this->cancelar_eliminar_compte->Name = L"cancelar_eliminar_compte";
			this->cancelar_eliminar_compte->Size = System::Drawing::Size(273, 68);
			this->cancelar_eliminar_compte->TabIndex = 23;
			this->cancelar_eliminar_compte->Text = L"Cancelar";
			this->cancelar_eliminar_compte->UseVisualStyleBackColor = true;
			this->cancelar_eliminar_compte->Visible = false;
			this->cancelar_eliminar_compte->Click += gcnew System::EventHandler(this, &MenuProp::cancelar_eliminar_compte_Click);
			// 
			// anteriorButton
			// 
			this->anteriorButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->anteriorButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->anteriorButton->Location = System::Drawing::Point(24, 473);
			this->anteriorButton->Margin = System::Windows::Forms::Padding(2);
			this->anteriorButton->Name = L"anteriorButton";
			this->anteriorButton->Size = System::Drawing::Size(123, 40);
			this->anteriorButton->TabIndex = 30;
			this->anteriorButton->Text = L"Anterior";
			this->anteriorButton->UseVisualStyleBackColor = true;
			this->anteriorButton->Click += gcnew System::EventHandler(this, &MenuProp::anteriorButton_Click);
			// 
			// contrasenyaelimina
			// 
			this->contrasenyaelimina->Location = System::Drawing::Point(203, 220);
			this->contrasenyaelimina->Name = L"contrasenyaelimina";
			this->contrasenyaelimina->Size = System::Drawing::Size(422, 20);
			this->contrasenyaelimina->TabIndex = 26;
			this->contrasenyaelimina->Visible = false;
			// 
			// Cancela_Tanca
			// 
			this->Cancela_Tanca->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Cancela_Tanca->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Cancela_Tanca->Location = System::Drawing::Point(151, 261);
			this->Cancela_Tanca->Margin = System::Windows::Forms::Padding(2);
			this->Cancela_Tanca->Name = L"Cancela_Tanca";
			this->Cancela_Tanca->Size = System::Drawing::Size(273, 53);
			this->Cancela_Tanca->TabIndex = 28;
			this->Cancela_Tanca->Text = L"Cancelar";
			this->Cancela_Tanca->UseVisualStyleBackColor = true;
			this->Cancela_Tanca->Visible = false;
			this->Cancela_Tanca->Click += gcnew System::EventHandler(this, &MenuProp::Cancela_Tanca_Click);
			// 
			// labelelimina
			// 
			this->labelelimina->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->labelelimina->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelelimina->Location = System::Drawing::Point(172, 133);
			this->labelelimina->Name = L"labelelimina";
			this->labelelimina->Size = System::Drawing::Size(495, 84);
			this->labelelimina->TabIndex = 25;
			this->labelelimina->Text = L"Per eliminar el compte introdueixi la contrasenya";
			this->labelelimina->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->labelelimina->Visible = false;
			// 
			// seguentButton
			// 
			this->seguentButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->seguentButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->seguentButton->Location = System::Drawing::Point(726, 473);
			this->seguentButton->Margin = System::Windows::Forms::Padding(2);
			this->seguentButton->Name = L"seguentButton";
			this->seguentButton->Size = System::Drawing::Size(123, 40);
			this->seguentButton->TabIndex = 29;
			this->seguentButton->Text = L"Seguent";
			this->seguentButton->UseVisualStyleBackColor = true;
			this->seguentButton->Click += gcnew System::EventHandler(this, &MenuProp::seguentButton_Click);
			// 
			// boxeliminar
			// 
			this->boxeliminar->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->boxeliminar->Location = System::Drawing::Point(130, 110);
			this->boxeliminar->Name = L"boxeliminar";
			this->boxeliminar->Size = System::Drawing::Size(588, 219);
			this->boxeliminar->TabIndex = 22;
			this->boxeliminar->TabStop = false;
			this->boxeliminar->Visible = false;
			// 
			// LabelTancaSessio
			// 
			this->LabelTancaSessio->BackColor = System::Drawing::SystemColors::ControlDark;
			this->LabelTancaSessio->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LabelTancaSessio->Location = System::Drawing::Point(172, 149);
			this->LabelTancaSessio->Name = L"LabelTancaSessio";
			this->LabelTancaSessio->Size = System::Drawing::Size(495, 110);
			this->LabelTancaSessio->TabIndex = 30;
			this->LabelTancaSessio->Text = L"Estas segur de que vols tancar la sessio actual en aquest dispositu\?";
			this->LabelTancaSessio->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->LabelTancaSessio->Visible = false;
			// 
			// apuntarseButton
			// 
			this->apuntarseButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->apuntarseButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->apuntarseButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 10));
			this->apuntarseButton->Location = System::Drawing::Point(344, 452);
			this->apuntarseButton->Margin = System::Windows::Forms::Padding(2);
			this->apuntarseButton->Name = L"apuntarseButton";
			this->apuntarseButton->Size = System::Drawing::Size(202, 61);
			this->apuntarseButton->TabIndex = 22;
			this->apuntarseButton->Text = L"Apuntam!!";
			this->apuntarseButton->UseVisualStyleBackColor = false;
			this->apuntarseButton->Click += gcnew System::EventHandler(this, &MenuProp::apuntarseButton_Click);
			// 
			// TancaSessioBox
			// 
			this->TancaSessioBox->BackColor = System::Drawing::SystemColors::ControlDark;
			this->TancaSessioBox->Location = System::Drawing::Point(130, 110);
			this->TancaSessioBox->Name = L"TancaSessioBox";
			this->TancaSessioBox->Size = System::Drawing::Size(588, 217);
			this->TancaSessioBox->TabIndex = 27;
			this->TancaSessioBox->TabStop = false;
			this->TancaSessioBox->Visible = false;
			// 
			// tipusLabel
			// 
			this->tipusLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->tipusLabel->ForeColor = System::Drawing::SystemColors::GrayText;
			this->tipusLabel->Location = System::Drawing::Point(19, 407);
			this->tipusLabel->Name = L"tipusLabel";
			this->tipusLabel->Size = System::Drawing::Size(214, 31);
			this->tipusLabel->TabIndex = 28;
			this->tipusLabel->Text = L"Tipus aqui";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label3->Location = System::Drawing::Point(19, 373);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(191, 32);
			this->label3->TabIndex = 27;
			this->label3->Text = L"Tipus:";
			// 
			// dataLabel
			// 
			this->dataLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->dataLabel->ForeColor = System::Drawing::SystemColors::GrayText;
			this->dataLabel->Location = System::Drawing::Point(19, 337);
			this->dataLabel->Name = L"dataLabel";
			this->dataLabel->Size = System::Drawing::Size(214, 31);
			this->dataLabel->TabIndex = 28;
			this->dataLabel->Text = L"Dia i hora aqui";
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label6->Location = System::Drawing::Point(19, 303);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(191, 32);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Dia i hora:";
			// 
			// ubicacionLabel
			// 
			this->ubicacionLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->ubicacionLabel->ForeColor = System::Drawing::SystemColors::GrayText;
			this->ubicacionLabel->Location = System::Drawing::Point(16, 264);
			this->ubicacionLabel->Name = L"ubicacionLabel";
			this->ubicacionLabel->Size = System::Drawing::Size(214, 31);
			this->ubicacionLabel->TabIndex = 26;
			this->ubicacionLabel->Text = L"Ubicacion aqui";
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label4->Location = System::Drawing::Point(16, 230);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(191, 32);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Ubicacio:";
			// 
			// descripcionLabel
			// 
			this->descripcionLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->descripcionLabel->ForeColor = System::Drawing::SystemColors::GrayText;
			this->descripcionLabel->Location = System::Drawing::Point(15, 150);
			this->descripcionLabel->Name = L"descripcionLabel";
			this->descripcionLabel->Size = System::Drawing::Size(834, 69);
			this->descripcionLabel->TabIndex = 24;
			this->descripcionLabel->Text = L"Descripcion aqui";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label5->Location = System::Drawing::Point(15, 116);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(191, 32);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Descripcio:";
			// 
			// tituloLabel
			// 
			this->tituloLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 16));
			this->tituloLabel->Location = System::Drawing::Point(15, 70);
			this->tituloLabel->Name = L"tituloLabel";
			this->tituloLabel->Size = System::Drawing::Size(398, 32);
			this->tituloLabel->TabIndex = 22;
			this->tituloLabel->Text = L"Titulo del evento aqui";
			// 
			// nombreLabel
			// 
			this->nombreLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->nombreLabel->ForeColor = System::Drawing::SystemColors::GrayText;
			this->nombreLabel->Location = System::Drawing::Point(146, 28);
			this->nombreLabel->Name = L"nombreLabel";
			this->nombreLabel->Size = System::Drawing::Size(388, 32);
			this->nombreLabel->TabIndex = 21;
			this->nombreLabel->Text = L"Nombre de la persona aqui";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 28));
			this->label2->Location = System::Drawing::Point(577, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(364, 43);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Events Publics";
			// 
			// MenuProp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->PublicarEventButton);
			this->Controls->Add(this->ProgramarVisitesButton);
			this->Controls->Add(this->ConsultaVisitesButton);
			this->Controls->Add(this->ConsultarMascotesButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->EliminarButton);
			this->Controls->Add(this->TancarButton);
			this->Controls->Add(this->ModificarButton);
			this->Controls->Add(this->ConsultaButton);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MenuProp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->Load += gcnew System::EventHandler(this, &MenuProp::MenuProp_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->boxeliminar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->TancaSessioBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void ac_ts_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
		// Cambiar el color de fondo del bot�n cuando el mouse entra
		//Cancela_Tanca->BackColor = System::Drawing::Color::Red; // Cambiar a cualquier color que desees
	}

		   // Manejador de eventos para el evento MouseLeave del bot�n
	private: System::Void ac_ts_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		// Restaurar el color de fondo del bot�n cuando el mouse sale
		//Cancela_Tanca->BackColor = System::Drawing::SystemColors::Control; // Puedes restaurarlo al color predeterminado del sistema
	}

	private: System::Void Cancela_Tanca_Click(System::Object^ sender, System::EventArgs^ e) {

		Accepta_Tanca->Visible = false;
		Cancela_Tanca->Visible = false;
		LabelTancaSessio->Visible = false;
		TancaSessioBox->Visible = false;

	}
	private: System::Void Accepta_Tanca_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();

	}


	private: System::Void Elimina_Click(System::Object^ sender, System::EventArgs^ e) {

		this->eliminar_compte_acceptar->Visible = true;
		this->cancelar_eliminar_compte->Visible = true;
		this->contrasenyaelimina->Visible = true;
		this->labelelimina->Visible = true;
		this->boxeliminar->Visible = true;

	}
	private: System::Void Consulta_Click(System::Object^ sender, System::EventArgs^ e) {

		//Redirigir al form de infoProp

		PetSalut::InfoProp^ infoProp = gcnew PetSalut::InfoProp();
		infoProp->Size = this->Size; 
		infoProp->Location = this->Location; 

		this->Visible = false;

		infoProp->ShowDialog();

		this->Visible = true;


	}
	private: System::Void Modifica_Click(System::Object^ sender, System::EventArgs^ e) {

		//Redirigir al form de modificaProp

		PetSalut::ModProp^ modProp = gcnew PetSalut::ModProp();

		// Set the size and position of IniUsu to match PantallaPrincipal
		modProp->Size = this->Size;
		modProp->Location = this->Location;

		this->Visible = false;

		modProp->ShowDialog();

		this->Visible = true;

	}
	private: System::Void Tanca_Click(System::Object^ sender, System::EventArgs^ e) {

		Accepta_Tanca->Visible = true;
		Cancela_Tanca->Visible = true;
		LabelTancaSessio->Visible = true;
		TancaSessioBox->Visible = true;

	}
	private: System::Void eliminar_compte_acceptar_Click(System::Object^ sender, System::EventArgs^ e) {

		//pedir la constrase�a al usuario
		//Pulsar aceptar 
		// En el boton de acceptar hacer lo siguiente (mas o menos):

		TxEsborraUsu esbU;

		try {
			esbU.crear(this->contrasenyaelimina->Text);
			esbU.executar();
			Ordinador^ ord = Ordinador::getInstance();
			ord->tancaSessio();
		}

		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}



		//Volver a la pagina principal
		this->Close();  // Cerrar el formulario actual (RegProp)


	}
	private: System::Void cancelar_eliminar_compte_Click(System::Object^ sender, System::EventArgs^ e) {

		this->boxeliminar->Visible = false;
		this->eliminar_compte_acceptar->Visible = false;
		this->cancelar_eliminar_compte->Visible = false;
		this->contrasenyaelimina->Visible = false;
		this->labelelimina->Visible = false;

	}
	private: System::Void PublicarEventButton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::CrearPublic^ creaPub = gcnew PetSalut::CrearPublic();
		// Set the size and position of IniUsu to match PantallaPrincipal
		creaPub->Size = this->Size;
		creaPub->Location = this->Location;
		this->Visible = false;

		creaPub->ShowDialog();

		this->Visible = true;

	}
	private: System::Void ConsultarMascotesButton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::ConsultaMascota_forms^ conMasc = gcnew PetSalut::ConsultaMascota_forms();
		// Set the size and position of IniUsu to match PantallaPrincipal
		conMasc->Size = this->Size;
		conMasc->Location = this->Location;

		this->Visible = false;

		conMasc->ShowDialog();

		this->Visible = true;

	}
	private: System::Void ProgramarVisitesButton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::CreaVisites_forms^ creaVisi = gcnew PetSalut::CreaVisites_forms();
		
		// Set the size and position of IniUsu to match PantallaPrincipal
		creaVisi->Size = this->Size;
		creaVisi->Location = this->Location;

		this->Visible = false;

		creaVisi->ShowDialog();

		this->Visible = true;

	}
	private: System::Void ConsultaVisitesButton_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::ConsultaVistes_forms^ conVisi = gcnew PetSalut::ConsultaVistes_forms();

		// Set the size and position of IniUsu to match PantallaPrincipal
		conVisi->Size = this->Size;
		conVisi->Location = this->Location;

		this->Visible = false;

		conVisi->ShowDialog();

		this->Visible = true;

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::ConsultarEvents^ conEvents = gcnew PetSalut::ConsultarEvents();

		// Set the size and position of IniUsu to match PantallaPrincipal
		conEvents->Size = this->Size;
		conEvents->Location = this->Location;

		this->Visible = false;

		conEvents->ShowDialog();

		this->Visible = true;

	}
	private: System::Void MenuProp_Load(System::Object^ sender, System::EventArgs^ e) {
		CercadoraPublic^ cpub = gcnew CercadoraPublic();
		Ordinador^ ord = Ordinador::getInstance();
		int searchIndex = ord->Index; // Reemplaza esto con el valor adecuado que deseas buscar
		int index_max = CercadoraPublic::maxIndex();
		try {
			PassarellaPublic^ ppub = cpub->cercaPublic(searchIndex);

			if (ppub != nullptr) {
				// Actualizar las etiquetas con los valores obtenidos
				tipusLabel->Text = ppub->Tipus;
				ubicacionLabel->Text = ppub->Ubicacio;
				descripcionLabel->Text = ppub->Descripcio;
				CercadoraEsdeveniments^ cesd = gcnew CercadoraEsdeveniments();
				PassarellaEsdeveniments^ pesd = cesd->cercaEsdeveniment(ppub->Numeroid);
				tituloLabel->Text = pesd->Nom;
				dataLabel->Text = pesd->Data.ToString();
				nombreLabel->Text = pesd->Propietari->ToString();


				paginasLabel->Text = String::Format("{0}/{1}", searchIndex, index_max);


				//logica de boton apuntat
				PassarellaUsuari^ pus = ord->obteUsuari();
				String^ username = pus->getUsername();
				CercadoraParticipa^ cpart = gcnew CercadoraParticipa();
				PassarellaParticipa^ ppart = cpart->cercaParticipa(ppub->Numeroid, username);
				if (ppart != nullptr) {
					//se cierra apuntarseButton
					apuntarseButton->Visible = false;
					//se abre apuntatButton
					apuntatButton->Visible = true;
				}
				else {

					// Se abre apuntarseButton
					apuntarseButton->Visible = true;
					// Se cierra apuntatButton
					apuntatButton->Visible = false;

				}
				//contar el numero de participants del evento
				int numParticipants = cpart->cuantosParticipa(ppub->Numeroid);
				participantsLabel->Text = numParticipants.ToString();

			}
			else {
				MessageBox::Show("No s'ha trobat l'esdeveniment amb l'índex especificat.");
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void seguentButton_Click(System::Object^ sender, System::EventArgs^ e) {
		Ordinador^ ord = Ordinador::getInstance();
		int index = ord->Index;
		int index_max = CercadoraPublic::maxIndex();
		if (index < index_max) index += 1;
		else {
			index = 1;
		}
		ord->Index = index;

		//AQUI ACTUALIZAR LAS LABELS PARA MOSTRAR EL SIGUIETNE

		MenuProp_Load(sender, e);

	}
	private: System::Void anteriorButton_Click(System::Object^ sender, System::EventArgs^ e) {

		Ordinador^ ord = Ordinador::getInstance();
		int index = ord->Index;
		int index_max = CercadoraPublic::maxIndex();
		if (index > 1) index -= 1;
		else {
			index = index_max;
		}
		ord->Index = index;

		MenuProp_Load(sender, e);

}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void apuntarseButton_Click(System::Object^ sender, System::EventArgs^ e) {
	TxCrearParticipa^ txCrear= gcnew TxCrearParticipa();
	txCrear->executar();

	
	MenuProp_Load(sender, e);
}
private: System::Void apuntatButton_Click(System::Object^ sender, System::EventArgs^ e) {
	TxEsborraParticipa^ txEsborra = gcnew TxEsborraParticipa();

	// Llamar al método executar en la instancia creada
	txEsborra->executar();
	MenuProp_Load(sender, e);
}
};
}