#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// Function y = -x*cos(x) + sin(x)
//실제 함수로써 오일러 근사치와의 비교 그래프가 된다
double actualFunction(double x) {
    return -x * cos(x) + sin(x);
}

// Derivative function f(x, y) = x*sin(x)
// 오일러 근사치를 구하기 위한 미분방정식
double derivativeFunction(double x, double y) {
    return x * sin(x);
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

    sf::RenderWindow window(sf::VideoMode(width, height), "Euler's method");
    sf::VertexArray graph(sf::LineStrip);

    // Set the coordinate system to match the function's range
    sf::View view(sf::FloatRect(-10.0f, -10.0f, 20.0f, 20.0f));
    window.setView(view);

    double stepSize;
    std::cout << "Enter the initial step size: ";
    std::cin >> stepSize;

    double startX = 0.0;
    double startY = actualFunction(startX);

    eulerMethod(window, graph, startX, startY, stepSize);

    // Draw the actual function
    sf::VertexArray actualGraph(sf::LineStrip);
    for (double x = -10.0; x <= 10.0; x += 0.01) {
        double y = actualFunction(x);
        actualGraph.append(sf::Vertex(sf::Vector2f(x, y), sf::Color::Blue));
    }
    window.draw(actualGraph);

    // Draw the coordinate axes
    sf::VertexArray axes(sf::Lines);
    axes.append(sf::Vertex(sf::Vector2f(-10.0f, 0.0f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(10.0f, 0.0f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(0.0f, -10.0f), sf::Color::Black));
    axes.append(sf::Vertex(sf::Vector2f(0.0f, 10.0f), sf::Color::Black));
    window.draw(axes);

    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)) {
            std::cout << "Enter the new step size: ";
            std::cin >> stepSize;

            eulerMethod(window, graph, startX, startY, stepSize);

            window.clear(sf::Color::White);
            window.draw(graph);
            window.draw(actualGraph);
            window.draw(axes);
            window.display();
        }
    }

    return 0;
}
