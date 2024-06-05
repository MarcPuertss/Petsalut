#pragma once

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ConsultarEvents
	/// </summary>
	public ref class ConsultarEvents : public System::Windows::Forms::Form
	{
	public:
		ConsultarEvents(void)
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
		~ConsultarEvents()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ centresListBox;
	private: System::Windows::Forms::Button^ tornarButton;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ descripcioLabel;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ titolLabel;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ organizadorLabel;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ UbicacioLabel;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ eliminarAsistencia;

	private: System::Windows::Forms::Label^ dataLabel;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ horaLabel;
	private: System::Windows::Forms::Label^ label9;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ConsultarEvents::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->centresListBox = (gcnew System::Windows::Forms::ListBox());
			this->tornarButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->horaLabel = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->dataLabel = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->UbicacioLabel = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->organizadorLabel = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->descripcioLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->titolLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->eliminarAsistencia = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 28));
			this->label2->Location = System::Drawing::Point(455, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(262, 54);
			this->label2->TabIndex = 4;
			this->label2->Text = L"PETSALUT";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 20));
			this->label1->Location = System::Drawing::Point(372, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(433, 39);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Consultar Events Publics";
			// 
			// centresListBox
			// 
			this->centresListBox->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->centresListBox->FormattingEnabled = true;
			this->centresListBox->ItemHeight = 26;
			this->centresListBox->Location = System::Drawing::Point(26, 142);
			this->centresListBox->Name = L"centresListBox";
			this->centresListBox->Size = System::Drawing::Size(411, 420);
			this->centresListBox->TabIndex = 5;
			// 
			// tornarButton
			// 
			this->tornarButton->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->tornarButton->Location = System::Drawing::Point(26, 568);
			this->tornarButton->Name = L"tornarButton";
			this->tornarButton->Size = System::Drawing::Size(177, 76);
			this->tornarButton->TabIndex = 12;
			this->tornarButton->Text = L"Tornar";
			this->tornarButton->UseVisualStyleBackColor = true;
			this->tornarButton->Click += gcnew System::EventHandler(this, &ConsultarEvents::tornarButton_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Controls->Add(this->horaLabel);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->dataLabel);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->UbicacioLabel);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->organizadorLabel);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->descripcioLabel);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->titolLabel);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(488, 142);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(656, 420);
			this->panel1->TabIndex = 13;
			// 
			// horaLabel
			// 
			this->horaLabel->AutoSize = true;
			this->horaLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->horaLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->horaLabel->Location = System::Drawing::Point(355, 205);
			this->horaLabel->Name = L"horaLabel";
			this->horaLabel->Size = System::Drawing::Size(103, 23);
			this->horaLabel->TabIndex = 25;
			this->horaLabel->Text = L"Data aqui";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label9->Location = System::Drawing::Point(355, 179);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(70, 26);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Hora";
			// 
			// dataLabel
			// 
			this->dataLabel->AutoSize = true;
			this->dataLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->dataLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->dataLabel->Location = System::Drawing::Point(355, 129);
			this->dataLabel->Name = L"dataLabel";
			this->dataLabel->Size = System::Drawing::Size(103, 23);
			this->dataLabel->TabIndex = 23;
			this->dataLabel->Text = L"Data aqui";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label7->Location = System::Drawing::Point(355, 103);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(66, 26);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Data";
			// 
			// UbicacioLabel
			// 
			this->UbicacioLabel->AutoSize = true;
			this->UbicacioLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->UbicacioLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->UbicacioLabel->Location = System::Drawing::Point(356, 46);
			this->UbicacioLabel->Name = L"UbicacioLabel";
			this->UbicacioLabel->Size = System::Drawing::Size(155, 23);
			this->UbicacioLabel->TabIndex = 21;
			this->UbicacioLabel->Text = L"Ubicacion aqui";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label5->Location = System::Drawing::Point(355, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 26);
			this->label5->TabIndex = 20;
			this->label5->Text = L"Ubicacio";
			// 
			// organizadorLabel
			// 
			this->organizadorLabel->AutoSize = true;
			this->organizadorLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->organizadorLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->organizadorLabel->Location = System::Drawing::Point(14, 46);
			this->organizadorLabel->Name = L"organizadorLabel";
			this->organizadorLabel->Size = System::Drawing::Size(183, 23);
			this->organizadorLabel->TabIndex = 19;
			this->organizadorLabel->Text = L"Organizador aqui";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label8->Location = System::Drawing::Point(13, 20);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(169, 26);
			this->label8->TabIndex = 18;
			this->label8->Text = L"Organitzador";
			// 
			// descripcioLabel
			// 
			this->descripcioLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->descripcioLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->descripcioLabel->Location = System::Drawing::Point(14, 205);
			this->descripcioLabel->Name = L"descripcioLabel";
			this->descripcioLabel->Size = System::Drawing::Size(335, 190);
			this->descripcioLabel->TabIndex = 17;
			this->descripcioLabel->Text = L"Descripcion aqui";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label6->Location = System::Drawing::Point(13, 179);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(135, 26);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Descripcio";
			// 
			// titolLabel
			// 
			this->titolLabel->AutoSize = true;
			this->titolLabel->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 12));
			this->titolLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->titolLabel->Location = System::Drawing::Point(14, 129);
			this->titolLabel->Name = L"titolLabel";
			this->titolLabel->Size = System::Drawing::Size(102, 23);
			this->titolLabel->TabIndex = 15;
			this->titolLabel->Text = L"Titol aqui";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->label3->Location = System::Drawing::Point(13, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 26);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Titol";
			// 
			// eliminarAsistencia
			// 
			this->eliminarAsistencia->BackColor = System::Drawing::Color::IndianRed;
			this->eliminarAsistencia->Font = (gcnew System::Drawing::Font(L"Gill Sans Ultra Bold", 14));
			this->eliminarAsistencia->Location = System::Drawing::Point(935, 568);
			this->eliminarAsistencia->Name = L"eliminarAsistencia";
			this->eliminarAsistencia->Size = System::Drawing::Size(209, 76);
			this->eliminarAsistencia->TabIndex = 14;
			this->eliminarAsistencia->Text = L"Desapuntrar-se";
			this->eliminarAsistencia->UseVisualStyleBackColor = false;
			this->eliminarAsistencia->Click += gcnew System::EventHandler(this, &ConsultarEvents::eliminarAsistencia_Click);
			// 
			// ConsultarEvents
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->eliminarAsistencia);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tornarButton);
			this->Controls->Add(this->centresListBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ConsultarEvents";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"PETSALUT";
			this->Load += gcnew System::EventHandler(this, &ConsultarEvents::ConsultarEvents_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void tornarButton_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Close();

}
private: System::Void eliminarAsistencia_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void ConsultarEvents_Load(System::Object^ sender, System::EventArgs^ e) {

	//Aqui actualizar la caja con la info de asistencia

}
};
}
