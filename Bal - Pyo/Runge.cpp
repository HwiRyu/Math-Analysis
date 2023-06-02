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

// Runge-Kutta method
void rungeKuttaMethod(sf::RenderWindow& window, sf::VertexArray& graph, double startX, double startY, double stepSize) {
    double x = startX;
    double y = startY;

    // Clear the previous graph
    graph.clear();

    // Set the initial point on the graph
    graph.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Magenta));

    // Apply Runge-Kutta method and draw the graph
    while (x <= 10.0) {
        double k1 = stepSize * derivativeFunction(x, y);
        double k2 = stepSize * derivativeFunction(x + stepSize / 2, y + k1 / 2);
        double k3 = stepSize * derivativeFunction(x + stepSize / 2, y + k2 / 2);
        double k4 = stepSize * derivativeFunction(x + stepSize, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += stepSize;

        // Add the next point to the graph
        graph.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Magenta));
    }

    // Draw the graph
    window.draw(graph);
}

// Euler's method
void eulerMethod(sf::RenderWindow& window, sf::VertexArray& graph, double startX, double startY, double stepSize) {
    double x = startX;
    double y = startY;

    // Clear the previous graph
    graph.clear();

    // Set the initial point on the graph
    graph.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Red));

    // Apply Euler's method and draw the graph
    while (x <= 10.0) {
        double dydx = derivativeFunction(x, y);
        y += dydx * stepSize;
        x += stepSize;

        // Add the next point to the graph
        graph.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Red));
    }

    // Draw the graph
    window.draw(graph);
}

int main() {
    const int width = 1200;
    const int height = 800;

    sf::RenderWindow window(sf::VideoMode(width, height), "Numerical Methods");
    sf::VertexArray eulerGraph(sf::LineStrip);
    sf::VertexArray rungeKuttaGraph(sf::LineStrip);

    // Set the coordinate system to match the function's range
    sf::View view(sf::FloatRect(-10.0f, 10.0f, 20.0f, -20.0f));
    window.setView(view);

    double stepSize;
    std::cout << "Enter the initial step size: ";
    std::cin >> stepSize;
    std::cout << "Step Size: " << stepSize << std::endl; // Print the initial step size

    double startX = 0.0;
    double startY = actualFunction(startX);

    eulerMethod(window, eulerGraph, startX, startY, stepSize);
    rungeKuttaMethod(window, rungeKuttaGraph, startX, startY, stepSize);

    // Draw the actual function
    sf::VertexArray actualGraph(sf::LineStrip);
    for (double x = -10.0; x <= 10.0; x += 0.01) {
        double y = actualFunction(x);
        actualGraph.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Blue));
    }

    // Draw the coordinate axes
    sf::VertexArray axes(sf::Lines);
    axes.append(sf::Vertex(sf::Vector2f(-10.0f, 0.0f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(10.0f, 0.0f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(0.0f, -10.0f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(0.0f, 10.0f), sf::Color::Black));

    bool showActualGraph = true;
    bool showRungeKuttaGraph = true;

    window.clear(sf::Color::White);

    eulerMethod(window, eulerGraph, startX, startY, stepSize);
    if (showRungeKuttaGraph)
        rungeKuttaMethod(window, rungeKuttaGraph, startX, startY, stepSize);
    if (showActualGraph)
        window.draw(actualGraph);
    window.draw(axes);
    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    stepSize -= 0.01;
                    if (stepSize < 0.01)
                        stepSize = 0.01;
                }
                else if (event.key.code == sf::Keyboard::Right) {
                    stepSize += 0.01;
                }
                else if (event.key.code == sf::Keyboard::Q) {
                    showActualGraph = !showActualGraph;
                }
                else if (event.key.code == sf::Keyboard::W) {
                    showRungeKuttaGraph = !showRungeKuttaGraph;
                }
            }
        }

        std::cout << "Step Size: " << stepSize << std::endl; // Print the current step size

        window.clear(sf::Color::White);

        eulerMethod(window, eulerGraph, startX, startY, stepSize);
        if (showRungeKuttaGraph)
            rungeKuttaMethod(window, rungeKuttaGraph, startX, startY, stepSize);
        if (showActualGraph)
            window.draw(actualGraph);
        window.draw(axes);
        window.display();
    }

    return 0;
}
