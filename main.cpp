#include <iostream>
#include <SFML/Graphics.hpp>
#include "solver.hpp"
#include "renderer.hpp"
#include "utils/number_generator.hpp"
#include "utils/math.hpp"


static sf::Color getRainbow(float t)
{
    const float r = sin(t);
    const float g = sin(t + 0.33f * 2.0f * Math::PI);
    const float b = sin(t + 0.66f * 2.0f * Math::PI);
    return {static_cast<uint8_t>(255.0f * r * r),
            static_cast<uint8_t>(255.0f * g * g),
            static_cast<uint8_t>(255.0f * b * b)};
}


int32_t main(int32_t, char*[])
{
    // Create window
    constexpr int32_t window_width  = 1000;
    constexpr int32_t window_height = 1000;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Verlet", sf::Style::Default, settings);
    const uint32_t frame_rate = 60;
    window.setFramerateLimit(frame_rate);

    Solver   solver;
    Renderer renderer{window};

    // Solver configuration
    const float        zoom_factor = 100.0f;
    const float        constraint_radius = 4.5f;// meters [m]
    const sf::Vector2f constraint_position{ static_cast<float>(window_width) * 0.5f / zoom_factor, static_cast<float>(window_height) * 0.5f / zoom_factor };
    solver.setConstraint(constraint_position, constraint_radius);
    solver.setSubStepsCount(8);
    solver.setSimulationUpdateRate(frame_rate);

    // Set simulation attributes
    const float        object_spawn_delay    = 0.025f;
    const float        object_spawn_speed    = 12.0f;// meters per second [m/s]
    const sf::Vector2f object_spawn_position = {5.0f, 2.0f};// meters [m]
    const float        object_min_radius     = 0.01f;// meters [m]
    const float        object_max_radius     = 0.2f;// meters [m]
    const uint32_t     max_objects_count     = 1000;
    const float        max_angle             = 1.0f;

    sf::Clock clock;
    // Main loop
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        if (solver.getObjectsCount() < max_objects_count && clock.getElapsedTime().asSeconds() >= object_spawn_delay) {
            clock.restart();
            auto&       object = solver.addObject(object_spawn_position, RNGf::getRange(object_min_radius, object_max_radius));
            const float t      = solver.getTime();
            const float angle  = max_angle * sin(t) + Math::PI * 0.5f;
            solver.setObjectVelocity(object, object_spawn_speed * sf::Vector2f{cos(angle), sin(angle)});
            object.color = getRainbow(t);
        }

        solver.update();
        window.clear(sf::Color::White);
        renderer.render(solver, zoom_factor);
		window.display();
    }

    return 0;
}
