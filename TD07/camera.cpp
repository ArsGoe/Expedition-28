#include "draw_scene.hpp"
#include <vector>
#include <GLFW/glfw3.h>

Vector3D cameraPos   = Vector3D(0.0f, 0.0f,  3.0f);
Vector3D cameraFront = Vector3D(0.0f, 1.0f, 0.0f);
Vector3D cameraUp    = Vector3D(0.0f, 0.0f,  1.0f);
double deltaTime = 0.0;
double lastFrame = 0.0; 

void MaCameraFPS(GLFWwindow* window){
		double currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;  

    	myEngine.mvMatrixStack.loadIdentity();
		Matrix4D viewMatrix = Matrix4D::lookAt(
			cameraPos,
			cameraPos + cameraFront,
			cameraUp
		);
		myEngine.setViewMatrix(viewMatrix);
		myEngine.updateMvMatrix();


		const float cameraSpeed = 5.0f*(float)deltaTime;
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
			cameraPos += cameraFront * cameraSpeed;
		}
		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
    		cameraPos -= cameraFront * cameraSpeed;
		}
		else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			Vector3D ProduitVectoriel;
			ProduitVectoriel.x = cameraFront.y * cameraUp.z - cameraFront.z * cameraUp.y;
			ProduitVectoriel.y = cameraFront.z * cameraUp.x - cameraFront.x * cameraUp.z;
			ProduitVectoriel.z = cameraFront.x * cameraUp.y - cameraFront.y * cameraUp.x;
			//float ProduitVectorielNormalize = ProduitVectoriel.normalize();
			cameraPos += ProduitVectoriel * cameraSpeed;
		}
		else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			Vector3D ProduitVectoriel;
			ProduitVectoriel.x = cameraFront.y * cameraUp.z - cameraFront.z * cameraUp.y;
			ProduitVectoriel.y = cameraFront.z * cameraUp.x - cameraFront.x * cameraUp.z;
			ProduitVectoriel.z = cameraFront.x * cameraUp.y - cameraFront.y * cameraUp.x;
			//float ProduitVectorielNormalize = ProduitVectoriel.normalize();
			cameraPos -= ProduitVectoriel * cameraSpeed;
		}
}