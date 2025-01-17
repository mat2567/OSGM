#include "window.h"
namespace OSGE {
	namespace graphics {
		Window::Window(const char* title, int width, int height) {
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (init()) {

			}
		}
		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {

			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window) {
				glfwTerminate();
				std::cout << "Failed to create window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);

			return true;
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window);
		}

		void Window::update() const {
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}
	}
}