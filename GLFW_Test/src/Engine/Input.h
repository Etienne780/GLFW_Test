﻿#pragma once

#include <GLFW/glfw3.h>
#include <unordered_map>

class Vector2;

namespace EngineCore {

	class Key {
	public:
		bool isPressed = false;     // true, if key pressed
		bool isRepeating = false;   // true, if GLFW_REPEAT triggered
		bool wasPressed = false;    // true, only in the frame that the key was pressed
		bool wasReleased = false;   // true, only in the frame that the key was released

		void update();              // should only be called once per frame
		void setState(int state);   // Gets called by the GLFW-Callback

		bool justPressed() const;   // true, if key pressed in this frame
		bool justReleased() const;  // true, if key released in this frame
	};

	class Input {
	public:
		static int frameCount;

		static void Init(GLFWwindow* window);
		static void LateUpdate();

		// is only one frame true
		static bool KeyJustPressed(int key);
		// is only one frame true
		static bool KeyJustReleased(int key);

		// is true as long as the key has the right state
		static bool KeyPressed(int key);
		// is true as long as the key has the right state
		static bool KeyRepeating(int key);

		// is only one frame true
		static bool AnyKeyJustPressed();
		// is only one frame true
		static bool AnyKeyJustReleased();

		// is true as long as the key has the right state
		static bool AnyKeyPressed();
		// is true as long as the key has the right state
		static bool AnyKeyReleased();

		static std::vector<int> KeysJustPressed();
		static std::vector<int> KeysJustReleased();

		static std::vector<int> KeysPressed();
		static std::vector<int> KeysReleased();

		static Vector2 GetMousePosition();

	private:
		Input();
		static std::unordered_map<int, Key> keyStates;
		static Vector2 m_mousePosition;

		static void GLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void GLFWMouseCallBack(GLFWwindow* window, double xpos, double ypos);

		static bool getAnyKeyState(bool keyPressed, bool justPressed);
		static std::vector<int> getKeysState(bool keyPressed, bool justPressed);
	};

}