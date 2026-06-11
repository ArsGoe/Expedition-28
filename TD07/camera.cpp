#include "draw_scene.hpp"
#include <vector>
#include <GLFW/glfw3.h>

Vector3D cameraPos   = Vector3D(0.0f, 0.0f,  3.0f);
Vector3D cameraFront = Vector3D(0.0f, 1.0f, 0.0f);
Vector3D cameraUp    = Vector3D(0.0f, 0.0f,  1.0f);

float yaw   = 90.0f;
float pitch = 0.0f;
float lastX = 600.0f; // WINDOW_WIDTH / 2
float lastY = 400.0f; // WINDOW_HEIGHT / 2
bool firstMouse = true;

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

void mouse_callback(GLFWwindow* /*window*/, double xpos, double ypos){
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // inversé car Y va vers le bas

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw   -= xoffset;
    pitch += yoffset;

    if (pitch > 89.0f)  pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    // Remplace glm::vec3 + glm::radians + glm::normalize par tes types
    cameraFront.x = cos(deg2rad(yaw)) * cos(deg2rad(pitch));
    cameraFront.y = sin(deg2rad(yaw)) * cos(deg2rad(pitch));
    cameraFront.z = sin(deg2rad(pitch));
    // Pas besoin de normalize si les formules sphériques sont correctes
}

  