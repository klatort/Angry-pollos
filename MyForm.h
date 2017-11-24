#pragma once
#include "Game_Manager.h"
#include "Juego.h"
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
			Game = new Juego();
			Nivel_Actual = new int;
			*Nivel_Actual = 1;
			Nivel1 = new Game_Manager();
			Nivel2 = new Game_Manager();
			Tile1_1 = new Tile_madera(700, 500, 20, 80);
			Tile1_2 = new Tile_madera(760, 500, 20, 80);
			Tile1_3 = new Tile_madera(700, 300, 80, 20);
			Tile1_4 = new Tile_madera(750, 250, 20, 80);
			Tile1_5 = new Tile_madera(700, 150, 80, 20);

			Chancho1_1 = new Cerdo_desnudo(700, 200, 30, 30);
			Chancho1_2 = new Cerdo_desnudo(780, 200, 30, 30);


			Tile2_1 = new Tile_madera(700, 500, 20, 80);
			Tile2_2 = new Tile_roca(750, 500, 20, 80);//Roca
			Tile2_3 = new Tile_madera(780, 500, 20, 80);
			Tile2_4 = new Tile_madera(700, 400, 80, 20);
			Tile2_5 = new Tile_glass(780, 400, 80, 20);//Glass
			Tile2_6 = new Tile_madera(800, 500, 20, 80);

			Chancho2_1 = new Cerdo_desnudo(710, 500, 30, 30);
			Chancho2_2 = new Cerdo_desnudo(760, 500, 30, 30);


			Tile3_1 = new Tile_madera(600, 500, 20, 80);
			Tile3_2 = new Tile_glass(600, 400, 80, 20);//Glass
			Tile3_3 = new Tile_madera(680, 500, 20, 80);
			Tile3_4 = new Tile_glass(680, 400, 80, 20);//Glass
			Tile3_5 = new Tile_madera(760, 500, 20, 80);
			Tile3_6 = new Tile_glass(760, 400, 80, 20);//Glass

			Chancho3_1 = new Cerdo_desnudo(640, 500, 30, 30);
			Chancho3_2 = new Cerdo_desnudo(720, 500, 30, 30);
			Chancho3_3 = new Cerdo_casco(800, 500, 30, 30);//Cascod

			//Poner la resortera un poquito mas arriba

			Tile4_1 = new Tile_madera(600, 500, 20, 80);
			Tile4_2 = new Tile_madera(600, 400, 80, 20);
			Tile4_3 = new Tile_roca(680, 500, 20, 80);//Roca
			Tile4_4 = new Tile_madera(760, 500, 20, 80);
			Tile4_5 = new Tile_madera(720, 400, 80, 20);

			Chancho4_1 = new Cerdo_desnudo(640, 500, 30, 30);
			Chancho4_2 = new Cerdo_desnudo(700, 500, 30, 30);
			Chancho4_3 = new Cerdo_desnudo(800, 500, 30, 30);

			Tile5_1 = new Tile_madera(500, 500, 20, 80);
			Tile5_2 = new Tile_madera(540, 400, 80, 20);
			Tile5_3 = new Tile_madera(600, 500, 20, 80);
			Tile5_4 = new Tile_madera(600, 400, 20, 20);
			Tile5_5 = new Tile_madera(600, 300, 20, 80);

			Chancho5_1 = new Cerdo_desnudo(540, 350, 30, 30);
			Chancho5_2 = new Cerdo_desnudo(560, 500, 30, 30);
			Chancho5_3 = new Cerdo_desnudo(700, 500, 30, 30);
			Chancho5_4 = new Cerdo_casco(750, 500, 30, 30);//Casco

			Tile6_1 = new Tile_madera(600, 400, 20, 20);
			Tile6_3 = new Tile_glass(600, 300, 20, 80);//Glass
			Tile6_4 = new Tile_madera(600, 200, 20, 20);
			Tile6_5 = new Tile_madera(700, 500, 20, 80);
			Tile6_6 = new Tile_madera(740, 400, 80, 20);

			Chancho6_1 = new Cerdo_casco(660, 500, 30, 30);//Casco
			Chancho6_2 = new Cerdo_casco(720, 500, 30, 30);//Casco
			Chancho6_3 = new Cerdo_casco(740, 350, 30, 30);//Casco

			imgpollo_rojo = gcnew Bitmap("Pollo_rojo.png");
			imgpollo_azul = gcnew Bitmap("Pollo_azul.png");
			imgpollo_amarillo = gcnew Bitmap("Pollo_amarillo.png");
			textura_madera = gcnew Bitmap("Textura_madera.png");
			textura_roca = gcnew Bitmap("Textura_roca.png");
			textura_glass = gcnew Bitmap("Textura_glass.png");
			imgcerdo = gcnew Bitmap("Cerdo.png");
			imgresortera = gcnew Bitmap("Resortera.png");
			imgcerdo_casco = gcnew Bitmap("Cerdo_casco.png");
			fondo = gcnew Bitmap("Fondo.png");
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
				delete fondo;
				delete textura_roca;
				delete textura_glass;
				delete imgcerdo_casco;
				delete Nivel_Actual;
				delete imgresortera;
				delete imgcerdo;
				delete textura_madera;
				delete imgpollo_amarillo;
				delete imgpollo_azul;
				delete imgpollo_rojo;
				delete Tile1_1, Tile1_2, Tile1_3, Tile1_4, Tile1_5, Tile2_1, Tile2_2, Tile2_3, Tile2_4, Tile2_5, Tile2_6, Tile3_1, Tile3_2, Tile3_3, Tile3_4, Tile3_5, Tile3_6, Tile4_1, Tile4_2, Tile4_3, Tile4_4, Tile4_5, Tile5_1, Tile5_2, Tile5_3, Tile5_4, Tile5_5, Tile5_6, Tile6_1, Tile6_2, Tile6_3, Tile6_4, Tile6_5, Tile6_6;
				delete Chancho1_1, Chancho1_2, Chancho2_1, Chancho2_2, Chancho3_1, Chancho3_2, Chancho3_3, Chancho4_1, Chancho4_2, Chancho4_3, Chancho5_1, Chancho5_2, Chancho5_3, Chancho6_1, Chancho6_2, Chancho6_3;
				delete Nivel1, Nivel2;
				delete components;
				delete Game;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Juego* Game;
		Tile *Tile1_1, *Tile1_2, *Tile1_3, *Tile1_4, *Tile1_5, *Tile2_1, *Tile2_2, *Tile2_3, *Tile2_4, *Tile2_5, *Tile2_6, *Tile3_1, *Tile3_2, *Tile3_3, *Tile3_4, *Tile3_5, *Tile3_6, *Tile4_1, *Tile4_2, *Tile4_3, *Tile4_4, *Tile4_5, *Tile5_1, *Tile5_2, *Tile5_3, *Tile5_4, *Tile5_5, *Tile5_6, *Tile6_1, *Tile6_2, *Tile6_3, *Tile6_4, *Tile6_5, *Tile6_6;
		Cerdo *Chancho1_1, *Chancho1_2, *Chancho2_1, *Chancho2_2, *Chancho3_1, *Chancho3_2, *Chancho3_3, *Chancho4_1, *Chancho4_2, *Chancho4_3, *Chancho5_1, *Chancho5_2, *Chancho5_3, *Chancho5_4, *Chancho6_1, *Chancho6_2, *Chancho6_3;
		Bitmap ^imgpollo_rojo;
		Bitmap ^imgpollo_amarillo;
		Bitmap ^imgpollo_azul;
		Bitmap ^textura_madera;
		Bitmap ^textura_glass;
		Bitmap ^textura_roca;
		Bitmap ^imgcerdo;
		Bitmap ^imgcerdo_casco;
		Bitmap ^imgresortera;
		Bitmap ^fondo;
		int mousex = 0;
		int mousey = 0;
		int tiempo_real = 0;
		double auxangulo = 0;
		double tiempo = 0;
		int* Nivel_Actual;
		bool fin_turno = false;
		bool habilidad_usar = false;
		bool pollo_moviendo = false;
		bool apuntando = false;
		Game_Manager* Nivel1, *Nivel2;
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
			this->PhysicsTime->Interval = 1;
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
		Game->GetNivel()[*Nivel_Actual - 1]->Mostrar_fondo(bg->Graphics,fondo);
		Game->GetNivel()[*Nivel_Actual - 1]->Mover_Tiles();
		Game->GetNivel()[*Nivel_Actual - 1]->Mover_Cerdos();
		Game->GetNivel()[*Nivel_Actual - 1]->Mostrar_Tiles(bg->Graphics,textura_madera);
		Game->GetNivel()[*Nivel_Actual - 1]->Mostrar_Cerdos(bg->Graphics, imgcerdo,imgcerdo_casco;);
		if (Game->GetNivel()[*Nivel_Actual-1]->getN_Pollos() > 0 && apuntando == false&&habilidad_usar) {
			tiempo += 0.1;
			if (Game->GetNivel()[*Nivel_Actual-1]->getpolloHabilidad_ultimo()) {
				Game->GetNivel()[*Nivel_Actual-1]->Mover_pollos(tiempo, auxangulo);	
			}
			else {
				Game->GetNivel()[*Nivel_Actual-1]->Habilidad_pollo2();
			}
			pollo_moviendo = true;
		}
		else
			tiempo = 0;
		if (Game->GetNivel()[*Nivel_Actual-1]->getN_Pollos() > 0) {
			
			int pollos_reposo = 0;
			for (int i = 0; i < Game->GetNivel()[*Nivel_Actual-1]->getN_Pollos(); i++) {
				if (Game->GetNivel()[*Nivel_Actual-1]->getPolloy(i) == 552)
				{
					pollos_reposo++;
				}
				if (Game->GetNivel()[*Nivel_Actual-1]->Pollo_desaparece(g,i)) {
					pollos_reposo = pollos_reposo + 1;
				}
			}
			if (pollos_reposo == Game->GetNivel()[*Nivel_Actual-1]->getN_Pollos() && pollo_moviendo == true)
			{
				pollo_moviendo = false;
				habilidad_usar = false;
				fin_turno = true;
			}
		}
		if (apuntando)
		{
			Game->GetNivel()[*Nivel_Actual-1]->Pollo_en_resortera(mousex, mousey);
			Game->GetNivel()[*Nivel_Actual-1]->Mostrar_resortera_liga(bg->Graphics, mousex, mousey);
			Game->GetNivel()[*Nivel_Actual-1]->SetpolloAngulo(Game->GetNivel()[*Nivel_Actual-1]->Calcular_angulo(mousex, mousey));
			auxangulo = Game->GetNivel()[*Nivel_Actual-1]->Calcular_distancia(mousex, mousey);
		}
		Game->GetNivel()[*Nivel_Actual-1]->Mostrar_pollos(bg->Graphics, imgpollo_rojo, imgpollo_amarillo, imgpollo_azul);
		Game->GetNivel()[*Nivel_Actual-1]->Mostrar_resortera(bg->Graphics,imgresortera);
		bg->Render(g);
		delete bg;
		delete bgct;
		delete g;
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Nivel1->Insertar_Tile(Tile1_1);
		Nivel1->Insertar_Tile(Tile1_2);
		Nivel1->Insertar_Tile(Tile1_3);
		Nivel1->Insertar_Tile(Tile1_4);
		Nivel1->Insertar_Tile(Tile1_5);

		Nivel1->Insertar_Cerdos(Chancho1_1);
		Nivel1->Insertar_Cerdos(Chancho1_2);


		Nivel2->Insertar_Tile(Tile2_1);
		Nivel2->Insertar_Tile(Tile2_2);
		Nivel2->Insertar_Tile(Tile2_3);
		Nivel2->Insertar_Tile(Tile2_4);
		Nivel2->Insertar_Tile(Tile2_5);
		Nivel2->Insertar_Tile(Tile2_6);

		Nivel2->Insertar_Cerdos(Chancho2_1);
		Nivel2->Insertar_Cerdos(Chancho2_2);
	Pollo_azul*repoio = new Pollo_azul(50, 576);
	Pollo_amarillo*repoiox2 = new Pollo_amarillo(30, 576);
	Pollo_rojo*repoiox3 = new Pollo_rojo(10, 576);

	Nivel1->Insertar_Pollo(repoiox2);
	Nivel1->Insertar_Pollo(repoio);
	Nivel1->Insertar_Pollo(repoiox3);

	}
	private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (pollo_moviendo && Game->GetNivel()[*Nivel_Actual-1]->getpolloHabilidad_ultimo())
			 {
			Game->GetNivel()[*Nivel_Actual-1]->Habilidad_pollo();
			if(Game->GetNivel()[*Nivel_Actual-1]->getpolloHabilidad_ultimo()==false)
				Game->GetNivel()[*Nivel_Actual-1]->Nuevo_angulo(tiempo, auxangulo);
			}
	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (fin_turno)
		tiempo_real++;
	if (tiempo_real == 3)
	{
		int kk = 0;
		for (int i = 0; i < Game->GetNivel()[*Nivel_Actual-1]->getN_Pollos(); i++) {
			if (Game->GetNivel()[*Nivel_Actual-1]->getpolloHabilidad(i) == false)
			{
				kk++;
			}
		}
		for (int i = 0; i < kk; i++) {
			Game->GetNivel()[*Nivel_Actual-1]->Eliminar_test();
		}
		tiempo_real = 0;
		fin_turno = false;
	}
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
	case Keys::C:	if (Game->GetNivel()[*Nivel_Actual-1]->getN_Pollos() > 0)
		Game->GetNivel()[*Nivel_Actual-1]->Eliminar_test(); break;
	default:
		break;
	}
}
private: System::Void PhysicsTime_Tick(System::Object^  sender, System::EventArgs^  e) {
	Game->GetNivel()[*Nivel_Actual-1]->CheckImpact();
	Game->GetNivel()[*Nivel_Actual-1]->KillEnemy();
	Game->GetNivel()[*Nivel_Actual-1]->CheckColision();
	Game->GetNivel()[*Nivel_Actual-1]->CheckColisionC();

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
	if (fin_turno == false && pollo_moviendo == false && Game->GetNivel()[*Nivel_Actual-1]->getN_Pollos() > 0&&apuntando ==false) {
		apuntando = true;
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
};
}
