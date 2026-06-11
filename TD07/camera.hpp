#include <vector>

extern Vector3D cameraPos;
extern Vector3D cameraFront;
extern Vector3D cameraUp;

void MaCameraFPS(GLFWwindow* window);
void mouse_callback(GLFWwindow* /*window*/, double xpos, double ypos);