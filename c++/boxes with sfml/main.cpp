#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

sf::RectangleShape** createArray(int rows, int col);
sf::RectangleShape newRectangleShape(float x, float y);
void fillArray(sf::RectangleShape** p, int rows, int col);
void deleteArray(sf::RectangleShape** p, int rows);
void draw(sf::RenderWindow& window, sf::RectangleShape** p, int rows, int col);

int main()
{
    int rows = 1;
    int col = 1;

    sf::VideoMode video(1366, 768, 32);
    sf::RenderWindow window(video, "SFML Lab 2D Array");

    sf::RectangleShape** p = createArray(100, 100); //create an array that will hold a certain amount of squares
    fillArray(p, rows, col);

    while(window.isOpen())
    {
        sf::Event event;

        draw(window, p, rows, col);

        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                deleteArray(p, rows);   //deletes the array so that a new one can be created for squares to disappear
                rows -= 1;
                col -= 1;
                p = createArray(100, 100);
                fillArray(p, rows, col);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                fillArray(p, rows, col);
                rows += 1;
                col += 1;
            }

            window.clear(sf::Color(0, 0, 0));
            draw(window, p, rows, col);
            window.display();
        }
    }

    return 0;
}


//function to create an array of squares
sf::RectangleShape** createArray (int rows, int col)
{
    sf::RectangleShape** p;
    p = new sf::RectangleShape * [rows];

    for (int i = 0; i < rows; i++)
    {
        *(p+i) = new sf::RectangleShape[col];
    }

    return p;
}


//function to set the shape of the image that is being displayed
sf::RectangleShape newRectangleShape (float x, float y)
{
    sf::RectangleShape square;
    sf::Vector2f size(50, 50);
    square.setSize(size); //square.setSize({50, 50})
    square.setFillColor(sf::Color::White);
    square.setPosition({x,y});

    return square;
}


//function to fill the array with squares
void fillArray (sf::RectangleShape** p, int rows, int col)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            *(*(p + i)+j) = newRectangleShape(x, y);
            x += 65;
        }
        x = 0;
        y += 65;
    }
}


//function to delete the previous array
void deleteArray (sf::RectangleShape** p, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] *(p+i);
    }
    delete p;
}


//function to simply draw and eventually display the squares
void draw(sf::RenderWindow& window, sf::RectangleShape** p, int rows, int col)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
        {
            window.draw(p[i][j]);
            //window.draw(*(*(p+i)+j));
        }
    }
}
