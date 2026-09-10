#pragma once
class Color
{
private:
	float red;
	float green;
	float blue;
public:
	
	//Constructor por defecto
	Color() :red(0.0), green(0.0), blue(0.0) {}//Inicializacion de los tres colores a 0 (negro)
	//Constructor con argumentos
	Color(const float& r, const float& g, const float& b) :red(r), green(g), blue(b) {}
	Color(const float& p) :red(p), green(p), blue(p) {}

	void SetColor(const float& r, const float& g, const float& b) { red = (r <= 1 && r >= 0) ? r : 0; green = (g <= 1 && g >= 0) ? g : 0; blue = (b <= 1 && b >= 0) ? b : 0;
	}//Cambio de los colores segun los argumentos de la funcion y que esten entre 1 y 0
	void SetColor(Color newColor) { red = newColor.GetColorR(); green = newColor.GetColorG(); blue = newColor.GetColorB(); }
	inline void SetColorR(const float& r) { this->red = (r<=1&&r>=0)? r:0; }//Cambio del valor r segun el argumento de la funcion
	inline void SetColorG(const float& g) { this->green = (g<=1&&g>=0)?g:0; }//Cambio del valor g segun el argumento de la funcion
	inline void SetColorB(const float& b) { this->blue =( b<=1&&b>=0)?b:0; }//Cambio del valor b segun el argumento de la funcion

	inline float GetColorR() const { return red; }//Devolver valor r
	inline float GetColorG() const { return green; }//Devolver valor g
	inline float GetColorB() const { return blue; }//Devolver valor b
};

