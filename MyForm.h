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
			Chanchito = new Cerdo(850, 100, 30, 30);
			Nivel1 = new Game_Manager();
			Wood1 = new Tile(900,500,20,80);
			Wood2 = new Tile(850,300, 80, 50);
			imgpollo_rojo = gcnew Bitmap("Pollo_rojo.png");
			imgpollo_azul = gcnew Bitmap("Pollo_azul.png");
			imgpollo_amarillo = gcnew Bitmap("Pollo_amarillo.png");

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
				delete imgpollo_amarillo;
				delete imgpollo_azul;
				delete imgpollo_rojo;
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
		Bitmap ^imgpollo_rojo;
		Bitmap ^imgpollo_amarillo;
		Bitmap ^imgpollo_azul;
		int mousex = 0;
		int mousey = 0;
		double auxangulo = 0;
		double tiempo = 0;
		bool habilidad_usar = false;
		bool pollo_moviendo = false;
		bool apuntando = false;
		Game_Manager* Nivel1;
		Graphics ^gr;
	private: System::Windows::Forms::Timer^  DeltaTime;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  PhysicsTime;

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
			this->PhysicsTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// DeltaTime
			// 
			this->DeltaTime->Enabled = true;
			this->DeltaTime->Interval = 60;
			this->DeltaTime->Tick += gcnew System::EventHandler(this, &MyForm::DeltaTime_Tick);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// PhysicsTime
			// 
			this->PhysicsTime->Enabled = true;
			this->PhysicsTime->Interval = 120;
			this->PhysicsTime->Tick += gcnew System::EventHandler(this, &MyForm::PhysicsTime_Tick);
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
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void DeltaTime_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^bgct = BufferedGraphicsManager::Current;
		BufferedGraphics^bg = bgct->Allocate(g, this->ClientRectangle);

		if (Nivel1->getN_Pollos() > 0 && !apuntando) {
			tiempo += 0.1;
			if (Nivel1->getpolloHabilidad()) {
				auxangulo = Nivel1->Calcular_distancia(mousex, mousey);
				Nivel1->Mover_pollos(tiempo, auxangulo);
				
			}
			else {
				Nivel1->Habilidad_pollo2();
			}
			Nivel1->Mostrar_pollos(bg->Graphics, imgpollo_rojo, imgpollo_amarillo, imgpollo_azul);
		}
		else
			tiempo = 0;
		if (Nivel1->getN_Pollos() > 0) {
			if (Nivel1->getPolloy() == 600 - 48)
			{
				pollo_moviendo = false;
			}
		}
		if (apuntando)
		{
			Nivel1->Pollo_en_resortera(mousex, mousey);
			Nivel1->Mostrar_pollos(bg->Graphics, imgpollo_rojo, imgpollo_amarillo, imgpollo_azul);
			Nivel1->Mostrar_resortera_liga(bg->Graphics, mousex, mousey);
			Nivel1->SetpolloAngulo(Nivel1->Calcular_angulo(mousex, mousey));
		}
		g->FillEllipse(gcnew System::Drawing::SolidBrush(System::Drawing::Color::Green), 100, 500, 20, 20);
		Wood1->Mover(bg->Graphics);
		Wood2->Mover(bg->Graphics);
		Chanchito->Mover(bg->Graphics);
		Wood1->Mostrar(bg->Graphics);
		Wood2->Mostrar(bg->Graphics);
		Chanchito->Mostrar(bg->Graphics);
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
		if (pollo_moviendo && habilidad_usar)
			 {
			Nivel1->Nuevo_angulo(tiempo, auxangulo);
			Nivel1->Habilidad_pollo();
			habilidad_usar = false;
			}
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	/*if (pollo_moviendo)
		tiempo++;
	else
		tiempo = 0;*/
}
	private: System::Void MyForm_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (apuntando) {
			mousey = e->Y;
			mousex = e->X;
			if (mousex > 220)
				mousex = 200;
			if (mousey > 600 - 24)
				mousey = 600 - 25;
			if (mousey < 400)
				mousey = 400;
			apuntando = false;
			habilidad_usar = true;
		}
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
private: System::Void PhysicsTime_Tick(System::Object^  sender, System::EventArgs^  e) {
	Nivel1->CheckImpact();
	Nivel1->KillEnemy();
	Nivel1->CheckColision();
	Nivel1->CheckColisionC();
}
private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (apuntando) {
		mousey = e->Y;
		mousex = e->X;
		if (mousex > 220)
			mousex = 200;
		if (mousey > 600 - 24)
			mousey = 600 - 25;
		if (mousey < 400)
			mousey = 400;
	}
}
private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (pollo_moviendo == false || Nivel1->getN_Pollos() < 1) {
		apuntando = true;
		pollo_moviendo = true;
		mousey = e->Y;
		mousex = e->X;
		if (mousex > 220)
			mousex = 200;
		if (mousey > 600 - 24)
			mousey = 600 - 25;
		if (mousey < 400)
			mousey = 400;
		//Pollo_azul*repoio = new Pollo_azul(mousex, mousey);
		Pollo_amarillo*repoio = new Pollo_amarillo(mousex, mousey);
		Nivel1->Insertar_Pollo(repoio);
	}
}
};
}
