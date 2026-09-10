#pragma once
#include "Triangle.h"
#include "Model.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include<vector>
using namespace std;
typedef Vector3D* Vector3DPtr;
class ModelLoader
{
private:

		float scale;
		Model model;
		vector<Vector3D> vertexList;
		vector<Vector3D> normList;
		//� Seis float para almacenar los valores m�ximos y m�nimos de X, Y y Z de los v�rtices le�dos del archivo.
		float maxX;
		float maxY;
		float maxZ;

		float minX;
		float minY;
		float minZ;
		
		
		

		
		//� M�todo getWidth que devuelve la diferencia entre el m�ximo y el m�nimo en el eje X.
		float 	getWidth(){ return maxX - minX; }
		//� M�todo getHeight que devuelve la diferencia entre el m�ximo y el m�nimo en el eje Y.
		float getHeight(){ return maxY - minY; }
		
		//� M�todo getLength que devuelve la diferencia entre el m�ximo y el m�nimo en el eje Z.
		float getLength() { return maxZ - minZ; }
		//� M�todo calcBoundaries, que recibe el vector asociado al �ltimo v�rtice le�do del archivo y actualiza los
		//valores m�ximo y m�nimo para los ejes X, Y y Z.
		void calcBoundaries(Vector3D vectorPoint);
		//� M�todo center, que recibe un objeto Triangle y devuelve otro cuyos v�rtices han sido modificados seg�n
		//el centro del modelo.El centro del modelo se calcula a partir de los m�ximos y m�nimos registrados
		//  despu�s de leer todos los v�rtices incluidos en el archivo obj.
		Triangle center(Triangle triangle);
		
		//� M�todo parseObjLineToVector3D, que recibe un string correspondiente a una l�nea del archivo obj y
		//devuelve un Vector3D correspondiente al punto definido en el archivo obj.
		Vector3D parseObjLineToVector3D(const string& line);
		//� M�todo parseObjTriangle, que recibe un string correspondiente a una l�nea del archivo obj en la que se
		//define una cara y devuelve el tri�ngulo correspondiente.

		Triangle parseObjTriangle(const string& line);
public:
	//ModelLoader() :scale(0.25f), maxX(0.25f), maxY(0.25f), maxZ(0.25f), minX(0.25f), minY(0.25f), minZ(0.25f) {}
	ModelLoader() :scale(2.5f), maxX(-100000.f), maxY(-100000.f), maxZ(-100000.f), minX(100000.f), minY(100000.f), minZ(100000.f) {}
	//ModelLoader() :scale(2.5f), maxX(1.f), maxY(1.f), maxZ(1.f), minX(1.f), minY(1.f), minZ(1.f) {}
	//ModelLoader():scale(2.5f), maxX(0.f), maxY(0.f), maxZ(0.f), minX(0.f), minY(0.f), minZ(0.f) {}

	//Los m�todos p�blicos que requiere la clase son :
	//� M�todo de acceso Get para el atributo model.
		//� M�todo de acceso Get y Set para el atributo de la escala.
		
		float GetScale() const { return scale; }
		void SetScale(const float& s) { scale = s; }
		void GetMaxMin(Vector3D vector);
		//� M�todo LoadModel que recibe una cadena de texto con la ruta del archivo obj a procesar.
		void LoadModel(const string& filePath);
		
		inline Model GetModel() { return this->model; }//obtiene una copia del modelo

		//� M�todo Clear, que vac�a los vectores de v�rtices y normales, as� como el vector de tri�ngulos del atributo
				//model.Esto permite reutilizar el mismo objeto para cargar varios modelos
		void Clear() {
			vertexList.clear();
			normList.clear();
			maxX= -100000.f;
			 maxY= - 100000.f;
			 maxZ= -100000.f;

			 minX= 100000.f;
			 minY = 100000.f;
			 minZ = 100000.f;
			 
			 model = *(new Model());
		}
};

