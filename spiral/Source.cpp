#include<iostream>
#include "SFML/Graphics.hpp"
#include <ctime>
#include<vector>
using namespace std;
int main() {
    //game set up (you'll need these lines in every game)
    sf::RenderWindow screen(sf::VideoMode(1920*2, 1000), "spiral"); //set up screen
    sf::Event event; //set up event queue
    sf::Clock clock; //set up the clock (needed for game timing)
    const float FPS = 60.0f; //FPS
    screen.setFramerateLimit(FPS); //set FPS
    int num;
    cout << "Enter number for sequence..." << endl;
    cin >> num;
    srand(time(NULL));
    vector <int> ALE;
    vector <int>::iterator ALE2;
    vector <sf::RectangleShape> REE;
    vector <sf::RectangleShape>::iterator REE2;
    ALE.push_back(0);
    int fib1 = 0;
    int fib2 = 1;
    for (int whatever = 0; whatever < num; whatever ++) {
       // cout << whatever << endl;
        
        
        fib2 = fib1 + fib2;
        fib1 += fib2;
        ALE.push_back(fib2);
        ALE.push_back(fib1);
        
        screen.display(); //flips memory drawings onto screen
    }
    int count = 0;
    int offset = 0;
    cout << "Start: ";
    for (ALE2 = ALE.begin(); ALE2 != ALE.end(); ALE2++) {
        count++;
        if (count <= num) {
            offset += (*ALE2);
            cout << (*ALE2) << ", ";
            sf::RectangleShape square;
            square.setFillColor(sf::Color(rand() % 256, rand() % 256, rand() % 256));
            square.setPosition(offset * .62, 0);
            square.setSize(sf::Vector2f((*ALE2), (*ALE2)));
            REE.push_back(square);
          
        }
    }
    cout << endl;
    screen.display();
    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (screen.isOpen()) {//keep window open until user shuts it down

        while (screen.pollEvent(event)) { //look for events-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                screen.close();

        }//end event loop---------------------------------------------------------------
                //render section-----------------------------------------
        //screen.clear(); //wipes screen, without this things smear
        for (REE2 = REE.begin(); REE2 != REE.end(); REE2++) {
            screen.draw(*REE2);
        }
        screen.display();
    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end of main