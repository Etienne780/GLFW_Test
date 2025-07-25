#pragma once
#define GLAD_GL_IMPLEMENTATION
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Application.h"
#include "Time.h"
#include "Input.h"

#include "..\Core\FormatUtils.h"
#include "..\Core\Log.h"
#include "..\Core\Math.h"

namespace EngineCore {
	class Engine {
	public:
		std::unique_ptr<Application> app;

		Engine(std::unique_ptr<Application> app, GLFWwindow* window);

		void Start();
		void Update(double currentTimeSec);
		void LateUpdate();
		void Shutdown();

		void WindowResize(int width, int height);

	private:
		int m_frameCount = 0;
		GLFWwindow* m_window = nullptr;
	};
}