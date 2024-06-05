#pragma once
#include "IniUsu.h"
#include "RegUsu.h"

namespace PetSalut {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// TEST GIT N� 1
	/// <summary>
	/// Summary for PantallaPrincipal
	/// </summary>
	public ref class PantallaPrincipal : public System::Windows::Forms::Form
	{
	public:
		PantallaPrincipal(void)
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
		~PantallaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;


	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PantallaPrincipal::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(471, 102);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(274, 62);
			this->label1->TabIndex = 0;
			this->label1->Text = L"PETSALUT";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->AutoSize = true;
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(468, 297);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(262, 45);
			this->button1->TabIndex = 1;
			this->button1->Text = L"INICIAR SESSIO";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &PantallaPrincipal::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->AutoSize = true;
			this->button2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(468, 369);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(262, 45);
			this->button2->TabIndex = 2;
			this->button2->Text = L"REGISTRAR-SE";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &PantallaPrincipal::button2_Click);
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Yu Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(351, 178);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(516, 25);
			this->label2->TabIndex = 3;
			this->label2->Text = L"La millor plataforma per a la salud de les teves mascotes";
			// 
			// PantallaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PantallaPrincipal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PETSALUT";
			this->Load += gcnew System::EventHandler(this, &PantallaPrincipal::PantallaPrincipal_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::IniUsu^ IniUsu = gcnew PetSalut::IniUsu();

		// Set the size and position of IniUsu to match PantallaPrincipal
		IniUsu->Size = this->Size;
		IniUsu->Location = this->Location;

		this->Visible = false;

		IniUsu->ShowDialog();

		this->Visible = true;

	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		PetSalut::RegUsu^ regUsu = gcnew PetSalut::RegUsu();

		// Set the size and position of IniUsu to match PantallaPrincipal
		regUsu->Size = this->Size;
		regUsu->Location = this->Location;

		this->Visible = false;

		regUsu->ShowDialog();

		this->Visible = true;

	}
	private: System::Void PantallaPrincipal_Load(System::Object^ sender, System::EventArgs^ e) {
	}

};
}