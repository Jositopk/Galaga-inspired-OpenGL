#include "ModelLoader.h"

void ModelLoader::LoadModel(const string& filePath)

{

	try

	{

		ifstream objFile (filePath);

		if (objFile.is_open())

		{

			string line;

			int count = 0;

			while (getline(objFile, line))

			{

				if (line[0] == 'v' && line[1] == 'n')

				{

					Vector3D normal = this->parseObjLineToVector3D(line);

					this->normList.push_back(normal);

				}

				else if (line[0] == 'v')

				{

					Vector3D vertex = this->parseObjLineToVector3D(line);

					this->calcBoundaries(vertex);

					this->vertexList.push_back(vertex);

				}

				else if (line[0] == 'f')

				{

					Triangle triangle = this->parseObjTriangle(line);

					//this->model.AddTriangle(this->center(triangle));

					this->model.AddTriangle(triangle);

				}

			}

			objFile.close();

		}

		else

		{

			cout << "No se ha podido abrir el archivo: " << filePath << endl;

		}

	}

	catch (exception& ex)

	{

		cout << "Excepcion al procesar el archivo: " << filePath << endl;

		cout << ex.what() << endl;

	}

}









Vector3D ModelLoader::parseObjLineToVector3D(const string& line)

{

	string typeOfPoint;

	float xCoordinate, yCoordinate, zCoordinate;

	istringstream stringStream(line);

	stringStream >> typeOfPoint >> xCoordinate >> yCoordinate >> zCoordinate;

	Vector3D vectorPoint(xCoordinate, yCoordinate, zCoordinate);
	GetMaxMin(vectorPoint);
	return vectorPoint * this->GetScale();//Devuelve el punto escalado

}









Triangle ModelLoader::parseObjTriangle(const string& line)

{

	char c;

	int idxVertex0, idxVertex1, idxVertex2;

	int idxNormal0, idxNormal1, idxNormal2;



	istringstream stringStream(line);

	stringStream >> c;

	stringStream >> idxVertex0 >> c>>c >> idxNormal0;//lectura iv//ivn, ignora las dos'/'

	stringStream >> idxVertex1 >> c >>c>> idxNormal1;

	stringStream >> idxVertex2 >> c>>c >> idxNormal2;



	Vector3D vertex0 = this->vertexList[idxVertex0 - 1];

	Vector3D vertex1 = this->vertexList[idxVertex1 - 1];

	Vector3D vertex2 = this->vertexList[idxVertex2 - 1];

	Vector3D normal = this->normList[idxNormal0 - 1]; //las 3 normales son iguales



	Triangle parsedTriangle(vertex0, normal, vertex1, normal, vertex2, normal);



	return parsedTriangle;

}


void ModelLoader::GetMaxMin(Vector3D vector) {
	//calcular maximos leidos
	if (vector.GetVectorX() > maxX) { maxX = vector.GetVectorX(); }
	if (vector.GetVectorY() > maxY) { maxY = vector.GetVectorY(); }
	if (vector.GetVectorZ() > maxZ) { maxZ = vector.GetVectorZ(); }
	//calcular minimos leidos
	if (vector.GetVectorX() < minX) { minX = vector.GetVectorX(); }
	if (vector.GetVectorY() < minY) { minY = vector.GetVectorY(); }
	if (vector.GetVectorZ() < minZ) { minZ = vector.GetVectorZ(); }
}










void ModelLoader::calcBoundaries(Vector3D vectorPoint)

{

	this->maxX = fmax(this->maxX, vectorPoint.GetVectorX());

	this->maxY = fmax(this->maxY, vectorPoint.GetVectorY());

	this->maxZ = fmax(this->maxZ, vectorPoint.GetVectorZ());

	this->minX = fmin(this->minX, vectorPoint.GetVectorX());

	this->minY = fmin(this->minY, vectorPoint.GetVectorY());

	this->minZ = fmin(this->minZ, vectorPoint.GetVectorZ());

}









Triangle ModelLoader::center(Triangle triangle)

{

	Vector3D modelCenter(this->minX + this->getWidth() / 2,

		this->minY + this->getHeight() / 2.0,

		this->minZ + this->getLength() / 2);

	Triangle centeredTriangle(

		triangle.GetVertex0() - modelCenter,

		triangle.GetVertex1() - modelCenter,

		triangle.GetVertex2() - modelCenter,

		triangle.GetNormal0(),

		triangle.GetNormal1(),

		triangle.GetNormal2());

	return centeredTriangle;

}





//Uso de un modelo en la escena del juego.

/*

ModelLoader* loader = new ModelLoader();



Model* star = new Model();

loader->LoadModel("assets/models/star.obj");

*star = loader->GetModel();

star->SetPosition(Vector3D(1, 1, 1));

star->SetOrientation(Vector3D(30, -60, -10));

star->SetOrientationSpeed(Vector3D(3, 2, 1));

star->SetSpeed(Vector3D(0.01, 0.02, 0.03));

star->PaintColor(Color(0.2, 0.5, 0.1));

this->mainScene.AddGameObject(star);

loader->Clear();
*/

