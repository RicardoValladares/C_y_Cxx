#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Float_Input.H>
#include <FL/Fl_Output.H>
#include <FL/fl_ask.H>
#include <string>

using namespace std;

/* clase Ventana, se declaran los objetos para interfaz grafica y funciones */
class Ventana : public Fl_Window{ 
	public:
		Ventana(int w, int h, const char* titulo );
		~Ventana();
		Fl_Float_Input* n1;
		Fl_Float_Input* n2;
		Fl_Button* boton;
		Fl_Output* resultado;   
	private:
		static void evento(Fl_Widget*, void*);
		inline void sumar();
};

Ventana::~Ventana(){}

/* se construye la ventana */
Ventana::Ventana(int w, int h, const char* titulo):Fl_Window(w,h,titulo){
	begin();
		n1 = new Fl_Float_Input(150, 10, 100, 25, "Ingrese un numero:");
		n2 = new Fl_Float_Input(150, 45, 100, 25, "Ingrese un numero:");
		boton = new Fl_Button(150, 80, 100, 25, "sumar");
		boton->callback(evento, this);
		resultado = new Fl_Output(150, 115, 100, 25, "El resultado es:");
	end();
	show();
}

/* se invoca la Ventana */
int main (int argc, char **argv){
	Ventana win(270, 160,"Suma");
	return Fl::run();
}

/* evento del boton */
void Ventana::evento(Fl_Widget* o, void* v) {
	( (Ventana*)v )->sumar();
}

/* funcion sumar */
void Ventana::sumar() {
	float sumando1 = atof(n1->value());
	float sumando2 = atof(n2->value());
	if(sumando1==0 || sumando2==0){
		fl_alert("No deje espacios en blanco");
	}
	else{
		float total = sumando1 + sumando2;
		string stotal = to_string(total);
		char* ctotal = new char[stotal.length() + 1];
		sprintf(ctotal, "%.2f", total);
		resultado->value(ctotal);  
	}
}

