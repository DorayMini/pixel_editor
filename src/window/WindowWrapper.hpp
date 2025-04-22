#ifndef __WINDOW_WRAPPER_HPP__
#define __WINDOW_WRAPPER_HPP__

#include <array>
#include <string>

#include <SFML/Graphics.hpp>

#include "PerfomanceStats.hpp"

typedef unsigned int uint;

namespace px {
	class WindowWrapper {
	public:
		static WindowWrapper& getInstance(const std::string& title, uint width, uint height);
		static WindowWrapper& getInstance();

		void update();

		sf::RenderWindow& getWindow();
	private:
		WindowWrapper(const std::string& title, uint width, uint height);
		~WindowWrapper();

		WindowWrapper(const WindowWrapper&) = delete;
		void operator=(const WindowWrapper&) = delete;

		std::string _title;
		uint _width, _height;
		sf::RenderWindow* _window;

		px::_detail::PerfomanceStats _stats;
		const float _fpsAlpha = 0.03f;


		static WindowWrapper* _instance;
	};
} // namespace px

#endif // __WINDOW_WRAPPER_HPP__
