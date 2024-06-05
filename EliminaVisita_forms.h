#include "PassarellaVisites.h"
#include "TxConsultarVisites.h"
#include "CercadoraVisita.h"
#include "TxConsultarMascotes.h"
#include "CercadoraMascota.h"
#include "CercadoraVisita.h"
#include "CercadoraPropietari.h"
#include "Ordinador.h"
#include "PassarellaVisites.h"
#include "CercadoraEsdeveniments.h"
#include "PassarellaEsdeveniments.h"
#include "TxEliminaVisita.h"
#include "TxEliminarValoracio.h"
#pragma once

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de EliminaVisita_forms
	/// </summary>
	public ref class EliminaVisita_forms : public System::Windows::Forms::Form
	{
	public:
		EliminaVisita_forms(void)
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
		~EliminaVisita_forms()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelElimina;
	protected:

	private: System::Windows::Forms::ComboBox^ visitaList;
	private: System::Windows::Forms::Button^ exitbutton;
	protected:


	private: System::Windows::Forms::Label^ titlelabel;

	private: System::Windows::Forms::Button^ eliminabutton;

	private: System::Windows::Forms::ComboBox^ petsList;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ mascotalabel;


	private: System::Windows::Forms::Label^ questionlabel;


	private: System::Void eliminabutton_Click(System::Object^ sender, System::EventArgs^ e) {
		
		if (visitaList->SelectedItem != nullptr) {

			String^ visitaSeleccionada = visitaList->SelectedItem->ToString();
			int indiceParentesisAbierto = visitaSeleccionada->IndexOf('(');
			int indiceParentesisCerrado = visitaSeleccionada->IndexOf(')');
			String^ idString = visitaSeleccionada->Substring(indiceParentesisAbierto + 1, indiceParentesisCerrado - indiceParentesisAbierto - 1);
			int id = Int32::Parse(idString);
			CercadoraVisita^ cercadorav = gcnew CercadoraVisita();
			PassarellaVisites^ visita = cercadorav->cercaVisita(id);
			int idcentre = visita->Centre;
			TxEliminaValoracio^ elimValoracio = TxEliminaValoracio::crear();
			elimValoracio->ejecutar(idcentre, id);
			TxEliminaVisita^ elimVisita = TxEliminaVisita::crear();
			elimVisita->ejecutar(id);
			this->Close();
		}
		
	}
	private: System::Void exitbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void visitalist_click(System::Object^ sender, System::EventArgs^ e) {
		//MessageBox::Show("LLEGA");
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

	private: System::Void consultar_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//	MessageBox::Show("LLEGA");
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EliminaVisita_forms::typeid));
			this->panelElimina = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mascotalabel = (gcnew System::Windows::Forms::Label());
			this->petsList = (gcnew System::Windows::Forms::ComboBox());
			this->visitaList = (gcnew System::Windows::Forms::ComboBox());
			this->exitbutton = (gcnew System::Windows::Forms::Button());
			this->titlelabel = (gcnew System::Windows::Forms::Label());
			this->eliminabutton = (gcnew System::Windows::Forms::Button());
			this->questionlabel = (gcnew System::Windows::Forms::Label());
			this->panelElimina->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelElimina
			// 
			this->panelElimina->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panelElimina->BackColor = System::Drawing::SystemColors::Control;
			this->panelElimina->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelElimina->Controls->Add(this->label1);
			this->panelElimina->Controls->Add(this->mascotalabel);
			this->panelElimina->Controls->Add(this->petsList);
			this->panelElimina->Controls->Add(this->visitaList);
			this->panelElimina->Controls->Add(this->exitbutton);
			this->panelElimina->Controls->Add(this->titlelabel);
			this->panelElimina->Controls->Add(this->eliminabutton);
			this->panelElimina->Controls->Add(this->questionlabel);
			this->panelElimina->Location = System::Drawing::Point(78, 100);
			this->panelElimina->Name = L"panelElimina";
			this->panelElimina->Size = System::Drawing::Size(1028, 460);
			this->panelElimina->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->label1->Location = System::Drawing::Point(278, 232);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 19);
			this->label1->TabIndex = 17;
			this->label1->Text = L"Visita:";
			// 
			// mascotalabel
			// 
			this->mascotalabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->mascotalabel->AutoSize = true;
			this->mascotalabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->mascotalabel->Location = System::Drawing::Point(258, 159);
			this->mascotalabel->Name = L"mascotalabel";
			this->mascotalabel->Size = System::Drawing::Size(79, 19);
			this->mascotalabel->TabIndex = 16;
			this->mascotalabel->Text = L"Mascota:";
			// 
			// petsList
			// 
			this->petsList->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->petsList->FormattingEnabled = true;
			this->petsList->Location = System::Drawing::Point(343, 156);
			this->petsList->Name = L"petsList";
			this->petsList->Size = System::Drawing::Size(334, 27);
			this->petsList->TabIndex = 15;
			this->petsList->Click += gcnew System::EventHandler(this, &EliminaVisita_forms::consultar_Click);
			// 
			// visitaList
			// 
			this->visitaList->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 9.75F));
			this->visitaList->FormattingEnabled = true;
			this->visitaList->Location = System::Drawing::Point(343, 229);
			this->visitaList->Name = L"visitaList";
			this->visitaList->Size = System::Drawing::Size(334, 27);
			this->visitaList->TabIndex = 14;
			this->visitaList->Click += gcnew System::EventHandler(this, &EliminaVisita_forms::visitalist_click);
			// 
			// exitbutton
			// 
			this->exitbutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->exitbutton->BackColor = System::Drawing::Color::Firebrick;
			this->exitbutton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->exitbutton->Location = System::Drawing::Point(988, 7);
			this->exitbutton->Name = L"exitbutton";
			this->exitbutton->Size = System::Drawing::Size(35, 32);
			this->exitbutton->TabIndex = 13;
			this->exitbutton->Text = L"X";
			this->exitbutton->UseVisualStyleBackColor = false;
			this->exitbutton->Click += gcnew System::EventHandler(this, &EliminaVisita_forms::exitbutton_Click);
			// 
			// titlelabel
			// 
			this->titlelabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->titlelabel->AutoSize = true;
			this->titlelabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->titlelabel->Location = System::Drawing::Point(397, 42);
			this->titlelabel->Name = L"titlelabel";
			this->titlelabel->Size = System::Drawing::Size(216, 26);
			this->titlelabel->TabIndex = 11;
			this->titlelabel->Text = L"ELIMINAR VISITA";
			// 
			// eliminabutton
			// 
			this->eliminabutton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->eliminabutton->BackColor = System::Drawing::Color::IndianRed;
			this->eliminabutton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14.25F));
			this->eliminabutton->Location = System::Drawing::Point(385, 312);
			this->eliminabutton->Name = L"eliminabutton";
			this->eliminabutton->Size = System::Drawing::Size(255, 76);
			this->eliminabutton->TabIndex = 10;
			this->eliminabutton->Text = L"ELIMINAR";
			this->eliminabutton->UseVisualStyleBackColor = false;
			this->eliminabutton->Click += gcnew System::EventHandler(this, &EliminaVisita_forms::eliminabutton_Click);
			// 
			// questionlabel
			// 
			this->questionlabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->questionlabel->AutoSize = true;
			this->questionlabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 11));
			this->questionlabel->Location = System::Drawing::Point(371, 87);
			this->questionlabel->Name = L"questionlabel";
			this->questionlabel->Size = System::Drawing::Size(269, 20);
			this->questionlabel->TabIndex = 3;
			this->questionlabel->Text = L"Quina Visita vols ELIMINAR\?";
			this->questionlabel->Click += gcnew System::EventHandler(this, &EliminaVisita_forms::label1_Click);
			// 
			// EliminaVisita_forms
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->panelElimina);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"EliminaVisita_forms";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->panelElimina->ResumeLayout(false);
			this->panelElimina->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void visitaList_click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
