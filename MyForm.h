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
			Chanchito = new Cerdo(950, 200, 30, 30);
			Nivel1 = new Game_Manager();
			Wood1 = new Tile(1000,500,20,80);
			Wood2 = new Tile(950, 300, 80, 20);
			gr = CreateGraphics();
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
				delete Chanchito;
				delete Wood1;
				delete Wood2;
				delete Nivel1;
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Tile* Wood1;
		Tile* Wood2;
		Cerdo* Chanchito;
		int mousex = 0;
		int mousey = 0;
		double tiempo = 0;
		bool pollo_moviendo = true;
		Game_Manager* Nivel1;
		Graphics ^gr;
	private: System::Windows::Forms::Timer^  DeltaTime;
	private: System::Windows::Forms::Timer^  timer1;

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
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// DeltaTime
			// 
			this->DeltaTime->Enabled = true;
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &MyForm::DeltaTime_Tick);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
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
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^bgct = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bgct->Allocate(g, this->ClientRectangle);

		if (Nivel1->getN_Pollos() > 0) {
			tiempo += 0.1;
			Nivel1->Mover_pollos(bg->Graphics, Nivel1->Calcular_angulo(mousex, mousey), tiempo, Nivel1->Calcular_distancia(mousex, mousey));
		}
		else
			tiempo = 0;
		g->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green), 100, 500, 20, 20);
		Wood1->Mover(bg->Graphics);
		Wood2->Mover(bg->Graphics);
		Chanchito->Mover(bg->Graphics);
		Wood1->Mostrar(bg->Graphics);
		Wood2->Mostrar(bg->Graphics);
		Chanchito->Mostrar(bg->Graphics);
		Nivel1->CheckImpact();
		Nivel1->KillEnemy();
		Nivel1->CheckColision();
		Nivel1->CheckColisionC();
		Nivel1->Pollo_desaparece(bg->Graphics);
		Nivel1->Mostrar_resortera(bg->Graphics);
		bg->Render(g);
		delete bg;
		delete bgct;
		delete g;
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	Nivel1->Insertar_Tile(Wood1);
	Nivel1->Insertar_Tile(Wood2);
	Nivel1->Insertar_Cerdos(Chanchito);

	}
	private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Pollo* repoio = new Pollo();
		Nivel1->Insertar_Pollo(repoio);
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	/*if (pollo_moviendo)
		tiempo++;
	else
		tiempo = 0;*/
}
private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	mousey = e->Y;
	mousex = e->X;
}

private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	switch (e->KeyCode)
	{
	case Keys::C:	if (Nivel1->getN_Pollos() > 0)
		Nivel1->Eliminar_test(); break;
	default:
		break;
	}
}
};
}
