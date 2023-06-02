#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// Function y = -x*cos(x) + sin(x)
double actualFunction(double x) {
    return -x * cos(x) + sin(x);
}

// Derivative function f(x, y) = x*sin(x)
double derivativeFunction(double x, double y) {
    return x * sin(x);
}

// Euler's method
void eulerMethod(sf::RenderWindow& window, sf::VertexArray& graph, double startX, double startY, double stepSize, bool clearGraph) {
    double x = startX;
    double y = startY;

    if (clearGraph) {
        graph.clear();
        graph.append(sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::Red));
    }

    while (x <= 10.0) {
        double dydx = derivativeFunction(x, y);
        y += dydx * stepSize;
        x += stepSize;

        graph.append(sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::Red));
    }

    window.draw(graph);
}

// Runge-Kutta method
void rungeKuttaMethod(sf::RenderWindow& window, sf::VertexArray& graph, double startX, double startY, double stepSize, bool clearGraph) {
    double x = startX;
    double y = startY;

    if (clearGraph) {
        graph.clear();
        graph.append(sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::Blue));
    }

    while (x <= 10.0) {
        double k1 = stepSize * derivativeFunction(x, y);
        double k2 = stepSize * derivativeFunction(x + stepSize / 2, y + k1 / 2);
        double k3 = stepSize * derivativeFunction(x + stepSize / 2, y + k2 / 2);
        double k4 = stepSize * derivativeFunction(x + stepSize, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += stepSize;

        graph.append(sf::Vertex(sf::Vector2f(static_cast<float>(x), static_cast<float>(y)), sf::Color::Blue));
    }

    window.draw(graph);
}

int main() {
    const int width = 1200;
    const int height = 800;

    sf::RenderWindow window(sf::VideoMode(width, height), "Euler's and Runge-Kutta Methods");

    sf::VertexArray eulerGraph(sf::LineStrip);
    sf::VertexArray rungeKuttaGraph(sf::LineStrip);

    // Set the initial values
    double startX = 0.0;
    double startY = actualFunction(startX);
    double stepSize = 0.1;

    // Create the step size label
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
        return 1;
    }

    sf::Text stepSizeLabel;
    stepSizeLabel.setFont(font);
    stepSizeLabel.setString("Step Size: " + std::to_string(stepSize));
    stepSizeLabel.setCharacterSize(20);
    stepSizeLabel.setFillColor(sf::Color::Black);
    stepSizeLabel.setPosition(10.0f, 10.0f);

    bool isRungeKuttaVisible = true;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    stepSize -= 0.1;
                    stepSizeLabel.setString("Step Size: " + std::to_string(stepSize));
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    stepSize += 0.1;
                    stepSizeLabel.setString("Step Size: " + std::to_string(stepSize));
                }
                else if (event.key.code == sf::Keyboard::Q) {
                    isRungeKuttaVisible = !isRungeKuttaVisible;
                }
            }
        }

        window.clear(sf::Color::White);

        eulerMethod(window, eulerGraph, startX, startY, stepSize, true);

        if (isRungeKuttaVisible) {
            rungeKuttaMethod(window, rungeKuttaGraph, startX, startY, stepSize, true);
        }

        window.draw(stepSizeLabel);
        window.display();
    }

    return 0;
}