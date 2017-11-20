#pragma once
#include "Game_Manager.h"
namespace WindowsForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			Nivel1 = new Game_Manager();
			Wood1 = new Tile(1000,500,20,80);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete Wood1;
				delete Nivel1;
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Tile* Wood1;
		Game_Manager* Nivel1;
	private: System::Windows::Forms::Timer^  DeltaTime;

	private: System::ComponentModel::IContainer^  components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->DeltaTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// DeltaTime
			// 
			this->DeltaTime->Enabled = true;
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &MyForm::DeltaTime_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^bgct = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bgct->Allocate(g, this->ClientRectangle);
		Nivel1->bolita->Mover(bg->Graphics);
		Wood1->Mover(bg->Graphics);
	//	Nivel1->CheckImpact();
		bg->Render(g);
		delete bg;
		delete bgct;
		delete g;
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
//	Nivel1->Insertar_Tile(Wood1);
	}
	};
}
