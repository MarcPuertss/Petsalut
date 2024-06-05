#pragma once
#include "PassarellaClinica.h"
#include "PassarellaCentre.h"
#include "PassarellaVisites.h"
#include "CercadoraVisita.h"
#include "CercadoraCentre.h"
#include "PassarellaEsdeveniments.h"
#include "CercadoraEsdeveniments.h"


namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;


	/// <summary>
	/// Resumen de ConsultaVisitesCentreForms
	/// </summary>
	public ref class ConsultaVisitesCentreForms : public System::Windows::Forms::Form
	{


	private:
		int centreId;
	public:
		//Declaració del BindingSource
		List<PassarellaCentre^>^ centresList = gcnew List<PassarellaCentre^>();
	private: System::Windows::Forms::ColumnHeader^ Hora;
	private: System::Windows::Forms::ColumnHeader^ Propietari;
	private: System::Windows::Forms::ColumnHeader^ Tipus;
	private: System::Windows::Forms::Label^ label1;
	public:

	public:
		//Declaració del BindingSource
		BindingSource^ bs = gcnew BindingSource();

		ConsultaVisitesCentreForms(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			bs->DataSource = centresList;
		}
		property int CentreId {
			int get() {
				return centreId;
			}
			void set(int value) {
				centreId = value;
			}
		}




	private: System::Windows::Forms::ColumnHeader^ Id;
	private: System::Windows::Forms::ColumnHeader^ Nom;
	private: System::Windows::Forms::ColumnHeader^ Data;


	private: System::Windows::Forms::ListBox^ visitesListBox;
	private: System::Windows::Forms::ListView^ visitesListView;
	private: System::Windows::Forms::Button^ tancarButton;





	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ConsultaVisitesCentreForms()
		{
			if (components)
			{
				delete components;
			}




		}

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConsultaVisitesCentreForms::typeid));
			this->visitesListBox = (gcnew System::Windows::Forms::ListBox());
			this->visitesListView = (gcnew System::Windows::Forms::ListView());
			this->Id = (gcnew System::Windows::Forms::ColumnHeader());
			this->Nom = (gcnew System::Windows::Forms::ColumnHeader());
			this->Data = (gcnew System::Windows::Forms::ColumnHeader());
			this->Hora = (gcnew System::Windows::Forms::ColumnHeader());
			this->Propietari = (gcnew System::Windows::Forms::ColumnHeader());
			this->Tipus = (gcnew System::Windows::Forms::ColumnHeader());
			this->tancarButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// visitesListBox
			// 
			this->visitesListBox->FormattingEnabled = true;
			this->visitesListBox->Location = System::Drawing::Point(260, 189);
			this->visitesListBox->Name = L"visitesListBox";
			this->visitesListBox->Size = System::Drawing::Size(163, 290);
			this->visitesListBox->TabIndex = 0;
			this->visitesListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &ConsultaVisitesCentreForms::visitesListBox_SelectedIndexChanged);
			// 
			// visitesListView
			// 
			this->visitesListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->Id, this->Nom,
					this->Data, this->Hora, this->Propietari, this->Tipus
			});
			this->visitesListView->HideSelection = false;
			this->visitesListView->Location = System::Drawing::Point(443, 189);
			this->visitesListView->Name = L"visitesListView";
			this->visitesListView->Size = System::Drawing::Size(562, 169);
			this->visitesListView->TabIndex = 1;
			this->visitesListView->UseCompatibleStateImageBehavior = false;
			this->visitesListView->View = System::Windows::Forms::View::Details;
			// 
			// Id
			// 
			this->Id->Text = L"ID";
			// 
			// Nom
			// 
			this->Nom->Text = L"Nom";
			this->Nom->Width = 163;
			// 
			// Data
			// 
			this->Data->Text = L"Data";
			this->Data->Width = 138;
			// 
			// Hora
			// 
			this->Hora->Text = L"Hora";
			// 
			// Propietari
			// 
			this->Propietari->Text = L"Propietari";
			this->Propietari->Width = 80;
			// 
			// Tipus
			// 
			this->Tipus->Text = L"Tipus";
			// 
			// tancarButton
			// 
			this->tancarButton->Location = System::Drawing::Point(47, 549);
			this->tancarButton->Name = L"tancarButton";
			this->tancarButton->Size = System::Drawing::Size(178, 70);
			this->tancarButton->TabIndex = 2;
			this->tancarButton->Text = L"Tanca";
			this->tancarButton->UseVisualStyleBackColor = true;
			this->tancarButton->Click += gcnew System::EventHandler(this, &ConsultaVisitesCentreForms::tancarButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(501, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(191, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Visites als Centres";
			// 
			// ConsultaVisitesCentreForms
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tancarButton);
			this->Controls->Add(this->visitesListView);
			this->Controls->Add(this->visitesListBox);
			this->Name = L"ConsultaVisitesCentreForms";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"ConsultaVisitesCentreForms";
			this->Load += gcnew System::EventHandler(this, &ConsultaVisitesCentreForms::ConsultaVisitesCentreForms_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void ConsultaVisitesCentreForms_Load(System::Object^ sender, System::EventArgs^ e) {
		//get Centre from centreId
		PassarellaCentre^ centre = CercadoraCentre::cercaCentre(centreId);

		//get visites from centre
		List<PassarellaVisites^>^ visites = CercadoraVisita::cercaVisites(centreId);

		//show visites
		if (visites != nullptr) {
			bs->ResetBindings(false);
			for each (PassarellaVisites ^ visita in visites) {
				visitesListBox->Items->Add(visita->Numero_ID);
			}
		}
	}

	private: System::Void visitesListBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		//get selected visita
		int numero_id = Convert::ToInt32(visitesListBox->SelectedItem);
		PassarellaEsdeveniments^ esdeveniment = CercadoraEsdeveniments::cercaEsdeveniment(numero_id);


		//  Convert SQL date format: "2024-06-16 19:12:36" to "16/06/2024"
		String^ data = esdeveniment->Data.ToString()->Substring(0, 10)->Replace("-", "/");


		//show visita
		visitesListView->Items->Clear();
		ListViewItem^ item = gcnew ListViewItem(esdeveniment->Numeroid.ToString());
		item->SubItems->Add(esdeveniment->Nom);
		item->SubItems->Add(data);
		item->SubItems->Add(esdeveniment->Hora->ToString());
		item->SubItems->Add(esdeveniment->Propietari->ToString());
		item->SubItems->Add(esdeveniment->Tipus);

		visitesListView->Items->Add(item);
	}
private: System::Void tancarButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
