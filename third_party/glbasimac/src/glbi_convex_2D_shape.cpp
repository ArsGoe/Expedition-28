#include "glbasimac/glbi_convex_2D_shape.hpp"
#include <array>

namespace glbasimac {

void GLBI_Convex_2D_Shape::initShape(std::vector<float> in_coord, std::vector<float> uvs, bool Arriere, std::vector<float> custom_normals){
		coord_pts.clear();
		if (dimension == 2) {
			assert(in_coord.size()%2 == 0);
			nb_pts = in_coord.size()/2;
		}
		else {
			assert(in_coord.size()%3 == 0);
			nb_pts = in_coord.size()/3;
			//std::cerr<<"NB POINT : "<<nb_pts<<std::endl;
		}

		shape.setNbElt(nb_pts);
		coord_pts = std::move(in_coord);

		std::vector<float> normals(nb_pts * 3, 0.0f);

		//Modifs lights
		if (!custom_normals.empty()) {
			// Utilise les normales fournies
			normals = custom_normals;
		} else {
			if (Arriere){
				for (int i = 0; i < nb_pts; i++) {
					normals[3*i + 1] = 1.0f;
				}
			} else {
				for (int i = 0; i < nb_pts; i++) {
					normals[3*i + 1] = -1.0f;
				}
			}
		}
		//Fin modifs light

		shape.addOneBuffer(0,dimension,coord_pts.data(),"Coordinates",false);
		shape.addOneBuffer(2,2,uvs.data(),"uvs",true);
		//Modifs lights
		shape.addOneBuffer(1, 3, normals.data(), "normals", false);
		//Fin modifs light

		if(!shape.createVAO()) {
			std::cerr<<"Unable to create VAO for Set of Points"<<std::endl;
			exit(1);
		}
	}

	void GLBI_Convex_2D_Shape::changeNature(unsigned int new_gl_type) {
		shape.changeType(new_gl_type);
	}

	void GLBI_Convex_2D_Shape::drawShape() {
		shape.draw();
	}

}