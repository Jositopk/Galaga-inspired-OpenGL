#include "display.h"
#include <iostream>

void Display :: Render() {
	glTranslatef(this->GetCoordinateX(), this->GetCoordinateY(), this->GetCoordinateZ());


	

	cuboidA.Render();
	cuboidB.Render();
	cuboidC.Render();
	cuboidD.Render();
	cuboidE.Render();
	cuboidF.Render();
	cuboidG.Render();
	
}
void Display:: displayNumber(unsigned char key) {
	switch (key) {
	case '1':
		
		cuboidA.SetColor(0.05f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(0.05f, 0.0f, 0.0f);
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		cuboidF.SetColor(0.05f, 0.0f, 0.0f);
		cuboidG.SetColor(0.05f, 0.0f, 0.0f);
		break;
	case '2':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(0.05f, 0.0f, 0.0f);
		cuboidD.SetColor(1.0f, 0.0f, 0.0f);
		cuboidE.SetColor(1.0f, 0.0f, 0.0f);
		cuboidF.SetColor(0.05f, 0.0f, 0.0f);
		cuboidG.SetColor(1.0f, 0.0f, 0.0f);
		break;
	case '3':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(1.0f, 0.0f, 0.0f);
		cuboidE.SetColor(.05f, 0.0f, 0.0f);
		cuboidF.SetColor(0.05f, 0.0f, 0.0f);
		cuboidG.SetColor(1.0f, 0.0f, 0.0f);
		break;
	case '4':
		cuboidA.SetColor(0.05f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(0.05f, 0.0f, 0.0f);
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		cuboidF.SetColor(1.0f, 0.0f, 0.0f);
		cuboidG.SetColor(1.0f, 0.0f, 0.0f);
		break;
	case '5':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(0.05f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(1.0f, 0.0f, 0.0f);
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		cuboidF.SetColor(1.0f, 0.0f, 0.0f);
		cuboidG.SetColor(1.0f, 0.0f, 0.0f);
		break;
	case '6':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(0.05f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(1.0f, 0.0f, 0.0f);
		cuboidE.SetColor(1.0f, 0.0f, 0.0f);
		cuboidF.SetColor(1.0f, 0.0f, 0.0f);
		cuboidG.SetColor(1.0f, 0.0f, 0.0f);
		break;
	case '7':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(0.05f, 0.0f, 0.0f);
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		cuboidF.SetColor(0.05f, 0.0f, 0.0f);
		cuboidG.SetColor(0.05f, 0.0f, 0.0f);
		break;
	case '8':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(1.0f, 0.0f, 0.0f);
		cuboidE.SetColor(1.0f, 0.0f, 0.0f);
		cuboidF.SetColor(1.0f, 0.0f, 0.0f);
		cuboidG.SetColor(1.0f, 0.0f, 0.0f);
		break;
	case '9':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(1.0f, 0.0f, 0.0f);
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		cuboidF.SetColor(1.0f, 0.0f, 0.0f);
		cuboidG.SetColor(1.0f, 0.0f, 0.0f);
		break;
	case '0':
		cuboidA.SetColor(1.0f, 0.0f, 0.0f);
		cuboidB.SetColor(1.0f, 0.0f, 0.0f);
		cuboidC.SetColor(1.0f, 0.0f, 0.0f);
		cuboidD.SetColor(1.0f, 0.0f, 0.0f);
		cuboidE.SetColor(1.0f, 0.0f, 0.0f);
		cuboidF.SetColor(1.0f, 0.0f, 0.0f);
		cuboidG.SetColor(0.05f, 0.0f, 0.0f);
		break;
	case 'r':
		cuboidA.SetColor(0.05f, 0.0f, 0.0f);
		cuboidB.SetColor(0.05f, 0.0f, 0.0f);
		cuboidC.SetColor(0.05f, 0.0f, 0.0f);
		cuboidD.SetColor(0.05f, 0.0f, 0.0f);
		cuboidE.SetColor(0.05f, 0.0f, 0.0f);
		cuboidF.SetColor(0.05f, 0.0f, 0.0f);
		cuboidG.SetColor(0.05f, 0.0f, 0.0f);
		break;
	}
}

